#pragma once

#include "Renderer.h"
#include <queue>

class BufferedRenderer : public Renderer
{
public:
	BufferedRenderer(RenderDevice* device, RenderTarget* target);
	void SubmitRenderable(Renderable& renderable) override;
	void Flush() override;

private:
	std::queue<Renderable> m_Queue;
};
