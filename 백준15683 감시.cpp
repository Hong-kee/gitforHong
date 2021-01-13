#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = 987654321, cctv_num = 0, temp_ans = 0;
int map[8][8];
int copy_map[8][8];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//북,동,남,서
vector<pair<pair<int, int>, pair<int, int>>> cctv_info;

bool Inbound(int y, int x) {
	if (y >= 0 && x >= 0 && y < N && x < M) {
		return true;
	}
	return false;
}

void up(int y, int x){
	int real_y = y;
	int real_x = x;

	while (1) {
		real_y += dir[0][0];
		real_x += dir[0][1];

		if (Inbound(real_y, real_x) && copy_map[real_y][real_x] != 6) {
			copy_map[real_y][real_x] = -1;
		}
		else {
			break;
		}
	}
}

void right(int y, int x) {

	int real_y = y;
	int real_x = x;

	while (1) {
		real_y += dir[1][0];
		real_x += dir[1][1];

		if (Inbound(real_y, real_x) && copy_map[real_y][real_x] != 6) {
			copy_map[real_y][real_x] = -1;
		}
		else {
			break;
		}
	}
}
void down(int y, int x) {
	int real_y = y;
	int real_x = x;

	while (1) {
		real_y += dir[2][0];
		real_x += dir[2][1];

		if (Inbound(real_y, real_x) && copy_map[real_y][real_x] != 6) {
			copy_map[real_y][real_x] = -1;
		}
		else {
			break;
		}
	}
}
void left(int y, int x) {
	int real_y = y;
	int real_x = x;

	while (1) {
		real_y += dir[3][0];
		real_x += dir[3][1];

		if (Inbound(real_y, real_x) && copy_map[real_y][real_x] != 6) {
			copy_map[real_y][real_x] = -1;
		}
		else {
			break;
		}
	}
}
void cctv_on() {
	for (int i = 0; i < cctv_info.size(); i++) {

		int y = cctv_info[i].first.first;
		int x = cctv_info[i].first.second;
		int cam = cctv_info[i].second.first;
		int cam_dir = cctv_info[i].second.second;

		if (cam == 1 && cam_dir == 0) {
			up(y, x);
		}
		else if (cam == 1 && cam_dir == 1) {
			right(y, x);
		}
		else if (cam == 1 && cam_dir == 2) {
			down(y, x);
		}
		else if (cam == 1 && cam_dir == 3) {
			left(y, x);
		}
		else if (cam == 2 && cam_dir == 0) {
			up(y, x);
			down(y, x);
		}
		else if (cam == 2 && cam_dir == 1) {
			right(y, x);
			left(y, x);
		}
		else if (cam == 3 && cam_dir == 0) {
			up(y, x);
			right(y, x);
		}
		else if (cam == 3 && cam_dir == 1) {
			right(y, x);
			down(y, x);
		}
		else if (cam == 3 && cam_dir == 2) {
			down(y, x);
			left(y, x);
		}
		else if (cam == 3 && cam_dir == 3) {
			left(y, x);
			up(y, x);
		}
		else if (cam == 4 && cam_dir == 0) {
			left(y, x);
			up(y, x);
			right(y, x);
		}
		else if (cam == 4 && cam_dir == 1) {
			up(y, x);
			right(y, x);
			down(y, x);
		}
		else if (cam == 4 && cam_dir == 2) {
			right(y, x);
			down(y, x);
			left(y, x);
		}
		else if (cam == 4 && cam_dir == 3) {
			down(y, x);
			left(y, x);
			up(y, x);
		}
		else if (cam == 5) {
			down(y, x);
			left(y, x);
			up(y, x);
			right(y, x);
		}
	}
}

void select_cam_dir(int cnt) {
	if (cnt == cctv_num) {
		cctv_on();
		for (int i = 0; i < N; i++) {//사각지대 갯수 체크
			for (int j = 0; j < M; j++) {
				if (copy_map[i][j] == 0) {
					temp_ans++;
				}
			}
		}

		if (ans > temp_ans) {
			ans = temp_ans;
		}
		temp_ans = 0;

		for (int i = 0; i < N; i++) {//카피맵 초기화
			for (int j = 0; j < M; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		return;
	}
	else {
		if (cctv_info[cnt].second.second == -1) {
			cctv_info[cnt].second.second = 0;
			select_cam_dir(cnt + 1);
		}
		if (cctv_info[cnt].second.second == 0) {
			cctv_info[cnt].second.second = 1;
			select_cam_dir(cnt + 1);
		}
		if (cctv_info[cnt].second.second == 1) {
			cctv_info[cnt].second.second = 2;
			select_cam_dir(cnt + 1);
		}
		if (cctv_info[cnt].second.second == 2) {
			cctv_info[cnt].second.second = 3;
			select_cam_dir(cnt + 1);
		}
		if (cctv_info[cnt].second.second == 3) {
			cctv_info[cnt].second.second = 0;
			select_cam_dir(cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
			if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 ||
				map[i][j] == 4 || map[i][j] == 5 ) {
				cctv_num++;
				cctv_info.push_back(make_pair(make_pair(i, j),make_pair(map[i][j], -1)));
			}
		}
	}

	select_cam_dir(0);

	cout << ans << '\n';

	return 0;
}
