#include <iostream>
using namespace std;
int N, ans_can_see = 0 , ans_cant_see = 0;
char map[101][101];
bool visit[101][101];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void can_see(int y, int x) {
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int my = y + dir[i][0];
		int mx = x + dir[i][1];

		if (Inbound(my, mx) && (map[y][x] == map[my][mx]) && !visit[my][mx]) {
			visit[my][mx] = true;
			can_see(my, mx);
		}
		else {
			continue;
		}
	}
}

void cant_see(int y, int x) {
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int my = y + dir[i][0];
		int mx = x + dir[i][1];

		if (Inbound(my, mx) && !visit[my][mx]) {
			if ((map[y][x] == 'R' && (map[my][mx] == 'G' || map[my][mx] == 'R'))
				|| (map[y][x] == 'G' && (map[my][mx] == 'G' || map[my][mx] == 'R')
					|| (map[y][x] == 'B' && map[my][mx] == 'B'))) {
				visit[my][mx] = true;
				cant_see(my, mx);
			}
		}
		else {
			continue;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				can_see(i,j);
				ans_can_see++;
			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				cant_see(i, j);
				ans_cant_see++;
			}
		}
	}
	cout << ans_can_see << ' ' << ans_cant_see << '\n';

	return 0;
}