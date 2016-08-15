#include "Mesh.h"

using namespace ge::graphics;

Mesh::Mesh(GLuint vao, GLuint* buffers, unsigned int drawCount)
{
	m_VAO = vao;
	m_Buffers = new GLuint[Mesh::BUFFER_COUNT];
	for (unsigned int i = 0; i < Mesh::BUFFER_COUNT; i++)
		m_Buffers[i] = buffers[i];

	m_DrawCount = drawCount;
}

void Mesh::Draw()
{
	glBindVertexArray(m_VAO);
	glDrawElementsBaseVertex(GL_TRIANGLES, m_DrawCount, GL_UNSIGNED_INT, 0, 0);
	glBindVertexArray(0);
}
