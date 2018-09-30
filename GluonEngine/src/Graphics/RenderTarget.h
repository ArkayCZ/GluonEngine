#pragma once

#include <GLAD/glad.h>
#include "RenderDevice.h"

namespace ge { namespace graphics {

	class RenderTarget
	{
	public:
		RenderTarget(GLuint id, unsigned int width, unsigned int height);

		void Bind() const;
		void Unbind() const;

		const unsigned int& GetID() const { return m_TargetID; }
		const unsigned int& GetWidth() const { return m_Width; }
		const unsigned int& GetHeight() const { return m_Height; }
	private:
		const GLuint m_TargetID;
		const unsigned int m_Width, m_Height;
	};
}}
