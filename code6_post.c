#include <string.h>
#include <ctype.h>

void del(char *s, int l, int r)
{
	int k = 0, len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (i != l && i != r)
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}


void skobcorrect(char *s)
{
	int flag = 0, k = 0, lpos = 0, len = strlen(s);
	char skob[1000];
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			skob[k++] = i;
			flag = 0;
		}
		else if (s[i] == ')' && flag == 0)
		{
			flag = 1;
			k--;
			lpos = skob[k];
		}
		else if (s[i] == ')' && flag == 1)
		{
			k--;
			if ((lpos - skob[k]) == 1)
			{
				del(s, skob[k], i);
				skobcorrect(s);
				return;
			}
			else
			{
				lpos = skob[k];
			}
		}
		else
		{
			flag = 0;
		}
	}
}

void skobcorrect2(char *s)
{
	int len = strlen(s), flag = 0;
	if (s[0] == '(' && s[len - 1] == ')')
	{
		for (int i = 1; i < len - 1; i++)
		{
			if (s[i] == '(')
			{
				flag++;
			}
			else if (s[i] == ')')
			{
				flag--;
			}
			if (flag < 0)
			{
				break;
			}
		}
		if (flag == 0)
		{
			s[len - 1] = '\0';
			for (int i = 0; i < len - 1; i++)
			{
				s[i] = s[i + 1];
			}
		}
	}
}

void mul1(char *s)
{
	int len = strlen(s), k = 0;
	if (s[len - 1] == '*')
	{
		s[len - 1] = '\0';
		len--;
	}
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '*') && (s[i + 1] == '1') && ((i == len - 1) || (s[i + 2] == '*') || (s[i + 2] == '+') || (s[i + 2] == '-') || (s[i + 2] == '/') || (s[i + 2] == ')') || (s[i + 2] == '\0')))
		{
			i++;
			continue;
		}
		else
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
	len = strlen(s);
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '1') && (s[i + 1] == '*') && ((i == 0) || (s[i - 1] == '*') || (s[i - 1] == '+') || (s[i - 1] == '-') || (s[i - 1] == '(') || (s[i - 1] == '/')))
		{
			i++;
			continue;
		}
		else
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}

void del0(char *s, int i)
{
	int len = strlen(s), r = 0, l = 0, j = i, flag = 0, k = 0;
	while ((((j >= 0) && (s[j] != '+') && (s[j] != '-')) || ((flag != 0) && (j >= 0))) && (flag >= 0))
	{
		if (s[j] == ')')
		{
			flag++;
		}
		else if (s[j] == '(')
		{
			flag--;
		}
		j--;
	}
	if (flag < 0)
	{
		l = j + 2;
	}
	else
	{
		l = j + 1;
	}
	j = i;
	flag = 0;
	while ((((j < len) && (s[j] != '+') && (s[j] != '-')) || ((flag != 0) && (j < len))) && (flag >= 0))
	{
		if (s[j] == '(')
		{
			flag++;
		}
		else if (s[j] == ')')
		{
			flag--;
		}
		j++;
	}
	if (flag < 0)
	{
		r = j - 2;
	}
	else
	{
		r = j - 1;
	}
	for (int i = 0; i < len; i++)
	{
		if (i == l)
		{
			s[k++] = '0';
			continue;
		}
		if (i > l && i <= r)
		{
			continue;
		}
		s[k++] = s[i];
	}
	s[k] = '\0';
}	

void mul0r(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '*' && s[i + 1] == '0')
		{
			del0(s, i);
			mul0r(s);
			return;
		}
	}
}

void mul0l(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '0') && (s[i + 1] == '*') && ((i == 0) || (!isdigit(s[i - 1]))))
		{
			del0(s, i + 1);
			mul0l(s);
			return;
		}
	}
}

void muldel0(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '0') && (s[i + 1] == '/') && (!isdigit(s[i - 1])))
		{
			del0(s, i + 1);
			muldel0(s);
			return;
		}
	}
}

void skob0(char *s)
{
	int len = strlen(s), k = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(' && s[i + 2] == ')')
		{
			s[k++] = s[i + 1];
			i += 2;
			continue;
		}
		else
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}

void plus0(char *s)
{
	int len = strlen(s), k = 0;
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '+' || s[i] == '-') && (s[i + 1] == '0'))
		{
			i++;
			continue;
		}
		else
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
	len = strlen(s);
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '0') && (s[i + 1] == '+') && (i == 0 || !isdigit(s[i - 1])))
		{
			i++;
			continue;
		}
		else if ((s[i] == '0') && (s[i + 1] == '-') && (i == 0 || !isdigit(s[i - 1])))
		{
			continue;
		}
		else
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}

void xdelx(char *s)
{
	int len = strlen(s), k = 0;
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == 'x') && (s[i + 1] == '/') && (s[i + 2] == 'x') && (i == 0 || !isalnum(s[i - 1])) && (!isalnum(s[i + 3])))
		{
			s[k++] = '1';
			i += 2;
			continue;
		}
		else
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}

void step1_post(char *s)
{
	int len = strlen(s), k = 0;
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '^') && (s[i + 1] == '1') && (!isdigit(s[i + 2])))
		{
			i++;
			continue;
		}
		else
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}

void delstep0(char *s, int p)
{
	int len = strlen(s), k = 0, flag = 1, i, r, l;
	for (i = p - 2; flag != 0; i--)
	{
		if (s[i] == ')')
		{
			flag++;
		}
		else if (s[i] == '(')
		{
			flag--;
		}
	}
	l = i + 1;
	r = p + 1;
	for (int i = 0; i < len; i++)
	{
		if (i == l)
		{
			s[i] = '1';
			k++;
			continue;
		}
		if (i > l && i <= r)
		{
			continue;
		}
		s[k++] = s[i];
	}
	s[k] = '\0';
}

void step0(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '^' && s[i + 1] == '0')
		{
			delstep0(s, i);
			step0(s);
			return;
		}
	}
}

void onestep(char *s)
{
	int len = strlen(s), k = 0, flag = 0, flag2 = 0;
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == '1') && (s[i + 1] == '^') && (i == 0 || !isdigit(s[i - 1])) && (!flag2))
		{
			s[k++] = '1';
			flag2 = 1;
			continue;
		}
		else if (flag2)
		{
			if (s[i] == '(')
			{
				flag++;
			}
			else if (s[i] == ')')
			{
				flag--;
			}
			else if (((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/')) && (flag == 0))
			{
				s[k++] = s[i];
				flag2 = 0;
				continue;
			}
			if (flag < 0)
			{
				s[k++] = s[i];
				flag2 = 0;
				flag = 0;
				continue;
			}
		}
		else
		{
			s[k++] = s[i];
		}
	}
	s[k] = '\0';
}

