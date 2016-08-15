#pragma once
#include "RenderTarget.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Shader.h"
#include "Transform.h"
#include "IndexedModel.h"
#include "Texture.h"

#include <vector>

class RenderDevice
{
public:
	RenderDevice() {}

	virtual bool Initialize() = 0;
	virtual void ClearScreen() = 0;
	virtual void SetClearColor(float r, float g, float b, float a) = 0;

	virtual Mesh* CreateMesh(IndexedModel* model) = 0;
	virtual Shader* CompileShader(const std::string& vertexShader, const std::string& fragmentShader) = 0;
	virtual Texture* CreateTexture(int* pixelData, int width, int height, int filtering) = 0;
	virtual RenderTarget* GenerateRenderTarget(unsigned int width, unsigned int height) = 0;

	enum
	{
		FILTERING_LINEAR,
		FILTERING_NEAREST
	};

private:

};
