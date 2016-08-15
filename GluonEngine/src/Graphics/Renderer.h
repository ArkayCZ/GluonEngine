#pragma once

#include "../Entity/Entity.h"
#include "RenderDevice.h"
#include "RenderTarget.h"
#include "Camera.h"


namespace ge
{
	class Entity;
}

namespace ge { namespace graphics
{
	class Renderer
	{
	public:
		virtual ~Renderer()
		{
		}

		Renderer(RenderDevice* device, RenderTarget* target)
		{
			m_RenderDevice = device;
			m_RenderTarget = target;
		}

		void SetRenderTarget(RenderTarget* target) { m_RenderTarget = target; }
		const RenderTarget& GetRenderTarget() const { return *m_RenderTarget; }

		unsigned int GetViewportWidth() { return m_RenderTarget->GetWidth(); }
		unsigned int GetViewportHeight() { return m_RenderTarget->GetHeight(); }


		virtual void Begin(const Camera& camera) = 0;
		virtual void Render(ge::Entity* entity) = 0;
		virtual void End(bool flush) = 0;
		virtual void Flush() = 0;
	protected:
		const Camera* m_CurrentCamera;
		RenderDevice* m_RenderDevice;
		RenderTarget* m_RenderTarget;
	};
} }

