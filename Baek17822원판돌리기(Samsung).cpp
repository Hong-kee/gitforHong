/*
1. 첫 원판과 끝 원판 index 잘 따져주기(Out of range 조심)
2. 바뀐 것들을 True처리 해주고 True처리 된 것들 다 0으로, 그 후 bool초기화
3. 만일 같은 것이 하나도 없으면 평균 값을 구해서
   평균보다 크면 그 값 -1, 작으면 그 값 +1

result=> 원판에 적힌 수의 합
*/
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> score_board[51];
bool check[51][51];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int board_num, score_num, turn, num, ans = 0;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 0 && y <= board_num && x < score_num) {
		return true;
	}
	return false;
}

void cnt_the_score() { //갯수 카운트
	for (int i = 1; i <= board_num; i++) {
		for (int j = 0; j < score_num; j++) {
			ans += score_board[i][j];
		}
	}
}

void turn_the_board(int multiple, int turn_dir, int turn_cnt){
	//배수에 따라 회전
	bool flag = false;
	double temp_score = 0, temp_cnt = 0;

	for (int i = multiple; i <= board_num; i += multiple) {
		for (int j = 1; j <= turn_cnt; j++) {
			if (turn_dir == 0) {//시계방향
				score_board[i].push_front(score_board[i][score_num - 1]);
				score_board[i].pop_back();
			}
			else {//반시계방향
				score_board[i].push_back(score_board[i][0]);
				score_board[i].pop_front();
			}
		}
	}
	//인접하는 것들이 같으면 지운다, 0이면 그냥 넘어가기, 지우면 0으로
	for (int i = 1; i <= board_num; i++) {
		for (int j = 0; j < score_num; j++) {
			//0이면 넘어가기
			if (score_board[i][j] == 0) {
				continue;
			}
			if (j == 0) {
				if (score_board[i][0] == score_board[i][score_num - 1]) {
					check[i][0] = true;
					check[i][score_num - 1] = true;
				}
			}
			for (int k = 0; k < 4; k++) {
				int my = i + dir[k][0];
				int mx = j + dir[k][1];

				if (Inbound(my, mx)) {
					if (score_board[i][j] == score_board[my][mx]) {
						check[i][j] = true;
						check[my][mx] = true;
					}
				}
			}
		}
	}
	//True들 0처리
	for (int i = 1; i <= board_num; i++) {
		for (int j = 0; j < score_num; j++) {
			if (check[i][j]) {
				score_board[i][j] = 0;
				flag = true;
			}
			check[i][j] = false;
		}
	}
	//만일 지워지는게 없다면 ?
	if (!flag) {
		for (int i = 1; i <= board_num; i++) {
			for (int j = 0; j < score_num; j++) {
				if (score_board[i][j] > 0) {
					temp_score += score_board[i][j];
					temp_cnt++;
				}
			}
		}
		if (temp_cnt > 0) {
			temp_score /= temp_cnt;

			for (int i = 1; i <= board_num; i++) {
				for (int j = 0; j < score_num; j++) {
					if (score_board[i][j] == 0) {
						continue;
					}
					if (score_board[i][j] > temp_score) {
						score_board[i][j]--;
					}
					else if (score_board[i][j] < temp_score) {
						score_board[i][j]++;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int multiple, turn_dir, turn_cnt;
	cin >> board_num >> score_num >> turn;

	for (int i = 1; i <= board_num; i++) {
		for (int j = 1; j <= score_num; j++) {
			cin >> num;
			score_board[i].push_back(num);
		}
	}
	while (turn > 0) {
		cin >> multiple >> turn_dir >> turn_cnt;
		turn_the_board(multiple, turn_dir, turn_cnt);
		turn--;
	}
	cnt_the_score();
	cout << ans << '\n';

	return 0;
}