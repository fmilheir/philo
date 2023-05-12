#include "../philo.h"

int     atoi(char   *value)
{
    int a;
	int negative;
	int result;

	negative = 1;
	a = 0;
	result = 0;

	while (value[a] == ' ' || value[a] == '\t' || value[a] == '\n' ||
			value[a] == '\r' || value[a] == '\v' || value[a] == '\f')
			a++;
	
	if (value[a] == '-')
	{
		negative = -1;
		a++;
	}

	while (value[a] >= '0' && value[a] <= '9')
	{
		result = result * 10+  value[a] - '0';
		a++;
	}
	return(result*negative);       
}