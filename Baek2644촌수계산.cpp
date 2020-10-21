#include <iostream>
using namespace std;

bool arr[101][101];
bool visit[101][101];
int answer = 0, people, _first, _end, relation, a, b;

void search_the_relation(int f, int e, int temp) {
	if ((f == _end)) {
		answer = temp;
		return;
	}
	for (int i = 1; i <= people; i++) {
		if (!visit[f][i]) {
			if (arr[f][i] == true) {
				visit[f][i] = true;
				visit[i][f] = true;
				search_the_relation(i, 1, temp + 1);
				visit[f][i] = false;
				visit[i][f] = false;
			}
		}
	}
}

int main() {
	cin >> people;
	cin >> _first >> _end;
	cin >> relation;

	for (int i = 1; i <= relation; i++) {
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}
	search_the_relation(_first, 1, 0);

	if (answer != 0) {
		cout << answer << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}