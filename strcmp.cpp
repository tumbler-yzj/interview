#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

int strcmp(const char* s1, const char* s2) {
	assert(s1 && s2);

	while(*s1 && *s1 == *s2) {
		s1++;
		s2++;
	}
	
	return *s1 - *s2;
}

int main() {
	char s1[] = "3.17";
	char s2[] = "3.1";
	
	cout << strcmp(s1, s2) << endl;
	system("pause");
}
