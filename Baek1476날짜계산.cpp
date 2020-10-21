#include <iostream>
using namespace std;

int main() {
	int ESM[3] = { 1,1,1 };
	int E, S, M, answer = 1;

	cin >> E >> S >> M;

	while (!(ESM[0] == E && ESM[1] == S && ESM[2] == M)) {
		for (int i = 0; i <= 2; i++) {
			ESM[i]++;
		}
		if (ESM[0] > 15) {
			ESM[0] = 1;
		}
		if (ESM[1] > 28) {
			ESM[1] = 1;
		}
		if (ESM[2] > 19) {
			ESM[2] = 1;
		}
		answer++;
	}
	cout << answer << '\n';
}