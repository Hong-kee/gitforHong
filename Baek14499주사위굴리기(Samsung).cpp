/*

1. map�Է� ����.
2. ���� : 1�� ����, 2�� ����, 3�� ����, 4�� ����
3. dice�迭 ����� : 0�� ��, 1�� �Ʒ�, 2�� ��, 3�� ��, 4�� ��, 5�� ��
4. ����, ��ǥ���� �迭�� �Ѿ�� ���x, But, ��ǥ�� ��� �������ֱ�
5. map�� 0�̸� �ֻ��� �ٴ�(idx:1)���� map�� ����.
   map�� 0�� �ƴϸ� map�� ���� �ֻ��� �Ʒ� ���� ����ǰ� map = 0.
6. ������ map �ȿ� ���� ��, �ֻ��� ����(idx:0)�� �ִ� �� ����ϱ�

*/
#include <iostream>
using namespace std;

int map[20][20];
int dice[6] = { 0,0,0,0,0,0 };//��,�Ʒ�,��,��,��,��
int dir[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
//x, ��, ��, ��, ��
int cmd_num, cmd, r, c, tmp;

bool Inbound(int y, int x) {
	if (y >= 0 && x >= 0 && y < r && x < c) {
		return true;
	}
	return false;
}

void roll_the_dice(int y, int x) {

	for (int i = 0; i < cmd_num; i++) {
		cin >> cmd;

		int my = y + dir[cmd][0];//move
		int mx = x + dir[cmd][1];

		if (!Inbound(my, mx)) { //������� ó��
			continue;
		}
		else {
			y = my; //init
			x = mx;
			if (cmd == 1) {//��
				tmp = dice[5];
				dice[5] = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[1];
				dice[1] = tmp;
			}
			else if (cmd == 2) {//��
				tmp = dice[4];
				dice[4] = dice[0];
				dice[0] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
			}
			else if (cmd == 3) {//��
				tmp = dice[3];
				dice[3] = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[1];
				dice[1] = tmp;
			}
			else if (cmd == 4) {//��
				tmp = dice[2];
				dice[2] = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[1];
				dice[1] = tmp;
			}
			
			if (map[my][mx] == 0) { //map = 0�� ��
				map[my][mx] = dice[1];
			}
			else { //�׷��� �ʴٸ�
				dice[1] = map[my][mx];
				map[my][mx] = 0;
			}
			cout << dice[0] << '\n'; //���� ���
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int f_y, f_x;

	cin >> r >> c >> f_x >> f_y >> cmd_num;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	roll_the_dice(f_y,f_x);

	return 0;
}