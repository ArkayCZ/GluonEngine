#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "IndexedModel.h"
#include "Texture.h"
#include "RenderTarget.h"
#include <vector>

namespace ge { namespace graphics
{
	class RenderTarget;

	class RenderDevice
	{
	public:
		virtual ~RenderDevice()
		{
		}

		RenderDevice() {}

		virtual bool Initialize() = 0;

		virtual void ClearScreen() = 0;

		virtual void SetClearColor(float r, float g, float b, float a) = 0;

		virtual ge::graphics::Mesh* CreateMesh(IndexedModel* model) = 0;

		virtual ge::graphics::Shader* CompileShader(const std::string& vertexShader, const std::string& fragmentShader) = 0;

		virtual ge::graphics::Texture* CreateTexture(int* pixelData, int width, int height, int filtering) = 0;

		virtual ge::graphics::RenderTarget* GenerateRenderTarget(unsigned int width, unsigned int height) = 0;

		enum
		{
			FILTERING_LINEAR,
			FILTERING_NEAREST
		};

	};

} }

