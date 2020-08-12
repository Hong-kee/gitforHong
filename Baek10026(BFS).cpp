#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
bool visit[101][101];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
queue<pair<int, int>>Q;
int N, ans_can_see = 0, ans_cant_see = 0;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void cant_see(int y, int x) {
	Q.push(make_pair(y, x));
	visit[y][x] = true;

	while (!Q.empty()) {
		int Q_size = Q.size();
		
		for (int j = 0; j < Q_size; j++) {
			int ny = Q.front().first;
			int nx = Q.front().second;
			Q.pop();


			for (int i = 0; i < 4; i++) {
				int my = ny + dir[i][0];
				int mx = nx + dir[i][1];

				if (Inbound(my, mx) && !visit[my][mx]) {
					if (map[ny][nx] == 'R') {
						if (map[my][mx] == 'B') {
							continue;
						}
						else {
							Q.push(make_pair(my, mx));
							visit[my][mx] = true;
						}
					}
					else if (map[ny][nx] == 'G') {
						if (map[my][mx] == 'B') {
							continue;
						}
						else {
							Q.push(make_pair(my, mx));
							visit[my][mx] = true;
						}
					}
					else if (map[ny][nx] == 'B') {
						if (map[ny][nx] == map[my][mx]) {
							Q.push(make_pair(my, mx));
							visit[my][mx] = true;
						}
					}
				}
				else {
					continue;
				}
			}
		}
	}
	ans_cant_see++;
}

void can_see(int y, int x) {
	Q.push(make_pair(y, x));
	visit[y][x] = true;

	while (!Q.empty()) {
		int Q_size = Q.size();

		for (int j = 0; j < Q_size; j++) {
			int ny = Q.front().first;
			int nx = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; i++) {
				int my = ny + dir[i][0];
				int mx = nx + dir[i][1];

				if (Inbound(my, mx) && !visit[my][mx] && (map[ny][nx] == map[my][mx])) {
					Q.push(make_pair(my, mx));
					visit[my][mx] = true;
				}
				else {
					continue;
				}
			}
		}
	}
	ans_can_see++;
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
				can_see(i, j);
			}
		}
	}
	cout << ans_can_see << ' ';

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				cant_see(i, j);
			}
		}
	}
	cout << ans_cant_see << '\n';

	return 0;
}