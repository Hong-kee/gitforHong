//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int>dragon_generator[11];
//int map[101][101];
//int cnt, x, y, dir, gen, ans = 0;
//int dir_info[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };//x,y
//
//void dragon_curve(int x, int y, int dir, int gen) {
//	int real_x = x;
//	int real_y = y;
//
//	map[real_x][real_y] = 1;
//
//	for (int i = 0; i < dragon_generator[gen].size(); i++) {
//		int M_X = real_x + dir_info[dragon_generator[gen][i]][0];
//		int M_Y = real_y + dir_info[dragon_generator[gen][i]][1];
//
//		real_x = M_X;
//		real_y = M_Y;
//
//		map[M_X][M_Y] = 1;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> cnt;
//
//	for (int i = 0; i < cnt; i++) {
//		cin >> x >> y >> dir >> gen;
//
//		dragon_generator[0].push_back(dir);
//
//		for (int i = 1; i <= gen; i++) {
//			dragon_generator[i] = dragon_generator[i - 1];
//			for (int j = dragon_generator[i - 1].size() - 1; j >= 0; j--) {
//				if ((dragon_generator[i - 1][j] + 1) >= 4) {
//					dragon_generator[i].push_back((dragon_generator[i - 1][j] + 1) % 4);
//				}
//				else {
//					dragon_generator[i].push_back(dragon_generator[i - 1][j] + 1);
//				}
//			}
//		}
//
//		dragon_curve(x, y, dir, gen);
//
//		for (int i = 0; i <= gen; i++) {
//			dragon_generator[i].clear();
//		}
//	}
//
//	for (int i = 0; i < 100; i++) {
//		for (int j = 0; j < 100; j++) {
//			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1 &&
//				map[i][j + 1] == 1) {
//				ans++;
//			}
//		}
//	}
//	cout << ans << '\n';
//
//	return 0;
//}