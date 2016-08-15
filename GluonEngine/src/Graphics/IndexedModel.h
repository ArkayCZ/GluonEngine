#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "Vertex.h"

namespace ge {namespace graphics
{
	class IndexedModel
	{
	public:
		IndexedModel()
		{
			m_Positions = new std::vector<glm::vec3>();
			m_TextureCoords = new std::vector<glm::vec2>();
			m_Indices = new std::vector<unsigned int>();
		}

		IndexedModel(std::vector<glm::vec3>* positions, std::vector<glm::vec2>* textureCoords, std::vector<unsigned int>* indices)
		{
			m_Positions = positions;
			m_TextureCoords = textureCoords;
			m_Indices = indices;
		}

		IndexedModel(Vertex* vertex, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount) : IndexedModel()
		{
			for (unsigned int i = 0; i < vertexCount; i++)
			{
				m_Positions->push_back(vertex[i].GetPosition());
				m_TextureCoords->push_back(vertex[i].GetTexCoord());
			}

			for (unsigned int i = 0; i < indexCount; i++)
			{
				m_Indices->push_back(indices[i]);
			}
		}

		std::vector<glm::vec3>& GetPositions() const { return *m_Positions; }
		std::vector<glm::vec2>& GetTextureCoords() const { return *m_TextureCoords; }
		std::vector<unsigned int>& GetIndices() const { return *m_Indices; }
	private:
		std::vector<glm::vec3>* m_Positions;
		std::vector<glm::vec2>* m_TextureCoords;
		std::vector<unsigned int>* m_Indices;
	};

} }

