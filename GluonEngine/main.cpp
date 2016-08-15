#include <iostream>
#define GLM_LEFT_HANDED

#include <glm/gtx/transform.hpp>
#include "src/Graphics/Window.h"
#include "src/Graphics/RenderDevice.h"
#include "src/Files/FileUtils.h"
#include <ctime>
#include "src/Graphics/Camera.h"
#include "src/Graphics/Transform.h"

#define WIDTH 1024
#define HEIGHT 576

void DumpMatrix(const glm::mat4& matrix);

int main(int argc, char** argv)
{
	srand(time(0));

	using namespace ge::graphics;

	Window* window = new Window(WIDTH, HEIGHT, "Window", false);
	RenderDevice* device = window->GetRenderDevice();
	window->Show();
	device->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	/*Vertex* vertices = new Vertex[3];
	vertices[0] = Vertex(glm::vec3(-0.5f, -0.5f, 0.0f));
	vertices[1] = Vertex(glm::vec3(0.0f, 0.5f, 0.0f));
	vertices[2] = Vertex(glm::vec3(0.5f, -0.5f, 0.0f));*/

	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5f, 0.0f, -0.5f)),
		Vertex(glm::vec3(0.5f, 0.0f, -0.5f)),
		Vertex(glm::vec3(-0.5f, 0.0f, 0.5f)),
		Vertex(glm::vec3(0.5f, 0.0f, 0.5f)),
		Vertex(glm::vec3(0.0f, 1.0f, 0.0f))
	};

	unsigned int indices[] = { 0,1,4,1,3,4,3,4,2,2,4,0,0,2,3,1,0,3 };

	Shader* shader = device->CompileShader(ge::files::FileUtils::LoadFile("Resources/Shaders/Basic/vertex.glsl"), ge::files::FileUtils::LoadFile("Resources/Shaders/Basic/fragment.glsl"));
	Transform* transform = new Transform(glm::vec3(0, 0, 1), glm::vec3(0), glm::vec3(1));
	IndexedModel* model = new IndexedModel(vertices, 5, indices, 18);
	Mesh* mesh = device->CreateMesh(model);
	Camera* camera = new Camera(glm::vec3(0, 0, -1), 70.0f, (float)WIDTH / (float)HEIGHT, 0.1f, 1000.0f);

	while (!window->ShouldClose())
	{
		window->Update();
		device->ClearScreen();

		shader->Bind();
		shader->SetUniform("u_WorldMatrix", transform->GetWorldMatrix(camera->GetViewProjection()));
		mesh->Draw();

		transform->GetRotation().z += 1.2f;
		transform->GetRotation().x += 0.9f;
		transform->GetRotation().y += 0.6f;
//		transform->GetTranslation().z += 0.01f;

		window->SwapBuffers();
	}

	window->Close();

	return 0;
}

void DumpMatrix(const glm::mat4& matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%4.2f \t", matrix[i][j]);
		}

		std::cout << std::endl;
	}
}