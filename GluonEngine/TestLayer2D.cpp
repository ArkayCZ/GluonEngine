#include "TestLayer2D.h"

#include "src/Entity/SpinningComponent.h"
#include "src/Entity/RenderComponent.h"
#include "src/Entity/MaterialComponent.h"
#include "src/Graphics/Texture.h"
#include "src/Graphics/BufferedRenderer.h"

ge::graphics::Mesh* _mesh;
ge::Entity* _entity;
ge::graphics::Texture* _texture;

TestLayer2D::~TestLayer2D()
{

}

void TestLayer2D::OnInit(ge::InitBundle* bundle)
{
	Layer::OnInit(bundle);
	SetRenderer(new ge::graphics::BufferedRenderer(m_Game->GetWindow()->GetRenderDevice(), m_Game->GetWindow()->GetRenderTarget()));

	ge::graphics::Vertex vertices[] = {
		ge::graphics::Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0, 0)),
		ge::graphics::Vertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec2(0, 1)),
		ge::graphics::Vertex(glm::vec3(0.5f,  0.5f, 0.0f), glm::vec2(1, 1))
	};

	unsigned int indices[] = { 0, 1, 2 };

	ge::graphics::TextureData* data = ge::files::FileUtils::LoadTextureData("Resources/Textures/brick.jpg");
	_texture = m_Renderer->GetRenderDevice()->CreateTexture(data, ge::graphics::Texture::Filtering::LINEAR);
	ge::files::FileUtils::FreeTextureData(data->_Data);

	_mesh = m_Renderer->GetRenderDevice()->CreateMesh(new ge::graphics::IndexedModel(vertices, 3, indices, 3));
	_entity = new ge::Entity();
	ge::graphics::Transform* _transform = new ge::graphics::Transform(glm::vec3(0, 0, 1), glm::vec3(0), glm::vec3(5));


	_entity->AddComponent(new ge::components::RenderComponent(_mesh));
	_entity->AddComponent(new ge::components::SpinningComponent("z"));
	_entity->AddComponent(new ge::components::MaterialComponent(_texture));
	_entity->SetTransform(_transform);

	m_Root->AddChild(_entity);
}

void TestLayer2D::OnUpdate(ge::UpdateBundle* bundle)
{
	Layer::OnUpdate(bundle);
}

void TestLayer2D::OnDestroy()
{
	Layer::OnDestroy();
}

void TestLayer2D::OnRender()
{
	Layer::OnRender();
}
