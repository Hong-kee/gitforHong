#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int my_card[500001];
int tmp_check_card[500001];
int check_card[500001];

void merge(int left, int right) {
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (check_card[i] <= check_card[j]) {
			tmp_check_card[k++] = check_card[i++];
		}
		else {
			tmp_check_card[k++] = check_card[j++];
		}
	}

	int tmp = i > mid ? j : i;
	while (k <= right) {
		tmp_check_card[k++] = check_card[tmp++];
	}
	for (int i = left; i <= right; i++) {
		check_card[i] = tmp_check_card[i];
	}
}

void partition(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> check_card[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> my_card[i];
	}

	partition(0, N-1);

	for (int i = 0; i < M; i++) {
		if (binary_search(check_card, check_card + N, my_card[i])) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}

	return 0;
}
