#pragma once

#include "EntityComponent.h"

namespace ge
{
	class Entity;
}

namespace ge { namespace graphics
{
	class Mesh;
} }

namespace ge { namespace components
{
	class MeshComponent : public EntityComponent
	{
	public:
		MeshComponent(ge::Entity* entity, graphics::Mesh* mesh);
		~MeshComponent() override;
	private:
		graphics::Mesh* m_Mesh;
	};
} }

