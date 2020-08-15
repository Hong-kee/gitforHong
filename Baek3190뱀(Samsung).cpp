//1.map을 받는다.(사과는 2, 뱀은 1, 빈칸은 0)
//2.(1,1)에서 뱀은 시작한다.
//3.queue에 (초,방향정보)를 넣어서 맞으면 바꿔주고 pop
//4.벽에 부딪히거나 본인의 꼬리와 닿으면 종료 후 시간 출력.
//5.몸길이 늘려 머리를 다음 칸에 위치 -> 사과 O .. 사과 없어지고 꼬리그대로
//                                ->사과 X .. 꼬리비워줌
#include <iostream>
#include <deque>
#include <queue>
#include <utility>
using namespace std;

int map[101][101];
int N, r, c, apple_cnt, dir_cnt, dir_change_sec;
char dir_change_dir;
int ans = 0;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
queue<pair<int,char>>dir_info;
deque<pair<int, int>>snake_info;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

int change_dir(int c_dir, char w_dir) {
	if (c_dir == 0 && w_dir == 'L') {
		return 3;
	}
	else if (c_dir == 0 && w_dir == 'D') {
		return 1;
	}
	
	else if (c_dir == 1 && w_dir == 'L') {
		return 0;
	}
	else if (c_dir == 1 && w_dir == 'D') {
		return 2;
	}

	else if (c_dir == 2 && w_dir == 'L') {
		return 1;
	}
	else if (c_dir == 2 && w_dir == 'D') {
		return 3;
	}

	else if (c_dir == 3 && w_dir == 'L') {
		return 2;
	}
	else if (c_dir == 3 && w_dir == 'D') {
		return 0;
	}
}

void play_the_game() {//시간 먼저 +1
	snake_info.push_back(make_pair(1,1));
	int cur_dir = 1, y = 1, x = 1;

	while (1) {
		ans++;
		int my = y + dir[cur_dir][0];
		int mx = x + dir[cur_dir][1];
		y = my; x = mx;

		if (!Inbound(my, mx)||map[my][mx] == 1) {
			return;
		}

		if (map[my][mx] == 0) {
			map[my][mx] = 1;
			int tail_y = snake_info.front().first;
			int tail_x = snake_info.front().second;
			map[tail_y][tail_x] = 0;
			snake_info.push_back(make_pair(my,mx));
			snake_info.pop_front();
		}

		else if (map[my][mx] == 2) {
			map[my][mx] = 1;
			snake_info.push_back(make_pair(my,mx));
		}

		if (dir_info.size() != 0) {
			if (dir_info.front().first == ans) {
				char want_dir = dir_info.front().second;
				cur_dir = change_dir(cur_dir, want_dir);
				dir_info.pop();
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
			map[i][j] = 0;
		}
	}
	map[1][1] = 1;

	cin >> apple_cnt;
	for (int i = 1; i <= apple_cnt; i++) {
		cin >> c >> r;
		map[c][r] = 2;
	}

	cin >> dir_cnt;
	for (int i = 1; i <= dir_cnt; i++) {
		cin >> dir_change_sec >> dir_change_dir;
		dir_info.push(make_pair(dir_change_sec,dir_change_dir));
	}
	play_the_game();
	cout << ans << '\n';

	return 0;
}