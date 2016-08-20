#include "SpinningComponent.h"

using namespace ge::components;

SpinningComponent::~SpinningComponent()
{

}

void SpinningComponent::OnInit(ge::InitBundle* bundle)
{
}

void SpinningComponent::OnUpdate(ge::UpdateBundle* bundle)
{ 
	if (m_Axes.find("z") != std::string::npos)
		GetOwner()->GetTransform()->GetRotation().z += 1.0f;
	if (m_Axes.find("x") != std::string::npos)
		GetOwner()->GetTransform()->GetRotation().x += 1.0f;
	if (m_Axes.find("y") != std::string::npos)
		GetOwner()->GetTransform()->GetRotation().y += 1.0f;
}

void SpinningComponent::OnRender(ge::RenderBundle* bundle)
{
}

void SpinningComponent::OnDestroy()
{
}
