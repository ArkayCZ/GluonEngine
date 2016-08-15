#pragma once

#include "RenderDevice.h"
#include "IndexedModel.h"

class OpenGLRenderDevice : public RenderDevice
{
public:
	OpenGLRenderDevice() {}

	bool Initialize() override;
	void ClearScreen() override;
	void SetClearColor(float r, float g, float b, float a) override;

	Mesh* CreateMesh(IndexedModel* model) override;
	Shader* CompileShader(const std::string& vertexShader, const std::string& fragmentShader) override;
	Texture* CreateTexture(int* pixelData, int width, int height, int filtering) override;
	RenderTarget* GenerateRenderTarget(unsigned int width, unsigned int height) override;
private:

	GLuint CreateShader(const std::string& source, GLuint type) const;

};