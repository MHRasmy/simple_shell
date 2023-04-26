#include <stdio.h>

/**
 * main - This code takes two numbers num1 & num2 and mutiplies them
 * Return: This code will always return 0
 */


int main(void)
{

	int num1, num2, result;

	printf("Enter the first number (num1): ");
	scanf("%d", &num1);
	printf("Enter the second number (num2): ");
	scanf("%d", &num2);

	result = num1 * num2;
	printf("The result of the multiplication is = %d", result);

	return (0);
}
