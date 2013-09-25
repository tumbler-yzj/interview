#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX 256

using namespace std;

void lcs(const string &t, const string &p, int c[][MAX], int b[][MAX], int m, int n) {
	
	for(int i = 0; i < m; i++) {
		c[i][0] = 0;
	}
	
	for(int j = 0; j < n; j++) { 
		c[0][j] = 0;
	}
	
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(t[i-1] == p[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1;
			}
			else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = -1;
			}
		}
	}	
}

void print_lcs(int b[][MAX], string &t, int m, int n) {
	if(m == 0 || n == 0)
		return;
	if(b[m][n] == 1) {
		print_lcs(b, t, m-1, n-1);
		cout << t[m-1] << " ";
	}
	else if(b[m][n] == 2) {
		print_lcs(b, t, m-1, n);
	}
	else {
		print_lcs(b, t, m, n-1);
	}
}

int main(int argc, char **argv)
{
    string t = "ABCBDAB";
    string p = "BDCABA";
    int b[MAX][MAX];
    int c[MAX][MAX];
    int m = t.length();
    int n = p.length();
    
    cout << m << " " << n << endl;
    
    lcs(t, p, c, b, m, n);
    
    for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
    }
    cout << endl;
   print_lcs(b, t, m, n);
    
    system("pause");
    return 0;
}
