#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, K, ans = 0;
string s;
vector<string>sentence;
char alpha[26] = { 'a','n','t','i','c','b','d','e','f','g',
				'h','j','k','l','m','o','p','q','r','s',
				'u','v','w','x','y','z' };
bool check_alpha[26];

void read_word() {
	int temp_ans = 0;
	bool flag = true;

	for (int i = 0; i < sentence.size(); i++) {
		for (int j = 0; j < sentence[i].size(); j++) {
			for (int k = 0; k < 26; k++) {
				if (alpha[k] == sentence[i][j]) {
					if (!check_alpha[k]) {
						flag = false;
						break;
					}
					else {
						break;
					}
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) {
			temp_ans++;
		}
		else {
			flag = true;
		}
	}
	ans = max(ans, temp_ans);
}

void select_alpha(int idx, int cnt) {
	if (cnt == K-5) {
		read_word();
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (!check_alpha[i]) {
			check_alpha[i] = true;
			select_alpha(i, cnt + 1);
			check_alpha[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	if (K < 5) {
		cout << 0 << '\n';
		return 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			cin >> s;
			sentence.push_back(s);
		}
		for (int i = 0; i < 5; i++) {
			check_alpha[i] = true;
		}
		select_alpha(5, 0);
	}
	cout << ans << '\n';
	return 0;
}