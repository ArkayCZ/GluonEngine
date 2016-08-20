#include "RenderComponent.h"
#include "MaterialComponent.h"

using namespace ge::components;
using namespace ge;

RenderComponent::RenderComponent(graphics::Mesh* mesh) : EntityComponent(Components::RENDER) 
{
	m_Mesh = mesh;
}

RenderComponent::~RenderComponent()
{
}


void RenderComponent::OnInit(ge::InitBundle* bundle)
{

}

void RenderComponent::OnRender(ge::RenderBundle* bundle)
{
	bundle->_Shader->Bind();
	if (GetOwner()->HasComponent(Components::MATERIAL))
	{
		((MaterialComponent*)GetOwner()->GetComponent(Components::MATERIAL))->GetTexture()->Bind();
	}

	glm::mat4 worldMatrix = GetOwner()->GetTransform()->GetWorldMatrix(bundle->_Renderer->GetCurrentCamera()->GetViewProjection());
	bundle->_Shader->SetUniform("u_WorldMatrix", worldMatrix);
	bundle->_Shader->SetUniform("u_Texture", 0);
	this->m_Mesh->Draw();
}

