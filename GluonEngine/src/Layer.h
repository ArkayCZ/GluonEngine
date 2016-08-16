#pragma once
#include "Graphics/Renderer.h"
#include "Game.h"
#include "Graphics/Camera.h"

namespace ge
{

	class Game;

	class Layer
	{
	public:

		Layer(ge::Game* game, ge::graphics::Camera* camera)
		{
			m_Game = game;
			m_Camera = camera;
		}

		virtual void OnInit(InitBundle* bundle) = 0;
		virtual void OnUpdate(UpdateBundle* bundle) = 0;
		virtual void OnRender(RenderBundle* bundle) = 0;
		virtual void OnDestroy() = 0;

		void SetRenderer(graphics::Renderer& renderer) { m_Renderer = &renderer; }

	protected:
		ge::Game* m_Game;
		ge::graphics::Renderer* m_Renderer;
		ge::graphics::Camera* m_Camera;
	};
}
