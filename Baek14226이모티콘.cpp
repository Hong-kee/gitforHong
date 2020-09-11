/*
1. BFS이용
2. 만일 현재 값이 원하는 값보다 크면 queue에 넣지 않음
3. check_map[cur][copy]를 이용하여 방문한적이 있으면 queue에 넣지 않음
4. 최솟값 받은 후 함수 종료
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool check_map[1001][1001];
struct pos{
	int cur_num;
	int copy_num;
	int cnt;
};
queue<pos>Q;
int S, ans = 0;

void emoticon() {
	Q.push({ 1,0,0 });

	while (!Q.empty()) {
		int size_of_Q = Q.size();

		for (int i = 0; i < size_of_Q; i++) {
			int cur = Q.front().cur_num;
			int copy = Q.front().copy_num;
			int cur_cnt = Q.front().cnt;

			Q.pop();

			if (cur < 0) {
				continue;
			}
			if (S == cur) {
				ans = cur_cnt;
				return;
			}
			else {
				if (S > cur && !check_map[cur][copy]) {
					check_map[cur][copy] = true;
					Q.push({ cur, cur, cur_cnt + 1 });
					if (copy != 0) {
						Q.push({ cur + copy, copy, cur_cnt + 1 });
					}
					Q.push({ cur - 1 ,copy, cur_cnt + 1 });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> S;

	emoticon();
	cout << ans << '\n';
	return 0;
}