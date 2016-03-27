#pragma once
#include "precompiled.h"

//seekg - move to a specific position in file
//pos=in.tellg() pos is the position of in’s get pointer

//ios_base::app Append(i.e., add to the end of the file)
//ios_base::ate ‘‘At end’’(open and seek to the end)
//ios_base::binary Binary mode; beware of system - specific behavior
//ios_base::in For reading
//ios_base::out For writing
//ios_base::trunc Truncate the file to 0 length

size_t binfile_size(char* file_name) 
{
	std::fstream file
		(file_name, std::ios::in | std::ios::app | std::ios::binary );
	if (file.is_open()) 
	{
		std::streampos fsize = file.tellg();
		file.seekg(0, std::ios::end);
		return size_t(file.tellg() - fsize);
	}

}

template<typename T>
size_t elems_in_binfile(char* file_name, T elem)
{
	size_t fsize = binfile_size(file_name);
	if (fsize % sizeof(T) == 0)
		return (fsize / sizeof(T));
	else
		throw runtime_error("elemens_in_binflie(): invalid type");
}