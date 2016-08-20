#version 330

layout (location = 0) out vec4 color;

uniform sampler2D u_Texture;

in vec2 v_TextureCoord;

void main() {
	color = texture2D(u_Texture, v_TextureCoord);
	//color = vec4(v_TextureCoord.xy, 1.0, 1.0);
}