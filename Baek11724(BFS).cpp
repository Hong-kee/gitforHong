#include <iostream>
#include <vector>
#include <queue>

using namespace std;
queue<int>Q;
vector<int>map[1001];
bool visit[1001];
int N, M, Apex_1, Apex_2, ans = 0;

void bfs(int Apex) {
	visit[Apex] = true;
	Q.push(Apex);

	while (!Q.empty()) {
		Apex = Q.front();
		Q.pop();
		for (int i = 0; i < map[Apex].size(); i++) {
			if (!visit[map[Apex][i]]) {
				visit[map[Apex][i]] = true;
				Q.push(map[Apex][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> Apex_1 >> Apex_2;

		map[Apex_1].push_back(Apex_2);
		map[Apex_2].push_back(Apex_1);
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			bfs(i);
			ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}