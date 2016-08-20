#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

namespace ge {namespace graphics
{
	class Camera
	{
	public:
		Camera(const glm::vec3& position, float fov, float aspect, float near, float far)
		{
			m_Perspective = glm::perspective(fov, aspect, near, far);
			m_Position = position;
			m_Up = glm::vec3(0, 1, 0);
			m_Forward = glm::vec3(0, 0, 1);
		}

		// Generates a common perspective camera.
		Camera() : Camera(glm::vec3(0, 0, -1), 70.0f, 16.0f / 9.0f, 0.001f, 1000.0f) {}

		inline glm::mat4 GetViewProjection() const
		{
			return m_Perspective * glm::lookAt(m_Position, m_Position + m_Forward, m_Up);
		}


	private:

		glm::mat4 m_Perspective;
		glm::vec3 m_Forward;
		glm::vec3 m_Up;
		glm::vec3 m_Position;
	};

} }

