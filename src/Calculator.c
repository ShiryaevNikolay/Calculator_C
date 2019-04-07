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
	/* Документация:
	 	 	 a - червое число
	 	 	 b - второе число
	 	 	 c - результат выполнения операций */

	float a, b;
	printf("Введите первое число: ");
	scanf("%f", &a);
	//==================================================================================================================================================================
	int k, f = 0;																																// Выбираем
	puts("1) \"+\" - сумма \n2) \"-\" - разность \n3) \"*\" - умножение \n4) \"/\" - деление \n5) \"!\" - факториал \n6) \"^\" - степень");		// арифметическую
	printf("Выберите команду: ");																												// операцию и проверяем,
	scanf("%d", &k);																															// существует ли она
	while(f == 0) {																																//
		if(k > 0 && k < 7)																														//
			f = 1;																																//
		else {																																	//
			printf("Нет такой команды. Введите команду из списка: ");																			//
			scanf("%d", &k);																													//
		}																																		//
	}																																			//
	//==================================================================================================================================================================
	if(k != 5) {								// Если выбрана
		printf("Введите второе число: ");		// операция "факториал",
		scanf("%f", &b);						// то второе число не нужно
	}											//
	//=====================================================================
	float c;
	switch(k) {
		case 1:			// Сумма
			printf("\nРезультат: %.2f\n\n", a + b);
			break;
		case 2:			// Разность
			printf("\nРезультат: %.2f\n\n", a - b);
			break;
		case 3:			// Умножение
			printf("\nРезультат: %.2f\n\n", a * b);
			break;
		case 4:			// Деление
			printf("\nРезультат: %.2f\n\n", a / b);
			break;
		case 5:			// Факториал
			c = 1;
			for(int i = 1; i <= a; i++) c = c * i;
			printf("\nРезультат: %.2f\n\n", c);
			break;
		case 6:			// Возведение в степень
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
	int *x1 = NULL, *y1 = NULL, *x2 = NULL, *y2 = NULL, f, size;

	printf("Введите кол-во ячеек памяти для одной координаты: ");
	scanf("%d", &size);

	x1 = calloc(size,sizeof(int));
	y1 = calloc(size,sizeof(int));

	printf("Введите координаты первого вектора(a) x1 y1: ");
	scanf("%d %d", x1, y1);

	x2 = calloc(size,sizeof(int));
	y2 = calloc(size,sizeof(int));

	printf("Введите координаты второго вектора(b) x2 y2: ");
	scanf("%d %d", x2, y2);
	//===========================================================================================================================
	int k;																						// Выбор
	puts("  1) \"+\" - сумма \n  2) \"-\" - разность \n  3) \"*\" - скалярное произведение");	// операции
	printf("Выберите команду: ");																// над
	scanf("%d", &k);																			// векторами
	//===========================================================================================================================
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
		case 1:					// Сумма
			printf("\n(%d %d) + (%d %d) = (%d, %d)\n\n", *x1, *y1, *x2, *y2, (*x1)+(*x2), (*y1)+(*y2));
			break;
		case 2:					// Разность
			printf("\n(%d %d) - (%d %d) = (%d, %d)\n\n", *x1, *y1, *x2, *y2, (*x1)-(*x2), (*y1)-(*y2));
			break;
		case 3:					// Скалярное произведение
			printf("\n(a,b) = %d\n\n", (*x1) * (*x2) + (*y1) * (*y2));
			break;
	}
	//====================================================
	free(x1);				// Освобождение
	free(y1);				// памяти
	free(x2);				//
	free(y2);				//
	//====================================================
	return EXIT_SUCCESS;
}

int main(void) {
	int exit_from_calculator = 1;

	while (exit_from_calculator == 1) {
		puts("Введите номер калькулятора.");
		printf("  1) Работа с обычными числами.\n  2) Работа с векторами.\n  3) Выйти из калькулятора.\n");

		int number, f;
		f = 0;
		//==============================================================================================================================
		while (f == 0) {																								// Проверяем,
			scanf("%d", &number);																						// есть ли
			if (number > 0 && number < 4) f = 1;																		// такая команда
			else {																										//
				printf("Такой команды нет. Выберите команду из списка:\n");												//
				printf("  1) Работа с обычными числами.\n  2) Работа с векторами.\n  3) Выйти из калькулятора.\n");		//
			}																											//
		}																												//
		//==============================================================================================================================
		if (number == 3) break;	// Выход из программы
		else	//=====================================================
			if (number == 1) regular_calculator();		// Выбор
			else vector_calculator();					// Калькулятора
		//=============================================================

		printf("Продолжить использовать калькулятор? \n  1)Продолжить\n  2)Выйти\n");
		scanf("%d", &exit_from_calculator);
	}
	printf("EXIT");
	return 0;
}
