#include "FileUtils.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../Lib/stb_image.h"

using namespace ge::files;

std::string FileUtils::LoadFile(const std::string& path)
{
	std::ifstream file;
	file.open((path).c_str());

	std::string output;
	std::string line;

	if(file.is_open())
	{
		while(file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << path << std::endl;
	}

	return output;
}

ge::graphics::TextureData* FileUtils::LoadTextureData(const std::string& path)
{
	ge::graphics::TextureData* data = new ge::graphics::TextureData();

	int width, height, bytesPerPixel;
	unsigned char* pixelData = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, 4);

	if (pixelData == NULL)
		LOG("Failed to load the texture '" << path << "'");

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
