#include "RenderComponent.h"

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
	glm::mat4 worldMatrix = GetOwner()->GetTransform()->GetWorldMatrix(bundle->_Renderer->GetCurrentCamera()->GetViewProjection());
	bundle->_Shader->SetUniform("u_WorldMatrix", worldMatrix);
	this->m_Mesh->Draw();
}

