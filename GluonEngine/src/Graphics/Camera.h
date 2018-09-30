#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

namespace ge {namespace graphics
{
	class Camera
	{
	public:
		virtual ~Camera()
		{
		}

		virtual inline glm::mat4 GetViewProjection() const = 0;

		virtual glm::vec3& GetPosition() = 0;
		virtual void SetPosition(glm::vec3 position) = 0;

	};

} }

