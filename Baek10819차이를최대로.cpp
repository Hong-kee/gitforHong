//DFS
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N,M,g=-1;
int a[9];
int b[9];
bool v[9];

void f(int d, int c) {
	if (c == N) {
		int t = 0;
		for (int i = 1; i < N; i++) {
			t += abs(b[i] - b[i + 1]);
		}
		if (g < t) {
			g = t;
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!v[i]) {
			b[i] = a[d];
			v[i] = true;
			f(d + 1, c + 1);
			v[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> M;
		a[i] = M;
	}
	f(1, 0);
	cout << g << '\n';
}