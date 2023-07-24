#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *			in ascending order
 * @list: Pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		temp = curr;
		prev = curr->prev;
		curr = curr->next;

		while (prev && temp->n < prev->n)
		{
			if (prev->prev)
				prev->prev->next = temp;
			if (temp->next)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;
			prev->prev = temp;
			temp->next = prev;

			if (!temp->prev)
				*list = temp;

			print_list(*list);
			prev = temp->prev;
		}
	}
}
