#include <iostream>
#include <cstdlib>

using namespace std;


void Merge(int *p, int *temp, int low, int m, int high) {
	int i = low;
	int j = m+1;
	int pos = low;

	while(i <= m && j <= high)
		temp[pos++] = (p[i] <= p[j])? p[i++]:p[j++];
	while(i <= m)
		temp[pos++] = p[i++];
	while(j <= high)
		temp[pos++] = p[j++];
	/*
	for(x = 0, i = low; i <=high; x++,i++)
		p[i] = temp[x];	
	*/
	while(pos-- >= low)
		p[pos] = temp[pos];
}

void MergePass(int *p, int *temp, int low, int high) {
	int mid;// = (low + high)/2;
	if(low < high) {
		mid = (low + high)/2;
		cout << "low: " << low <<" mid: " << mid << " high: " << high << " " << p[mid] << endl;
		MergePass(p, temp, low, mid);
		MergePass(p, temp, mid+1, high);
		Merge(p, temp, low, mid, high);
		for(int i = 0; i < 7; i++)
			cout << temp[i] << " ";
		cout << endl;
	}
}

void MergeSort(int *p, int n) {
	if(p == NULL || n <= 0)
		return;
	int *temp = (int*)malloc(sizeof(int)*n);
	if(temp == NULL)
		return;
	MergePass(p, temp, 0, n-1);
}

int main() {
	int a[7] = {4,8,2,5,1,6,7};
	for(int i = 0; i < 7; i++)
		cout << a[i] << " ";
	cout << endl;
	MergeSort(a, 7);
	
	for(int i = 0; i < 7; i++)
		cout << a[i] << " ";
	cout << endl;
	while(1);
}
