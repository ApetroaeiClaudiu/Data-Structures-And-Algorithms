#pragma once
#include "Colectie.h"
#include <stdio.h>

void Colectie::adauga(TElem e)
{
	if (size == capacity)
	{
		if (capacity == 0)
			capacity = 1;

		capacity *= 2;

		// allocate 2x larger memory
		TElem_pair* pNewMemory = new TElem_pair[capacity];

		// copy data to there
		for (int i = 0; i < size; ++i)
			pNewMemory[i] = data[i];

		delete data;
		data = pNewMemory;
	}

	// insert the new element
	int position = binarysearch(e);
	if (position == -1)
	{
		//new element
		int i;
		for (i = 0; i < size; i++)
			if (!rel(data[i].element, e))
			{
				for (int j = size; j > i; --j)
					data[j] = data[j - 1];
				break;
			}
		data[i].element = e;
		data[i].frequency = 1;
		++size;
	}
	else
	{
		//already existing element
		data[position].frequency += 1;
	}
}

bool Colectie::sterge(TElem e)
{
	int position = binarysearch(e);
	if (position == -1)
		return false;

	if (data[position].frequency > 1)
		data[position].frequency--;
	else
	{
		for (int i = position; i < size - 1; i++)
			data[i] = data[i + 1];
		--size;
	}
	return true;
}

bool Colectie::cauta(TElem elem) const
{
	if (binarysearch(elem) == -1)
		return false;
	return true;
}

int Colectie::nrAparitii(TElem elem) const
{
	int position = binarysearch(elem);
	if (position == -1)
		return 0;
	return data[position].frequency;
}

int Colectie::dim() const
{
	int dim = 0;
	for (int i = 0; i < size; i++)
		dim += data[i].frequency;
	return dim;
}

bool Colectie::vida() const
{
	if (size == 0)
		return true;
	return false;
}

int Colectie::binarysearch(TElem e) const
{
	int left = 0, right = size-1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (data[middle].element == e)
		{
			return middle;
		}
		else if (data[middle].element < e)
		{
			left = middle + 1;
		}
		else if (data[middle].element > e)
		{
			right = middle - 1;
		}
	}
	return -1;
}

IteratorColectie Colectie::iterator() const
{
	return IteratorColectie(data,size,capacity);
}

Colectie::~Colectie()
{
	delete data;
	size = 0;
	capacity = 0;
}

bool rel(TElem e1, TElem e2)
{
	return e1 <= e2;
}
