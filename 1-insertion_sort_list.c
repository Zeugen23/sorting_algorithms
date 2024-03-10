#include "sort.h"

/**
 * get_list_length - Returns the length of a linked list
 * @head: Pointer to the head of the list
 *
 * Return: Length of the list
 */
int get_list_length(listint_t *head)
{
    int length = 0;
    listint_t *current = head;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
}

/**
 * insertion_sort_list - Sorts a linked list using the Insertion Sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || get_list_length(*list) < 2)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current;

        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            temp->prev->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->next->prev;
            temp->next->prev = temp;

            if (temp->prev != NULL)
                temp->prev->next = temp;
            else
                *list = temp;

            print_list(*list);
        }

        current = current->next;
    }
}

/* 
 * Attribution: This code is based on the insertion_sort_list function
 * from the file "sort.h" in the holbertonschool-low_level_programming repository on GitHub.
 * Repository URL: https://github.com/holbertonschool/holbertonschool-low_level_programming
 */
