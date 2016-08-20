#pragma once

#include "ComponentIds.h"
#include "../Bundles.h"
#include "../Graphics/Transform.h"
#include "EntityComponent.h"
#include <vector>

namespace ge
{
	class Entity
	{
	public:

		Entity();
		~Entity();
		void AddComponent(components::EntityComponent* comp) const;
		const components::EntityComponent* GetComponent(const int& id);

		template <typename T>
		T* GetComponent();

		void RemoveComponent(const int& id);

		void AddChild(Entity* other);
		const std::vector<Entity*> GetChildren();

		void OnRender(RenderBundle* bundle);
		void OnUpdate(UpdateBundle* bundle);
		void OnInit(InitBundle* bundle);
		void OnDestroy();

		bool IsRemoved() const { return m_Removed; }
		void Remove() { m_Removed = true; }

		ge::graphics::Transform* GetTransform() const { return m_Transform; }
		void SetTransform(ge::graphics::Transform* transform) { m_Transform = transform; }

	private:

		std::vector<Entity*> m_Children;
		components::EntityComponent** m_Components;

		bool m_Removed = false;

		ge::graphics::Transform* m_Transform;

	};
}
