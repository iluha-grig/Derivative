#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "code6_post.h"
#include "code6_pred.h"

char str[1000000];
char res[1000000];
int strl = 0, p = 0;

void findf(int, int);

void step1(int x, int y)
{
	char ss[100];
	int x1 = x + 1, y1, t = 1, k = x + 1, k2 = 0, st;
	while ((str[k] != ')') || (t != 1))
	{
		if (str[k] == '(')
			t++;
		if (str[k] == ')')
			t--;
		k++;
	}
	y1 = k - 1;
	k = y1 + 3;
	while (k <= y)
	{
		res[p++] = str[k];
		k++;
	}
	res[p++] = '*';
	res[p++] = '(';
	k = x1;
	while (k <= y1)
	{
		res[p++] = str[k];
		k++;
	}
	res[p++] = ')';
	res[p++] = '^';
	k = y1 + 3;
	for (; k <= y; k++)
	{
		ss[k2++] = str[k];
	}
	ss[k2] = '\0';
	st = atoi(ss);
	st--;
	sprintf(ss, "%d", st);
	for (k = 0; k < strlen(ss); k++)
	{
		res[p++] = ss[k];
	}
	res[p++] = '*';
	findf(x1, y1);
}

void step2(int x, int y)
{
	int x1 = x + 1, y1, k = x + 1, a = 0, b = 0, c, i = 0, t = 1;
	char ss[100];
	while ((str[k] != ')') || (t != 1))
	{
		if (str[k] == '(')
			t++;
		if (str[k] == ')')
			t--;
		k++;
	}
	y1 = k - 1;
	k = y1 + 4;
	while (str[k] != '/')
	{
		a = a * 10 + (str[k] - '0');
		k++;
	}
	k++;
	while (str[k] != ')')
	{
		b = b * 10 + (str[k] - '0');
		k++;
	}
	c = a - b;
	k = y1 + 3;
	while (k <= y)
	{
		res[p++] = str[k];
		k++;
	}
	res[p++] = '*';
	res[p++] = '(';
	k = x1;
	while (k <= y1)
	{
		res[p++] = str[k];
		k++;
	}
	res[p++] = ')';
	res[p++] = '^';
	if (c == 0)
	{
		res[p++] = '0';
		res[p++] = '*';
		findf(x1, y1);
	}
	else
	{
		res[p++] = '(';
		sprintf(ss, "%d", c);
		while (ss[i] != '\0')
		{
			res[p++] = ss[i];
			i++;
		}
		res[p++] = '/';
		i = 0;
		sprintf(ss, "%d", b);
		while (ss[i] != '\0')
		{
			res[p++] = ss[i];
			i++;
		}
		res[p++] = ')';
		res[p++] = '*';
		findf(x1, y1);
	}
}

void step3(int x, int y)
{
	int x1 = x + 1, y1, k = x + 1, t = 1, a = 0, i = 0;
	char ss[100];
	while ((str[k] != ')') || (t != 1))
	{
		if (str[k] == '(')
			t++;
		if (str[k] == ')')
			t--;
		k++;
	}
	y1 = k - 1;
	k = y1 + 3;
	while (k <= y)
	{
		res[p++] = str[k];
		k++;
	}
	res[p++] = '*';
	res[p++] = '(';
	k = x1;
	while (k <= y1 + 4)
	{
		res[p++] = str[k];
		k++;
	}
	while (str[k] != ')')
	{
		a = a * 10 + (str[k] - '0');
		k++;
	}
	a++;
	sprintf(ss, "%d", a);
	while (ss[i] != '\0')
	{
		res[p++] = ss[i];
		i++;
	}
	res[p++] = ')';
	res[p++] = '*';
	findf(x1, y1);
}

void step4(int x, int y)
{
	int x1 = x + 1, y1, k = x + 1, a = 0, b = 0, c, i = 0, t = 1;
	char ss[100];
	while ((str[k] != ')') || (t != 1))
	{
		if (str[k] == '(')
			t++;
		if (str[k] == ')')
			t--;
		k++;
	}
	y1 = k - 1;
	k = y1 + 5;
	while (str[k] != '/')
	{
		a = a * 10 + (str[k] - '0');
		k++;
	}
	k++;
	while (str[k] != ')')
	{
		b = b * 10 + (str[k] - '0');
		k++;
	}
	c = a + b;
	k = y1 + 3;
	while (k <= y)
	{
		res[p++] = str[k];
		k++;
	}
	res[p++] = '*';
	res[p++] = '(';
	k = x1;
	while (k <= y1)
	{
		res[p++] = str[k];
		k++;
	}
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '(';
	res[p++] = '-';
	sprintf(ss, "%d", c);
	while (ss[i] != '\0')
	{
		res[p++] = ss[i];
		i++;
	}
	res[p++] = '/';
	i = 0;
	sprintf(ss, "%d", b);
	while (ss[i] != '\0')
	{
		res[p++] = ss[i];
		i++;
	}
	res[p++] = ')';
	res[p++] = '*';
	findf(x1, y1);
}

void expon(int x, int y)
{
	for (int i = x - 4; i <= y + 1; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void logar(int x, int y)
{
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}
void sinf(int x, int y)
{
	res[p++] = 'c';
	res[p++] = 'o';
	res[p++] = 's';
	res[p++] = '(';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void cosf(int x, int y)
{
	res[p++] = '(';
	res[p++] = '-';
	res[p++] = 's';
	res[p++] = 'i';
	res[p++] = 'n';
	res[p++] = '(';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void tgf(int x, int y)
{
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	res[p++] = '(';
	res[p++] = 'c';
	res[p++] = 'o';
	res[p++] = 's';
	res[p++] = '(';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '2';
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void ctgf(int x, int y)
{
	res[p++] = '(';
	res[p++] = '-';
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	res[p++] = '(';
	res[p++] = 's';
	res[p++] = 'i';
	res[p++] = 'n';
	res[p++] = '(';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '2';
	res[p++] = ')';
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void asinf(int x, int y)
{
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '-';
	res[p++] = '(';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '2';
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	res[p++] = '2';
	res[p++] = ')';
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void acosf(int x, int y)
{
	res[p++] = '(';
	res[p++] = '-';
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '-';
	res[p++] = '(';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '2';
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	res[p++] = '2';
	res[p++] = ')';
	res[p++] = ')';
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void atgf(int x, int y)
{
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	res[p++] = '1';
	res[p++] = '+';
	res[p++] = '(';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '2';
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void actgf(int x, int y)
{
	res[p++] = '(';
	res[p++] = '-';
	res[p++] = '(';
	res[p++] = '1';
	res[p++] = '/';
	res[p++] = '1';
	res[p++] = '+';
	res[p++] = '(';
	for (int i = x; i <= y; i++)
	{
		res[p++] = str[i];
	}
	res[p++] = ')';
	res[p++] = '^';
	res[p++] = '2';
	res[p++] = ')';
	res[p++] = ')';
	res[p++] = '*';
	res[p++] = '(';
	findf(x, y);
	res[p++] = ')';
}

void xxx(void)
{
	res[p++] = '1';
}

void cons(void)
{
	res[p++] = '0';
}

int skob(int x, int y)
{
	int k = 0;
	for (int i = x; i <= y; i++)
	{
		if (str[i] == '(')
		{
			k++;
		}
		else if (str[i] == ')')
		{
			k--;
		}
		if ((k == 0) && (i != y))
		{
			return 0;
		}
	}
	return 1;
}

int stepcheck(int x, int y)
{
	int k = x, t = 0;
	if (str[k++] != '(')
	{
		return 0;
	}
	t = 1;
	while ((str[k] != ')') || (t != 1))
	{
		if (str[k] == '(')
			t++;
		if (str[k] == ')')
			t--;
		k++;
	}
	k++;
	if (str[k++] != '^')
	{
		return 0;
	}
	if (str[k] == '(')
	{
		k++;
		if (str[k] == '-')
		{
			k++;
			while (isdigit(str[k]))
			{
				k++;
			}
			if (str[k] == '/')
			{
				k++;
				while (isdigit(str[k]))
				{
					k++;
				}
				if ((str[k] != ')') || (k != y))
				{
					return 0;
				}
				return 4; //negative drob power
			}
			else if ((str[k] == ')') && (k == y))
			{
				return 3; //negative power
			}
			else
			{
				return 0;
			}
		}
		else
		{
			while (isdigit(str[k]))
			{
				k++;
			}
			if (str[k] == '/')
			{
				k++;
				while (isdigit(str[k]))
				{
					k++;
				}
				if ((str[k] != ')') || (k != y))
				{
					return 0;
				}
				return 2; //drob power
			}
			else if ((str[k] == ')') && (k == y))
			{
				return 1; //usual power
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		while (k <= y)
		{
			if (!isdigit(str[k]))
			{
				return 0;
			}
			k++;
		}
		return 1; //usual power
	}
}

int conscheckl(int x, int y)
{
	if (!isdigit(str[x]) && str[x] != '(')
	{
		return 0;
	}
	int flag = (str[x] == '(') ? -1 : 1;
	int i = x + 1;
	if (str[i] == '-')
	{
		i++;
	}
	if (flag == 1)
	{
		while (isdigit(str[i]))
		{
			i++;
		}
		if (str[i] == '*')
		{
			return flag;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		while (isdigit(str[i]) || str[i] == '/')
		{
			i++;
		}
		if (str[i] == ')' && str[i + 1] == '*')
		{
			return flag;
		}
		else
		{
			return 0;
		}
	}
}

int conscheckr(int x, int y)
{
	if (!isdigit(str[y]) && str[y] != ')')
	{
		return 0;
	}
	int flag = (str[y] == ')') ? -1 : 1;
	int i = y - 1;
	if (flag == 1)
	{
		while (isdigit(str[i]))
		{
			i--;
		}
		if (str[i] == '*')
		{
			return flag;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		while (isdigit(str[i]) || str[i] == '/')
		{
			i--;
		}
		if ((str[i] == '-') && (str[i - 1] == '(') && (str[i - 2] == '*'))
		{
			return flag;
		}
		else if (str[i] == '(' && str[i - 1] == '*')
		{
			return flag;
		}
		else
		{
			return 0;
		}
	}
}

int conscheckall(int x, int y)
{
	if (str[x] == '-')
	{
		x++;
	}
	for (int i = x; i <= y; i++)
	{
		if (!isdigit(str[i]) && str[i] != '/')
		{
			return 0;
		}
	}
	return 1;
}

int pluscheck(int x, int y)
{
	int flag = 0;
	for (int i = x; i <= y; i++)
	{
		if (str[i] == '(')
		{
			flag++;
			continue;
		}
		else if (str[i] == ')')
		{
			flag--;
			continue;
		}
		if ((flag == 0) && (str[i] == '+' || str[i] == '-'))
		{
			return i;
		}
	}
	return -1;
}

int mulcheck(int x, int y)
{
	int flag = 0;
	for (int i = x; i <= y; i++)
	{
		if (str[i] == '(')
		{
			flag++;
			continue;
		}
		else if (str[i] == ')')
		{
			flag--;
			continue;
		}
		if ((flag == 0) && (str[i] == '*'))
		{
			return i;
		}
	}
	return -1;
}

int delcheck(int x, int y)
{
	int flag = 0;
	for (int i = x; i <= y; i++)
	{
		if (str[i] == '(')
		{
			flag++;
			continue;
		}
		else if (str[i] == ')')
		{
			flag--;
			continue;
		}
		if ((flag == 0) && (str[i] == '/'))
		{
			return i;
		}
	}
	return -1;
}

int hardstepcheck(int x, int y)
{
	int flag = 1, k = x, k1;
	if (str[k++] != '(')
	{
		return -1; //no step
	}
	for (; k <= y; k++)
	{
		if (str[k] == '(')
		{
			flag++;
		}
		else if (str[k] == ')')
		{
			flag--;
		}
		if (flag == 0)
		{
			break;
		}
	}
	k1 = k++;
	flag = 0;
	if (str[k++] != '^')
	{
		return -1;
	}
	if (str[k] == '(')
	{
		for (; k <= y; k++)
		{
			if (str[k] == '(')
			{
				flag++;
			}
			else if (str[k] == ')')
			{
				flag--;
			}
			if (flag == 0)
			{
				break;
			}
		}
		if (flag == 0 && k == y)
		{
			return k1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		for (; k <= y; k++)
		{
			if ((str[k] == '+') || (str[k] == '-') || (str[k] == '*') || (str[k] == '/') || (str[k] == '^'))
			{
				return -1;
			}
		}
		return k1;
	}
}

void findf(int x, int y)
{
	if ((str[x] == '(') && (str[y] == ')') && (skob(x, y)))
	{
		findf(x + 1, y - 1);
		return;
	}
	if ((isdigit(str[x])) && (str[x + 1] == '*'))
	{
		res[p++] = str[x];
		res[p++] = str[x + 1];
		if (str[x + 2] == '(' && skob(x + 2, y) != 0)
		{
			res[p++] = str[x + 2];
		}
		findf(x + 2, y);
		if (str[x + 2] == '(' && skob(x + 2, y) != 0)
		{
			res[p++] = ')';
		}
		return;
	}
	if ((isdigit(str[y])) && (str[y - 1] == '*') && (pluscheck(x, y) == -1))
	{
		res[p++] = str[y];
		res[p++] = str[y - 1];
		if (str[y - 2] == ')' && skob(x, y - 2) != 0)
		{
			res[p++] = '(';
		}
		findf(x, y - 2);
		if (str[y - 2] == ')' && skob(x, y - 2) != 0)
		{
			res[p++] = ')';
		}
		return;
	}
	if ((str[x] == str[y]) && (str[x] == 'x') && (x == y))
	{
		xxx();
		return;
	}
	if ((str[x] == str[y]) && (isdigit(str[x])) && (x == y))
	{
		cons();
		return;
	}
	if (conscheckall(x, y))
	{
		cons();
		return;
	}
	if (conscheckl(x, y))
	{
		int i = x;
		while (str[i] != '*')
		{
			res[p++] = str[i];
			i++;
		}
		res[p++] = '*';
		if (str[i + 1] == '(' && skob(i + 1, y) != 0)
		{
			res[p++] = '(';
		}
		findf(i + 1, y);
		if (str[i + 1] == '(' && skob(i + 1, y) != 0)
		{
			res[p++] = ')';
		}
		return;
	}
	if ((conscheckr(x, y)) && (pluscheck(x, y) == -1))
	{
		int i = y, j;
		while (str[i] != '*')
		{
			i--;
		}
		j = i - 1;
		i++;
		while (i <= y)
		{
			res[p++] = str[i];
			i++;
		}
		res[p++] = '*';
		if (str[j] == ')' && skob(x, j) != 0)
		{
			res[p++] = '(';
		}
		findf(x, j);
		if (str[j] == ')' && skob(x, j) != 0)
		{
			res[p++] = ')';
		}
		return;
	}
	int t = stepcheck(x, y);
	if (t == 1)
	{
		step1(x, y);
		return;
	}
	if (t == 2)
	{
		step2(x, y);
		return;
	}
	if (t == 3)
	{
		step3(x, y);
		return;
	}
	if (t == 4)
	{
		step4(x, y);
		return;
	}
	if ((str[x] == 'e') && (str[x + 1] == 'x') && (str[x + 2] == 'p') && (str[y] == ')') && (skob(x + 3, y)))
	{
		expon(x + 4, y - 1);
		return;
	}
	if ((str[x] == 'l') && (str[x + 1] == 'n') && (str[y] == ')') && (skob(x + 2, y)))
	{
		logar(x + 3, y - 1);
		return;
	}
	if ((str[x] == 's') && (str[x + 1] == 'i') && (str[x + 2] == 'n') && (str[y] == ')') && (skob(x + 3, y)))
	{
		sinf(x + 4, y - 1);
		return;
	}
	if ((str[x] == 'c') && (str[x + 1] == 'o') && (str[x + 2] == 's') && (str[y] == ')') && (skob(x + 3, y)))
	{
		cosf(x + 4, y - 1);
		return;
	}
	if ((str[x] == 't') && (str[x + 1] == 'g') && (str[y] == ')') && (skob(x + 2, y)))
	{
		tgf(x + 3, y - 1);
		return;
	}
	if ((str[x] == 'c') && (str[x + 1] == 't') && (str[x + 2] == 'g') && (str[y] == ')') && (skob(x + 3, y)))
	{
		ctgf(x + 4, y - 1);
		return;
	}
	if ((str[x] == 'a') && (str[x + 1] == 's') && (str[x + 2] == 'i') && (str[x + 3] == 'n') && (str[y] == ')') && (skob(x + 4, y)))
	{
		asinf(x + 5, y - 1);
		return;
	}
	if ((str[x] == 'a') && (str[x + 1] == 'c') && (str[x + 2] == 'o') && (str[x + 3] == 's') && (str[y] == ')') && (skob(x + 4, y)))
	{
		acosf(x + 5, y - 1);
		return;
	}
	if ((str[x] == 'a') && (str[x + 1] == 't') && (str[x + 2] == 'g') && (str[y] == ')') && (skob(x + 3, y)))
	{
		atgf(x + 4, y - 1);
		return;
	}
	if ((str[x] == 'a') && (str[x + 1] == 'c') && (str[x + 2] == 't') && (str[x + 3] == 'g') && (str[y] == ')') && (skob(x + 4, y)))
	{
		actgf(x + 5, y - 1);
		return;
	}
	int hsc = hardstepcheck(x, y);
	if (hsc != -1)
	{
		for (int i = x; i <= y; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = '*';
		res[p++] = '(';
		res[p++] = '(';
		findf(hsc + 2, y);
		res[p++] = ')';
		res[p++] = '*';
		res[p++] = 'l';
		res[p++] = 'n';
		res[p++] = '(';
		for (int i = x + 1; i < hsc; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = ')';
		res[p++] = '+';
		res[p++] = '(';
		for (int i = hsc + 2; i <= y; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = '/';
		for (int i = x + 1; i < hsc; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = ')';
		res[p++] = '*';
		res[p++] = '(';
		findf(x + 1, hsc - 1);
		res[p++] = ')';
		res[p++] = ')';
		return;
	}
	int plc = pluscheck(x, y);
	if (plc != -1)
	{
		findf(x, plc - 1);
		res[p++] = str[plc];
		findf(plc + 1, y);
		return;
	}
	int mlc = mulcheck(x, y);
	if (mlc != -1)
	{
		res[p++] = '(';
		if (str[mlc - 1] == ')')
		{
			res[p++] = '(';
		}
		findf(x, mlc - 1);
		if (str[mlc - 1] == ')')
		{
			res[p++] = ')';
		}
		res[p++] = '*';
		for (int i = mlc + 1; i <= y; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = '+';
		for (int i = x; i <= mlc - 1; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = '*';
		if (str[mlc + 1] == '(')
		{
			res[p++] = '(';
		}
		findf(mlc + 1, y);
		if (str[mlc + 1] == '(')
		{
			res[p++] = ')';
		}
		res[p++] = ')';
		return;
	}
	int dlc = delcheck(x, y);
	if (dlc != -1)
	{
		res[p++] = '(';
		res[p++] = '(';
		if (str[dlc - 1] == ')')
		{
			res[p++] = '(';
		}
		findf(x, dlc - 1);
		if (str[dlc - 1] == ')')
		{
			res[p++] = ')';
		}
		res[p++] = '*';
		for (int i = dlc + 1; i <= y; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = '-';
		for (int i = x; i <= dlc - 1; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = '*';
		if (str[dlc + 1] == '(')
		{
			res[p++] = '(';
		}
		findf(dlc + 1, y);
		if (str[dlc + 1] == '(')
		{
			res[p++] = ')';
		}
		res[p++] = ')';
		res[p++] = '/';
		res[p++] = '(';
		for (int i = dlc + 1; i <= y; i++)
		{
			res[p++] = str[i];
		}
		res[p++] = ')';
		res[p++] = '^';
		res[p++] = '2';
		res[p++] = ')';
		return;
	}
}

int main(void)
{
	char c = 0;
	int i = 0, reslen = 0, reslennew;
	printf("Input your function...\n");
	while ((c = getchar()) != '\n')
	{
		str[i++] = c;
	}
	str[i] = '\0';

	if (skobcheck(str) != 0)
	{
		fprintf(stderr, "Error: Problems with parentheses!\n");
		exit(1);
	}
	if (delzero(str) != 0)
	{
		fprintf(stderr, "Error: Division by zero!\n");
		exit(1);
	}
	if (dotcheck(str) != 0)
	{
		fprintf(stderr, "Error: No floating point numbers! Use rational fractions.\n");
		exit(1);
	}
	delspace(str);

	strl = strlen(str);
	findf(0, strl - 1);
	res[p] = '\0';
	if (strlen(res) == 0)
	{
		fprintf(stderr, "Error: Incorrect function!\n");
		exit(1);
	}

	skobcorrect(res);
	skobcorrect2(res);
	reslennew = strlen(res);
	while (reslen != reslennew)
	{
		step0(res);
		step1_post(res);
		reslen = reslennew;
		reslennew = strlen(res);
	}
	skobcorrect(res);
	skobcorrect2(res);
	reslen = 0;
	while (reslen != reslennew)
	{
		xdelx(res);
		skob0(res);
		mul1(res);
		muldel0(res);
		skob0(res);
		mul0r(res);
		mul0l(res);
		skob0(res);
		plus0(res);
		step0(res);
		step1_post(res);
		onestep(res);
		reslen = reslennew;
		reslennew = strlen(res);
	}
	skobcorrect(res);
	skobcorrect2(res);

	printf("%s\n", res);
	return 0;
}
