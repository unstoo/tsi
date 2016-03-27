#include "__cin_buffer.h"

//prompts until proper integer followed by white space provided
//accepts only integers followed by whitespace
//refuses '1.23' or '56fvdf'
int get_integer() 
{
	for (int z;;)
	{
		__cin_buffer cinbuf;

		if (cin >> z)
		{	
			if (isspace(cin.peek()))
			{//throws away tracing any characters			
				cinbuf.flush_line(); 
				return z;
			}			
		}
		else if (!cin)
		{
			cerr << "\t not an integer... ";
			cinbuf.flush_line();
			cerr << "try again: ";
		}
	}
}

//---------------------------------------------------------------------------


//promts for an integer within given range
//throws exception if > or <
int get_integer(int min, int max) 
{	
	if (min > max)
	{
		int temp = 0;
		temp = max;
		max = min;
		min = temp;
	}

	cout << "Please enter an integer in range"
		<< " [" << min << "," << max << "]: ";

	int z = get_integer();

	//returns value only if it's within set range
	if (min <= z && z <= max)	
		return z;
	else
		throw (runtime_error
			(" get_integer(int,int): tried to return out-of-range integer value"));
}


int get_integer(int min, int max, const char* str)
{
	if (min > max)
	{
		int temp = 0;
		temp = max;
		max = min;
		min = temp;
	}

	cout << str << " [" << min << "," << max << "]: "; 

	while (true) {
		int z = get_integer();

		//returns value only if it's within set range
		if (min <= z && z <= max)
			return z;
		else
			cerr << z << " is out of range.s try again: ";
	}
		
}

//---------------------------------------------------------------------------


void keep_window_open()
{
	cin.clear();
	cout << "\nEnter a character to close the window.";
	char ch;
	cin >> ch;
}

void error(string& str) {
	throw std::runtime_error(str);
}

void error(const char* str) {
	throw std::runtime_error(str);
}