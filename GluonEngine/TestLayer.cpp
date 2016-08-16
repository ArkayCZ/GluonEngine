#include "TestLayer.h"
#include "src/Graphics/Transform.h"
#include "src/Files/FileUtils.h"

ge::graphics::Mesh* mesh;
ge::graphics::Shader* shader;
ge::graphics::Transform* transform;
ge::graphics::Camera* camera;

void TestLayer::OnInit(ge::InitBundle* bundle)
{
	ge::graphics::Vertex vertices[] = {
		ge::graphics::Vertex(glm::vec3(-0.5f, 0.0f, -0.5f)),
		ge::graphics::Vertex(glm::vec3(0.5f, 0.0f, -0.5f)),
		ge::graphics::Vertex(glm::vec3(-0.5f, 0.0f, 0.5f)),
		ge::graphics::Vertex(glm::vec3(0.5f, 0.0f, 0.5f)),
		ge::graphics::Vertex(glm::vec3(0.0f, 1.0f, 0.0f))
	};

	unsigned int indices[] = { 0,1,4,1,3,4,3,4,2,2,4,0,0,2,3,1,0,3 };

	mesh = m_Renderer->GetRenderDevice()->CreateMesh(new ge::graphics::IndexedModel(vertices, 5, indices, 18));
	shader = m_Renderer->GetRenderDevice()->CompileShader(
		ge::files::FileUtils::LoadFile("Resources/Shaders/Basic/vertex.glsl"),
		ge::files::FileUtils::LoadFile("Resources/Shaders/Basic/fragment.glsl")
	);

	transform = new ge::graphics::Transform(glm::vec3(0), glm::vec3(0), glm::vec3(1));
	camera = new ge::graphics::Camera();
}

void TestLayer::OnUpdate(ge::UpdateBundle* bundle)
{

}

void TestLayer::OnRender(ge::RenderBundle* bundle)
{

}

void TestLayer::OnDestroy()
{

}
