#pragma once
#include "IteratorColectie.h"
#include <exception>

IteratorColectie::IteratorColectie(const Colectie & c) :c(c)
{
	prim();
}

void IteratorColectie::prim()
{
	position = 0;
	while (valid() && c.elements[position].next == -2)
		position++;
}

void IteratorColectie::urmator()
{
	if (!valid())
	{
		std::exception e;
		throw e;
	}
	position++;
	while (valid() && c.elements[position].next == -2)
		position++;
}

bool IteratorColectie::valid() const
{
	return position < c.capacity;
}

TElem IteratorColectie::element() const
{
	if (!valid())
	{
		std::exception e;
		throw e;
	}
	return c.elements[position].element;
}
