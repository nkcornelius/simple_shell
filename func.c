#include "shell.h"

/**
  *_atoin - to a integer
  *@s: the string to convert
  *Return: integer
  **/

int _atoin(char *s)
{
	int nb = 0;
	int g;
	int i = 0;

	if (s[0] == '-')
	{
		g = -1;
		i = 1;
	}
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			nb = nb * 10 + (s[i] - '0');
			i++;
		}
		else
		{
			break;
		}
	}
	return (nb * g);
}

/**
  *_alphabet - chekcks if c an alphabet
  *
  *Return: 1 if yes 0 if no
  *
  *@c:the input character
  **/

int _alphabet(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

