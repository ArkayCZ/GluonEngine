#include "FileUtils.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../Lib/stb_image.h"

using namespace ge::files;

std::string FileUtils::LoadFile(const std::string& path)
{
	std::ifstream inputStream;
	inputStream.open(path.c_str());

	std::string content;
	std::string line;

	if(inputStream.is_open())
	{
		while(inputStream.good())
		{
			std::getline(inputStream, line);
			content.append(line).append("\n");
		}
	} else
	{
		ERROR("Could not open file " << path << "!");
	}

	return content;
}

ge::graphics::TextureData* FileUtils::LoadTextureData(const std::string& path)
{
	ge::graphics::TextureData* data = new ge::graphics::TextureData();

	int width, height, bytesPerPixel;
	unsigned char* pixelData = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 4);

	if (pixelData == NULL)
		ERROR("Failed to load the texture '" << path << "'");

	data->_Width = width;
	data->_Height = height;
	data->_Data = pixelData;
	data->_BytesPerPixel = bytesPerPixel;

	return data;
}


void FileUtils::FreeTextureData(unsigned char* data)
{
	stbi_image_free(data);
}
