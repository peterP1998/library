#pragma once
template <typename T>
class Set
{
private:
	
	int capacity;
	int size;
	void ResizeUp();
	void clear();
	void copy(const Set&);
	T ** objects;
public:
	Set(int capacity = 1);
	Set(const Set<T>&);
	Set& operator=(const Set<T>&);
	~Set();

	int getCapacity()const { return capacity; }

	int getSize()const { return size; }
	T* clone()const {return new T(*this); }
	T** getObjects()const { return this->objects; }
	void insert( const T&);
	bool isEmpty()const;
	void print()const;
	T& operator[](int idx);
	const T& operator[](int idx) const;
	bool has( const T& obj) const;
	void remove(const T& obj);
};
template <typename T>
Set<T>::Set(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->objects = new T*[capacity];
}
template <typename T>
void Set<T>::clear()
{
	for (int i = 0; i < this->size; i++)
	{
		delete this->objects[i];
	}
	delete[] this->objects;
}
template <typename T>
Set<T>::~Set()
{
	clear();
}

template <typename T>
void Set<T>::copy(const Set &other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->objects = new T*[other.capacity];
	for (int i = 0; i < other.size; i++)
	{
		this->objects[i] = other.objects[i];
	}
	
}
template <typename T>
Set<T>::Set(const Set<T>& other)
{
	copy(other);
}
template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}
template <typename T>
void Set<T>::ResizeUp()
{
	T** tmp = new T*[this->capacity * 2];

	for (int i = 0; i < this->size; i++)
	{
		tmp[i] =objects[i];
	}
	delete[] objects;
	this->objects = tmp;
	this->capacity *= 2;
}
template <typename T>
bool Set<T>::has(const T& obj) const
{
	for (int i = 0; i < this->size; i++)
	{
		
		if (*objects[i] ==obj)
		{
			return true;
		}
	}
	return false;
}
template <typename T>
void Set<T>::insert(const T &ob)
{
	if (!this->has(ob))
	{
		if (capacity == size)
		{
			this->ResizeUp();
		}
		this->objects[this->size] =ob.clone();
		this->size++;
	}
}
template <typename T>
bool Set<T>::isEmpty()const
{
	return this->size == 0;
}
template <typename T>
void Set<T>::print()const
{
	for (int i = 0; i < this->size; i++)
	{
		this->objects[i]->print();
	}
}
template <typename T>
T& Set<T>:: operator[](int idx)
{
	if (idx < this->size)
	{
		return *this->objects[idx];
	}
}
template <typename T>
const T& Set<T>::operator[](int idx) const
{
	if (idx < this->size)
	{
		return this->objects[idx];
	}
}
template <typename T>
void Set<T>::remove(const T& ob)
{
	if (this->has(ob))
	{
		cout << "yes" << endl;
		int idx=0;
		for (int i = 0; i < this->size; i++)
		{
			
			if (*this->objects[i] == ob)
			{
				idx = i;
			}
		}
		cout << idx << endl;
		for (int i = idx; i < this->size-1; ++i)
		{
			this->objects[i] =objects[i+1];
		}
		this->size--;
	}
	if (this->capacity / 2 > this->size)
	{
		T** tmp = new T*[this->capacity / 2];

		for (int i = 0; i < this->size; i++)
		{
			tmp[i] = objects[i];
		}
		delete[] objects;
		this->objects = tmp;
		this->capacity /= 2;
	}
}