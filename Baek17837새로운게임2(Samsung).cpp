/*
1. ü���� : 0�� ���, 1�� ������, 2�� �Ķ���

2.  ����� ��� : �̵��� ���� �� ���� �÷�����
	�������� ��� : �̵��� ������ �ݴ�� �����ؼ� �ø�
	�Ķ����� ��� : (1) �̵� ������ �ݴ�� �ϰ� �� ĭ �̵�
				  (2) �ݴ�� �ٲٰ� �̵��Ϸ��µ� ����ų�
					  �Ķ����� ��� ���⸸ �ٲ���

3. �� ĭ�� size�� ��ü ���� ������ ������ ���� ����

4. ���� ���� ����ϵ�, ���� ���� 1000���� ũ�� -1���
*/
#include <iostream>
#include <vector>
using namespace std;

struct pos {
	int y;
	int x;
	int dir_of_mal;
};
vector<int> position[13][13];
vector<pos> mal_info;
int dir[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };//�����ϳ�
int ans = 0, N, K;
int map[14][14];

int change_the_dir(int d) {
	if (d == 1) {
		return 2;
	}
	else if (d == 2) {
		return 1;
	}
	else if (d == 3) {
		return 4;
	}
	else {
		return 3;
	}
}

bool check_the_finish() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (position[i][j].size() >= 4) {
				return false;
			}
		}
	}
	return true;
}

void move_the_mal() {
	int p,c=0;
	while (ans <= 1000) {
		ans++;
		for (int i = 0; i < mal_info.size(); i++) {
			int dir_of_mal = mal_info[i].dir_of_mal;
			int y = mal_info[i].y;
			int x = mal_info[i].x;

			int my = y + dir[dir_of_mal][0];
			int mx = x + dir[dir_of_mal][1];

			for (int j = 0; j < position[y][x].size(); j++) {
				if (position[y][x][j] == i) {
					p = j;
					break;
				}
			}

			if (map[my][mx] == 0) {//White
				int size_of_q = position[y][x].size();
				for (int n = p; n < size_of_q; n++) {
					position[my][mx].push_back(position[y][x][n]);
					mal_info[position[y][x][n]].y = my;
					mal_info[position[y][x][n]].x = mx;
					c++;
				}
				while (c != 0) {
					position[y][x].pop_back();
					c--;
				}
			}
			else if (map[my][mx] == 1) {//Red
				int size_of_q = position[y][x].size();
				for (int n = size_of_q - 1; n >= p; n--) {
					position[my][mx].push_back(position[y][x][n]);
					mal_info[position[y][x][n]].y = my;
					mal_info[position[y][x][n]].x = mx;
					c++;
				}
				while (c != 0) {
					position[y][x].pop_back();
					c--;
				}
			}
			else {//Blue or Out of range
				dir_of_mal = change_the_dir(dir_of_mal);
				mal_info[i].dir_of_mal = dir_of_mal;

				int my = y + dir[dir_of_mal][0];
				int mx = x + dir[dir_of_mal][1];

				for (int j = 0; j < position[y][x].size(); j++) {
					if (position[y][x][j] == i) {
						p = j;
						break;
					}
				}

				if (map[my][mx] == 0) {//White
					int size_of_q = position[y][x].size();
					for (int n = p; n < size_of_q; n++) {
						position[my][mx].push_back(position[y][x][n]);
						mal_info[position[y][x][n]].y = my;
						mal_info[position[y][x][n]].x = mx;
						c++;
					}
					while (c != 0) {
						position[y][x].pop_back();
						c--;
					}
				}
				else if (map[my][mx] == 1) {//Red
					int size_of_q = position[y][x].size();
					for (int n = size_of_q - 1; n >= p; n--) {
						position[my][mx].push_back(position[y][x][n]);
						mal_info[position[y][x][n]].y = my;
						mal_info[position[y][x][n]].x = mx;
						c++;
					}
					while (c != 0) {
						position[y][x].pop_back();
						c--;
					}
				}
				else {
					mal_info[i].dir_of_mal = dir_of_mal;
				}
			}
			if (!check_the_finish()) {
				return;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i <= 13; i++) {
		for (int j = 0; j <= 13; j++) {
			map[i][j] = -1;
		}
	}

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	int r, c, d;

	for (int i = 0; i < K; i++) {
		cin >> r >> c >> d;
		mal_info.push_back({ r,c,d });
		position[r][c].push_back(i);
	}
	move_the_mal();

	if (ans == 1001) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}