#pragma once
#include "Colectie.h"
#include <vector>
#include <iostream>

void Colectie::resize()
{
	int old_capacity = capacity;
	if (capacity == 0)
		capacity = 5;
	else
		capacity = next_prime(capacity * 2);
	pair *temporary = elements;
	elements = new pair[capacity];

	for (int i = 0; i < capacity; i++)
		elements[i].next = -2;
	size = 0;
	for (int i = 0; i < old_capacity; i++)
		if (temporary[i].next != -2)
			adauga(temporary[i].element);
	delete[] temporary;
}

int Colectie::next_prime(int capacity)
{
	capacity += capacity % 2 + 1;
	while (!prime(capacity))
		capacity += 2;
	return capacity;
}

bool Colectie::prime(int number)
{
	if (number < 2)
		return false;
	if (number == 2)
		return true;
	if (number % 2 == 0)
		return false;
	for (int i = 3; i*i <= number; i += 2)
		if (number%i == 0)
			return false;
	return true;
}

int Colectie::hash(TElem element) const
{
	return abs(element % capacity);
}

int Colectie::next_free()
{
	int i = (first_free + 1) % capacity;
	while (i != first_free && elements[i].next != -2)
		i = (i + 1) % capacity;
	if (i == first_free)
		throw "error";
	return i;
}

unsigned Colectie::abs(int number) const
{
	if (number < 0)
		return -number;
	return number;
}

Colectie::Colectie()
{
	size = 0;
	capacity = 0;
	first_free = 0;
	resize();
}

bool Colectie::adauga(TElem elem)
{
	if (size >= capacity * 0.75)
		resize();
	int position = hash(elem);
	if (elements[position].next == -2)
	{
		elements[position].element = elem;
		elements[position].next = -1;
		size++;
		if (position == first_free)
			first_free = next_free();
		return true;
	}
	else
	{
		while (elements[position].next != -1)
			position = elements[position].next;
		elements[position].next = first_free;
		elements[first_free].element = elem;
		elements[first_free].next = -1;
		first_free = next_free();
		size++;
		return true;
	}
}

bool Colectie::sterge(TElem elem)
{
	std::vector<pair>vect;
	for (int i = 0; i < capacity; i++) {
		vect.push_back(elements[i]);
	}
	int position = hash(elem);
	if (elements[position].next == -2)
		return false;
	do
	{
		if (elements[position].element == elem)
		{
			int new_hash = position;
			int current_position = position;
			int position_hash = position;
			int trail = position;
			while (elements[current_position].next > 0)
			{
				///!!!!!!!!!!!!!!!!!!!!!
				trail = current_position;
				current_position = elements[current_position].next;
				new_hash = hash(elements[current_position].element);
				if (position_hash == new_hash)
				{
					elements[position_hash].element = elements[current_position].element;
					position_hash = current_position;
				}
			}
			if (position_hash != position || elements[position].next == -1)
			{
				elements[trail].next = elements[position_hash].next;
				elements[position_hash].next = -2;
			}
			else
			{
				bool ok = true;
				bool ok2 = true;
				int current_position2 = position;
				current_position = position;
				while (elements[current_position].next > 0)
				{
					trail = current_position;
					current_position = elements[current_position].next;
					new_hash = hash(elements[current_position].element);
					ok2 = (current_position == new_hash);
					current_position2 = current_position;
					ok = true;
					while (elements[current_position2].next > 0 && ok == true)
					{
						current_position2 = elements[current_position2].next;
						position_hash = hash(elements[current_position2].element);
						if (new_hash == position_hash)
							ok = false;
					}
					if (ok == true)
					{
						if (ok2 == true)
						{
							elements[position].next = -2;
							break;
						}
						elements[trail].next = elements[current_position].next;
						elements[trail].element = elements[current_position].element;
						elements[current_position].next = -2;
						break;
					}
				}
			}
			size--;
			return true;
		}
		position = elements[position].next;
	} while (position >= 0);
	return false;
}

bool Colectie::cauta(TElem elem) const
{
	int position = hash(elem);
	if (elements[position].next == -2)
		return false;
	if (elements[position].element == elem)
		return true;
	while (elements[position].next != -1)
	{
		position = elements[position].next;
		if (elements[position].element == elem)
			return true;
	}
	return false;
}

int Colectie::nrAparitii(TElem elem) const
{
	int i = 0;
	int position = hash(elem);
	if (elements[position].next == -2)
		return 0;
	if (elements[position].element == elem)
		i++;
	while (elements[position].next > 0)
	{	
		position = elements[position].next;
		if (elements[position].element == elem)
			i++;
	}
	return i;
}

int Colectie::dim() const
{
	return size;
}

bool Colectie::vida() const
{
	return size == 0;
}

IteratorColectie Colectie::iterator() const
{
	return IteratorColectie(*this);
}

Colectie::~Colectie()
{
	delete[] elements;
}
