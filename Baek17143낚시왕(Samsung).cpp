#include <iostream>
#include <queue>
using namespace std;

int map[102][102];
int copy_map[102][102];
int r, c, ans = 0, speed, siz, shark_dir, shark_num, shark_r, shark_c, control_speed;
int dir[5][2] = { {0, 0}, {-1, 0},{1, 0},{0, 1},{0, -1} };
//x, 상, 하, 우, 좌//
queue<pair<pair<pair<int, int>, pair<int, int>>, int>>shark_info;

void init_map() {
	for (int i = 1; i <= shark_r; i++) {
		for (int j = 1; j <= shark_c; j++) {
			map[i][j] = copy_map[i][j];
		}
	}
}

void init_copy_map() {
	for (int i = 1; i <= shark_r; i++) {
		for (int j = 1; j <= shark_c; j++) {
			copy_map[i][j] = 0;
		}
	}
}

void move_the_shark() {
	init_copy_map();//카피 맵 초기화

	int size_of_Q = shark_info.size();

	for (int i = 0; i < size_of_Q; i++) {
		int y = shark_info.front().first.first.first;
		int x = shark_info.front().first.first.second;
		int shark_speed = shark_info.front().first.second.first;
		int shark_dir = shark_info.front().first.second.second;
		int shark_size = shark_info.front().second;
		int shark_control_speed = shark_info.front().first.second.first;;

		shark_info.pop();

		if (shark_size != map[y][x]) { //만약 낚시꾼에게 잡히거나, 다른 상어에게 먹혔으면 다음 Queue.
			continue;
		}
		else {
			if (shark_dir == 1 || shark_dir == 2) { //상,하 움직임
				if (shark_speed >= (shark_r - 1) * 2) {
					shark_speed = shark_speed % ((shark_r - 1) * 2);
				}
				for (int i = 0; i < shark_speed; i++) {
					int my = y + dir[shark_dir][0];
					int mx = x + dir[shark_dir][1];
					y = my; x = mx;

					if (shark_dir == 2 && my == shark_r) {
						shark_dir = 1;
					}
					else if (shark_dir == 1 && my == 1) {
						shark_dir = 2;
					}
					else if (shark_dir == 2 && my > shark_r) {
						shark_dir = 1;
						y += 2 * dir[shark_dir][0];
						x += 2 * dir[shark_dir][1];
					}
					else if (shark_dir == 1 && my < 1) {
						shark_dir = 2;
						y += 2 * dir[shark_dir][0];
						x += 2 * dir[shark_dir][1];
					}
				}

			}
			else{ //우, 좌 움직임
				if (shark_speed >= (shark_c - 1) * 2) {
					shark_speed = shark_speed % ((shark_c - 1) * 2);
				}
				for (int i = 0; i < shark_speed; i++) {
					int my = y + dir[shark_dir][0];
					int mx = x + dir[shark_dir][1];
					y = my; x = mx;

					if (shark_dir == 3 && mx == shark_c) {
						shark_dir = 4;
					}
					else if (shark_dir == 4 && mx == 1) {
						shark_dir = 3;
					}
					else if (shark_dir == 3 && mx > shark_c) {
						shark_dir = 4;
						y += 2 * dir[shark_dir][0];
						x += 2 * dir[shark_dir][1];
					}
					else if (shark_dir == 4 && mx < 1) {
						shark_dir = 3;
						y += 2 * dir[shark_dir][0];
						x += 2 * dir[shark_dir][1];
					}
				}

			}
			if (copy_map[y][x] <= shark_size) { //크기 비교 후 상어 잡아 먹히는지 파악
				copy_map[y][x] = shark_size;
				shark_info.push(make_pair(make_pair(make_pair(y, x), make_pair(shark_control_speed, shark_dir)), shark_size));
			}
		}
	}
}

void catch_the_shark() {
	for (int i = 1; i <= shark_c; i++) {
		for (int j = 1; j <= shark_r; j++) {
			if (map[j][i] != 0) {
				ans += map[j][i];
				map[j][i] = 0;
				break;
			}
		}
		move_the_shark();
		init_map();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> shark_r >> shark_c >> shark_num;

	for (int i = 1; i <= shark_num; i++) {
		cin >> r >> c >> speed >> shark_dir >> siz;
		shark_info.push(make_pair(make_pair(make_pair(r, c), make_pair(speed, shark_dir)), siz));
		//y,x,speed,dir,size//
		map[r][c] = siz;
		copy_map[r][c] = map[r][c];
	}

	catch_the_shark();

	cout << ans << '\n';

	return 0;
}