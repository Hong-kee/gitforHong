#include <iostream>
#include <queue>
using namespace std;

int N, island_num = 1, ans = 987654321;
int map[101][101];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool visit[101][101];
queue<pair<int, int>>Q;
queue<pair<pair<int,int>,int>>bridge;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void make_bridge(int y, int x, int n, int cnt) {
	bridge.push(make_pair(make_pair(y,x),cnt));

	while (!bridge.empty()) {
		int size_of_bridge = bridge.size();

		for (int i = 0; i < size_of_bridge; i++) {
			int ny = bridge.front().first.first;
			int nx = bridge.front().first.second;
			int bridge_cnt = bridge.front().second;

			bridge.pop();

			for (int j = 0; j < 4; j++) {
				int my = ny + dir[j][0];
				int mx = nx + dir[j][1];

				if (Inbound(my, mx) && !visit[my][mx]
					&& (map[my][mx] == 0 || map[my][mx] != n)) {
					if (map[my][mx] == 0) {
						bridge.push(make_pair(make_pair(my, mx), bridge_cnt + 1));
						visit[my][mx] = true;
					}
					else if (map[my][mx] != n) {
						ans = min(ans, bridge_cnt);
						while (!bridge.empty()) {
							bridge.pop();
						}
						return;
					}
				}
			}
		}
	}
}

void island_allocate(int num) {
	while (!Q.empty()) {
		int size_of_Q = Q.size();

		for (int i = 0; i < size_of_Q; i++) {
			int y = Q.front().first;
			int x = Q.front().second;
			Q.pop();

			for (int j = 0; j < 4; j++) {
				int my = y + dir[j][0];
				int mx = x + dir[j][1];

				if (Inbound(my, mx) && !visit[my][mx] && map[my][mx] == 1) {
					Q.push(make_pair(my, mx));
					visit[my][mx] = true;
					map[my][mx] = num;
				}
			}
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
	for (int i = 1; i <= N; i++) { //island에 번호 부여
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j] && map[i][j] != 0) {
				visit[i][j] = true;
				map[i][j] = island_num;
				Q.push(make_pair(i, j));

				island_allocate(island_num);

				island_num++;
			}
		}
	}

	for (int i = 1; i <= N; i++) {//다리 건설
		for (int j = 1; j <= N; j++) {
			if (map[i][j] != 0) {
				for (int i = 1; i <= N; i++) {//방문처리 해제
					for (int j = 1; j <= N; j++) {
						visit[i][j] = false;
					}
				}
				visit[i][j] = true;
				make_bridge(i, j, map[i][j], 0);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}