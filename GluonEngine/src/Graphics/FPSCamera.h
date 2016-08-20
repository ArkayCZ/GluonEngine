#pragma once

#include "Camera.h"

namespace ge { namespace graphics
{
	class FPSCamera : public Camera
	{
	public:

		~FPSCamera() override {}

		FPSCamera(const glm::vec3& position, float fov, float aspectRatio, float near, float far)
		{
			m_ProjectionMatrix = glm::perspective(fov, aspectRatio, near, far);
			m_Position = position;
			m_Forward = glm::vec3(0, 0, 1);
			m_Up = glm::vec3(0, 1, 0);
		}


		inline glm::mat4 GetViewProjection() const override 
		{
			return m_ProjectionMatrix * glm::lookAt(m_Position, m_Position + m_Forward, m_Up);
		}


		glm::vec3& GetPosition() override { return m_Position; }
		void SetPosition(glm::vec3& position) override { m_Position = position; }
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::vec3 m_Position;
		glm::vec3 m_Forward;
		glm::vec3 m_Up;
	};
} }


