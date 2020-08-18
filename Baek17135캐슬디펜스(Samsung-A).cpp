#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int map[17][17];
int copy_map[17][17];
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };//��,��,��,��
bool visit[15];
bool map_visit[17][17];
bool flag = false;
int archer_distance, r, c, ans = 0, kda, enemy_num = 0, kill;
vector<pair<int,int>>possible_archer;
queue<pair<pair<int, int>, int>>archer;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= r + 1 && x <= c) {
		return true;
	}
	return false;
}

void move_enemy() {
	for (int i = r; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			if (i == r) {
				if (copy_map[i][j] == 1) {
					kill--;
				}
			}
			else {
				if (copy_map[i][j] == 3) {
					copy_map[i + 1][j] = 0;
				}
				else {
					copy_map[i + 1][j] = copy_map[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= c; i++) {
		copy_map[1][i] = 0;
	}
}

void defence_the_castle() {
	kill = enemy_num;
	kda = 0;
	
	while (!(kill == 0)) {
		for (int i = 0; i < possible_archer.size(); i++) {
			if (!visit[i]) {//�ü� 1�� �� Kill
				continue;
			}
			for (int i = 1; i <= r; i++) { // �ü��� �湮�� �� �ʱ�ȭ
				for (int j = 1; j <= c; j++) {
					map_visit[i][j] = false;
				}
			}
			flag = false;
			archer.push(make_pair(make_pair(r + 1, possible_archer[i].second), 0));

			while (!archer.empty()) {
				int size_of_archer = archer.size();
				
				for (int i = 0; i < size_of_archer; i++) {

					int y = archer.front().first.first;
					int x = archer.front().first.second;
					int count = archer.front().second;

					archer.pop();

					for (int i = 0; i < 4; i++) {
						int my = y + dir[i][0];
						int mx = x + dir[i][1];

						if (!Inbound(my, mx) || (count >= archer_distance) || map_visit[my][mx]) {
							continue;
						}
						if (copy_map[my][mx] == 0) { // 0�� �� �Ÿ� ���� Ž��
							map_visit[my][mx] = true;
							archer.push(make_pair(make_pair(my, mx), count + 1));
						}
						else if (copy_map[my][mx] == 2) { // 2�� �� �Ÿ� ���� Ž��
							map_visit[my][mx] = true;
							archer.push(make_pair(make_pair(my, mx), count + 1));
						}
						else if (copy_map[my][mx] == 1){ // 1�� �� Kill. ������ 3���� ����� ��.(���ļ� �´°� ���)
							copy_map[my][mx] = 3;
							kill--;
							kda++;
							flag = true;
						}
						else if (copy_map[my][mx] == 3) { // Kill���� �� �ٷ� 0���� ������ ����(���� �� ��)
							flag = true;
						}

						if (flag) { //Kill log
							break;
						}
					}
					if (flag) { // Kill log�� �߸� ��
						while (!archer.empty()) {
							archer.pop();
						}
						break;
					}
				}
			}

		}
		move_enemy();
	}
}

void locate_archer(int idx, int cnt) { //�ü� ��ġ ����
	if (cnt == 3) {
		for (int i = 1; i <= r; i++) { // �� �ʱ�ȭ
			for (int j = 1; j <= c; j++) {
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < possible_archer.size(); i++) {
			if (visit[i]) { //�ü���ġ
				copy_map[r + 1][possible_archer[i].second] = 2;
			}
		}

		defence_the_castle();
		ans = max(ans, kda);
		return;
	}
	for (int i = 0; i < possible_archer.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			locate_archer(i, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> archer_distance;

	for (int i = 1; i <= r; i++) { // �� �Է�
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
			if (map[i][j] == 1) {
				enemy_num++;
			}
		}
	}

	for (int i = 1; i <= c; i++) { // �ü� �ʱ�ȭ
		map[r + 1][i] = -1;
		possible_archer.push_back(make_pair(r + 1, i));
	}

	locate_archer(0, 0);
	cout << ans << '\n';

	return 0;
}