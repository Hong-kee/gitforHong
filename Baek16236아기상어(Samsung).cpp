/*
1. 처음의 아기 상어의 크기는 2
2. 자신보다 큰 크기는 지나갈 수 x
   같은 크기는 지나갈 수 o
   작은 크기는 먹을 수 o
3. <이동방식>
   1. 먹을 수 있는 물고기 >= 1 이라면 먹으러 감-> 탐색
   2. 가장 가까운 물고기를 먹으러감
   -> 만일 여러 마리라면 가장 위에있는 물고기.
   -> 위에 있는 물고기가 여러 마리라면 그 중 가장 왼쪽의 물고기
4. Result = Q가 empty일 때.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };//북서동남
int map[21][21];
bool check[21][21];
int temp_ans = 0, ans = 0, N, shark_y, shark_x, M_s, M_c;

struct pos {
	int y;
	int x;
	int size;
	int eat_cnt;
};
queue<pos>Q;
vector<pair<int, int>>V;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void check_init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			check[i][j] = false;
		}
	}
}

void baby_shark_move() {
	while (!Q.empty()) {
		temp_ans++;
		int size_of_q = Q.size();

		for (int i = 0; i < size_of_q; i++) {

			int y = Q.front().y;
			int x = Q.front().x;
			int size = Q.front().size;
			int eat_cnt = Q.front().eat_cnt;

			Q.pop();

			for (int j = 0; j < 4; j++) {
				int my = y + dir[j][0];
				int mx = x + dir[j][1];

				if (Inbound(my, mx)) {
					if (!check[my][mx]) {
						if (size < map[my][mx]) {
							continue;
						}
						else if (size == map[my][mx] || map[my][mx] == 0) {
							Q.push({ my,mx,size,eat_cnt });
							check[my][mx] = true;
						}
						else if (map[my][mx] != 0 && size > map[my][mx]) {
							V.push_back(make_pair(my, mx));
							check[my][mx] = true;
							M_s = size;
							M_c = eat_cnt;
						}
					}
				}
			}
		}
		if (V.size() > 0) {
			sort(V.begin(), V.end());
			ans = temp_ans;
			map[V.front().first][V.front().second] = M_s;
			map[shark_y][shark_x] = 0;
			shark_y = V.front().first;
			shark_x = V.front().second;
			M_c++;
			if (M_s == M_c) {
				M_s++;
				M_c = 0;
			}

			V.clear();
			check_init();

			while (!Q.empty()) {
				Q.pop();
			}

			Q.push({ shark_y, shark_x, M_s, M_c });
			check[shark_y][shark_x] = true;
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
			if (map[i][j] == 9) {
				Q.push({ i,j,2,0 });
				shark_y = i;
				shark_x = j;
			}
		}
	}
	baby_shark_move();
	cout << ans << '\n';
	return 0;
}