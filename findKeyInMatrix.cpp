#include <iostream>

using namespace std;

bool find(int*mat, int rows, int cols, int key) {
	if(mat == NULL || rows <=0 || cols <= 0)
		return false;
	int i = 0;
	int j = cols - 1;
	while(i < rows && j >= 0) {
		if(mat[i*cols + j] == key)
			return true;
		else if(mat[i*cols + j] > key){
			j--;
		} else {
			i++;
		}
	}
	return false;
}

int main() {
	int mat[16] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
	int key = 7;
	if(find(mat, 4, 4, key))
		cout << "find " << key << endl;
	else
		cout << "Can't find " << key << endl;
	while(1);
}
