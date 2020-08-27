/*
1. 치킨집을 벡터에 넣는다.
2. 조합으로 뽑은 벡터와 집과의 거리비교
3. ans 값이 최소인 것을 뽑으면 끗!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int map[51][51];
int N, ans = 987654321, M, temp_ans, temp = 0;
bool alive_chicken[13];

vector<pair<int,int>>chicken;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void chicken_delivery(int y, int x){ //bfs로 배달
	temp_ans = 987654321;
	for (int i = 0; i < chicken.size();i++) {
		if (alive_chicken[i]) {
			temp_ans = min(temp_ans, abs(y - chicken[i].first) + abs(x - chicken[i].second));
		}
	}
	temp += temp_ans;
}

void select_the_chicken(int idx, int check) {
	if (check == M) {
		temp = 0;
		for (int i = 1; i <= N; i++) { //배달 시작
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 1) {
					chicken_delivery(i, j);
				}
			}
		}
		if (ans > temp) {
			ans = temp;
		}
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (!alive_chicken[i]) {
			alive_chicken[i] = true;
			select_the_chicken(i, check + 1);
			alive_chicken[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chicken.push_back(make_pair(i,j)); //치킨집들 다 넣기
			}
		}
	}
	select_the_chicken(0,0);
	cout << ans << '\n';
	return 0;
}