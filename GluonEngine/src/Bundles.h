#pragma once

#include "Graphics/Renderer.h"

namespace ge { namespace graphics
{
	class Renderer;
	class Shader;
} }

namespace ge
{
	struct UpdateBundle
	{

	};

	struct RenderBundle
	{
	public:
		graphics::Renderer* _Renderer;
		graphics::Shader* _Shader;
	};

	struct InitBundle
	{

	};

}