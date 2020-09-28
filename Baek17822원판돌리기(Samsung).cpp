/*
1. ù ���ǰ� �� ���� index �� �����ֱ�(Out of range ����)
2. �ٲ� �͵��� Trueó�� ���ְ� Trueó�� �� �͵� �� 0����, �� �� bool�ʱ�ȭ
3. ���� ���� ���� �ϳ��� ������ ��� ���� ���ؼ�
   ��պ��� ũ�� �� �� -1, ������ �� �� +1

result=> ���ǿ� ���� ���� ��
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

void cnt_the_score() { //���� ī��Ʈ
	for (int i = 1; i <= board_num; i++) {
		for (int j = 0; j < score_num; j++) {
			ans += score_board[i][j];
		}
	}
}

void turn_the_board(int multiple, int turn_dir, int turn_cnt){
	//����� ���� ȸ��
	bool flag = false;
	double temp_score = 0, temp_cnt = 0;

	for (int i = multiple; i <= board_num; i += multiple) {
		for (int j = 1; j <= turn_cnt; j++) {
			if (turn_dir == 0) {//�ð����
				score_board[i].push_front(score_board[i][score_num - 1]);
				score_board[i].pop_back();
			}
			else {//�ݽð����
				score_board[i].push_back(score_board[i][0]);
				score_board[i].pop_front();
			}
		}
	}
	//�����ϴ� �͵��� ������ �����, 0�̸� �׳� �Ѿ��, ����� 0����
	for (int i = 1; i <= board_num; i++) {
		for (int j = 0; j < score_num; j++) {
			//0�̸� �Ѿ��
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
	//True�� 0ó��
	for (int i = 1; i <= board_num; i++) {
		for (int j = 0; j < score_num; j++) {
			if (check[i][j]) {
				score_board[i][j] = 0;
				flag = true;
			}
			check[i][j] = false;
		}
	}
	//���� �������°� ���ٸ� ?
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