//#include <iostream>
//#include <queue>
//#include <vector>
//#include <utility>
//using namespace std;
//
//int map[50][50];
//int map_copy[50][50];
//int R, C, T, dir_cnt = 0, ans = 0;
//int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//북동남서
//queue<pair<int, int>> q;
//vector<pair<int, int>> robot;
//
//void Spread_dust()
//{
//	while (!q.empty())
//	{
//		int y = q.front().first;
//		int x = q.front().second;
//
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int M_Y = y + dir[i][0];
//			int M_X = x + dir[i][1];
//
//			if (M_Y >= 0 && M_X >= 0 && M_Y < C && M_X < R)
//			{
//				if (map[M_Y][M_X] != -1)
//				{
//					map_copy[M_Y][M_X] += (map[y][x] / 5);
//					dir_cnt++;
//				}
//			}
//
//		}
//		map_copy[y][x] += map[y][x] - (map[y][x] / 5)*dir_cnt;
//		dir_cnt = 0;
//	}
//}
//
//void Blow_wind()
//{
//	for (int i = robot[0].first - 2; i > -1; i--)//위쪽
//	{
//		map_copy[i + 1][0] = map_copy[i][0];
//	}
//	for (int i = 1; i <= R - 1; i++)
//	{
//		map_copy[0][i - 1] = map_copy[0][i];
//	}
//	for (int i = 1; i <= robot[0].first; i++)
//	{
//		map_copy[i - 1][R - 1] = map_copy[i][R - 1];
//	}
//	for (int i = R - 2; i > 0; i--)
//	{
//		map_copy[robot[0].first][i + 1] = map_copy[robot[0].first][i];
//	}
//	map_copy[robot[0].first][1] = 0;
//
//
//	for (int i = robot[1].first + 2; i <= C - 1; i++)//아래쪽
//	{
//		map_copy[i - 1][0] = map_copy[i][0];
//	}
//	for (int i = 1; i <= R - 1; i++)
//	{
//		map_copy[C - 1][i - 1] = map_copy[C - 1][i];
//	}
//	for (int i = C - 2; i >= robot[1].first; i--)
//	{
//		map_copy[i + 1][R-1] = map_copy[i][R-1];
//	}
//	for (int i = R - 2; i > 0; i--)
//	{
//		map_copy[robot[1].first][i + 1] = map_copy[robot[1].first][i];
//	}
//	map_copy[robot[1].first][1] = 0;
//
//	for (int i = 0; i < C; i++)
//	{
//		for (int j = 0; j < R; j++)
//		{
//			map[i][j] = map_copy[i][j];
//			map_copy[i][j] = 0;
//			if (map[i][j] > 0)
//			{
//				q.push(pair<int, int>(i, j));
//			}
//		}
//	}
//	map[robot[0].first][robot[0].second] = -1;
//	map[robot[1].first][robot[1].second] = -1;
//	map_copy[robot[0].first][robot[0].second] = -1;
//	map_copy[robot[1].first][robot[1].second] = -1;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> C >> R >> T;
//
//	for (int i = 0; i < C; i++)
//	{
//		for (int j = 0; j < R; j++)
//		{
//			cin >> map[i][j];
//
//			if (map[i][j] == -1)
//			{
//				map_copy[i][j] = -1;
//				robot.push_back(pair<int, int>(i, j));
//			}
//
//			if (map[i][j] != 0 && map[i][j] != -1)
//			{
//				q.push(pair<int, int>(i, j));
//			}
//		}
//	}
//	while (T--)
//	{
//		Spread_dust();
//		Blow_wind();
//	}
//
//	for (int i = 0; i < C; i++)
//	{
//		for (int j = 0; j < R; j++)
//		{
//			if (map[i][j] == -1)
//			{
//				continue;
//			}
//			else
//			{
//				ans += map[i][j];
//			}
//		}
//	}
//	cout << ans << '\n';
//}