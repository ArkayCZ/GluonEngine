#include "Game.h"

using namespace ge;

typedef unsigned long long int ulong;

Game::Game(const std::string& title, unsigned int windowWidth, unsigned int windowHeight, bool fullscreen) : m_Title(title)
{
	m_Running = false;
	m_Window = nullptr;

	this->OpenWindow(windowWidth, windowHeight, fullscreen);

	m_RenderDevice = this->GetWindow()->GetRenderDevice();

	m_UpdateBundle = new ge::UpdateBundle();
	m_InitBundle = new ge::InitBundle();

	m_InputManagers.push_back(new input::KeyboardInputManager());
}

void Game::OnUpdate()
{
	for (unsigned int i = 0; i < m_InputManagers.size(); i++)
		m_InputManagers[i]->OnUpdate();

	for (unsigned int i = 0; i < m_LayerStack.size(); i++)
		m_LayerStack[i]->OnUpdate(m_UpdateBundle);
}

void Game::OnRender()
{
	for (unsigned int i = 0; i < m_LayerStack.size(); i++)
		m_LayerStack[i]->OnRender();
}

void Game::OnDestroy()
{
	for (unsigned int i = 0; i < m_InputManagers.size(); i++)
		m_InputManagers[i]->OnDestroy();

	for (unsigned int i = 0; i < m_LayerStack.size(); i++)
		m_LayerStack[i]->OnDestroy();
}

void Game::_OnInit()
{
	OnInit();

	for (unsigned int i = 0; i < m_InputManagers.size(); i++)
		m_InputManagers[i]->OnInit(this, &m_UpdateBundle->input);

	for (unsigned int i = 0; i < m_LayerStack.size(); i++)
		m_LayerStack[i]->OnInit(m_InitBundle);
}

void Game::Start()
{
	m_Running = true;
	this->Run();
}

void Game::Stop()
{
	m_Running = false;
}

void Game::PushLayer(Layer* layer)
{
	m_LayerStack.push_back(layer);
}

void Game::PopLayer()
{
	m_LayerStack.erase(m_LayerStack.end());
}

void Game::OpenWindow(unsigned int width, unsigned int height, bool fullscreen)
{
	m_Window = new ge::graphics::Window(width, height, m_Title.c_str(), fullscreen);
	m_Window->Show();
}

void Game::Run()
{
	this->_OnInit();

	if (m_Window == nullptr)
		LOG("You did not create a Window!");

	ulong last = Timer::GetCurrentNano();
	ulong lastOut = Timer::GetCurrentMillis();
	double delta = 0;
	double nsPerTick = 1000000000 / 60.0;
	int FPS = 0;
	int TPS = 0;

	ulong now;
	while(m_Running)
	{
		m_Window->Update();
		m_Window->GetRenderDevice()->ClearScreen();
		now = Timer::GetCurrentNano();
		delta += (now - last) / nsPerTick;
		last = now;

		while(delta >= 1)
		{
			this->OnUpdate();
			delta--;
			TPS++;
		}
		
		FPS++;
		this->OnRender();
		m_Window->SwapBuffers();

		if((Timer::GetCurrentMillis() - lastOut) > 100000)
		{
			LOG("FPS: " << FPS << " TPS: " << TPS);
			FPS = 0;
			TPS = 0;
			lastOut = Timer::GetCurrentMillis();
		}

		if (m_Window->ShouldClose())
			this->Stop();
	}

	this->OnDestroy();
	m_Window->Close();
}
