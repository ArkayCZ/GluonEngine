#pragma once

#include <glm/glm.hpp>

class Vertex
{
public:

	Vertex()
	{
		m_Position = glm::vec3(0);
		m_TexCoord = glm::vec2(0);
	}

	Vertex(glm::vec3 position)
	{
		m_Position = position;
		m_TexCoord = glm::vec2(0);
	}

	Vertex(glm::vec3 position, glm::vec2 textureCoord)
	{
		m_Position = position;
		m_TexCoord = textureCoord;
	}

	glm::vec3& GetPosition() { return m_Position; }
	glm::vec2& GetTexCoord() { return m_TexCoord; }

private:
	glm::vec3 m_Position;
	glm::vec2 m_TexCoord;
};
