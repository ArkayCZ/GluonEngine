#include "Window.h"

using namespace ge::graphics;

Window::Window(int width, int height, const char* title, bool fullscreen)
{
	if (!this->InitGLFW())
		ERROR("Failed to init GLFW!");

	m_Width = width;
	m_Height = height;
	m_Title = title;
	m_Fullscreen = fullscreen;

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, m_Fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
	glfwMakeContextCurrent(m_Window);

	this->Center();

	m_RenderDevice = new OpenGLRenderDevice();
	m_RenderDevice->Initialize();

	m_RenderTarget = new RenderTarget(0, m_Width, m_Height);
}

void Window::Show() const
{
	glfwShowWindow(m_Window);
}

void Window::Close() const
{
	glfwDestroyWindow(m_Window);
}

bool Window::ShouldClose() const
{
	return glfwWindowShouldClose(m_Window);
}

void Window::SwapBuffers() const
{
	glfwSwapBuffers(m_Window);
}

void Window::Center() const
{
	const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (vidmode->width - m_Width) / 2;
	int yPos = (vidmode->height - m_Height) / 2;

	glfwSetWindowPos(m_Window, xPos, yPos);
}

void Window::Update() const
{
	glfwPollEvents();
}

OpenGLRenderDevice* Window::GetRenderDevice() const
{
	return m_RenderDevice;
}

bool Window::InitGLFW()
{
	int initCode = glfwInit();
	return initCode == GLFW_TRUE;
}

RenderTarget* Window::GetRenderTarget() const
{
	return m_RenderTarget;
}