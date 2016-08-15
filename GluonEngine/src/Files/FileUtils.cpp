#include "FileUtils.h"
#include <fstream>
#include "../Common.h"

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
