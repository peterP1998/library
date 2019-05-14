#include "Set.h"
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
		delete objects[i];
	}
	delete[] this->objects;
}
template <typename T>
Set<T>::~Set()
{
	clear();
}
template <typename T>
void Set<T>::copy(const Set<T> &other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	clear();
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
		copy(other);
    }
	return *this;
}
template <typename T>
void Set<T>::ResizeUp()
{
	this->capacity *= 2;
    T ** buffer = new T*[this->capacity];
    for (int i = 0; i < this->size; ++i)
	{
		buffer[i] = this->objects[i];
	}
	clear();
	
	this->objects = buffer;
	
  
}
template <typename T>
bool Set<T>::has(const T& obj) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->objects[i] == &obj)
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
		if (capacity == size + 1)
		{
			this->ResizeUp();
		}
		this->objects[this->size] = ob.clone();
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
		return this->objects[idx];
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
		int idx;
		for (int i = 0; i < this->size; i++)
		{
			if (this->objects[i] == ob.clone())
			{
				idx = i;
			}
		}
		for (int i = idx; i < this->size-1; i++)
        {
			this->objects[i] = this->objects[i + 1];
		}
		this->size--;
	}
	if (this->capacity / 2 > this->size)
	{
		this->capacity /= 2;
	}
}
