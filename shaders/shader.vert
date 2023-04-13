#version 450

// layout(binding = 0) uniform UniformBufferObject {
//     mat4 model;
//     mat4 view;
//     mat4 proj;
// } ubo;

layout(binding = 0) uniform MatrixBlock {
    mat4 matrices[1000000];
};

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec2 inTexCoord;
layout(location = 2) in uint meshIndex;

layout(location = 0) out vec2 fragTexCoord;

void main() {
    gl_Position = matrices[1] * matrices[0] * matrices[2 + meshIndex] * vec4(inPosition, 1.0);
    fragTexCoord = inTexCoord;
}