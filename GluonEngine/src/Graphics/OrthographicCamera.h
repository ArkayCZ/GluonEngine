#pragma once

#include "Camera.h"

namespace ge { namespace graphics
{
	class OrthographicCamera : public Camera
	{
		
	public:

		OrthographicCamera(glm::vec3& position, float left, float right, float bottom, float top, float near, float far) 
			: m_Position(position)
		{
			m_ProjectionMatrix = glm::ortho(left, right, bottom, top, near, far);
		}

		~OrthographicCamera()
		{
			
		}

		inline glm::mat4 GetViewProjection() const override 
		{
			return m_ProjectionMatrix * glm::translate(m_Position);
		}


		glm::vec3& GetPosition() override { return m_Position; }
		void SetPosition(glm::vec3& position) override { m_Position = position; }
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::vec3 m_Position;
	};
} }


