#include <iostream>
#include <cstdlib>


using namespace std;

void HeapAdjust(int a[], int i, int size) {
	int lchild = 2*i;
	int rchild = 2*i + 1;
	int max = i;
	
	if(i <= size/2) {
		if(lchild <= size && a[max] < a[lchild])
			max = lchild;
		if(rchild <= size && a[rchild] > a[max])
			max = rchild;
		if(max != i) {
			swap(a[i],a[max]);
			HeapAdjust(a, max, size);
		}
	}
}

void HeapSort(int a[], int size) {
	for(int i = size/2; i >= 1; i--)
		HeapAdjust(a, i, size);
	for(int j = size; j>=1; j--) {
		swap(a[j],a[1]);
		HeapAdjust(a, 1, j-1);
	}
}

int main() {
	int a[]={0,16,20,3,11,17,8};
	HeapSort(a, 6);
	for(int i=1;i<=6;i++)
            cout<<a[i]<<" ";
    cout<<endl;
    while(1);
}
