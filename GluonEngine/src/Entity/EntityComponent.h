#pragma once

namespace ge
{
	class Entity;
	struct InitBundle;
	struct UpdateBundle;
	struct RenderBundle;
}

namespace ge { namespace components
{

	class EntityComponent
	{
	public:
		virtual ~EntityComponent()
		{
		}

		EntityComponent(const unsigned int& id) : m_ID(id)
		{
			m_Removed = false;
		}

		EntityComponent() : m_ID(0xFFFFFFFF) {}

		virtual void OnInit(ge::InitBundle* bundle) {}
		virtual void OnUpdate(ge::UpdateBundle* bundle) {}
		virtual void OnRender(ge::RenderBundle* bundle) {}
		virtual void OnDestroy() {}

		bool IsRemoved() { return m_Removed; }
		void Remove() { m_Removed = true; }

		const Entity* GetOwner() const { return m_Owner; }
		void SetOwner(const ge::Entity* owner) { m_Owner = owner; }

		const unsigned int& GetID() { return m_ID; }

	private:
		const Entity* m_Owner;
		bool m_Removed;

		const unsigned int m_ID;
	};
}}

