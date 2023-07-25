#version 450

layout(set = 0, binding = 0) uniform MatrixBlock {
    mat4 matrices[1000000];
};

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoord;
layout(location = 3) in uint inMeshIndex;

layout(location = 0) out vec3 fragPosition;
layout(location = 1) out vec3 fragNormal;
layout(location = 2) out vec2 fragTexCoord;
layout(location = 3) out uint outMeshIndex;

void main() {
    gl_Position = matrices[1] * matrices[0] * matrices[2 + inMeshIndex] * vec4(inPosition, 1.0);
    fragTexCoord = inTexCoord;
    outMeshIndex = inMeshIndex;
    fragPosition = vec3(matrices[2 + inMeshIndex] * vec4(inPosition, 1.0));
    fragNormal = mat3(transpose(inverse(matrices[2 + inMeshIndex]))) * inNormal;
}