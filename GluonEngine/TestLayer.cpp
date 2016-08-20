#include "TestLayer.h"

ge::graphics::Mesh* mesh;
ge::graphics::Shader* shader;
ge::graphics::Transform* transform;
ge::graphics::Camera* camera;
ge::graphics::Texture* texture;

void TestLayer::OnInit(ge::InitBundle* bundle)
{
	Layer::OnInit(bundle);
	SetRenderer(new ge::graphics::BufferedRenderer(m_Game->GetWindow()->GetRenderDevice(), m_Game->GetWindow()->GetRenderTarget()));

	ge::graphics::Vertex vertices[] = {
		ge::graphics::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0, 0)),
		ge::graphics::Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1, 0)),
		ge::graphics::Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0, 1)),
		ge::graphics::Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1, 1)),
		ge::graphics::Vertex(glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 0.5f))
	};

	unsigned int indices[] = { 0,1,4,1,3,4,3,4,2,2,4,0,0,2,3,1,0,3 };
	mesh = m_Renderer->GetRenderDevice()->CreateMesh(new ge::graphics::IndexedModel(vertices, 5, indices, 18));

	ge::graphics::TextureData* data = ge::files::FileUtils::LoadTextureData("Resources/Textures/brick.jpg");
	texture = m_Renderer->GetRenderDevice()->CreateTexture(data, ge::graphics::Texture::Filtering::LINEAR);
	ge::files::FileUtils::FreeTextureData(data->_Data);

	transform = new ge::graphics::Transform(glm::vec3(0, 0, 1), glm::vec3(0), glm::vec3(1));
	ge::Entity* entity = new ge::Entity();
	entity->AddComponent(new ge::components::RenderComponent(mesh));
	entity->AddComponent(new ge::components::SpinningComponent("y"));
	entity->AddComponent(new ge::components::MaterialComponent(texture));
	entity->SetTransform(transform);

	m_Root->AddChild(entity);
}

void TestLayer::OnUpdate(ge::UpdateBundle* bundle)
{
	Layer::OnUpdate(bundle);
}

void TestLayer::OnRender()
{
	Layer::OnRender();
}

void TestLayer::OnDestroy()
{
	Layer::OnDestroy();
}
