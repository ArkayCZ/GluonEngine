#pragma once

#include "Renderer.h"

class Renderable
{
public:
	virtual ~Renderable()
	{
	}

	virtual void Render(Renderer& renderer) = 0;
};
