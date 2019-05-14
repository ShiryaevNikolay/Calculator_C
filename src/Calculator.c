/*
 ============================================================================
 Name        : Structure.c
 Author      : Nikolay Shiryaev
 Version     : List(1.0)
 Copyright   : Your copyright notice
 Description : Calculator(structures) in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	char oper;
	char vect;
	int size;
	float *value1;
	float *value2;
	struct element *next;
} element;

typedef struct res {
	char vs;
	int size;
	float *result;
	struct res *next;
} res;

element* getLastEl(element *head){	// Finding the last item
	if(head == NULL){
		return NULL;
	}
	while(head->next){
		head = head->next;
	}
	return head;
}

res* getLastRes(res *head){	// Finding the last item
	if(head == NULL){
		return NULL;
	}
	while(head->next){
		head = head->next;
	}
	return head;
}

void pushEl (element* head, FILE* in_file) {
	element *last = getLastEl(head);
	element *tmp = (element*)malloc(sizeof(element));

	fscanf(in_file, " %c %c", &tmp->oper, &tmp->vect);
	if (tmp->vect == 'v')
		fscanf(in_file, "%d", &tmp->size);
	else
		tmp->size = 1;
	tmp->value1 = malloc(tmp->size*sizeof(float));
	tmp->value2 = malloc(tmp->size*sizeof(float));
	for (int i = 0; i < tmp->size; i++)
		fscanf(in_file, "%f", &tmp->value1[i]);
	for (int i = 0; i < tmp->size; i++)
		fscanf(in_file, "%f", &tmp->value2[i]);
	tmp->next = NULL;
	last->next = tmp;
}

void pushRes (element *el, res *result) {
	res *tmp = (res*)malloc(sizeof(res));
	if (el->vect == 'v') {
		tmp->vs = 'v';
		if (el->oper == '*' || el->oper == '/' || el->oper == '^' || el->oper == '!')
			tmp->size = 1;
		else
			tmp->size = el->size;
	} else {
		tmp->vs = 's';
		tmp->size = 1;
	}
	tmp->result = malloc(tmp->size*sizeof(float));
	switch (el->oper) {
	case '+':
		for (int i = 0; i < tmp->size; i++)
			tmp->result [i] = el->value1[i] + el->value2[i];
		break;
	case '-':
		for (int i = 0; i < tmp->size; i++)
			tmp->result [i] = el->value1[i] - el->value2[i];
		break;
	case '*':
		tmp->result[0] = 0;
		for (int i = 0; i < el->size; i++)
			tmp->result[0] = tmp->result[0] + el->value1[i] * el->value2[i];
		break;
	case '/':
		tmp->result[0] = el->value1[0] / el->value2[0];
		break;
	case '^':
		tmp->result[0] = el->value1[0];
		if (el->value2[0] != 0) {
			for (int i = 1;i < el->value2[0]; i++) {
				tmp->result[0] = tmp->result[0] * el->value1[0];
			}
		} else
			tmp->result[0] = 1;
		break;
	case '!':
		tmp->result[0] = 1;
		for (int i = 1; i <= el->value1[0]; i++) {
			tmp->result[0] = tmp->result[0] * i;
		}
		break;
	}
	tmp->next = NULL;
	result->next = tmp;
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *in_file;

	in_file = fopen("input.txt", "r");

	element *head; // Creating the first list item
	head = (element*)malloc(sizeof(element));
	fscanf(in_file, "%c %c", &head->oper, &head->vect);
	if (head->vect == 'v')
		fscanf(in_file, "%d", &head->size);
	else
		head->size = 1;
	head->value1 = malloc(head->size*sizeof(float));
	head->value2 = malloc(head->size*sizeof(float));
	for (int i = 0; i < head->size; i++)
		fscanf(in_file, "%f", &head->value1[i]);
	for (int i = 0; i < head->size; i++)
		fscanf(in_file, "%f", &head->value2[i]);
	head->next = NULL;

	//=================================================================================

	element *last = head;
	while (!feof(in_file)) {
		pushEl (getLastEl(last), in_file); // Добавление операций в список
	}

	fclose(in_file);

	last = head; // Возвращаемся в первый элемент списка

	res *head_res = (res*)malloc(sizeof(res));
	if (last->vect == 'v') {
		head_res->vs = 'v';
		if (last->oper == '*')
			head_res->size = 1;
		else
			head_res->size = last->size;
	} else {
		head_res->vs = 's';
		head_res->size = 1;
	}
	head_res->result = malloc(head_res->size*sizeof(float));
	switch (last->oper) {
	case '+':
		for (int i = 0; i < head_res->size; i++)
			head_res->result [i] = last->value1[i] + last->value2[i];
		break;
	case '-':
		for (int i = 0; i < head_res->size; i++)
			head_res->result [i] = last->value1[i] - last->value2[i];
		break;
	case '*':
		head_res->result[0] = 0;
		for (int i = 0; i < last->size; i++)
			head_res->result[0] = head_res->result[0] + last->value1[i] * last->value2[i];
		break;
	case '/':
		head_res->result[0] = last->value1[0] / last->value2[0];
		break;
	case '^':
		head_res->result[0] = last->value1[0];
		if (last->value2[0] != 0) {
			for (int i = 1;i < last->value2[0]; i++) {
				head_res->result[0] = head_res->result[0] * last->value1[0];
			}
		} else
			head_res->result[0] = 1;
		break;
	case '!':
		head_res->result[0] = 1;
		for (int i =1; i <= last->value1[0]; i++) head_res->result[0] = head_res->result[0] * i;
		break;
	}
	head_res->next = NULL;

	last = head->next;
	while (last) { // Заполняем список с результатами
		pushRes (last, getLastRes(head_res));
		last = last->next;
	}

	FILE *out_file = fopen("output.txt", "w");
	res *last_r = head_res;
	while (last_r->next != NULL) { // Вывод списка с результатами в консоль
		for (int i = 0; i < last_r->size; i++)
			fprintf(out_file, "%.0f ", last_r->result[i]);
		fprintf(out_file, "\n");
		last_r = last_r->next;
	}
	fclose(out_file);

	return EXIT_SUCCESS;
}
