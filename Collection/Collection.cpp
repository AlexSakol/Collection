#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <ctime>

struct list_element
{
	int value;
	struct list_element* next;
};

struct list_element* create_LIFO(int N)
{
	struct list_element* FIRST = NULL, * TMP = NULL;
	for (int i = 0; i < N; i++)
	{
		TMP = FIRST;
		FIRST = new list_element;
		FIRST->next = TMP;
		FIRST->value = rand();
		printf("%d - %d\n", i + 1, FIRST->value);
	}
	return FIRST;
}

void print_list(struct list_element* list)
{
	if (list == NULL) {
		puts("Empty list");
		exit(0);
	}
	int i = 1;
	while (list)
	{
		printf("%2.d ADDR: %p VALUE: %d\tADDR_NEXT: %p\n", i, list, list->value, list->next);
		list = list->next;
		i++;
	}
}

list_element* AddStack(list_element* begin, int N) {
	list_element* tmp = begin;
	for (int i = 0; i < N; i++) {
		tmp = begin;
		begin = new list_element;
		begin->next = tmp;
		begin->value = rand();
		printf_s("%2.d ADR : %p info : %d\t ADR_NEXT : %p\n", i + 1, begin, begin->value, begin->next);
	}
	return begin;
}

int FindMin(struct list_element* list)
{
	if (list == NULL) {
		puts("Empty list");
		exit(0);
	}
	int i = 1;
	int min = list->value;
	while (list)
	{
		if (min > list->value) {
			min = list->value;
		}
		list = list->next;
		i++;
	}
	printf("Minimum %d\n", min);
	return min;
}

list_element* NewStack(list_element* list, list_element* newbegin, int min) {
	if (list == NULL) {
		puts("Empty list");
		exit(0);
	}
	list_element* tmp = NULL;
	int i = 0;
	while (list) {
		tmp = newbegin;
		newbegin = new list_element;
		newbegin->next = tmp;
		newbegin->value = list->value;
		if (list->value == min) {
			list == NULL;
			break;
		}
		list = list->next;
		i++;
	}
	return newbegin;
}

void Delete(list_element* list) {
	if (list == NULL) {
		puts("Empty list");
		exit(0);
	}
	list_element* tmp;
	while (list) {
		tmp = list;
		list = list->next;
		delete tmp;
	}
}

void main() {
	int s = 1;
	int w, n;
	struct list_element* FIRST = NULL;
	list_element* newbegin = NULL;
	srand(time(0));
	for (s; s > 0 && s < 5; s = w) {
		puts("1. Create list");
		puts("2. Output created list");
		puts("3. Add element");
		puts("4. Task");
		puts("5. Exit");
		puts("Select an option");
		scanf("%d", &w);
		switch (w) {
		case 1:
			puts("Enter a quantity of elements");
			scanf("%d", &n);
			puts("List creation");
			FIRST = create_LIFO(n);
			break;
		case 2:
			puts("Created list");
			print_list(FIRST);
			break;
		case 3:
			int M;
			puts("Enter a quantity of added elements");
			scanf_s("%d", &M);
			FIRST = AddStack(FIRST, M);
			printf_s("begin ADR : %p", FIRST);
			puts("\nList added\n");
			print_list(FIRST);
			break;
		case 4:
			int min = FindMin(FIRST);
			newbegin = NewStack(FIRST, newbegin, min);
			puts("New list");
			print_list(newbegin);
			_getch();
			break;
			break;
		}
	}
	Delete(FIRST);
}



