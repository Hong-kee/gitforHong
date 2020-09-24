/*
1. Brute-Force
2. [5][8] 배열생성//12시 방향에서 시계 방향으로 저장
3. 1은 시계 방향, -1은 반시계 방향
3-1. 그 옆의 톱니 극이 다르다면 선택 톱니바퀴의 방향과 반대로 회전
3-2. 먼저 회전 할 수 있는지 Check
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
			gear[1].push_front(gear[1][7]);//시계
			gear[1].pop_back();
		}
		else {
			gear[1].push_back(gear[1][0]);
			gear[1].pop_front();
		}

		if (dir == 1 && check[0]) {
			gear[2].push_back(gear[2][0]);//반시계
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
			gear[2].push_front(gear[2][7]);//시계
			gear[2].pop_back();
			if (check[1]) {
				gear[3].push_back(gear[3][0]);
				gear[3].pop_front();
				if (check[2]) {
					gear[4].push_front(gear[4][7]);//시계
					gear[4].pop_back();
				}
			}
		}
	}
	else if (gear_num == 2) {
		if (dir == 1) {
			gear[2].push_front(gear[2][7]);//시계
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
			gear[1].push_front(gear[1][7]);//시계
			gear[1].pop_back();
		}

		if (dir == 1 && check[1]) {
			gear[3].push_back(gear[3][0]);
			gear[3].pop_front();
			if (check[2]) {
				gear[4].push_front(gear[4][7]);//시계
				gear[4].pop_back();
			}
		}
		else if (dir == -1 && check[1]) {
			gear[3].push_front(gear[3][7]);//시계
			gear[3].pop_back();
			if (check[2]) {
				gear[4].push_back(gear[4][0]);
				gear[4].pop_front();
			}
		}
	}
	else if (gear_num == 3) {
		if (dir == 1) {
			gear[3].push_front(gear[3][7]);//시계
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
			gear[4].push_front(gear[4][7]);//시계
			gear[4].pop_back();
		}

		if (dir == 1 && check[1]) {
			gear[2].push_back(gear[2][0]);
			gear[2].pop_front();
			if (check[0]) {
				gear[1].push_front(gear[1][7]);//시계
				gear[1].pop_back();
			}
		}
		else if (dir == -1 && check[1]) {
			gear[2].push_front(gear[2][7]);//시계
			gear[2].pop_back();
			if (check[0]) {
				gear[1].push_back(gear[1][0]);
				gear[1].pop_front();
			}
		}
	}
	else{
		if (dir == 1) {
			gear[4].push_front(gear[4][7]);//시계
			gear[4].pop_back();
		}
		else {
			gear[4].push_back(gear[4][0]);
			gear[4].pop_front();
		}

		if (dir == 1 && check[2]) {
			gear[3].push_back(gear[3][0]);//반시계
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
			gear[3].push_front(gear[3][7]);//시계
			gear[3].pop_back();
			if (check[1]) {
				gear[2].push_back(gear[2][0]);
				gear[2].pop_front();
				if (check[0]) {
					gear[1].push_front(gear[1][7]);//시계
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
			gear[i].push_back(gear_info);//톱니바퀴 값 입력, N은 0, S는 1
		}
	}

	cin >> turn_info;

	for (int i = 0; i < turn_info; i++) {
		cin >> gear_num >> dir;//톱니번호와 방향
		turn_the_gear();
	}
	cout << gear[1][0] + gear[2][0]*2 + gear[3][0]*4 + gear[4][0]*8 << '\n';

	return 0;
}