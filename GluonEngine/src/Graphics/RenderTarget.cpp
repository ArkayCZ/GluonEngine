#include "RenderTarget.h"
#include "GL/glew.h"

RenderTarget::RenderTarget(GLuint id, unsigned int width, unsigned int height)
	: m_TargetID(id), m_Width(width), m_Height(height)
{
	
}

void RenderTarget::Bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_TargetID);
}

void RenderTarget::Unbind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

