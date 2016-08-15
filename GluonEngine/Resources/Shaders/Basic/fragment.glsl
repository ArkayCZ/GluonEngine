#version 330

layout (location = 0) out vec4 color;
uniform vec3 u_Color;

in vec3 v_Color;

void main() {
	vec3 c = v_Color;
	c += u_Color;
	color = vec4(c, 1.0);
}