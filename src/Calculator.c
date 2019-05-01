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

element* getLast(element *head){	// Finding the last item
	if(head == NULL){
		return NULL;
	}
	while(head->next){
		head = head->next;
	}
	return head;
}

void pushBack(element *head, FILE *in_file){	// Adding a item to end of list
	while(!feof(in_file)){
		element *last = getLast(head);
		element *tmp = (element*)malloc(sizeof(element));
		fscanf(in_file, " %c %c", &tmp->oper, &tmp->vect);
		if(tmp->vect == 'v') {
			fscanf(in_file, "%d", &tmp->size);
			tmp->value1 = malloc(tmp->size*sizeof(float));
			tmp->value2 = malloc(tmp->size*sizeof(float));
			for(int i = 0; i < tmp->size; i++){
				fscanf(in_file, "%f", &tmp->value1[i]);
			}
			for(int i = 0; i < tmp->size; i++){
				fscanf(in_file, "%f", &tmp->value2[i]);
			}
		}else{
			tmp->value1 = malloc(sizeof(float));
			tmp->value2 = malloc(sizeof(float));
			fscanf(in_file, "%f %f", tmp->value1, tmp->value2);
		}
		tmp->next = NULL;
		last->next = tmp;
	}
}

void printList(const element *head){	// Printing the list to console
	while(head){
		printf("%c %c", head->oper, head->vect);
		if(head->vect == 'v'){
			printf(" %d", head->size);
			for(int i = 0; i < head->size; i++) printf(" %.0f", head->value1[i]);
			for(int i = 0; i < head->size; i++) printf(" %.0f", head->value2[i]);
		}else{
			printf(" %.0f %.0f", head->value1[0], head->value2[0]);
		}
		head = head->next;
		printf("\n");
	}
}

void regular_calculator_file(FILE *out_file, element *head) {
	float c;
	switch(head->oper) {
		case '+':
			fprintf(out_file, "Result: %.1f", head->value1[0] + head->value2[0]);
			break;
		case '-':
			fprintf(out_file, "Result: %.1f", head->value1[0] - head->value2[0]);
			break;
		case '*':
			fprintf(out_file, "Result: %.1f", head->value1[0] * head->value2[0]);
			break;
		case '/':
			fprintf(out_file, "Result: %.1f", head->value1[0] / head->value2[0]);
			break;
		case '!':
			c = 1;
			for(int i = 1; i <= head->value1[0]; i++) c = c * i;
			fprintf(out_file, "Result: %.1f", c);
			break;
		case '^':
			c = head->value1[0];
			if(head->value2[0] != 0){
				for(int i = 1; i < head->value2[0]; i++) {
					head->value1[0] = head->value1[0] * c;
				}
			}
			else {
				head->value1[0] = 1;
			}
			fprintf(out_file, "Result: %.1f", head->value1[0]);
			break;
	}
}

void vector_calculator_file(FILE *out_file, element *head) {
	float result = 0;
	switch(head->oper) {
		case '+':
			fprintf(out_file, "Result: (");
			for (int i = 0; i < head->size; i++) {
				fprintf(out_file, "%.1f", head->value1[i]);
				if (i != head->size - 1) fprintf(out_file, " ");
			}
			fprintf(out_file, ") + (");
			for (int i = 0; i < head->size; i++) {
				fprintf(out_file, "%.1f", head->value2[i]);
				if (i != head->size - 1) fprintf(out_file, " ");
			}
			fprintf(out_file, ") = (");
			for (int i = 0; i < head->size; i++) {
				fprintf(out_file, "%.1f", head->value1[i] + head->value2[i]);
				if (i != head->size - 1) fprintf(out_file, " ");
			}
			fprintf(out_file, ")");
			break;
		case '-':
			fprintf(out_file, "Result: (");
			for (int i = 0; i < head->size; i++) {
				fprintf(out_file, "%.1f", head->value1[i]);
				if (i != head->size - 1) fprintf(out_file, " ");
			}
			fprintf(out_file, ") - (");
			for (int i = 0; i < head->size; i++) {
				fprintf(out_file, "%.1f", head->value2[i]);
				if (i != head->size - 1) fprintf(out_file, " ");
			}
			fprintf(out_file, ") = (");
			for (int i = 0; i < head->size; i++) {
				fprintf(out_file, "%.1f", head->value1[i] - head->value2[i]);
				if (i != head->size - 1) fprintf(out_file, " ");
			}
			fprintf(out_file, ")");
			break;
		case '*':
			for (int i = 0; i < head->size; i++) {
				result += head->value1[i] * head->value2[i];
			}
			fprintf(out_file, "Result: (a, b) = %.1f", result);
			break;
	}
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *in_file, *out_file;

	in_file = fopen("input.txt", "r");
	out_file = fopen("output.txt", "w");

	element *head; // Creating the first list item
	head = (element*)malloc(sizeof(element));
	fscanf(in_file, "%c %c", &head->oper, &head->vect);
	if(head->vect == 'v') {
		fscanf(in_file, "%d", &head->size);
		head->value1 = malloc(head->size*sizeof(float));
		head->value2 = malloc(head->size*sizeof(float));
		for(int i = 0; i < head->size; i++){
			fscanf(in_file, "%f", &head->value1[i]);
		}
		for(int i = 0; i < head->size; i++){
			fscanf(in_file, "%f", &head->value2[i]);
		}
	}else{
		head->value1 = malloc(sizeof(float));
		head->value2 = malloc(sizeof(float));
		fscanf(in_file, "%f %f", head->value1, head->value2);
	}
	head->next = NULL;

	//=================================================================================

	pushBack(getLast(head), in_file); // Creating a list of commands

	element *out; // Creating a new item so as not to lose the beginning of the list
	out = head;
	while(out){
		if(out->vect == 'v'){	// If the operation with vectors, then calling the calculator for vectors
			vector_calculator_file(out_file, out);
		}else{	// If the operation with numbers, then we call the usual calculator
			regular_calculator_file(out_file, out);
		}
		out = out->next; // Moving on the list
		fprintf(out_file, "\n");
	}

	//=================================================================================

	fclose(in_file);
	fclose(out_file);

	//printList(head);	Printing the list to console

	return EXIT_SUCCESS;
}
