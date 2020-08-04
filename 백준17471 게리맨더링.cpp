////구역은 2개로 나뉘어 있으므로 만약 n = 10이면 10C1 + 10C2....+10C5까지만 계산. 즉, 절반만 계산하면 됨
//// 1. 조합으로 선거구를 구별한다.
//// 2. 각 선거구가 맞는 선거구와 연결되어있는지 판별
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cmath>
//using namespace std;
//
//int N, connect, ans = 987654321, temp_ans = 0;
//bool map[11][11];
//int person[11];
//bool visit[11];
//bool area[11];
//vector<int> A, B;
//queue<int> Q;
//
//void person_cal() {
//	int A_total = 0, B_total = 0;
//
//	for (int i = 1; i <= N; i++) {
//		if (area[i]) {
//			A_total += person[i];
//		}
//		else {
//			B_total += person[i];
//		}
//	}
//	temp_ans = abs(A_total - B_total);
//}
//
//bool A_connect_area() {
//	int cnt = 1;
//
//	for (int i = 1; i <= N; i++) {//A선거구 연결되어있는지 파악
//		visit[i] = false;
//	}
//	Q.push(A[0]);
//	visit[A[0]] = true;
//
//	while (!Q.empty()) {
//		int cur = Q.front();
//		Q.pop();
//
//		for (int i = 1; i <= N; i++) {
//			if (map[cur][i] == true && area[i] == true && visit[i] == false) {
//				visit[i] = true;
//				cnt++;
//				Q.push(i);
//			}
//		}
//	}
//	if (A.size() != cnt) {
//		return false;
//	}
//	return true;
//}
//
//bool B_connect_area() {
//	int cnt = 1;
//
//	for (int i = 1; i <= N; i++) {//B선거구 연결되어있는지 파악
//		visit[i] = false;
//	}
//	Q.push(B[0]);
//	visit[B[0]] = true;
//
//	while (!Q.empty()) {
//		int cur = Q.front();
//		Q.pop();
//
//		for (int i = 1; i <= N; i++) {
//			if (map[cur][i] == true && area[i] == false && visit[i] == false) {
//				visit[i] = true;
//				cnt++;
//				Q.push(i);
//			}
//		}
//	}
//	if (B.size() != cnt) {
//		return false;
//	}
//	return true;
//}
//
//void pick(int idx, int cnt) {
//	if (cnt >= 1) {
//		if (cnt == N) {
//			return;
//		}
//		//선거구 나누기
//		A.clear(); B.clear();
//		for (int i = 1; i <= N; i++) {
//			if (area[i]) {
//				A.push_back(i);
//			}
//			else {
//				B.push_back(i);
//			}
//		}
//		//연결되어있는지 체크함수, 계산
//		temp_ans = 0;
//		if (A_connect_area() && B_connect_area()) {
//			person_cal();
//			if (ans > temp_ans) {
//				ans = temp_ans;
//			}
//		}
//	}
//	for (int i = idx; i <= N; i++) {
//		if (area[i]) {
//			continue;
//		}
//		area[i] = true;
//		pick(i, cnt + 1);
//		area[i] = false;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {//각 구역에 인원 받기
//		cin >> person[i];
//	}
//
//	for (int i = 1; i <= N; i++) { // map만들기
//		int value;
//		cin >> connect;
//		for (int j = 1; j <= connect; j++) {
//			cin >> value;
//			map[i][value] = true;
//			map[value][i] = true;
//		}
//	}
//	pick(1, 0);
//
//	if (ans == 987654321) {
//		cout << -1 << '\n';
//	}
//	else {
//		cout << ans << '\n';
//	}
//
//	return 0;
//}