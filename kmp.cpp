#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void getNext(const string &str, int next[]) {
	int i = 0; 
	next[0] = -1;
	int j = -1;
	while(i < str.length()-1) {
		if(j == -1 || str[i] == str[j]) {
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

int kmp(const string &t, const string &p) {
	int i = 0;
	int j = 0;
	int next[100];
	getNext(p, next);
	for(int i = 0; i < p.length(); i++)
		cout << next[i] << " ";
	cout << endl;
	while(i < t.length()) {
		if(j == -1 || t[i] == p[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
		cout << t[i] << " " << p[j] << endl;
	}
	cout << j << " " << p.length() << endl;
	if(j == p.length())
		return i - j;
	else
		return -1;
}



int main() {
	string t = "ababcababa";
	string p = "ababa";
	int ret = kmp(t, p);
	cout << ret << endl;
	system("pause");
}
