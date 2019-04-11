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

float regular_calculator() {
	float a, b;
	int f = 0;
	printf("Введите первое число: ");
	scanf("%f", &a);

	int k;
	puts("1) \"+\" - сумма \n2) \"-\" - разность \n3) \"*\" - умножение \n4) \"/\" - деление \n5) \"!\" - факториал \n6) \"^\" - степень");
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

float vector_calculator() {
	int *x1 = NULL, *y1 = NULL, *x2 = NULL, *y2 = NULL, f;

	x1 = calloc(1,sizeof(int));
	y1 = calloc(1,sizeof(int));

	//printf("Введите координаты первого вектора(a) x1 y1: ");
	//scanf("%d %d", x1, y1);

	x2 = calloc(1,sizeof(int));
	y2 = calloc(1,sizeof(int));

	//printf("Введите координаты второго вектора(b) x2 y2: ");
	//scanf("%d %d", x2, y2);

	printf("(x, y) = (%d, %d)", *x1, *y1);

	int k;
	puts("  1) \"+\" - сумма \n  2) \"-\" - разность \n  3) \"*\" - скалярное произведение");
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

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FILE *in_file;
	char operation;

	in_file = fopen("input.txt", "r");

	fscanf(in_file, "%c", &operation);

	printf("%c", operation);

	fclose(in_file);

	printf("EXIT");
	return 0;
}
