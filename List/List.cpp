#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

struct Spis {
	int info;
	Spis* next;
	Spis* prev;
};

void CreateSpis(Spis** begin, Spis** end) {
	Spis* t = new Spis;
	srand((unsigned)t);
	t->info = rand() % 200 - 100;
	if (*begin == NULL) {
		t->next = NULL;
		t->prev = NULL;
		*begin = *end = t;
	}
	else {
		t->next = NULL;
		t->prev = *end;
		(*end)->next = t;
		*end = t;
	}
}

void CreateSpis_pos(Spis** begin_pos, Spis** end_pos, int value) {
	Spis* t = new Spis;
	t->info = value;
	if (*begin_pos == NULL) {
		t->next = NULL;
		t->prev = NULL;
		*begin_pos = *end_pos = t;
	}
	else {
		t->next = NULL;
		t->prev = *end_pos;
		(*end_pos)->next = t;
		*end_pos = t;
	}
}

void CreateSpis_neg(Spis** begin_neg, Spis** end_neg, int value) {
	Spis* t = new Spis;
	t->info = value;
	if (*begin_neg == NULL) {
		t->next = NULL;
		t->prev = NULL;
		*begin_neg = *end_neg = t;
	}
	else {
		t->next = NULL;
		t->prev = *end_neg;
		(*end_neg)->next = t;
		*end_neg = t;
	}
}

void SpisViewBegin(Spis* t) {
	int i = 1;
	if (t == NULL) {
		puts("List is empty");
		return;
	}
	while (t) {
		printf_s("%2.d ADR: %p info: %d\t ADR_NEXT: %p\n", i, t, t->info, t->next);
		t = t->next;
		i++;
	}
}
void SpisViewEnd(Spis* t) {
	int i = 1;
	if (t == NULL) {
		puts("List is empty");
		return;
	}
	while (t) {
		printf_s("%2.d ADR: %p info: %d\t ADR_NEXT: %p\n", i, t, t->info, t->prev);
		t = t->prev;
		i++;
	}
}

void DeleteSpis(Spis** list) {
	Spis* tmp;
	while (*list != 0) {
		tmp = *list;
		*list = (*list)->next;
		delete (tmp);
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu, menu2;
	Spis* begin = NULL;
	Spis* end = NULL;
	Spis* begin_pos = NULL;
	Spis* end_pos = NULL;
	Spis* begin_neg = NULL;
	Spis* end_neg = NULL;
	Spis* t = NULL;

	do {
		puts("1 – Create list");
		puts("2 – View list");
		puts("3 – Add an element");
		puts("4 – Create lists with positif elements and negatif elements");
		puts("5 – Exit ");
		puts("Choose an option");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: {
			DeleteSpis(&begin);
			int N, i = 0;
			puts("Create list");
			puts("Enter a quantity of elements");
			scanf_s("%d", &N);
			for (int i = 0; i < N; i++) {
				CreateSpis(&begin, &end);
				printf_s("%d - %d\n", i + 1, end->info);
			}
			_getch();
			break;
		}
		case 2: {
			puts("View list");
			puts("11 - From the beginning");
			puts("22 - From the end");
			puts("0 - Exit");
			scanf_s("%d", &menu2);
			switch (menu2) {
			case 11: {
				SpisViewBegin(begin);
				_getch();
				break;
			}
			case 22: {
				SpisViewEnd(end);
				_getch();
				break;
			}
			case 0: {
				exit(0);
			}
			default: {
				puts("Incorrect choise");
				_getch();
				break;
			}
			}
			break;
		}
		case 3: {
			int M;
			puts("Add an element");
			puts("Enter a quantity of added elements");
			scanf_s("%d", &M);
			for (int i = 0; i < M; i++) {
				CreateSpis(&begin, &end);
				printf_s("%d - %d\n", i + 1, end->info);
			}
			_getch();
			break;
		}
		case 4: {
			DeleteSpis(&begin_pos);
			DeleteSpis(&begin_neg);
			t = begin;
			if (t->next == t->prev) {
				puts("List is empty");
			}
			else {
				while (begin != 0) {
					if (begin->info > 0) {
						CreateSpis_pos(&begin_pos, &end_pos, begin->info);
					}
					else {
						CreateSpis_neg(&begin_neg, &end_neg, begin->info);
					}
					begin = begin->next;
				}
			}
			begin = t;
			puts("List of positif elements");
			SpisViewBegin(begin_pos);
			puts("List of negatif elements");
			SpisViewBegin(begin_neg);
			_getch();
			break;
		}
		case 5: {
			exit(0);
		}
		default: {
			puts("Incorrect value");
			_getch();
			break;
		}
		}
	} while (menu != 5);
	DeleteSpis(&begin);
	DeleteSpis(&begin_pos);
	DeleteSpis(&begin_neg);
}


