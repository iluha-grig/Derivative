#include <string.h>

int skobcheck(char *s)
{
	int count = 0, len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			count++;
		}
		else if (s[i] == ')')
		{
			count--;
		}
		if (count < 0)
		{
			return 1;
		}
	}
	return count; //0 is OK
}

void delspace(char *s)
{
	int len = strlen(s), k = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}

int delzero(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] == '/' && s[i + 1] == '0')
		{
			return 1;
		}
	}
	return 0;
}

int dotcheck(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '.')
		{
			return 1;
		}
	}
	return 0;
}
