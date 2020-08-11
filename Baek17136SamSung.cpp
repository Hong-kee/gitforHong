#include <iostream>
#include <algorithm>
using namespace std;

int map[11][11];
int paper[6] = { 0,0,0,0,0,0 };
int ans = 987654321;
bool flag = false;

void make_0(int y, int x, int size, int state) {
	for (int i = y; i <= y + size - 1; i++) {
		for (int j = x; j <= x + size - 1; j++) {
			map[i][j] = state;
		}
	}
}

bool try_paper(int y, int x, int size) {
	for (int i = y; i <= y + size - 1; i++) {
		for (int j = x; j <= x + size - 1; j++) {
			if (map[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int y, int x, int cnt) {

	while (map[y][x] != 1) {
		if (++x >= 11) {
			if (++y >= 11) {
				ans = min(ans, paper[1] + paper[2] + paper[3] + paper[4] +
					paper[5]);
					return;
			}
			x = 1;
		}
	}

	if (ans <= paper[1] + paper[2] + paper[3] + paper[4] +
		paper[5]) {
		return;
	}

	for (int size = 5; size > 0; --size) {
		if (y + size - 1 > 10 || x + size - 1 > 10 || paper[size] == 5) {
			continue;
		}
		if (try_paper(y, x, size)) {
			make_0(y, x, size, 0);
			paper[size]++;
			dfs(y, x, cnt - 1);
			make_0(y, x, size, 1);
			paper[size]--;
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num_1_cnt = 0;

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				num_1_cnt++;
			}
		}
	}
	if (num_1_cnt == 100) {
		cout << 4;
		return 0;
	}

	dfs(1, 1, num_1_cnt);

	if (ans == 987654321) {
		cout << -1;
		return 0;
	}

	cout << ans;

	return 0;

}