#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int y;
	int x;
	int cnt;
};

int map[300][300];
int N, f_y, f_x, d_y, d_x, ans;
int dir[8][2] = { {-1,-2},{-2,-1},{1,-2},{2,-1},{2,1},{1,2},
{2,-1},{1,-2} };
bool visit[300][300];
queue<pos>Q;

bool Inbound(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < N) {
		return true;
	}
	return false;
}

void move_the_knight() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
	while (!Q.empty()) {
		Q.pop();
	}
	ans = 0;


	Q.push({ f_y,f_x, 0 });
	visit[f_y][f_x] = true;

	while (!Q.empty()) {
		int ny = Q.front().y;
		int nx = Q.front().x;
		int cnt = Q.front().cnt;

		Q.pop();

		for (int i = 0; i < 8; i++) {
			int my = ny + dir[i][0];
			int mx = nx + dir[i][1];

			if (Inbound(my, mx) && !visit[my][mx]) {
				if (map[my][mx] == 0) {
					visit[my][mx] = true;
					Q.push({ my,mx, cnt + 1 });
				}
				else if(map[my][mx] == 1){
					ans = cnt + 1;
					return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Testcase;

	cin >> Testcase;

	while (Testcase--) {
		cin >> N;
		cin >> f_y >> f_x;
		cin >> d_y >> d_x;
		if (f_y == d_y && f_x == d_x) {
			cout << 0 << '\n';
			continue;
		}
		map[d_y][d_x] = 1;
		move_the_knight();
		cout << ans << '\n';
		map[d_y][d_x] = 0;
	}
}