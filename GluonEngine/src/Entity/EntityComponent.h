#pragma once

namespace ge { class Entity; }

namespace ge { namespace components
{

	class EntityComponent
	{
	public:
		virtual ~EntityComponent()
		{
		}

		EntityComponent(ge::Entity* entity)
		{
			m_Parent = entity;
		}

		virtual void OnInit(ge::InitBundle* bundle) {}
		virtual void OnUpdate(ge::UpdateBundle* bundle) {}
		virtual void OnRender(ge::RenderBundle* bundle) {}
		virtual void OnDestroy() {}

		bool IsRemoved() { return m_Removed; }
		void Remove() { m_Removed = true; }

		Entity* GetOwner() { return m_Parent; }

	private:
		Entity* m_Parent;
		bool m_Removed;
	};
}}

