/*
 ============================================================================
 Name        : Structure.c
 Author      : Nikolay Shiryaev
 Version     : Turn(1.0)
 Copyright   : Your copyright notice
 Description : Calculator(structures) in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
	char *emelement;
	struct queue *next;
} queue;

typedef struct stek {
	float value;
	struct stek *next;
} stek;

typedef struct arr_val {
	char c;
	struct arr_val *next;
} arr_val;

void clear () {

}

queue* pushBack (FILE *in_file, char c) {
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
	queue *tmp = (queue*) malloc(sizeof(queue));
	tmp->emelement = array;
	tmp->next = NULL;
	return tmp;
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *in_file;
	in_file = fopen("input.txt", "r");
	char c;

	// Создание первого элемента (головы) очереди
	queue *head_queue;
	head_queue = (queue*)malloc(sizeof(queue));
	fscanf(in_file, "%c", &c);
	head_queue = pushBack(in_file, c);

	// Создание последнего элемента (хвоста) очереди
	queue *tail_queue;
	tail_queue = (queue*)malloc(sizeof(queue));
	tail_queue = head_queue;
	while (!feof(in_file)) {
		fscanf(in_file, "%c", &c);
		tail_queue->next = pushBack(in_file, c);
		tail_queue = tail_queue->next;
	}
	fclose(in_file);

	stek *head_stek = (stek*)malloc(sizeof(stek));
	head_stek->value = atof(head_queue->emelement);
	head_stek->next = NULL;
	while (head_queue) { // Проход по всем элементам очереди
		if (head_queue->emelement[0] == '+'
			|| head_queue->emelement[0] == '*'
			|| head_queue->emelement[0] == '/'
			|| (head_queue->emelement[0] == '-'
				&& strlen(head_queue->emelement) == 1)) {
			switch (head_queue->emelement[0]) {
			case '+':
				head_stek->next->value = head_stek->next->value + head_stek->value;
				break;
			case '-':
				head_stek->next->value = head_stek->next->value - head_stek->value;
				break;
			case '*':
				head_stek->next->value = head_stek->next->value * head_stek->value;
				break;
			case '/':
				head_stek->next->value = head_stek->next->value / head_stek->value;
				break;
			}
			head_stek = head_stek->next;
		} else { // Если число, добавляем его в стек
			stek *tmp = (stek*)malloc(sizeof(stek));
			tmp->value = atof(head_queue->emelement);
			tmp->next = head_stek;
			head_stek = tmp;
		}
		head_queue = head_queue->next;
	}
	// Вывод результата в файл
	FILE *out_file;
	out_file = fopen("output.txt", "w");
	fprintf(out_file, "result: %.2f", head_stek->value);
	fclose(out_file);
	return EXIT_SUCCESS;
}
