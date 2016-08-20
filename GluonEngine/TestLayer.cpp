#include "TestLayer.h"
#include "src/Graphics/Transform.h"
#include "src/Files/FileUtils.h"
#include "src/Entity/RenderComponent.h"
#include "src/Entity/SpinningComponent.h"

ge::graphics::Mesh* mesh;
ge::graphics::Shader* shader;
ge::graphics::Transform* transform;
ge::graphics::Camera* camera;

void TestLayer::OnInit(ge::InitBundle* bundle)
{
	Layer::OnInit(bundle);

	ge::graphics::Vertex vertices[] = {
		ge::graphics::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f)),
		ge::graphics::Vertex(glm::vec3(0.5f, -0.5f, -0.5f)),
		ge::graphics::Vertex(glm::vec3(-0.5f, -0.5f, 0.5f)),
		ge::graphics::Vertex(glm::vec3(0.5f, -0.5f, 0.5f)),
		ge::graphics::Vertex(glm::vec3(0.0f, 0.5f, 0.0f))
	};

	unsigned int indices[] = { 0,1,4,1,3,4,3,4,2,2,4,0,0,2,3,1,0,3 };
	mesh = m_Renderer->GetRenderDevice()->CreateMesh(new ge::graphics::IndexedModel(vertices, 5, indices, 18));
	shader = m_Renderer->GetRenderDevice()->CompileShader(
		ge::files::FileUtils::LoadFile("Resources/Shaders/Basic/vertex.glsl"),
		ge::files::FileUtils::LoadFile("Resources/Shaders/Basic/fragment.glsl")
	);

	transform = new ge::graphics::Transform(glm::vec3(0, 0, 1), glm::vec3(0), glm::vec3(1));
	camera = new ge::graphics::Camera(glm::vec3(0, 0, -1), 70.0f, 1024.0f / 576.0f, 0.1f, 1000.0f);

	ge::Entity* entity = new ge::Entity();
	entity->AddComponent(new ge::components::RenderComponent(mesh));
	entity->AddComponent(new ge::components::SpinningComponent());
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

	/*shader->Bind();
	shader->SetUniform("u_WorldMatrix", transform->GetWorldMatrix(camera->GetViewProjection()));

	mesh->Draw();

	shader->Unbind();
	transform->GetRotation().y += 1.0f;*/
}

void TestLayer::OnDestroy()
{
	Layer::OnDestroy();
}
