#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
//1.벽을 만들고 3개가 되면 bfs돌림
//2.다 돌렸으면 0의 갯수를 카운트. 그 카운트의 값이 최대가 되는 것 찾기
int r, c, ans = 0;
bool visit[9][9];
bool wall[9][9];
int map[9][9];
int copy_map[9][9];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
queue<pair<int, int>>Q;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= r && x <= c) {
		return true;
	}
	return false;
}

void spread_virus() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			copy_map[i][j] = map[i][j];
			visit[i][j] = false;
			if (map[i][j] == 2) {
				Q.push(make_pair(i,j));
			}
		}
	}

	while (!Q.empty()) {
		int size_of_Q = Q.size();
		
		for (int i = 0; i < size_of_Q; i++) {
			int y = Q.front().first;
			int x = Q.front().second;

			Q.pop();

			for (int i = 0; i < 4; i++) {
				int my = y + dir[i][0];
				int mx = x + dir[i][1];

				if (Inbound(my, mx) && !visit[my][mx]
					&& map[my][mx] == 0){
					Q.push(make_pair(my, mx));
					visit[my][mx] = true;
					copy_map[my][mx] = 2;
				}
			}
		}
	}
}

void make_wall(int y, int x, int wall_cnt) {
	if (wall_cnt == 3) {
		spread_virus();

		int safe_area = 0;

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (copy_map[i][j] == 0) {
					safe_area++;
				}
			}
		}
		ans = max(safe_area, ans);
		return;
	}
	for (int i = y; i <= r; i++) {
		for (int j = x; j <= c; j++) {
			if (map[i][j] == 0 && !wall[i][j]) {
				wall[i][j] = true;
				map[i][j] = 1;
				make_wall(i, j, wall_cnt + 1);
				map[i][j] = 0;
				wall[i][j] = false;
			}
		}
		x = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];

			if (map[i][j] == 2) {
				visit[i][j] = true;
			}
		}
	}
	make_wall(1,1,0);

	cout << ans << '\n';

	return 0;
}