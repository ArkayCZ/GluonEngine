#include "Shader.h"
#include "../Common.h"

using namespace ge::graphics;

Shader::Shader(GLuint programId, GLuint* shaders)
{
	m_Program = programId;
	for (int i = 0; i < Shader::SHADER_COUNT; i++)
		m_Shaders[i] = shaders[i];
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else glGetShaderiv(shader, flag, &success);

	if(success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		ERROR(errorMessage << ": '" << error << "'");
	}
}

void Shader::CacheUniform(const std::string& name)
{
	GLint location = glGetUniformLocation(m_Program, name.c_str());
	if (location == -1)
		ERROR("Could not find uniform " << name);
	m_UniformCache.insert_or_assign(name, location);
}

GLint Shader::FindUniform(const std::string& name)
{
	if(m_UniformCache.count(name) == 0)
		this->CacheUniform(name);

	return m_UniformCache[name];
}

void Shader::Bind() const
{
	glUseProgram(m_Program);
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void Shader::Unbind() const
{
	glUseProgram(0);
}

void Shader::SetUniform(const std::string& name, int i)
{
	glUniform1i(this->FindUniform(name), i);
}

void Shader::SetUniform(const std::string& name, float f)
{
	glUniform1f(this->FindUniform(name), f);
}

void Shader::SetUniform(const std::string& name, glm::vec2 vector)
{
	glUniform2f(this->FindUniform(name), vector.x, vector.y);
}

void Shader::SetUniform(const std::string& name, glm::vec3 vector)
{
	glUniform3f(this->FindUniform(name), vector.x, vector.y, vector.z);
}

void Shader::SetUniform(const std::string& name, glm::mat4 matrix)
{
	glUniformMatrix4fv(this->FindUniform(name), 1, GL_FALSE, &matrix[0][0]);
}
