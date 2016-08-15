#include "MeshComponent.h"

using namespace ge::components;
using namespace ge;

MeshComponent::MeshComponent(Entity* entity, graphics::Mesh* mesh): 
	EntityComponent(entity) 

{
	m_Mesh = mesh;
}

MeshComponent::~MeshComponent()
{
}
