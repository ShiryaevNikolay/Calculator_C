/*
 ============================================================================
 Name        : Calculator.c
 Author      : Shiryaev Nikolay
 Version     :
 Copyright   : Your copyright notice
 Description : Calculator in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float regular_calculator_keyboard() {
	float a, b;
	int f = 0;
	printf("Введите первое число: ");
	scanf("%f", &a);

	int k;
	puts("    1) \"+\" - сумма\n    2) \"-\" - разность\n    3) \"*\" - умножение\n    4) \"/\" - деление\n    5) \"!\" - факториал\n    6) \"^\" - степень");
	printf("Выберите команду: ");
	scanf("%d", &k);
	while(f == 0) {
		if(k > 0 && k < 7)
			f = 1;
		else {
			printf("Нет такой команды. Введите команду из списка: ");
			scanf("%d", &k);
		}
	}
	if(k != 5) {
		printf("Введите второе число: ");
		scanf("%f", &b);
	}

	float c;
	switch(k) {
		case 1:
			printf("\nРезультат: %.2f\n\n", a + b);
			break;
		case 2:
			printf("\nРезультат: %.2f\n\n", a - b);
			break;
		case 3:;
			printf("\nРезультат: %.2f\n\n", a * b);
			break;
		case 4:
			printf("\nРезультат: %.2f\n\n", a / b);
			break;
		case 5:
			c = 1;
			for(int i = 1; i <= a; i++) c = c * i;
			printf("\nРезультат: %.2f\n\n", c);
			break;
		case 6:
			c = a;
			if(b != 0){
				for(int i = 1; i < b; i++) {
					a = a * c;
				}
			}
			else {
				a = 1;
			}
			printf("\nРезультат: %.2f\n\n", a);
			break;
	}

	return EXIT_SUCCESS;
}

float vector_calculator_keyboard() {
	int *x1 = NULL, *y1 = NULL, *x2 = NULL, *y2 = NULL, f, size;

	printf("Введите кол-во ячеек памяти для одной координаты: ");
	scanf("%d", &size);

	x1 = calloc(size,sizeof(int));
	y1 = calloc(size,sizeof(int));

	printf("Введите координаты первого вектора(a) x1 y1: ");
	scanf("%d %d", x1, y1);

	x2 = calloc(size,sizeof(int));
	y2 = calloc(size,sizeof(int));

	printf("Введите координаты первого вектора(a) x2 y2: ");
	scanf("%d %d", x2, y2);

	int k;
	puts("    1) \"+\" - сумма\n    2) \"-\" - разность\n    3) \"*\" - скалярное произведение");
	printf("Выберите команду: ");
	scanf("%d", &k);

	f = 0;
	while(f == 0) {
		if(k > 0 && k < 4){
			f = 1;
		}
		else {
			printf("Нет такой команды! Введите команду из списка: ");
			scanf("%d", &k);
		}
	}

	switch(k) {
		case 1:
			printf("\n(%d %d) + (%d %d) = (%d, %d)\n\n", *x1, *y1, *x2, *y2, (*x1)+(*x2), (*y1)+(*y2));
			break;
		case 2:
			printf("\n(%d %d) - (%d %d) = (%d, %d)\n\n", *x1, *y1, *x2, *y2, (*x1)-(*x2), (*y1)-(*y2));
			break;
		case 3:
			printf("\n(a,b) = %d\n\n", (*x1) * (*x2) + (*y1) * (*y2));
			break;
	}
	free(x1);
	free(y1);
	free(x2);
	free(y2);

	return EXIT_SUCCESS;
}

float regular_calculator_file(FILE *in_file, FILE *out_file, char k) {
	float *a = NULL, *b = NULL;

	a = calloc(4, sizeof(float));
	b = calloc(4, sizeof(float));

	fscanf(in_file, "%f", a);
	fscanf(in_file, "%f", b);

	float c;
	switch(k) {
		case '+':
			fprintf(out_file, "\nРезультат: %.2f\n\n", (*a) + (*b));
			break;
		case '-':
			fprintf(out_file, "\nРезультат: %.2f\n\n", (*a) - (*b));
			break;
		case '*':
			fprintf(out_file, "\nРезультат: %.2f\n\n", (*a) * (*b));
			break;
		case '/':
			fprintf(out_file, "\nРезультат: %.2f\n\n", (*a) / (*b));
			break;
		case '!':
			c = 1;
			for(int i = 1; i <= (*a); i++) c = c * i;
			fprintf(out_file, "\nРезультат: %.2f\n\n", c);
			break;
		case '^':
			c = *a;
			if((*b) != 0){
				for(int i = 1; i < (*b); i++) {
					(*a) = (*a) * c;
				}
			}
			else {
				*a = 1;
			}
			fprintf(out_file, "\nРезультат: %.2f\n\n", *a);
			break;
	}

	free(a);
	free(b);

	return EXIT_SUCCESS;
}

float vector_calculator_file(FILE *in_file, FILE *out_file, char k) {
	int *x1 = NULL, *y1 = NULL, *x2 = NULL, *y2 = NULL;
	int coordinates, size;
	x1 = calloc(4,sizeof(int));
	y1 = calloc(4,sizeof(int));
	x2 = calloc(4,sizeof(int));
	y2 = calloc(4,sizeof(int));

	fscanf(in_file, " %d", &size);

	for (int i = 0; i < size; i++) {
		fscanf(in_file, "%d", &coordinates);
		switch(i) {
			case 0:
				*x1 = coordinates;
				break;
			case 1:
				*y1 = coordinates;
				break;

		}
	}
	for (int i = 0; i < size; i++) {
		fscanf(in_file, "%d", &coordinates);
		switch(i) {
			case 0:
				*x2 = coordinates;
				break;
			case 1:
				*y2 = coordinates;
				break;

		}
	}

	switch(k) {
		case '+':
			fprintf(out_file, "\n(%d %d) + (%d %d) = (%d, %d)\n\n", *x1, *y1, *x2, *y2, (*x1)+(*x2), (*y1)+(*y2));
			break;
		case '-':
			fprintf(out_file, "\n(%d %d) - (%d %d) = (%d, %d)\n\n", *x1, *y1, *x2, *y2, (*x1)-(*x2), (*y1)-(*y2));
			break;
		case '*':
			fprintf(out_file, "\n(a,b) = %d\n\n", (*x1) * (*x2) + (*y1) * (*y2));
			break;
	}
	free(x1);
	free(y1);
	free(x2);
	free(y2);


	return EXIT_SUCCESS;
}

int calc_keyboard() {
	int exit_from_calculator = 1;

	while (exit_from_calculator == 1) {
		puts("Введите номер калькулятора.");
		printf("  1) Работа с обычными числами.\n  2) Работа с векторами.\n");
		int number, f;
		f = 0;
		while (f == 0) {
			scanf("%d", &number);
			if (number > 0 && number < 3) f = 1;
			else {
				printf("Такой команды нет. Выберите команду из списка:\n");
				printf("  1) Работа с обычными числами.\n  2) Работа с векторами.\n");
			}
		}

		if (number == 1) regular_calculator_keyboard();
		else vector_calculator_keyboard();

		printf("Продолжить использовать калькулятор? \n1)Да - продолжить\n2)Нет - выйти\n");
		scanf("%d", &exit_from_calculator);
	}
	printf("EXIT");
	return 0;
}

int calc_file() {
	FILE *in_file, *out_file;
	in_file = fopen("input.txt", "r");
	out_file = fopen("output.txt", "w");

	char operation, calc;

	fscanf(in_file, "%c %c", &operation, &calc);
	if (calc == 's') regular_calculator_file(in_file, out_file, operation);
	else vector_calculator_file(in_file, out_file, operation);

	fclose(in_file);
	fclose(out_file);
	return EXIT_SUCCESS;
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int k;
	printf("Как вы хотите использовать калькулятор:\n	1) Ввод с клавиатуры\n	2) Работа с файлами\n");
	//scanf("%d", &k);
	while (1 == 1) {
		scanf("%d", &k);
		if (k > 0 && k < 3) break;
		else
			printf("Такой команды нет. Введите команду из списка");
	}

	if (k == 1) calc_keyboard();
	else
		calc_file();

	printf("EXIT");
	return 0;
}
