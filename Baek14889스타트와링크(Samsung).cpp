/*
1. Start, Link 팀의 Combination으로 팀 나눔->vector에 저장
2. 최솟값 찾기!
3. nCr의 반만 계산하면 됨.(123 456과 456 123은 같으므로)
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, ans = 987654321;
int board[21][21];
bool team[21], start_visit[10], link_visit[10];
vector<int>start, link;

void calculate_status() {
	int start_sum = 0, link_sum = 0, diff = -1;

	for (int i = 0; i < start.size(); i++) {
		for (int j = i; j < start.size(); j++) {
			start_sum += board[start[i]][start[j]];
			start_sum += board[start[j]][start[i]];
		}
	}


	for (int i = 0; i < link.size(); i++) {
		for (int j = i; j < link.size(); j++) {
			link_sum += board[link[i]][link[j]];
			link_sum += board[link[j]][link[i]];
		}
	}
	diff = abs(start_sum - link_sum);

	if (ans > diff) {
		ans = diff;
	}
	return;
}

void div_team(int person, int cnt, int idx, int total_cnt, int temp_cnt) {
	if (person == cnt) {
		if (total_cnt >= temp_cnt) {
			for (int i = 1; i <= N; i++) {
				if (team[i]) {
					start.push_back(i);
				}
				else {
					link.push_back(i);
				}
			}
			calculate_status();
			start.clear();
			link.clear();
		}
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (!team[i]) {
			team[i] = true;
			div_team(person, cnt + 1, i, total_cnt, temp_cnt + 1);
			team[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	unsigned long long total_cnt = 1, div_cnt = 1;

	for (int i = total_cnt; i <= N; i++) {
		total_cnt *= i;
	}
	for (int i = div_cnt; i <= N / 2; i++) {
		div_cnt *= i;
	}
	total_cnt /= (div_cnt * div_cnt);

	div_team(N / 2, 0, 1, total_cnt, 0);
	cout << ans << '\n';

	return 0;
}