#pragma once
#include "src/Layer.h"
#include "src/Graphics/Camera.h"

class TestLayer : public ge::Layer
{
public:

	explicit TestLayer(ge::Game* game)
		: Layer(game, new ge::graphics::Camera())
	{
	}

	void OnInit(ge::InitBundle* bundle) override;
	void OnUpdate(ge::UpdateBundle* bundle) override;
	void OnRender(ge::RenderBundle* bundle) override;
	void OnDestroy() override;
};
