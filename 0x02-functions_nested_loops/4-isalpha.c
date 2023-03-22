#include "main.h"

/**
  * File: 3-islower.c
  * _isalpha - a function that checks for alphabetic character.
  * c parameter  is a letter, lowercase or uppercase.
  * Returns 1 if c is a lowercase or uppercase returns 0 otherwise.
  */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
	return (1);
}
else
{
	return (0);
}
}
