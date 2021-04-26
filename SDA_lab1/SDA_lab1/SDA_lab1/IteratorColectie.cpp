#include "IteratorColectie.h"

IteratorColectie::IteratorColectie(TElem_pair *data, int size, int capacity)
{
	iterator_data = data;
	iterator_data_size = size;
	iterator_data_capacity = capacity;
}

bool IteratorColectie::valid()
{
	int dim = 0;
	for (int i = 0; i < iterator_data_size; i++)
		dim += iterator_data[i].frequency;
	if (dim > current_dim)
		return true;
	return false;
}

TElem IteratorColectie::element()
{
	int dim = 0;
	for (int i = 0; i < iterator_data_size; i++)
	{
		dim += iterator_data[i].frequency;
		if (current_dim < dim)
			return iterator_data[i].element;
	}
}

void IteratorColectie::urmator()
{
	current_dim++;
}

void IteratorColectie::prim()
{
	current_dim = 0;
}
