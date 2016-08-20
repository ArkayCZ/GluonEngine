#include "OpenGLRenderDevice.h"
#include "../Common.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace ge::graphics;

bool OpenGLRenderDevice::Initialize()
{
	int glewInitResult = glewInit();

	LOG("GLEW intialized with code " << glewInitResult);

	if(glewInitResult != GLEW_OK)
	{
		ERROR("Failed to init GLEW!");
		return false;
	}

	glEnable(GL_DEPTH_TEST);
	//glFrontFace(GL_CW);
	return true;
}


void OpenGLRenderDevice::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderDevice::SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

Mesh* OpenGLRenderDevice::CreateMesh(IndexedModel* model)
{
	GLuint vertexArray;
	GLuint vertexBuffers[Mesh::BUFFER_COUNT];

	int drawCount = model->GetIndices().size();

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(Mesh::BUFFER_COUNT, vertexBuffers);

	// Position buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffers[Mesh::POSITION_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, model->GetPositions().size() * sizeof(model->GetPositions()[0]), &model->GetPositions()[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glDisableVertexAttribArray(0);

	// Texcoord buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffers[Mesh::TEXCOORD_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, model->GetTextureCoords().size() * sizeof(model->GetTextureCoords()[0]), &model->GetTextureCoords()[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	//glDisableVertexAttribArray(1);
	
	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexBuffers[Mesh::INDEX_BUFFER]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model->GetIndices()[0]) * drawCount, &model->GetIndices()[0], GL_STATIC_DRAW);

	glBindVertexArray(0);

	Mesh* mesh = new Mesh(vertexArray, vertexBuffers, drawCount);
	return mesh;
}

Shader* OpenGLRenderDevice::CompileShader(const std::string& vertexSource, const std::string& fragmentSource)
{
	GLuint program, vertexShader, fragmentShader;

	program = glCreateProgram();
	GLuint shaders[Shader::SHADER_COUNT];

	shaders[0] = this->CreateShader(vertexSource, GL_VERTEX_SHADER);
	shaders[1] = this->CreateShader(fragmentSource, GL_FRAGMENT_SHADER);

	for (int i = 0; i < Shader::SHADER_COUNT; i++)
		glAttachShader(program, shaders[i]);

	glLinkProgram(program);
	Shader::CheckShaderError(program, GL_LINK_STATUS, true, "Failed linking shaders");

	glValidateProgram(program);
	Shader::CheckShaderError(program, GL_VALIDATE_STATUS, true, "Failed validating shaders");

	Shader* result = new Shader(program, shaders);
	
	// Must be in every shader.
	result->CacheUniform("u_WorldMatrix");

	return result;
}

Texture* OpenGLRenderDevice::CreateTexture(const TextureData* data, int filtering)
{
	GLuint texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	int _filtering = filtering == Texture::Filtering::LINEAR ? GL_LINEAR : GL_NEAREST;
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _filtering);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _filtering);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, data->_Width, data->_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data->_Data);
	
	glBindTexture(GL_TEXTURE_2D, 0);

	Texture* tex = new Texture(texture, data);
	return tex;
}


RenderTarget* OpenGLRenderDevice::GenerateRenderTarget(unsigned int width, unsigned int height)
{
	GLuint framebuffer, texture, depthRenderBuffer;
	glGenFramebuffers(1, &framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	glGenRenderbuffers(1, &depthRenderBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, depthRenderBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderBuffer);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture, 0);
	
	GLenum drawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
	glDrawBuffers(1, drawBuffers);

	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		ERROR("FALED TO CREATE A FRAMEBUFFER!");
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	RenderTarget* target = new RenderTarget(framebuffer, width, height);
	return target;
}

GLuint OpenGLRenderDevice::CreateShader(const std::string& source, GLuint type) const
{
	GLuint shader = glCreateShader(type);

	if (shader == 0)
		ERROR("Error compiling shader!");

	const GLchar* src[1];
	src[0] = source.c_str();
	GLint length[1];
	length[0] = source.length();

	glShaderSource(shader, 1, src, length);
	glCompileShader(shader);

	Shader::CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");

	return shader;
}
