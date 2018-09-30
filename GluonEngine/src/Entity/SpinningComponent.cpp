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
		GetOwner()->GetTransform()->GetRotation().z += 0.01f;
	if (m_Axes.find("x") != std::string::npos)
		GetOwner()->GetTransform()->GetRotation().x += 0.01f;
	if (m_Axes.find("y") != std::string::npos)
		GetOwner()->GetTransform()->GetRotation().y += 0.01f;

	if (bundle->input.IsPressed(input::Key::LEFT))
		GetOwner()->GetTransform()->GetRotation().x += 0.01f;
}

void SpinningComponent::OnRender(ge::RenderBundle* bundle)
{
}

void SpinningComponent::OnDestroy()
{
}
