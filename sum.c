#include "shell.h"
/**
 * add_numbers - Adds two numbers.
 * @c: The first number.
 * @d: The second number.
 *
 * Return: The sum of the two numbers.
 */
int add_numbers(int c, int d)
{
	return (c + d);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int num1 = 30;
	int num2 = 45;
	int sum;

	sum = add_numbers(num1, num2);
	printf("The sum of %d and %d is %d\n", num1, num2, sum);
	return (0);
}
