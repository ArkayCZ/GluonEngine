#pragma once

#include <glm/glm.hpp>
#include <GLAD/glad.h>
#include <string>
#include <map>

namespace ge {namespace graphics
{

	class Shader
	{
	public:

		Shader(GLuint programId, GLuint* shaders);

		void Bind() const;
		void Unbind() const;

		void SetUniform(const std::string& name, int i);
		void SetUniform(const std::string& name, float f);
		void SetUniform(const std::string& name, glm::vec2 vector);
		void SetUniform(const std::string& name, glm::vec3 vector);
		void SetUniform(const std::string& name, glm::mat4 matrix);

		GLint FindUniform(const std::string& name);
		void CacheUniform(const std::string& name);
		GLuint GetProgram() const { return m_Program; }
		static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
		static const unsigned int SHADER_COUNT = 3;

	private:

		GLuint m_Program;
		GLuint m_Shaders[SHADER_COUNT];

		std::map<std::string, GLint> m_UniformCache;

	};

} }
