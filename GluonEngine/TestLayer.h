#pragma once
#include "src/Layer.h"
#include "src/Graphics/FPSCamera.h"
#include "src/Graphics/Transform.h"
#include "src/Files/FileUtils.h"
#include "src/Entity/RenderComponent.h"
#include "src/Entity/SpinningComponent.h"
#include "src/Graphics/BufferedRenderer.h"
#include "src/Entity/MaterialComponent.h"

class TestLayer : public ge::Layer
{
public:

	explicit TestLayer(ge::Game* game)
		: Layer(game, new ge::graphics::FPSCamera(glm::vec3(0, 0, -1), 70.0f, 16.0f/ 9.0f, 0.001f, 1000.0f))
	{
	}

	void OnInit(ge::InitBundle* bundle) override;
	void OnUpdate(ge::UpdateBundle* bundle) override;
	void OnRender() override;
	void OnDestroy() override;
	
};
