#pragma once

#include "Renderer.h"
#include <deque>

namespace ge {namespace graphics
{
	class BufferedRenderer : public Renderer
	{
	public:
		BufferedRenderer(RenderDevice* device, RenderTarget* target);
		~BufferedRenderer();

		void SubmitRenderable(ge::Entity* renderable);
		void Flush() override;

	private:
		std::deque<ge::Entity*>* m_Queue;
	};

} }