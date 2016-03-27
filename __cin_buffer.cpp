#include "__cin_buffer.h"

void __cin_buffer::flush_line()
{
	cin.clear();
	std::getline(cin, _buffer);
}
