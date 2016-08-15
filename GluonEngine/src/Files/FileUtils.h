#pragma once

#include <string>


namespace ge { namespace files
{
	class FileUtils
	{
	public:
		static std::string LoadFile(const std::string& path);
	};

}}
