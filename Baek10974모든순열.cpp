//DFS
#include <iostream>
using namespace std;

int N;
int arr[9];
int a[9];
bool visit[9];

void f(int idx, int cnt) {
	if (cnt == N) {
		for (int i = 1; i <= N; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			a[idx] = i;
			visit[i] = true;
			f(idx + 1, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N;
	f(1,0);
}