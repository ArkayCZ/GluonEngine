#include "Texture.h"

using namespace ge::graphics;

Texture::Texture(GLuint textureID, const TextureData* data)
{
	m_TextureID = textureID;
	SetTextureParamters(data);
}


Texture::~Texture()
{
	glDeleteTextures(1, &m_TextureID);
}


void Texture::SetTextureParamters(const TextureData* data)
{
	m_Width = data->_Width;
	m_Height = data->_Height;
	m_BytesPerPixel = data->_BytesPerPixel;
}

void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
