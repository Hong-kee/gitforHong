/*

1. map입력 받음.
2. 방향 : 1은 동쪽, 2는 서쪽, 3은 북쪽, 4는 남쪽
3. dice배열 만들기 : 0은 위, 1은 아래, 2는 앞, 3은 뒤, 4는 왼, 5는 오
4. 만일, 좌표값이 배열을 넘어가면 출력x, But, 좌표는 계속 움직여주기
5. map이 0이면 주사위 바닥(idx:1)값이 map에 복사.
   map이 0이 아니면 map의 값이 주사위 아래 값에 복사되고 map = 0.
6. 굴리고 map 안에 있을 때, 주사위 윗면(idx:0)에 있는 값 출력하기

*/
#include <iostream>
using namespace std;

int map[20][20];
int dice[6] = { 0,0,0,0,0,0 };//위,아래,앞,뒤,왼,오
int dir[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
//x, 동, 서, 북, 남
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

		if (!Inbound(my, mx)) { //경계조건 처리
			continue;
		}
		else {
			y = my; //init
			x = mx;
			if (cmd == 1) {//동
				tmp = dice[5];
				dice[5] = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[1];
				dice[1] = tmp;
			}
			else if (cmd == 2) {//서
				tmp = dice[4];
				dice[4] = dice[0];
				dice[0] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
			}
			else if (cmd == 3) {//북
				tmp = dice[3];
				dice[3] = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[1];
				dice[1] = tmp;
			}
			else if (cmd == 4) {//남
				tmp = dice[2];
				dice[2] = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[1];
				dice[1] = tmp;
			}
			
			if (map[my][mx] == 0) { //map = 0일 떄
				map[my][mx] = dice[1];
			}
			else { //그렇지 않다면
				dice[1] = map[my][mx];
				map[my][mx] = 0;
			}
			cout << dice[0] << '\n'; //윗면 출력
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