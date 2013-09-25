#include <iostream>
#include <cstdlib>

using namespace std;

int Fac(int N) {
	int ret = 1;
	if(N < 1)
		return 0;
	for(int i = 1; i <=N; i++) {
		ret *= i;
	}
	return ret;
}

int find(int id[], int N) {
	int candidate;
	int times = 0;
	for(int i = 0; i < N; i++) {
		if(times == 0) {
			candidate = id[i];
			times++;
		} else {
			if(candidate == id[i]) {
				times++;
			} else {
				times--;
			}
		}
	}
	return candidate;
}

int main() {
	int N = 10;
	cout << Fac(N) << endl;
	
	int id[10] = {1,2,3,4,4,4,4,4,4,6};
	cout << find(id, 10) << endl;
	
	system("pause");
}
