#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcs.h"

// Реализовать операцию взятия остатка от деления на число используя битовые поля.
// Число передается через командную строку. Реализовать функции поиска и
// сортировки информации по одному из новых свойств.

// Использование встроенных/самописных динамических структур данных. Включая
// функции сортировки, поиска и тд.

// Обосновать выбор динамической структуры данных. Создание .log файлов

// Библиотека. Содержаться данные о книгах — id, название, год издания, автор,
// популярность(сколько раз читали).
// + Информация о книге дополнительно может содержать одно из трех свойств: жанр, тираж,
// рекомендуемый возраст. При входе запрашивать возраст пользователя. Создать функцию,
// которая будет рекомендовать к прочтению книги(возраст не должен совпадать полностью).

typedef union Fields
{
	unsigned int bits2: 1;
	unsigned int bits4: 2;
	unsigned int bits8: 3;
	unsigned int bits16: 4;
	unsigned int bits32: 5;
	unsigned int bits64: 6;
} fields;


int main()
{
	union Fields *p;
	int res2, res4, res8, res16, res32, res64;
	int value;
	printf("E n t e r   a   n u m b e r   t o   f i n d   t h e   r e s i d u e:\n\n\
P.S. Since the numbers in the bit fields are stored\n\
in the binary system, we can only find the remainder\n\
after dividing by multiples of 2 )))\n\n");
	value = inputInt();
	p = (fields*)&value;
	res2 = p->bits2;
	res4 = p->bits4;
	res8 = p->bits8;
	res16 = p->bits16;
	res32 = p->bits32;
	res64 = p->bits64;
	printf("Residue of the division:\n\
by 2 -  %d\n\
by 4 -  %d\n\
by 8 -  %d\n\
by 16 - %d\n\
by 32 - %d\n\
by 64 - %d\n", res2, res4, res8, res16, res32, res64);
	printf("\npress ENTER to continue...");
	getch();
	return 0;
}


//  // структура - битовое поле для вычисления остатка от деления на 2 
// struct BitField1  
// {  
//  unsigned int lastBit: 1; // младший (последний) бит числа 
// }; 

//  // структура - битовое поле для вычисления остатка от деления на 4 
// struct BitField2  
// {  
//  unsigned int bitCount: 2; // два младших (последних) бита числа 
// }; 

//  // объединение, содержащее переменные структур, описанных выше 
// union Fields 
// { 
//  struct BitField1 field1;  
//  struct BitField2 field2; 
// }; 

// int main()  
// {  
//  union Fields *pointer; 
//  int number, residue2, residue4; 
//  setlocale(LC_ALL,"russian"); 
//  printf("Введите число:\n"); 
//  scanf("%d",&number); 
//  // указателю pointer явно присваивается адрес переменной number 
//  pointer=(union Fields *)&number;
// system("cls");  
//  // присваивается значение lastBit (младшего бита числа)  
//  residue2=pointer->field1.lastBit;  
//  // присваивается значение bitCount (двух младших бит числа) 
//  residue4=pointer->field2.bitCount;  
//  printf("\nОстаток от деления на 2: %d\n",residue2); 
//  printf("\nОстаток от деления на 4: %d\n",residue4); 
//  return 0; 
// }