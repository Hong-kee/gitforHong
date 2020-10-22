//DFS using vector STL and Back-tracking
#include <iostream>
#include <vector>
using namespace std;

vector<int>_connect[2001];
bool visit[2001];
bool flag = false;
int people, relation;

void searching_the_friend(int idx, int cnt) {
	if (cnt == 4) {
		flag = true;
		return;
	}
	for (int i = 0; i < _connect[idx].size(); i++) {
		if (!visit[_connect[idx][i]]) {
			visit[_connect[idx][i]] = true;
			searching_the_friend(_connect[idx][i], cnt + 1);
			visit[_connect[idx][i]] = false;
		}
		if (flag) {
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int idx_1, idx_2;

	cin >> people >> relation;

	for (int i = 1; i <= relation; i++) {
		cin >> idx_1 >> idx_2;
		_connect[idx_1].push_back(idx_2);
		_connect[idx_2].push_back(idx_1);
	}
	for (int i = 0; i < people; i++) {
		visit[i] = true;
		searching_the_friend(i, 0);
		visit[i] = false;
		if (flag) {
			break;
		}
	}
	if (flag) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
	return 0;
}