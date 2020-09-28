/*
ó�� ����� ��� ĭ�� 5��ŭ �������.
1x1ĭ�� ���� ������ �ɾ��� ���� ���� ����.
�� - ������ �ڽ��� ���̸�ŭ ��� �԰� ���̰� +1��
	������ ������ �� ĭ�� ��и� ���� �� ����
	���̰� � �������� ����� �Դ´�.
	����� �����Ͽ� �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����

���� - ���� ���� ������ ������� ����.
	  ���� �������� ������ /2�� ���� ������� �߰���.

���� - ������ ������. �����ϴ� ������ ���̰� 5�� ���������
	  ������ 8���� ĭ�� ���̰� 1�� ������ �����.
	  ���� ��� ���� ������x

�ܿ� - ���� ����� �߰�.

result => K�� �� ���� ����ִ� ������ ����
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, tree_num, years, ans = 0;
int nutrient[12][12];
int temp_nutrient[12][12];
int die[12][12];
int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0}
					,{1,-1},{0,-1} };
vector<int> trees_info[12][12];

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void cnt_the_trees() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += trees_info[i][j].size();
		}
	}
}
void spring_and_summer() {
	int idx = 0, pop_cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int size = trees_info[i][j].size();
			for (int k = 0; k < size; k++) {
				if (trees_info[i][j][k] <= nutrient[i][j]) {
					nutrient[i][j] -= trees_info[i][j][k];
					trees_info[i][j][k]++;
				}
				else {
					idx = k;
					for (int m = idx; m < size; m++) {
						die[i][j] += trees_info[i][j][m] / 2;
						pop_cnt++;
					}
					break;
				}
			}
			while (pop_cnt > 0) {
				trees_info[i][j].pop_back();
				pop_cnt--;
			}
		}
	}
}
void autumn() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int size = trees_info[i][j].size();
			for (int k = 0; k < size; k++) {
				if (trees_info[i][j][k] % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						int my = i + dir[l][0];
						int mx = j + dir[l][1];

						if (Inbound(my, mx)) {
							trees_info[my][mx].push_back(1);
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (trees_info[i][j].size() > 1) {
				sort(trees_info[i][j].begin(), trees_info[i][j].end());
			}
			nutrient[i][j] += (temp_nutrient[i][j] + die[i][j]);
			die[i][j] = 0;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> tree_num >> years;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			nutrient[i][j] = 5;
			cin >> temp_nutrient[i][j];
		}
	}

	for (int i = 1; i <= tree_num; i++) {
		int input_x, input_y, input_age;
		cin >> input_y >> input_x >> input_age;

		trees_info[input_y][input_x].push_back(input_age);
	}

	while (years > 0) {
		spring_and_summer();
		autumn();
		winter();
		years--;
	}
	cnt_the_trees();

	cout << ans << '\n';

	return 0;
}