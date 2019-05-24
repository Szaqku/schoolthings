
#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include "ItemObject.h"

template<class T>
class Chest{
	std::vector<T> listOfItems;
	int maxItems;

public:
	Chest();
	Chest(int);
	
	void addItem(T item) noexcept(false);
	T getItem(int i) noexcept(false);
	void throwAwayItem(int i) noexcept(false);

	bool isFull();

	int getNumberOfItems();
	int getMaxNumberOfItems();
	const std::vector<T> getListOfItems();

	~Chest();
};

