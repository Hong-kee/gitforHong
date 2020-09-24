/*
1. Brute-Force
2. [5][8] �迭����//12�� ���⿡�� �ð� �������� ����
3. 1�� �ð� ����, -1�� �ݽð� ����
3-1. �� ���� ��� ���� �ٸ��ٸ� ���� ��Ϲ����� ����� �ݴ�� ȸ��
3-2. ���� ȸ�� �� �� �ִ��� Check
4. LEGO~
*/
#pragma warning(disable:4996)
#include <iostream>
#include <deque>
using namespace std;

deque<int> gear[5];
bool check[3];
int turn_info, gear_num, dir, gear_info;

void check_the_turn() {
	if (gear[1][2] == gear[2][6]) {
		check[0] = false;
	}
	else {
		check[0] = true;
	}
	if (gear[2][2] == gear[3][6]) {
		check[1] = false;
	}
	else {
		check[1] = true;
	}
	if (gear[3][2] == gear[4][6]) {
		check[2] = false;
	}
	else {
		check[2] = true;
	}
}

void turn_the_gear() {
	check_the_turn();

	if (gear_num == 1) {
		if (dir == 1) {
			gear[1].push_front(gear[1][7]);//�ð�
			gear[1].pop_back();
		}
		else {
			gear[1].push_back(gear[1][0]);
			gear[1].pop_front();
		}

		if (dir == 1 && check[0]) {
			gear[2].push_back(gear[2][0]);//�ݽð�
			gear[2].pop_front();
			if (check[1]) {
				gear[3].push_front(gear[3][7]);
				gear[3].pop_back();
				if (check[2]) {
					gear[4].push_back(gear[4][0]);
					gear[4].pop_front();
				}
			}
		}
		else if (dir == -1 && check[0]) {
			gear[2].push_front(gear[2][7]);//�ð�
			gear[2].pop_back();
			if (check[1]) {
				gear[3].push_back(gear[3][0]);
				gear[3].pop_front();
				if (check[2]) {
					gear[4].push_front(gear[4][7]);//�ð�
					gear[4].pop_back();
				}
			}
		}
	}
	else if (gear_num == 2) {
		if (dir == 1) {
			gear[2].push_front(gear[2][7]);//�ð�
			gear[2].pop_back();
		}
		else {
			gear[2].push_back(gear[2][0]);
			gear[2].pop_front();
		}


		if (dir == 1 && check[0]) {
			gear[1].push_back(gear[1][0]);
			gear[1].pop_front();
		}
		else if (dir == -1 && check[0]) {
			gear[1].push_front(gear[1][7]);//�ð�
			gear[1].pop_back();
		}

		if (dir == 1 && check[1]) {
			gear[3].push_back(gear[3][0]);
			gear[3].pop_front();
			if (check[2]) {
				gear[4].push_front(gear[4][7]);//�ð�
				gear[4].pop_back();
			}
		}
		else if (dir == -1 && check[1]) {
			gear[3].push_front(gear[3][7]);//�ð�
			gear[3].pop_back();
			if (check[2]) {
				gear[4].push_back(gear[4][0]);
				gear[4].pop_front();
			}
		}
	}
	else if (gear_num == 3) {
		if (dir == 1) {
			gear[3].push_front(gear[3][7]);//�ð�
			gear[3].pop_back();
		}
		else {
			gear[3].push_back(gear[3][0]);
			gear[3].pop_front();
		}

		if (dir == 1 && check[2]) {
			gear[4].push_back(gear[4][0]);
			gear[4].pop_front();
		}
		else if (dir == -1 && check[2]) {
			gear[4].push_front(gear[4][7]);//�ð�
			gear[4].pop_back();
		}

		if (dir == 1 && check[1]) {
			gear[2].push_back(gear[2][0]);
			gear[2].pop_front();
			if (check[0]) {
				gear[1].push_front(gear[1][7]);//�ð�
				gear[1].pop_back();
			}
		}
		else if (dir == -1 && check[1]) {
			gear[2].push_front(gear[2][7]);//�ð�
			gear[2].pop_back();
			if (check[0]) {
				gear[1].push_back(gear[1][0]);
				gear[1].pop_front();
			}
		}
	}
	else{
		if (dir == 1) {
			gear[4].push_front(gear[4][7]);//�ð�
			gear[4].pop_back();
		}
		else {
			gear[4].push_back(gear[4][0]);
			gear[4].pop_front();
		}

		if (dir == 1 && check[2]) {
			gear[3].push_back(gear[3][0]);//�ݽð�
			gear[3].pop_front();
			if (check[1]) {
				gear[2].push_front(gear[2][7]);
				gear[2].pop_back();
				if (check[0]) {
					gear[1].push_back(gear[1][0]);
					gear[1].pop_front();
				}
			}
		}
		else if (dir == -1 && check[2]) {
			gear[3].push_front(gear[3][7]);//�ð�
			gear[3].pop_back();
			if (check[1]) {
				gear[2].push_back(gear[2][0]);
				gear[2].pop_front();
				if (check[0]) {
					gear[1].push_front(gear[1][7]);//�ð�
					gear[1].pop_back();
				}
			}
		}
	}
}

int main() {
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear_info);
			gear[i].push_back(gear_info);//��Ϲ��� �� �Է�, N�� 0, S�� 1
		}
	}

	cin >> turn_info;

	for (int i = 0; i < turn_info; i++) {
		cin >> gear_num >> dir;//��Ϲ�ȣ�� ����
		turn_the_gear();
	}
	cout << gear[1][0] + gear[2][0]*2 + gear[3][0]*4 + gear[4][0]*8 << '\n';

	return 0;
}