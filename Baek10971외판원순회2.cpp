//DFS, TSP Problem
#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = 987654321;
int map[11][11];
bool visit[11];

void search_the_low_cost(int first, int cnt, int temp, int destination) {
	if (cnt == N - 1) {
		if (map[first][destination] > 0) {
			answer = min(temp + map[first][destination], answer);
		}
		return;
	}
	for (int i = 2; i <= N; i++) {
		if (!visit[i]) {
			if (map[first][i] > 0) {
				visit[i] = true; 
				search_the_low_cost(i, cnt + 1, temp + map[first][i], destination);
				visit[i] = false;
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	search_the_low_cost(1, 0, 0, 1);
	cout << answer << '\n';
}