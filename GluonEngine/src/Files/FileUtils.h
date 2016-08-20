#pragma once


#include <string>
#include "../Graphics/Texture.h"
#include <fstream>
#include "../Common.h"


namespace ge { namespace files
{
	class FileUtils
	{
	public:
		static std::string LoadFile(const std::string& path);
		static ge::graphics::TextureData* LoadTextureData(const std::string& path);
		static void FreeTextureData(unsigned char* data);
	};

}}
