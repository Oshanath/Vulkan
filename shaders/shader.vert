#version 450

layout(set = 0, binding = 0) uniform MatrixBlock {
    mat4 matrices[1000000];
};

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec2 inTexCoord;
layout(location = 2) in uint inMeshIndex;

layout(location = 0) out vec2 fragTexCoord;
layout(location = 1) out uint outMeshIndex;

void main() {
    gl_Position = matrices[1] * matrices[0] * matrices[2 + inMeshIndex] * vec4(inPosition, 1.0);
    fragTexCoord = inTexCoord;
    outMeshIndex = inMeshIndex;
}