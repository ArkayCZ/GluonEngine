#pragma once

#include "Renderer.h"
#include "../Files/FileUtils.h"
#include <deque>

namespace ge {namespace graphics
{
	class BufferedRenderer : public Renderer
	{
	public:
		BufferedRenderer(RenderDevice* device, RenderTarget* target);
		~BufferedRenderer();

		void Render(ge::Entity* renderable) override;
		void Begin(const Camera& camera) override;
		void End(bool flush) override;
		void Flush() override;
	private:
		ge::graphics::Shader* m_BasicShader;
		std::deque<ge::Entity*> m_Queue;
	};

} }