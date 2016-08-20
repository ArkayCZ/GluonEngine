#pragma once
#include "EntityComponent.h"
#include "ComponentIds.h"
#include "../Graphics/Texture.h"

//namespace ge { namespace graphics { class Texture; } }

namespace ge { namespace components
{
	class MaterialComponent : public ge::components::EntityComponent
	{
	public:

		MaterialComponent(graphics::Texture* texture) : EntityComponent(Components::MATERIAL) { m_Texture = texture; }

		graphics::Texture* GetTexture() { return m_Texture; }
		void SetTexture(graphics::Texture* texture) { m_Texture = texture; }
	private:
		graphics::Texture* m_Texture;
	};
} }

