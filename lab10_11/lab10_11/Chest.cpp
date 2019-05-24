#include "Chest.h"

template<class T>
Chest<T>::Chest(): Chest(10){}

template<class T>
Chest<T>::Chest(int maxSize) : maxItems(maxSize)
{
	listOfItems = std::vector<T>();
	listOfItems.reserve(maxSize);
}

template<class T>
void Chest<T>::addItem(T item) noexcept(false)
{
	if (isFull())
		throw std::runtime_error("Couldn't add new item. Chest is already full.");

	listOfItems.push_back(item);
}

template<class T>
T Chest<T>::getItem(int i) noexcept(false){
	if( i >= maxItems || i < 0)
		throw std::runtime_error("Nothing is there.");
	return listOfItems[i];
}

template<class T>
void Chest<T>::throwAwayItem(int i) noexcept(false){
	if(getItem(i))
		listOfItems.erase(listOfItems.begin() + i);
	else
		throw std::runtime_error("Can't throw item on position: "+std::to_string(i)+". Nothing is there.");
}

template<class T>
bool Chest<T>::isFull()
{
	return listOfItems.size() == maxItems;
}

template<class T>
int Chest<T>::getNumberOfItems()
{
	return listOfItems.size();
}

template<class T>
int Chest<T>::getMaxNumberOfItems()
{
	return maxItems;
}

template<class T>
const std::vector<T> Chest<T>::getListOfItems()
{
	return listOfItems;
}

template<class T>
Chest<T>::~Chest(){}
