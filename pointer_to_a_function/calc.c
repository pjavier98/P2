#include <stdio.h>

void calc(double (*f)(double, double), double num1, double num2)
{
	printf("%.2lf\n", (*f)(num1, num2));
}

double soma(double n1, double n2)
{
	return n1 + n2;
}

double subt(double n1, double n2)
{
	return n1 - n2;
}

double mult(double n1, double n2)
{
	return n1 * n2;
}

double div(double n1, double n2)
{
	return n1 / n2;
}

int main()
{
	double num1, num2;
	char operacao;

	scanf("%c", &operacao);
	scanf("%lf %lf", &num1, &num2);

	if (operacao == '+')
	{
		calc(soma, num1, num2);
	}

	else if (operacao == '-')
	{
		calc(subt, num1, num2);
	} 
	
	else if (operacao == '*')
	{
		calc(mult, num1, num2);
	}

	else if (operacao == '/')
	{
		if (num2 == 0)
		{
			printf("∃\n");
		}

		else
		{
			calc(div, num1, num2);
		}
	}

	return 0;
}