#version 450

layout(location = 0) in vec2 fragTexCoord;
layout(location = 1) flat in uint meshIndex;

layout(location = 0) out vec4 outColor;

layout(set = 1, binding = 0) uniform sampler2D texSamplers[1000];

void main() {
    outColor = texture(texSamplers[meshIndex], fragTexCoord);
}