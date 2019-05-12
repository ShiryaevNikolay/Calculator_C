/*
 ============================================================================
 Name        : Structure.c
 Author      : Nikolay Shiryaev
 Version     : Stack(1.0)
 Copyright   : Your copyright notice
 Description : Calculator(structures) in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
	char *emelement;
	struct list *next;
} list;

typedef struct stek {
	float value;
	struct stek *next;
} stek;

typedef struct arr_val {
	char c;
	struct arr_val *next;
} arr_val;

list* getLast(list *head) { // Получаем последний элемент списка
	if (head == NULL) return NULL;
	while (head->next) head= head->next;
	return head;
}

void pushBack(FILE *in_file, char c, list *head) {
	arr_val *head_arr; // Объявляем список для чисел >=10 и отрицательных чисел
	arr_val *last_arr;
	head_arr = (arr_val*) malloc(sizeof(arr_val));
	last_arr = (arr_val*) malloc(sizeof(arr_val));

	char *array; // Объявляем массив для чисел >=10 и отрицательных чисел
	int size = 0; // Кол-во символов в одном элементе (число, операция)
	while (c != ' ') {
		size++;
		if (size == 1) { // Если кол-во симоволов элемента =1, то создаём первый элемент списка(голову)
			head_arr->c = c;
			head_arr->next = NULL;
			last_arr = head_arr;
		} else { // Иначе заполняем список, пока не достигнем 0
			arr_val *tmp = (arr_val*) malloc(sizeof(arr_val));
			tmp->c = c;
			tmp->next = NULL;
			last_arr->next = tmp;
			last_arr = tmp;
		}
		if (feof(in_file) != 0)
			break;
		else
			fscanf(in_file, "%c", &c);
	}
	last_arr = head_arr; // Возвращаемся в начало списка
	array = malloc(size * sizeof(char));
	for (int i = 0; i < size; i++) { // Записываем значения из списка в массив
		array[i] = last_arr->c;
		last_arr = last_arr->next;
	}
	// Присваиваем массив (число, операция) в новый списка
	list *tmp = (list*) malloc(sizeof(list));
	tmp->emelement = array;
	tmp->next = NULL;
	list *last = getLast(head);
	last->next = tmp;
	printf("%s", last->emelement);
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *in_file;

	in_file = fopen("input.txt", "r");

	char c;

	list *head_list;
	head_list = (list*) malloc(sizeof(list));
	fscanf(in_file, "%c", &c);

	//=====================================================================================================================================
	/* Создание первного элемента списка */
	arr_val *head_arr; // Объявляем список для чисел >=10 и отрицательных чисел
	arr_val *last_arr;
	head_arr = (arr_val*) malloc(sizeof(arr_val));
	last_arr = (arr_val*) malloc(sizeof(arr_val));

	char *array; // Объявляем массив для чисел >=10 и отрицательных чисел
	int size = 0; // Кол-во символов в одном элементе (число, операция)
	while (c != ' ') {
		size++;
		if (size == 1) { // Если кол-во симоволов элемента =1, то создаём первый элемент списка(голову)
			head_arr->c = c;
			head_arr->next = NULL;
			last_arr = head_arr;
		} else { // Иначе заполняем список, пока не достигнем 0
			arr_val *tmp = (arr_val*) malloc(sizeof(arr_val));
			tmp->c = c;
			tmp->next = NULL;
			last_arr->next = tmp;
			last_arr = tmp;
		}
		if (feof(in_file) != 0)
			break;
		else
			fscanf(in_file, "%c", &c);
	}
	last_arr = head_arr; // Возвращаемся в начало списка
	array = malloc(size * sizeof(char));
	for (int i = 0; i < size; i++) { // Записываем значения из списка в массив
		array[i] = last_arr->c;
		last_arr = last_arr->next;
	}
	// Присваиваем массив (число, операция) в голову списка
	list *tmp = (list*) malloc(sizeof(list));
	tmp->emelement = array;
	tmp->next = NULL;
	head_list = tmp;
	//=====================================================================================================================================

	while (!feof(in_file)) { // Заполняем список числами и операциями
		fscanf(in_file, "%c", &c);
		pushBack(in_file, c, getLast(head_list));
	}
	fclose(in_file);

	list *last_list = (list*)malloc(sizeof(list));
	last_list = head_list;
	stek *head_stek;
	head_stek = (stek*) malloc(sizeof(stek));
	head_stek->value = atof(last_list->emelement);
	head_stek->next = NULL;
	while (last_list) {	// Проход по всем елементам списка
		if (last_list->emelement[0] == '+'
			|| last_list->emelement[0] == '*'
			|| last_list->emelement[0] == '/'
			|| (last_list->emelement[0] == '-'
				&& strlen(last_list->emelement) == 1)) { // Если операция
			switch (last_list->emelement[0]) {
			case '+':
				head_stek->next->value = head_stek->next->value
										+ head_stek->value;
				break;
			case '-':
				head_stek->next->value = head_stek->next->value
										- head_stek->value;
				break;
			case '*':
				head_stek->next->value = head_stek->next->value
										* head_stek->value;
				break;
			case '.':
				head_stek->next->value = head_stek->next->value
										/ head_stek->value;
				break;
			}
			head_stek = head_stek->next;
		} else {	// Если число, добавляем его в стек
			stek *tmp = (stek*) malloc(sizeof(stek));
			tmp->value = atof(last_list->emelement);
			tmp->next = head_stek;
			head_stek = tmp;
		}
		last_list = last_list->next;
	}
	// Вывод результата в файл
	FILE *out_file;
	out_file = fopen("output.txt", "w");
	fprintf(out_file, "result: %.2f", head_stek->value);
	fclose(out_file);

	return EXIT_SUCCESS;
}
