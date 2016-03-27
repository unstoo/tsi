#pragma once
#include "precompiled.h"

//------------------------------------------------------------------------
class __cin_buffer {
private:
	string _buffer;
public:
	__cin_buffer() : _buffer("_blank_string") {}

	void flush_line(); //clears cin fail state, 
					   //eats the line untill '\n'
};

//------------------------------------------------------------------------



