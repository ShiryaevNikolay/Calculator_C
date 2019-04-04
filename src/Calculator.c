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
			printf("\nРезультат: %f\n\n", a + b);
			break;
		case 2:
			printf("\nРезультат: %f\n\n", a - b);
			break;
		case 3:;
			printf("\nРезультат: %f\n\n", a * b);
			break;
		case 4:
			printf("\nРезультат: %f\n\n", a / b);
			break;
		case 5:
			c = 1;
			for(int i = 1; i <= a; i++) c = c * i;
			printf("\nРезультат: %f\n\n", c);
			break;
		case 6:
			if(b != 0){
				for(int i = 2; i < b; i++) {
					a = a * a;
				}
			}
			else {
				a = 1;
			}
			printf("\nРезультат: %f\n\n", a);
			break;
	}

	return EXIT_SUCCESS;
}

float vector_calculator() {
	int x1, y1, x2, y2, f;

	printf("Введите координаты первого вектора(a) x1 y1: ");
	scanf("%d %d", &x1, &y1);

	printf("Введите координаты второго вектора(b) x2 y2: ");
	scanf("%d %d", &x2, &y2);

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
			printf("\n(%d %d) + (%d %d) = (%d, %d)\n\n", x1, y1, x2, y2, x1+x2, y1+y2);
			break;
		case 2:
			printf("\n(%d %d) - (%d %d) = (%d, %d)\n\n", x1, y1, x2, y2, x1-x2, y1-y2);
			break;
		case 3:
			printf("\n|a|*|b|*cosA = %d\n\n", x1*x2 + y1*y2);
			break;
	}

	return EXIT_SUCCESS;
}

int main(void) {
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

		if (number == 1) regular_calculator();
		else vector_calculator();

		printf("Продолжить использовать калькулятор? \n1)Да - продолжить\n2)Нет - выйти\n");
		scanf("%d", &exit_from_calculator);
	}
	printf("EXIT");
	return 0;
}
