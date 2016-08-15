#include "BufferedRenderer.h"

using namespace ge::graphics;

BufferedRenderer::BufferedRenderer(RenderDevice* device, RenderTarget* target)
	: Renderer(device, target)
{
	m_Queue = new std::deque<ge::Entity*>();
}

BufferedRenderer::~BufferedRenderer()
{
	delete m_Queue;
}

void BufferedRenderer::SubmitRenderable(ge::Entity* renderable)
{
	m_Queue->push_back(renderable);
}

void BufferedRenderer::Flush()
{
	while(m_Queue->front() != nullptr)
	{
		Entity* entity = m_Queue->front();
		m_Queue->pop_front();

		entity->OnRender(nullptr);
	}
}
