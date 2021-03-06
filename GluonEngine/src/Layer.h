﻿#pragma once
#include "Graphics/Renderer.h"
#include "Game.h"
#include "Graphics/Camera.h"

namespace ge
{

	class Game;

	class Layer
	{
	public:
		virtual ~Layer()
		{
		}

		Layer(ge::Game* game, const ge::graphics::Camera* camera)
		{
			m_Game = game;
			m_Root = new ge::Entity();
			m_Camera = camera;
		}

		virtual void OnInit(InitBundle* bundle) { m_Root->OnInit(bundle); };
		virtual void OnUpdate(UpdateBundle* bundle) { m_Root->OnUpdate(bundle); }
		virtual void OnDestroy() { m_Root->OnDestroy(); }

		virtual void OnRender()
		{
			m_Renderer->Render(m_Root);
			m_Renderer->Flush();
		}

		void SetRenderer(graphics::Renderer* renderer)
		{
			m_Renderer = renderer;
			m_Renderer->SetCamera(m_Camera);
		}

	protected:
		ge::Entity* m_Root;
		ge::Game* m_Game;
		ge::graphics::Renderer* m_Renderer;
		const ge::graphics::Camera* m_Camera;
	};
}
