#pragma once

#include "RenderDevice.h"
#include "OpenGLRenderDevice.h"
#include <GLFW/glfw3.h>

namespace ge { namespace graphics
{
	class Window
	{
	public:
		Window(int width, int height, const char* title, bool fullscreen);

		bool ShouldClose() const;
		void Show() const;
		void Close() const;
		void Update() const;
		void SwapBuffers() const;
		void Center() const;
		void EnableVSync(bool value);
		OpenGLRenderDevice* GetRenderDevice() const;
		RenderTarget* GetRenderTarget() const;

		int GetWidth() const { return m_Width; }
		int GetHeight() const { return m_Height; }

	private:
		GLFWwindow* m_Window;
		OpenGLRenderDevice* m_RenderDevice;
		RenderTarget* m_RenderTarget;

		int m_Width, m_Height;
		bool m_Fullscreen;
		const char* m_Title;

		bool InitGLFW();
	};
}}

