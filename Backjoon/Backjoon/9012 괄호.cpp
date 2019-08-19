#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int check(char *string)
{
	fflush(stdin);
	scanf("%s", string);
	int len = strlen(string);
	int i = 0;
	int result = 0;
	for (i = 0; i < len; i++) {
		if (string[i] == '(') {
			result = result + 1;
		}
		else {
			result = result - 1;
		}

		if (result < 0) {
			return result;
		}
	}
	return result;
}

int main(void) {

	int num = 0;
	int c = 0;
	scanf("%d", &c);

	while (num < c) {
		char string[100];

		if (check(string) == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		num++;
	}
	return 0;
}