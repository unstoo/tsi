#pragma once

template <typename T>
class Array
{
	size_t _sz; //number of cells
	size_t _elems_stored;
	T * _array; //ptr to an array		

public:
		
	size_t size() const { return _sz; }
	size_t elements() const { return _elems_stored; }
	size_t byte_size() const { return sizeof(T) * _sz; }
	bool isfull() const { return _elems_stored == _sz; }

	//----------------------------------------------------------//

	explicit Array() : _sz(0), _elems_stored(0), _array(nullptr) {}
	explicit Array(size_t n) : _sz(n), _elems_stored(0), _array(new T[n]) {}
	~Array() { _sz = 0; _elems_stored = 0;  delete[] _array; }

	//-----------------------------------------------------------------//
	
	Array(const Array& arr) =delete;
	Array& operator=(const Array& arr) =delete;
	Array(Array&& arr) =delete;
	Array& operator=(Array&& arr) =delete;

	//-----------------------------------------------------------------//

	/* T& operator[](size_t i); */ //write-in [] notation disabled
	const T& operator[](size_t i) const; //read-only [] notation

	//-----------------------------------------------------------------//

	bool insert(T& instance); //main function to add new elements Array
	
	//-----------------------------------------------------------------//

	const T* begin() const;
	const T* end() const;

	//-----------------------------------------------------------------//

	void sort_ascending(); //not implemented yet
	void sort_descending(); //not implemented yet

	//-----------------------------------------------------------------//	
	// only for built-in types elements
	// and for objects with non-virtual methods

	bool array_to_binaryfile(std::string& file_name) const;
	bool binaryfile_to_array(std::string& file_name);

	//-----------------------------------------------------------------//
};

//=============================================================================

template<typename T>
inline bool Array<T>::insert(T& instance) {

	if (!isfull())
	{ //if all OK store element 
		_array[_elems_stored] = instance;
		++_elems_stored;
		return true;
	}
	else
		cerr << "Array is full";
		return false;
}

//=============================================================================

template<typename T>
inline const T & Array<T>::operator[](size_t i) const
{
	if (i < 0 || size() <= i)
		throw std::out_of_range{ "Array::operator[]" };
	return _array[i];
}

//=============================================================================
// begin() & end() iterators

template<typename T>
inline const T * Array<T>::begin() const
{
	return &_array[0];
}


template<typename T>
inline const T * Array<T>::end() const
{
	return this->begin() + this->size();
}

//=============================================================================

template<typename T>
inline void Array<T>::sort_ascending()
{
	if (this->size() > 0)
		//sort
}


template<typename T>
inline void Array<T>::sort_descending()
{
	if (this->size() > 0)
		//sort
}

//=============================================================================

template<typename T>
inline bool Array<T>::array_to_binaryfile(std::string & file_name) const
{	
	std::ofstream fileOut (file_name,
		std::ios_base::out | std::ios_base::app | std::ios_base::binary);

	if (fileOut.is_open())

		fileOut.write	//write all elements at once		
		((char *)this->begin(), sizeof(T)*this->elements());

	else
		return false;	

	return true;
}

template<typename T>
inline bool Array<T>::binaryfile_to_array(std::string & file_name)
{	
		std::streampos 	fsize = 0;{	 //calculate file size

		std::ifstream fileIn(file_name, std::ios_base::in);

			if (!fileIn.is_open())					
				return false;

		fsize = fileIn.tellg();
		fileIn.seekg(0, std::ios::end);
		fsize = fileIn.tellg() - fsize;
	}	 

	//resize in case of Array's insufficient capacity
	if ((fsize/sizeof(T)) > this->size())
	{
		delete[] _array;
		_sz = size_t(fsize) / sizeof(T);
		_array = new T[_sz];
	}


	std::ifstream fileIn(file_name,
		std::ios_base::in | std::ios_base::binary);	

	if (!fileIn.is_open())
		return false;
		
		//read one element at a time
		for (T element;	fileIn.read((char *)&element, sizeof(T));)
			this->insert(element);		
	
		return true;
	
}

//=============================================================================