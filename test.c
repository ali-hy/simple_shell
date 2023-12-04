#include "main.h"

/**
 * test - function to run a test
 */
void test(void)
{
	char *res = NULL;
	char inp[] = "okay so what my friend\n";

	res = _strtok(inp, " \n");
	while (res != NULL)
	{
		printf("%s, ", res);
		res = _strtok(NULL, " \n");
	}
	printf("[n/a tokens]\n");
}
