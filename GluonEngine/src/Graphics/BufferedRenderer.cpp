#include "BufferedRenderer.h"

using namespace ge::graphics;

BufferedRenderer::BufferedRenderer(RenderDevice* device, RenderTarget* target)
	: Renderer(device, target)
{
	m_BasicShader = device->CompileShader(
		ge::files::FileUtils::LoadFile("Resources/Shaders/Basic/vertex.glsl"),
		ge::files::FileUtils::LoadFile("Resources/Shaders/Basic/fragment.glsl")
	);
}

BufferedRenderer::~BufferedRenderer()
{
	m_Queue.clear();
}

void BufferedRenderer::Begin(const Camera& camera)
{
	m_CurrentCamera = &camera;
	m_Queue.clear();
}

void BufferedRenderer::Render(ge::Entity* entity)
{
	m_Queue.push_back(entity);
}

void BufferedRenderer::End(bool flush)
{
	if (flush)
		this->Flush();
}

void BufferedRenderer::Flush()
{
	RenderBundle* bundle = new RenderBundle();
	bundle->_Renderer = this;
	bundle->_Shader = m_BasicShader;

	// Sets the camera matrix used for the entire scene. Each entity then uloads its transformation matrix to the GPU.
	// TODO: Verify whether this actually brings any benefits.
	bundle->_Shader->SetUniform("u_ProjectionMatrix", m_CurrentCamera->GetViewProjection());

	while(m_Queue.front() != nullptr)
	{
		Entity* entity = m_Queue.front();
		m_Queue.pop_front();

		entity->OnRender(bundle);
	}
}
