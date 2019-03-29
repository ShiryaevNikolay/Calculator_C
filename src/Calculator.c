/*
 ============================================================================
 Name        : Calculator.c
 Author      : Shiryaev
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
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
			printf("Результат: %f", a + b);
			break;
		case 2:
			printf("Результат: %f", a - b);
			break;
		case 3:;
			printf("Результат: %f", a * b);
			break;
		case 4:
			printf("Результат: %f", a / b);
			break;
		case 5:
			c = 1;
			for(int i = 1; i <= a; i++) c = c * i;
			printf("Результат: %f", c);
			break;
		case 6:
			if(b != 0){
				for(int i = 2; i <= b; i++) {
					a = a * a;
				}
			}
			else {
				a = 1;
			}
			printf("Результат: %f", a);
			break;
		default: printf("Неправльный ввод.\n");
	}

	return EXIT_SUCCESS;
}

float vector_calculator() {
	int x1, y1, x2, y2, f;
	/*if (x1 != NULL) x1 = calloc(1,sizeof(float));
	if (x1 != NULL) y1 = calloc(1,sizeof(float));
	if (x1 != NULL) x2 = calloc(1,sizeof(float));
	if (x1 != NULL) y2 = calloc(1,sizeof(float));
	*/
	printf("Введите координаты первого вектора(a) x1 y1: ");
	scanf("%d %d", &x1, &y1);

	printf("Введите координаты второго вектора(b) x2 y2: ");
	scanf("%d %d", &x2, &y2);

	int k;
	puts("1) \"+\" - сумма \n2) \"-\" - разность \n3) \"*\" - скалярное произведение");
	printf("Выберите команду: ");
	scanf("%d", &k);

	f = 0;
	while(f == 0) {
		if(k > 0 && k < 4)
			f = 1;
		else {
			printf("Нет такой команды. Введите команду из списка: ");
			scanf("%d", &k);
		}
	}

	switch(k) {
		case 1:
			printf("(%d %d) + (%d %d) = (%d, %d)", x1, y1, x2, y2, x1+x2, y1+y2);
			break;
		case 2:
			printf("(%d %d) - (%d %d) = (%d, %d)", x1, y1, x2, y2, x1-x2, y1-y2);
			break;
		case 3:
			printf("|a|*|b|*cosA = %d", x1*x2 + y1*y2);
			break;
	}

	return EXIT_SUCCESS;
}

int main(void) {
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

	return 0;
}
