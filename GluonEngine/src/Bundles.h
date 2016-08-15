#pragma once

#include "Graphics/Renderer.h"

namespace ge
{
	struct UpdateBundle
	{

	};

	struct RenderBundle
	{
		graphics::Renderer* _Renderer;
		graphics::Shader* _Shader;
	};

	struct InitBundle
	{

	};

}