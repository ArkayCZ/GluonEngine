#pragma once

#include <glm/glm.hpp>

namespace ge { namespace graphics
{
	class Transform
	{
	public:

		Transform();
		Transform(glm::vec3& translation, glm::vec3& rotation, glm::vec3& scale);

		glm::vec3& GetTranslation() { return m_Translation; }
		glm::vec3& GetRotation() { return m_Rotation; }
		glm::vec3& GetScale() { return m_Scale; }

		glm::mat4 GetModelMatrix() const;
		glm::mat4 GetWorldMatrix(const glm::mat4& projectionMatrix) const;

	private:
		glm::vec3 m_Translation;
		glm::vec3 m_Rotation;
		glm::vec3 m_Scale;
	};

} }

