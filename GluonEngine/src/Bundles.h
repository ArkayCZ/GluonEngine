#pragma once

#include "src/Input/InputStatus.h"
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
		input::InputStatus input;
	};

	struct RenderBundle
	{
	public:
		graphics::Renderer* renderer;
		graphics::Shader* shader;
	};

	struct InitBundle
	{

	};

}