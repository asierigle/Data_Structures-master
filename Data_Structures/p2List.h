#ifndef __P2LIST_H__
#define __P2LIST_H__


#include  "p2Defs.h"



template<class tdata>
struct p2List_item
{
	tdata                 data;
	p2List_item<tdata>*   next;
	p2List_item<tdata>*   prev;

	inline p2List_item(const tdata& _data)
	{
		data = _data;
		next = prev = NULL;
	}

	~p2List_item()
	{}
};

/**
* Manages a double linked list
*/
template<class tdata>
class p2List
{

public:

	p2List_item<tdata>*   start;
	p2List_item<tdata>*   end;

private:

	unsigned int  size;

public:

	/**
	* Constructor
	*/
	inline p2List()
	{
		start = end = NULL;
		size = 0;
	}

	/**
	* Destructor
	*/
	~p2List()
	{
		clear();
	}

	/**
	* Get Size
	*/
	uint count()
	{
		return size;
	}

	/**
	* Add new item
	*/
	void swap(p2List_item<tdata>* a, p2List_item<tdata>* b)
	{
		p2List_item<tdata>* tmp;
		p2List_item<tdata>* tmp2;
		tmp = a;
		tmp2 = b;
		a = b;
		a->next = tmp->next;
		a->prev = tmp->prev;
		b = tmp;
		b->next = tmp2->next;
		b->prev = tmp2->prev;


	}
	unsigned int add(const tdata& item)
	{
		p2List_item<tdata>*   p_data_item;
		p_data_item = new p2List_item < tdata >(item);

		if (start == NULL)
		{
			start = end = p_data_item;
		}
		else
		{
			p_data_item->prev = end;
			end->next = p_data_item;
			end = p_data_item;
		}

		return(++size);
	}
	void InsertAfter(unsigned int index, const p2List<tdata>& otherlist) {
		p2List_item<tdata>* tmp = start;
		if (index >= size && size != 0) { index = size - 1; end = otherlist.end; }
		int i = 0;
		if (index == 0 || size == 0) i = 1;
		else i = 0;

		for (i; i <index; i++) {
			tmp = tmp->next;
		}

		otherlist.start->prev = tmp;
		otherlist.end->next = tmp->next;
		tmp->next = otherlist.start;
		tmp->next->prev = otherlist.end;
		size += otherlist.size;
	}//intercalar dos llistes, prefix llista, flip llista

	void InsertMiddle(const p2List<tdata>& otherlist) {


		p2List_item<tdata>* tmp = start;
		p2List_item<tdata>* tmp_otherlist = otherlist.start;

		if (start == NULL) {

			for (int i = 0; i < otherlist.size; i++) {

				add(tmp_otherlist->data);
				tmp_otherlist = tmp_otherlist->next;

			}

		}

		else {

			for (int i = 0; i < (count() / 2) - 1; i++) {

				tmp = tmp->next;

			}



			while (tmp_otherlist != NULL) {

				p2List_item<tdata>* p_new_item = new p2List_item<tdata>(tmp_otherlist->data);
				size++;
				p_new_item->next = tmp->next;
				p_new_item->next->prev = p_new_item;
				p_new_item->prev = tmp;
				p_new_item->prev->next = p_new_item;

				tmp_otherlist = tmp_otherlist->next;
				tmp = tmp->next;

			}

		}

	}


	//operator +=

	const p2List<tdata>& operator +=(const p2List<tdata>& otherlist) {

		for (unsigned int i = 0; i < otherlist.size; i++) {
			add(otherlist[i]);
		}

		return (*this);
	}
	//Operator []

	tdata& operator[](const unsigned int index)const {

		if (index == 0) { return start->data; }

		else {

			p2List_item<tdata>* tmp = start;

			for (int i = 0; i < index; i++) {

				tmp = tmp->next;


			}
			return tmp->data;
		}
	}

	tdata& operator[](const unsigned int index) {

		if (index == 0) { return start->data; }

		else {

			p2List_item<tdata>* tmp = start;

			for (int i = 0; i < index; i++) {

				tmp = tmp->next;


			}
			return tmp->data;
		}
	}

	int BubbleSort() {
		int contador = 0;
		bool correct = true;

		while (correct) {
			correct = false;
			p2List_item<tdata>* tmp = start;

			while (tmp != NULL && tmp->next != NULL) {


				++contador;
				if (tmp->data > tmp->next->data) {
					swap(tmp, tmp->next);
					correct = true;
				}

				tmp = tmp->next;


			}
		}
		return contador;
	}


	/**
	* Deletes an item from the list
	*/
	bool del(p2List_item<tdata>* item)
	{
		if (item == NULL)
		{
			return (false);
		}

		// Now reconstruct the list
		if (item->prev != NULL)
		{
			item->prev->next = item->next;

			if (item->next != NULL)
			{
				item->next->prev = item->prev;
			}
			else
			{
				end = item->prev;
			}
		}
		else
		{
			if (item->next)
			{
				item->next->prev = NULL;
				start = item->next;
			}
			else
			{
				start = end = NULL;
			}
		}

		delete item;
		--size;
		return(true);
	}

	/**
	* Destroy and free all mem
	*/
	void clear()
	{
		p2List_item<tdata>*   p_data;
		p2List_item<tdata>*   p_next;
		p_data = start;

		while (p_data != NULL)
		{
			p_next = p_data->next;
			delete p_data;
			p_data = p_next;
		}

		start = end = NULL;
		size = 0;
	}
	
	p2DynArray<tdata>& listToArray()
	{
	p2DynArray<tdata>* new_array = new p2DynArray<tdata>(size);
	p2List_item<tdata>* tmp = start;
	uint i = 0;
	for (; i < size; i++)
	{
	new_array->PushBack(tmp->data);
	tmp = tmp->next;
	}

	return (*new_array);
	}
};
#endif //__P2LIST_H__