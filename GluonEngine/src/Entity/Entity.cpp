#include "Entity.h"

using namespace ge;

Entity::Entity()
{
}


Entity::~Entity()
{
	for (unsigned int i = 0; i < m_Components.size(); i++)
		if (m_Components[i])
			delete m_Components[i];
	for (unsigned int i = 0; i < m_Children.size(); i++)
		if (m_Children[i])
			delete m_Children[i];
}

void Entity::AddComponent(ge::components::EntityComponent* component)
{
	m_Components.push_back(component);
}


const components::EntityComponent* Entity::GetComponent(const int& id)
{
	return nullptr;
}

template <typename T>
T* Entity::GetComponent()
{
	return nullptr;
}

void Entity::OnRender(ge::RenderBundle* bundle)
{
	for (unsigned int i = 0; i < m_Children.size(); i++)
		m_Children[i]->OnRender(bundle);
	for (unsigned int i = 0; i < m_Components.size(); i++)
		m_Components[i]->OnRender(bundle);
}

void Entity::OnUpdate(ge::UpdateBundle* bundle)
{
	for(unsigned int i = 0; i < m_Children.size(); i++)
	{
		m_Children[i]->OnUpdate(bundle);
		if (m_Children[i]->IsRemoved())
			m_Children.erase(m_Children.begin() + i);
	}

	for (unsigned int i = 0; i < m_Components.size(); i++)
	{
		m_Components[i]->OnUpdate(bundle);
		if (m_Components[i]->IsRemoved())
			m_Components.erase(m_Components.begin() + i);
	}
}

void Entity::OnInit(ge::InitBundle* bundle)
{
	for (unsigned int i = 0; i < m_Children.size(); i++)
		m_Children[i]->OnInit(bundle);
	for (unsigned int i = 0; i < m_Components.size(); i++)
		m_Components[i]->OnInit(bundle);
}

void Entity::OnDestroy()
{
	for (unsigned int i = 0; i < m_Children.size(); i++)
		m_Children[i]->OnDestroy();
	for (unsigned int i = 0; i < m_Components.size(); i++)
		m_Components[i]->OnDestroy();
}
