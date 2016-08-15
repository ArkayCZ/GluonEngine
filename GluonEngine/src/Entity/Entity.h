#pragma once

#include "../Bundles.h"
#include "EntityComponent.h"
#include <vector>

namespace ge
{
	class Entity
	{
	public:
		Entity();
		~Entity();
		void AddComponent(components::EntityComponent* comp);
		const components::EntityComponent* GetComponent(const int& id);

		template <typename T>
		T* GetComponent();

		void OnRender(RenderBundle* bundle);
		void OnUpdate(UpdateBundle* bundle);
		void OnInit(InitBundle* bundle);
		void OnDestroy();

		bool IsRemoved() const { return m_Removed; }
		void Remove() { m_Removed = true; }

	private:
		std::vector<Entity*> m_Children;
		std::vector<components::EntityComponent*> m_Components;

		bool m_Removed = false;
	};
}
