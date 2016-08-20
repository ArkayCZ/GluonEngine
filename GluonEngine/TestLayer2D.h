#pragma once
#include "src/Layer.h"
#include "src/Graphics/OrthographicCamera.h"


class TestLayer2D : public ge::Layer {
	
public:
	TestLayer2D(ge::Game* game)
		: Layer(game, new ge::graphics::OrthographicCamera(glm::vec3(0, 0, 0), -8.0f, 8.0f, -4.5f, 4.5f, -1.0f, 1.0f))
	{
	}

	~TestLayer2D() override;
	void OnInit(ge::InitBundle* bundle) override;
	void OnUpdate(ge::UpdateBundle* bundle) override;
	void OnDestroy() override;
	void OnRender() override;
};
