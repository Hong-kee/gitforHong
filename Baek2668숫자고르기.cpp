#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = -1;
int number_map[101];
bool visit[101];
vector<int>number;

void select_number(int idx, int first) {
	if (visit[idx]) {
		if (idx != first) {
			for (int i = 1; i <= N; i++) {
				visit[i] = false;
			}
			return;
		}
		else {
			ans = 0;
			for (int i = 1; i <= N; i++) {
				if (visit[i]) {
					number.push_back(i);
				}
			}
			for (int i = 1; i <= N; i++) {
				visit[i] = false;
			}
			return;
		}

	}

	for (int i = idx; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			select_number(number_map[i], first);
			return;
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> number_map[i];
	}

	for (int i = 1; i <= N; i++) {
		select_number(i,i);
	}

	if (ans != -1) {
		for (int i = 1; i <= N; i++) {
			if (visit[i]) {
				number.push_back(i);
			}
		}
		sort(number.begin(), number.end());
		number.erase(unique(number.begin(), number.end()), number.end());
		ans = number.size();
		cout << ans << '\n';
		for (int i = 0; i < number.size(); i++) {
			cout << number[i] << '\n';
		}
	}

	else {
		for (int i = 1; i <= N; i++) {
			visit[i] = false;
		}
		for (int i = 1; i <= N; i++) {
			if (number_map[i] == i) {
				visit[i] = true;
			}
		}
		ans = 0;
		for (int i = 1; i <= N; i++) {
			if (visit[i]) {
				ans++;
			}
		}
		cout << ans << '\n';

		for (int i = 1; i <= N; i++) {
			if (number_map[i] == i) {
				cout << i << '\n';
				break;
			}
		}
	}

	return 0;
}