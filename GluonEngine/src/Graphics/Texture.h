#pragma once
#include <GL/glew.h>

namespace ge { namespace graphics
{
	struct TextureData
	{
		unsigned int _Width;
		unsigned int _Height;
		unsigned char _BytesPerPixel;
		unsigned char* _Data;

		unsigned int GetDataSize() const { return this->_Width * this->_Height; }
	};

	class Texture
	{
	public:
		Texture(GLuint textureID, const TextureData* data);
		~Texture();

		void SetTextureParamters(const TextureData* data);
		void Bind() const;
		void Unbind() const;

		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }
		unsigned char GetBytesPerPixel() const { return m_BytesPerPixel; }

		void SetWidth(unsigned int width) { m_Width = width; }
		void SetHeight(unsigned int height) { m_Height = height; }
		void SetBytesPerPixel(unsigned char bytesPerPixel) { m_BytesPerPixel = bytesPerPixel; }

		enum Filtering
		{
			NEAREST, LINEAR
		};

	private:
		GLuint m_TextureID;

		unsigned int m_Width, m_Height;
		unsigned char m_BytesPerPixel;

	};

} }
