#pragma once
#include "Graphics/Renderer.h"

namespace ge
{
	class Layer
	{
	public:

		Layer(const glm::mat4& projectionMatrix)
		{
			m_ProjectionMatrix = projectionMatrix;
		}

		virtual void OnInit(InitBundle* bundle) = 0;
		virtual void OnUpdate(UpdateBundle* bundle) = 0;
		virtual void OnRender(RenderBundle* bundle) = 0;
		virtual void OnDestroy() = 0;

		void SetRenderer(graphics::Renderer& renderer) { m_Renderer = &renderer; }

	private:
		ge::graphics::Renderer* m_Renderer;
		glm::mat4 m_ProjectionMatrix;
	};
}
