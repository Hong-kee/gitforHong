/*
1. +, -, *, /의 배열을 만들어준다.
2. 그 후 갯수들을 배열에 넣어준다.
3. DFS처리를 통해 값 계산.(연산자는 중복조합 이용)
4. 최댓 값과 최솟 값 뽑아내기.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, max_num = -1000000001, min_num = 1000000001, ans;
int operator_num[4];
int num[11];
vector<int>op;

void operator_the_value() {
	ans = num[0];
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == 0) {
			ans += num[i + 1];
		}
		else if (op[i] == 1) {
			ans -= num[i + 1];
		}
		else if (op[i] == 2) {
			ans *= num[i + 1];
		}
		else if (op[i] == 3) {
			if (ans < 0) {
				ans = abs(ans) / num[i + 1];
				ans = -ans;
			}
			else {
				ans /= num[i + 1];
			}
		}
	}
}

void select_the_op(int cnt) {
	if (cnt == N - 1) {
		operator_the_value();
		max_num = max(ans, max_num);
		min_num = min(ans, min_num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operator_num[i] == 0) {
			continue;
		}
		else {
			operator_num[i]--;
			op.push_back(i);
			select_the_op(cnt + 1);
			operator_num[i]++;
			op.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];//값 입력 받기
	}
	for (int i = 0; i < 4; i++) {
		cin >> operator_num[i];
	}
	select_the_op(0);//연산자 중복조합으로 뽑기
	cout << max_num << '\n' << min_num << '\n';
}