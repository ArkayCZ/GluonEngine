#pragma once

// ReSharper disable once CppUnusedIncludeDirective
#include "Timer.h"
#include "Layer.h"
#include "Bundles.h"
#include "Graphics/Window.h"

namespace ge
{
	class Layer;
}

namespace ge
{
	class Game
	{
	public:
		virtual ~Game()
		{
		}

		Game(const std::string& title, unsigned int windowWidth, unsigned int windowHeight, bool fullscreen);

		virtual void OnInit() = 0;

		virtual void OnUpdate();
		virtual void OnRender();
		virtual void OnDestroy();
		void _OnInit();

		void Start();
		void Stop();

		void PushLayer(ge::Layer* layer);
		void PopLayer();

		void CreateWindow(unsigned int width, unsigned int height, bool fullscreen);
		
		ge::graphics::Window* GetWindow() const { return m_Window; }
		ge::graphics::RenderDevice* GetRenderDevice() const { return m_RenderDevice; }

	protected:

		ge::InitBundle* m_InitBundle;
		ge::UpdateBundle* m_UpdateBundle;

		ge::graphics::Window* m_Window;
		ge::graphics::RenderDevice* m_RenderDevice;

	private:

		const std::string& m_Title;
		std::vector<Layer*> m_LayerStack;
		bool m_Running;
		
		void Run();

	};
};
