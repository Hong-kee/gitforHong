//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int r, c, k, ans = 0, leng = 0, temp_leng = -1, sero = -1;
//int map[100][100];
//int copy_map[100][100];
//vector<pair<int, int>> v;
//int num[101];
//
//bool cmp(pair<int, int> &a, pair<int, int> &b) {
//	if (a.second == b.second) {
//		a.first < b.first;
//	}
//	return a.second < b.second;
//
//}
//
//void R_cal() {  //r >= c
//
//	
//	for (int i = 0; i < sero; i++) {
//		for (int j = 0; j < temp_leng; j++) {
//			if (map[i][j] == 0 || map[i][j] == -1) {
//				continue;
//			}
//			else {
//				num[map[i][j]]++;
//			}
//		}
//
//		for (int k = 1; k <= 100; k++) {
//			if (num[k] > 0) {
//				v.push_back(make_pair(k,num[k]));
//			}
//			else {
//				continue;
//			}
//		}
//
//		sort(v.begin(), v.end(), cmp);
//
//		leng = v.size() * 2;
//
//		if (leng > 100) {
//			leng = 100;
//		}
//
//		if (leng > temp_leng) {
//			temp_leng = leng;
//		}
//
//		int u = 0;
//		for (int m = 0; m < v.size() * 2; m+=2) {
//			if (m >= 100) {
//				break;
//			}
//			else {
//				copy_map[i][m] = v[u].first;
//				copy_map[i][m + 1] = v[u].second;
//			}
//			u++;
//		}
//		v.clear();
//		for (int q = 1; q <= 100; q++) {
//			num[q] = 0;
//		}
//	}
//
//	for (int n = 0; n < sero; n++) {
//		for (int l = 0; l < temp_leng; l++) {
//			if (copy_map[n][l] == -1) {
//				copy_map[n][l] = 0;
//			}
//		}
//	}
//	ans++;
//}
//
//void C_cal() {  //r < c 
//
//	for (int i = 0; i < temp_leng; i++) {
//		for (int j = 0; j < sero; j++) {
//			if (map[j][i] == 0 || map[j][i] == -1) {
//				continue;
//			}
//			else {
//				num[map[j][i]]++;
//			}
//		}
//
//		for (int k = 1; k <= 100; k++) {
//			if (num[k] > 0) {
//				v.push_back(make_pair(k, num[k]));
//			}
//			else {
//				continue;
//			}
//		}
//
//
//		sort(v.begin(), v.end(), cmp);
//
//		leng = v.size() * 2;
//
//		if (leng > 100) {
//			leng = 100;
//		}
//
//		if (leng > sero) {
//			sero = leng;
//		}
//
//		int u = 0;
//		for (int m = 0; m < v.size() * 2; m+=2) {
//			if (m >= 100) {
//				break;
//			}
//			else {
//				copy_map[m][i] = v[u].first;
//				copy_map[m+1][i] = v[u].second;
//			}
//			u++;
//		}
//		v.clear();
//
//		for (int q = 1; q <= 100; q++) {
//			num[q] = 0;
//		}
//	}
//
//	for (int n = 0; n < temp_leng; n++) {
//		for (int l = 0; l < sero; l++) {
//			if (copy_map[l][n] == -1) {
//				copy_map[l][n] = 0;
//			}
//		}
//	}
//	ans++;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> r >> c >> k;
//
//	for (int i = 0; i < 100; i++) { //mapÃÊ±âÈ­
//		for (int j = 0; j < 100; j++){
//			map[i][j] = -1;
//			copy_map[i][j] = -1;
//		} 
//	}
//
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++) {
//			cin >> map[i][j];
//		}
//	}
//	temp_leng = 3;
//	sero = 3;
//
//	while (1) {
//		if (map[r - 1][c - 1] == k) {
//			break;
//		}
//
//		if (ans > 100) {
//			break;
//		}
//
//		if (temp_leng <= sero) {
//			R_cal();
//		}
//		else {
//			C_cal();
//		}
//
//		for (int i = 0; i < 100; i++) {
//			for (int j = 0; j < 100; j++) {
//				map[i][j] = -1;
//				map[i][j] = copy_map[i][j];
//				copy_map[i][j] = -1;
//			}
//		}
//	}
//
//	if (ans > 100) {
//		cout << "-1" << '\n';
//	}
//	else {
//		cout << ans << '\n';
//	}
//
//	return 0;
//}
