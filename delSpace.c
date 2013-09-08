#include <stdio.h>

void delSpace(char* s) {
	int k = -1;
	int i = 0;
	while(*(s+i) != '\0') {
		if(*(s+i) != ' ') {
			k++;
			*(s+k) = *(s+i);
			i++;
		} else {
			i++;
		}
	}
	k++;
	*(s+k) = *(s+i);
}

int main() {
	char s[] = "hell w o";
	delSpace(s);
	printf("%s\n", s);
	getchar();
}
