#pragma once

#include "../Entity/Entity.h"
#include "RenderDevice.h"
#include "RenderTarget.h"


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

		virtual void Render(ge::Entity* entity) = 0;
		virtual void Flush() = 0;
	private:
		RenderDevice* m_RenderDevice;
		RenderTarget* m_RenderTarget;
	};
} }

