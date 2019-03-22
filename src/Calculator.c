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
	int a, b, f;
	f = 0;
	printf("Введите первое число: ");
	scanf("%d", &a);

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
		scanf("%d", &b);
	}

	int c;
	float d;
		switch(k) {
			case 1:
				c = a + b;
				printf("Результат: %d\n", c);
				break;
			case 2:
				c = a - b;
				printf("Результат: %d\n", c);
				break;
			case 3:
				c = a * b;
				printf("Результат: %d\n", c);
				break;
			case 4:
				d = a / b;
				printf("Результат: %f\n", d);
				break;
			case 5:
				c = 1;
				for(int i = 1; i <= a; i++) c = c * i;
				printf("Результат: %d\n", c);
				break;
			case 6:
				for(int i = 2; i <= b; i++) {
					a = a * a;
				}
				printf("Результат: %d\n", a);
				break;
			default: printf("Неправльный ввод.\n");
		}

	printf("\n");

	return EXIT_SUCCESS;
}
