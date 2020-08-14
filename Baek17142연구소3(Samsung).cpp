//1.vector에 바이러스들의 좌표를 넣고 조합.
//2.조합으로 뽑힌 좌표들을 큐에 넣어주고 bfs 돌림(virus_visit이용)
//3.bfs를 돌릴 때 좌표와 cnt 값을 넣어 줌
//4. 큐가 empty일 때, dfs로 돌아가서 0이 있으면 return. 
//   아니면 최솟값 출력
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, virus_num, ans = 987654321, zero_num = 0, del_num, one_num = 0, spread_time;
int map[51][51];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool visit[51][51];
bool virus_visit[10];
queue<pair<pair<int,int>,int>>Q;
vector<pair<int,int>>virus_pos;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void spread_virus() {
	del_num = N * N - virus_pos.size() - one_num;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
		}
	}

	for (int i = 0; i < virus_pos.size(); i++) {
		if (virus_visit[i] == true) {
			visit[virus_pos[i].first][virus_pos[i].second] = true;
			Q.push(make_pair(make_pair(virus_pos[i].first,virus_pos[i].second),0));
		}
	}

	while (!Q.empty()) {
		int size_of_Q = Q.size();

		for (int i = 0; i < size_of_Q; i++) {
			if (del_num == 0) {
				ans = min(ans, spread_time);
				while (!Q.empty()) {
					Q.pop();
				}
				return;
			}
			int y = Q.front().first.first;
			int x = Q.front().first.second;
			spread_time = Q.front().second;

			Q.pop();

			for (int i = 0; i < 4; i++) {
				int my = y + dir[i][0];
				int mx = x + dir[i][1];

				if (Inbound(my, mx) && !visit[my][mx] && map[my][mx] == 0) {
					Q.push(make_pair(make_pair(my,mx), spread_time + 1));
					visit[my][mx] = true;
					del_num--;
				}
				else if (Inbound(my, mx) && !visit[my][mx] && map[my][mx] == 2) {
					Q.push(make_pair(make_pair(my, mx), spread_time + 1));
					visit[my][mx] = true;
				}
			}
		}
	}
}

void select_virus(int idx, int cnt) {
	if (cnt == virus_num) {
		spread_virus();
		return;
	}
	else {
		for (int i = idx; i < virus_pos.size(); i++) {
			if (!virus_visit[i]) {
				virus_visit[i] = true;
				select_virus(i, cnt + 1);
				virus_visit[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> virus_num;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				one_num++;
			}
			if (map[i][j] == 2) {
				virus_pos.push_back(make_pair(i,j));
			}
			if (map[i][j] == 0) {
				zero_num++;
			}
		}
	}
	select_virus(0, 0);

	if (ans == 987654321) {
		cout << -1 << '\n';
		return 0;
	}
	if (zero_num == 0) {
		cout << 0 << '\n';
		return 0;
	}
	cout << ans + 1 << '\n';

	return 0;
}

