#include <iostream>
#include <algorithm>
using namespace std;

char map[11][11];
int ans = 987654321, r, c;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//��,��,��,��
int r_y, r_x, b_y, b_x;

int locate_the_bid(int R, int B) {
	if (R > B) {//������ �������� R�� �ڿ� ���� ��
		return 0;
	}
	else { //������ �������� B�� �ڿ� ���� ��
		return 1;
	}
}

int dir_change(int dir_info) {
	if (dir_info == 0) {
		return 2;
	}
	else if (dir_info == 1) {
		return 3;
	}
	else if (dir_info == 2) {
		return 0;
	}
	else if (dir_info == 3) {
		return 1;
	}
}

void exit_the_bid(int cur_r_y,int cur_r_x, int cur_b_y, int cur_b_x, int dir_info, int cnt) {
	bool R_goal = false, B_goal = false;
	int R_cnt = 0, B_cnt = 0;

	if (cnt > 10) {
		return;
	}

	map[cur_r_y][cur_r_x] = '.';//Red�� �ϴ� ������ �ٲ�.

	while (1) { //Red ������
		R_cnt++;
		cur_r_y += dir[dir_info][0];
		cur_r_x += dir[dir_info][1];

		if (map[cur_r_y][cur_r_x] == '#') {
			cur_r_y -= dir[dir_info][0];
			cur_r_x -= dir[dir_info][1];
			break;
		}
		else if (map[cur_r_y][cur_r_x] == 'O') {//Red Goal in
			R_goal = true;
			break;
		}
	}
	
	map[cur_b_y][cur_b_x] = '.';//Blue�� �ϴ� ������ �ٲ�.

	while (1) { //Blue ������
		B_cnt++;
		cur_b_y += dir[dir_info][0];
		cur_b_x += dir[dir_info][1];

		if (map[cur_b_y][cur_b_x] == '#') {
			cur_b_y -= dir[dir_info][0];
			cur_b_x -= dir[dir_info][1];
			break;
		}
		else if (map[cur_b_y][cur_b_x] == 'O') { // Blue Goal in
			B_goal = true;
			break;
		}
	}

	if (cur_r_y == cur_b_y && cur_r_x == cur_b_x && !B_goal
		&& !R_goal) { //��ģ�ٸ� ?
		int order = locate_the_bid(R_cnt, B_cnt);
		
		if (order == 0) { //������ �������� R�� �ڿ�
			map[cur_b_y][cur_b_x] = 'B';
			cur_r_y -= dir[dir_info][0];
			cur_r_x -= dir[dir_info][1];
			map[cur_r_y][cur_r_x] = 'R';
		}
		else {//B�� �ڿ�
			map[cur_r_y][cur_r_x] = 'R';
			cur_b_y -= dir[dir_info][0];
			cur_b_x -= dir[dir_info][1];
			map[cur_b_y][cur_b_x] = 'B';
		}
	}

	if (B_goal) { //Blue�� ���� �� �ʿ� ���� �Լ� exit
		return;
	}
	else {
		if (R_goal) { // Blue�� ������ �ʰ� Red�� ���Դٸ�, ���� ��
			ans = min(ans, cnt);
			return;
		}
	}
	
	for (int i = 0; i < 4; i++) {
		if (i == dir_info) {
			continue;
		}
		if (i == dir_change(dir_info)) {
			continue;
		}
		exit_the_bid(cur_r_y, cur_r_x, cur_b_y, cur_b_x, i, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				r_y = i;
				r_x = j;
			}
			else if (map[i][j] == 'B') {
				b_y = i;
				b_x = j;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		exit_the_bid(r_y,r_x,b_y,b_x,i, 1);
	}

	if (ans == 987654321) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}