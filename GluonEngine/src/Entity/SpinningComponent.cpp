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
	GetOwner()->GetTransform()->GetRotation().y += 1.0f;
}

void SpinningComponent::OnRender(ge::RenderBundle* bundle)
{
}

void SpinningComponent::OnDestroy()
{
}
