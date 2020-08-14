#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[26][26];
bool visit[26][26];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int N, data_num, area_num = 0;
vector<int>data_info;
queue<pair<int, int>>Q;

bool Inbound(int y, int x) {
	if (y >= 1 && x >= 1 && y <= N && x <= N) {
		return true;
	}
	return false;
}

void patch(int y, int x) {
	data_num = 1;
	Q.push(make_pair(y, x));

	while (!Q.empty()) {
		int size_of_Q = Q.size();

		for (int i = 0; i < size_of_Q; i++) {
			int ny = Q.front().first;
			int nx = Q.front().second;
			Q.pop();

			for (int j = 0; j < 4; j++) {
				int my = ny + dir[j][0];
				int mx = nx + dir[j][1];

				if (Inbound(my, mx) && !visit[my][mx] && map[my][mx] == 1) {
					Q.push(make_pair(my, mx));
					visit[my][mx] = true;
					data_num++;
				}
			}
		}
	}
	data_info.push_back(data_num);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				visit[i][j] = true;
				patch(i,j);
				area_num++;
			}
		}
	}
	cout << area_num << '\n';
	sort(data_info.begin(), data_info.end());
	for (int i = 0; i < data_info.size(); i++) {
		cout << data_info[i] << '\n';
	}
	return 0;
}