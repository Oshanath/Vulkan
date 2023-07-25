#version 450

layout(location = 0) in vec3 fragPosition;
layout(location = 1) in vec3 fragNormal;
layout(location = 2) in vec2 fragTexCoord;
layout(location = 3) flat in uint meshIndex;

layout(location = 0) out vec4 outColor;

layout(set = 1, binding = 0) uniform sampler2D texSamplers[1000];

struct LightSource {
    vec3 position;
    vec3 color;
};

layout(set = 2, binding = 0) uniform LightSources {
    LightSource lightSources[1000];
} lightSources;

void main() {

    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 lightPos = vec3(0.0, 4.0, 0.0);

    vec3 norm = normalize(fragNormal);
    vec3 lightDirection = normalize(lightPos - fragPosition);
    float diff = max(dot(norm, lightDirection), 0.0);
    vec3 diffuse = diff * lightColor;

    float ambientStrength = 0.05;
    vec3 ambient = ambientStrength * lightColor;
    outColor = vec4(ambient + diffuse, 1.0) * texture(texSamplers[meshIndex], fragTexCoord);
}