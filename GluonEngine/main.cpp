#include <iostream>
#include <glm/gtx/transform.hpp>
#include "src/Graphics/Window.h"
#include "src/Graphics/RenderDevice.h"
#include "src/Files/FileUtils.h"
#include <ctime>
#include "src/Graphics/Camera.h"

#define WIDTH 1024
#define HEIGHT 576

int main(int argc, char** argv)
{
	srand(time(0));

	Window* window = new Window(WIDTH, HEIGHT, "Window", false);
	RenderDevice* device = window->GetRenderDevice();
	window->Show();
	device->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Vertex* vertices = new Vertex[3];
	vertices[0] = Vertex(glm::vec3(-0.5f, -0.5f, 0.0f));
	vertices[1] = Vertex(glm::vec3(0.0f, 0.5f, 0.0f));
	vertices[2] = Vertex(glm::vec3(0.5f, -0.5f, 0.0f));


	std::string vertexSource = FileUtils::LoadFile("Resources/Shaders/Basic/vertex.glsl");
	std::string fragmentSource = FileUtils::LoadFile("Resources/Shaders/Basic/fragment.glsl");

	Shader* shader = device->CompileShader(FileUtils::LoadFile("Resources/Shaders/Basic/vertex.glsl"), FileUtils::LoadFile("Resources/Shaders/Basic/fragment.glsl"));
	Transform* transform = new Transform(glm::vec3(0, 0, 3), glm::vec3(0), glm::vec3(1));

	Camera* camera = new Camera(glm::vec3(0, 0, -3), 70.0f, (float)WIDTH / (float)HEIGHT, -0.1f, 100.0f);

	while(!window->ShouldClose())
	{
		window->Update();
		device->ClearScreen();

		shader->Bind();
		shader->SetUniform("u_Color", glm::vec3((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX));
		shader->SetUniform("u_WorldMatrix", transform->GetWorldMatrix(camera->GetViewProjection()));

		transform->GetRotation().x += 0.01f;

		window->SwapBuffers();
	}

	return 0;
}