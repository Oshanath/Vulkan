#version 450

layout(location = 0) in vec2 fragTexCoord;
layout(location = 1) flat in uint meshIndex;

layout(location = 0) out vec4 outColor;

layout(set = 1, binding = 0) uniform sampler2D texSamplers[1000];

void main() {
    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    outColor = vec4(ambientStrength * lightColor, 1.0) * texture(texSamplers[meshIndex], fragTexCoord);
}