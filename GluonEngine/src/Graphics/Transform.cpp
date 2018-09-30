#include "Transform.h"
#include <glm/gtx/transform.hpp>

using namespace ge::graphics;

Transform::Transform()
{
	m_Translation = glm::vec3(1);
	m_Rotation = glm::vec3(1);
	m_Scale = glm::vec3(1);
}

Transform::Transform(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
{
	m_Translation = translation;
	m_Rotation = rotation;
	m_Scale = scale;
}


glm::mat4 Transform::GetModelMatrix() const
{
	glm::mat4 translationMatrix = glm::translate(m_Translation);
	glm::mat4 scaleMatrix = glm::scale(m_Scale);
	glm::mat4 xRotationMatrix = glm::rotate(m_Rotation.x, glm::vec3(1, 0, 0));
	glm::mat4 yRotationMatrix = glm::rotate(m_Rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 zRotationMatrix = glm::rotate(m_Rotation.z, glm::vec3(0, 0, 1));

	glm::mat4 rotationMatrix = xRotationMatrix * yRotationMatrix * zRotationMatrix;

	return translationMatrix * rotationMatrix * scaleMatrix;
}

glm::mat4 Transform::GetWorldMatrix(const glm::mat4& projectionMatrix) const
{
	glm::mat4 projection = projectionMatrix;
	glm::mat4 model = this->GetModelMatrix();

	return projection * model;
}