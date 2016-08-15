#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoord;

uniform mat4 u_WorldMatrix;
out vec3 v_Color;

void main() {
	v_Color = position;
	gl_Position = u_WorldMatrix *  vec4(position, 1);
}