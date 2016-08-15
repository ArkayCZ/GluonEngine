#pragma once

#include "RenderDevice.h"
#include "OpenGLRenderDevice.h"
#include <GLFW/glfw3.h>

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
	OpenGLRenderDevice* GetRenderDevice() const;
	RenderTarget* GetRenderTarget() const;

private:
	GLFWwindow* m_Window;
	OpenGLRenderDevice* m_RenderDevice;
	RenderTarget* m_RenderTarget;

	int m_Width, m_Height;
	bool m_Fullscreen;
	const char* m_Title;

	bool InitGLFW();
};

