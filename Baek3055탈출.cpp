#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int y;
	int x;
};
queue<pos>q_hedgehog, q_water;
char map[51][51];
bool visit[51][51];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int r, c, answer = 0, d_y = -1, d_x = -1;
bool flag = false;

bool inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= r && x <= c) {
		return true;
	}
	return false;
}

void flow_the_water() {
	int size_of_water = q_water.size();

	for (int i = 0; i < size_of_water; i++) {
		int y = q_water.front().y;
		int x = q_water.front().x;

		q_water.pop();

		for (int j = 0; j < 4; j++) {
			int my = y + dir[j][0];
			int mx = x + dir[j][1];

			if (inbound(my, mx)) {
				if (map[my][mx] != '*' && map[my][mx] != 'd'
					&& map[my][mx] != 'x') {
					q_water.push({ my,mx });
					map[my][mx] = '*';
					visit[my][mx] = true;
				}
			}
		}
	}
}

void move_the_hedgehog() {
	int size_of_hedgehog = q_hedgehog.size();

	for (int i = 0; i < size_of_hedgehog; i++) {
		int y = q_hedgehog.front().y;
		int x = q_hedgehog.front().x;

		q_hedgehog.pop();

		for (int j = 0; j < 4; j++) {
			int my = y + dir[j][0];
			int mx = x + dir[j][1];

			if (inbound(my, mx)) {
				if (!visit[my][mx]) {
					if (map[my][mx] == '.') {
						q_hedgehog.push({ my,mx });
						visit[my][mx] = true;
					}
					else if (map[my][mx] == 'd') {
						answer++;
						d_y = my;
						d_x = mx;
						flag = true;
						return;
					}
				}
			}
		}
	}
	answer++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 's') {
				q_hedgehog.push({ i,j });
				visit[i][j] = true;
			}
			else if (map[i][j] == '*') {
				q_water.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
	while (!q_hedgehog.empty()) {
		flow_the_water();
		move_the_hedgehog();
		if (flag) {
			break;
		}
	}
	if (d_y == -1 && d_x == -1) {
		cout << "kaktus" << '\n';
	}
	else {
		cout << answer << '\n';
	}
	return 0;
}