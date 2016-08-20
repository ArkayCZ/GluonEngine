#include "Entity.h"

using namespace ge;

Entity::Entity()
{
	m_Children = std::vector<Entity*>();
	m_Components = new components::EntityComponent*[Components::COMPONENT_COUNT];
	m_Transform = new ge::graphics::Transform(glm::vec3(0), glm::vec3(0), glm::vec3(1));

	for (unsigned int i = 0; i < Components::COMPONENT_COUNT; i++) 
		m_Components[i] = nullptr;
}


Entity::~Entity()
{
	for (unsigned int i = 0; i < Components::COMPONENT_COUNT; i++)
		if (m_Components[i])
			delete m_Components[i];
	for (unsigned int i = 0; i < m_Children.size(); i++)
		if (m_Children[i])
			delete m_Children[i];
}

void Entity::AddComponent(ge::components::EntityComponent* component) const
{
	m_Components[component->GetID()] = component;
	component->SetOwner(this);
}


const components::EntityComponent* Entity::GetComponent(const int& id) const
{
	return m_Components[id];
}

bool Entity::HasComponent(const int& id) const
{
	return m_Components[id] != nullptr;
}

void Entity::RemoveComponent(const int& id) const
{
	delete m_Components[id];
}

void Entity::AddChild(Entity* other)
{
	m_Children.push_back(other);
}

void Entity::OnRender(ge::RenderBundle* bundle)
{
	for (unsigned int i = 0; i < m_Children.size(); i++)
		m_Children[i]->OnRender(bundle);
	for (unsigned int i = 0; i < Components::COMPONENT_COUNT; i++)
		if(m_Components[i] != nullptr)
			m_Components[i]->OnRender(bundle);	
}

void Entity::OnUpdate(ge::UpdateBundle* bundle)
{
	for (unsigned int i = 0; i < m_Children.size(); i++)
	{
		m_Children[i]->OnUpdate(bundle);
		if (m_Children[i]->IsRemoved())
			m_Children.erase(m_Children.begin() + i);
	}

	for (unsigned int i = 0; i < Components::COMPONENT_COUNT; i++)
	{
		if(m_Components[i] != nullptr)
		{
			m_Components[i]->OnUpdate(bundle);
			if (m_Components[i]->IsRemoved())
				delete m_Components[i];
		}
	}
}

void Entity::OnInit(ge::InitBundle* bundle)
{
	for (unsigned int i = 0; i < m_Children.size(); i++)
		m_Children[i]->OnInit(bundle);
	for (unsigned int i = 0; i < Components::COMPONENT_COUNT; i++)
		if (m_Components[i] != nullptr)
			m_Components[i]->OnInit(bundle);
}

void Entity::OnDestroy()
{
	for (unsigned int i = 0; i < m_Children.size(); i++)
		m_Children[i]->OnDestroy();
	for (unsigned int i = 0; i < Components::COMPONENT_COUNT; i++)
		if(m_Components[i] != nullptr)
			m_Components[i]->OnDestroy();
}
