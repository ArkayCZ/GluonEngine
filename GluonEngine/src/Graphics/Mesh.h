#pragma once

#include "../Common.h"
#include <vector>
#include <GL/glew.h>
#include <glm/detail/type_vec3.hpp>

namespace ge {namespace graphics
{
	class Mesh
	{
	public:
		Mesh(GLuint vao, GLuint* buffers, unsigned int drawCount);

		GLuint GetVAO() const { return m_VAO; }
		GLuint* GetBuffers() const { return m_Buffers; }
		const unsigned int& GetDrawCount() const { return m_DrawCount; }

		void Draw();

		enum
		{
			POSITION_BUFFER,
			TEXCOORD_BUFFER,
			INDEX_BUFFER,
			BUFFER_COUNT
		};

	private:
		unsigned int m_DrawCount;
		GLuint m_VAO;
		GLuint* m_Buffers;
	};

} }