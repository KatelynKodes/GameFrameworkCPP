#pragma once
#include <exception>

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	T getItem(int index);
	int getLength();
	bool contains(T* item);

	void addItem(T item);
	void addItems(T items[], int itemsSize);
	bool removeItem(T item);
	bool removeItem(int index);
	void sortItems();

	T operator [](int index);
private:
	T* m_items;
	int m_length;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_items = nullptr;
	m_length = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
}

template<typename T>
T DynamicArray<T>::getItem(int index)
{
	if (index < 0 || index >= getLength())
	{
		return T();
	}

	for (int i = 0; i < m_length; i++)
	{
		if (i == index)
		{
			return m_items[i];
		}
	}
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}

template<typename T>
inline bool DynamicArray<T>::contains(T* item)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_items[i] == item)
			return true;
	}

	return false;
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	T* tempArray = new T[getLength() + 1];

	for (int i = 0; i < getLength(); i++)
	{
		tempArray[i] = m_items[i];
	}

	tempArray[getLength()] = item;
	delete[] m_items;
	m_items = tempArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T items[], int itemsSize)
{
	for (int i = 0; i < itemsSize; i++)
	{
		addItem(items[i]);
	}
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	//Check if actor is null
	if (!item)
	{
		return false;
	}

	bool itemRemoved = false;

	T* tempArray = new T[getLength() - 1];

	int j = 0;
	for (int i = 0; i < getLength(); i++)
	{
		if (item != m_items[i])
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}

	if (itemRemoved)
	{
		delete[] m_items;
		m_items = tempArray;
		m_length--;
	}

	return itemRemoved;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(int index)
{
	if (index < 0 || index >= getLength())
		return false;

	bool itemRemoved = false;

	T* newitemArray = new T * [getLength() - 1];
	int j = 0;

	for (int i = 0; i < getLength(); i++)
	{
		if (i != index)
		{
			newitemArray[j] = m_items[i];
			j++;
		}
		else
		{
			delete m_items[i];
			itemRemoved = true;
		}
	}

	//Set the old array to be the tempArray
	m_items = newitemArray;
	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	T key;
	int j = 0;

	for (int i = 0; i < getLength(); i++)
	{
		key = m_items[i];
		j = i - 1;
		while (j >= 0 && m_items[j] > key)
		{
			m_items[j + 1] = m_items[j];
			j--;
		}

		m_items[j + 1] = key;
	}
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
	if (index > 0 || index < getLength())
	{
		return m_items[index];
	}

	throw std::exception("Item was not found or index is out of bounds.");
}
