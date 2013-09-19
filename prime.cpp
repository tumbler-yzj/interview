#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>

using namespace std;

#define INF INT_MAX


int prime(int graph[][9], int m) {
	bool visit[9];
	int dist[9];
	for(int i = 0; i < 9; i++) {
		visit[i] = false;
	}
	int cur = 0;
	int sum = 0;
	int index;
	visit[cur] = true;
	for(int i = 0; i < m; i++)
		dist[i] = graph[cur][i];
	
	for(int i = 1; i < m; i++) {
		for(int i = 0; i < m; i++)
			cout << dist[i] << " ";
		cout << endl;
		int minicost = INF;
		for(int j = 0; j < m; j++) {
			if(!visit[j] && dist[j] < minicost) {
				minicost = dist[j];
				index = j;
				cout << "dist[j] " << dist[j] << "   j " << j << endl;
			}
		}
		cout << "index = : " << index << endl;
		visit[index] = true;
		sum += minicost;
		
		for(int j = 0; j < m; j++) {
			if(!visit[j] && dist[j] > graph[index][j]) {
				dist[j] = graph[index][j];
			}
		}
	}
	return sum;			
}

int main() {
	const int m = 9;
	int graph[][m] = {
		{0, 4, INF, INF, INF, INF, INF, 8, INF},
		{4, 0, 8, INF, INF, INF, INF, 11, INF},
		{INF, 8, 0, 7, INF, 4, INF, INF, 2},
		{INF, INF, 7, 0, 9, 14, INF, INF, INF},
		{INF, INF, INF, 9, 0, 10, INF, INF, INF},
		{INF, INF, 4, 14, 10, 0, 2, INF, INF},
		{INF, INF, INF, INF, INF, 2, 0, 1, 6},
		{8, 11, INF, INF, INF, INF, 1, 0, 7},
		{INF, INF, 2, INF, INF, INF, 6, 7, 0}
		};
	cout << prime(graph, m) << endl;
	system("pause");
}
