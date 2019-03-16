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

int main(void) {
	int a;
	int b;
	printf("Введите первое число: ");
	scanf("%d", &a);

	printf("Введите второе число: ");
	scanf("%d", &b);

	puts("1) \"+\" - сумма \n2) \"-\" - разность \n3) \"*\" - умножение \n4) \"/\" - деление \n5) \"!\" - факториал \n6) \"^\" - степень");
	printf("\n");
	puts("Выберите команду:");

	int k;
	scanf("%d", &k);
	if(k > 0 && k < 7) {
	printf("\n");

	int c;
	float d;
		switch(k) {
			case 1:
				c = a + b;
				printf("Результат: %d", c);
				break;
			case 2:
				c = a - b;
				printf("Результат: %d", c);
				break;
			case 3:
				c = a * b;
				printf("Результат: %d", c);
				break;
			case 4:
				d = a / b;
				printf("Результат: %f", d);
				break;
			case 5:
				c = 1;
				for(int i = 1; i < a; i++) c = c * i;
				printf("Результат: %d", c);
				break;
			case 6:
				for(int i = 1; i <= b; i++) {
					a = a * a;
				}
				printf("Результат: %d", a);
				break;
			default: printf("Неправльный ввод.\n");
		}
	}
	return EXIT_SUCCESS;
}
