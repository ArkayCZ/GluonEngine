#pragma once

#include "EntityComponent.h"
#include "../Graphics/Mesh.h"
#include "../Bundles.h"
#include "ComponentIds.h"

namespace ge
{
	class Entity;
}

namespace ge { namespace components
{
	class RenderComponent : public EntityComponent
	{
	public:
		RenderComponent(graphics::Mesh* mesh);
		~RenderComponent() override;

		void OnInit(ge::InitBundle* bundle) override;
		void OnRender(ge::RenderBundle* bundle) override;

	private:
		graphics::Mesh* m_Mesh;
	};
} }

