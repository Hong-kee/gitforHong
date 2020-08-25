/*중복조합으로 풀기*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int select_num[5];
int map[21][21];
int copy_map[21][21];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//북,동,남,서
bool visit[21][21];

void play_the_2048(int idx) {
	int direction = select_num[idx];

	if (direction == 0) { //북
		for (int i = 1; i <= N; i++) { //가로
			for (int j = 2; j <= N; j++) { //세로
				int ny = j; //init
				int nx = i;

				while (ny <= N && ny >= 2) { //ny가 맵 안에 index라면
					if (map[ny][nx] == 0 || visit[ny - 1][nx]) {
						break;
					}
					if (map[ny - 1][nx] == 0) { //위에 없으면
						map[ny - 1][nx] = map[ny][nx];
						map[ny][nx] = 0;
						ny--;
					}
					else if (map[ny - 1][nx] != 0 && !visit[ny - 1][nx] //위에 있고 합쳐지지 않았고 값이 같다면
						&& map[ny - 1][nx] == map[ny][nx]) {
						visit[ny - 1][nx] = true;
						map[ny][nx] = 0;
						map[ny - 1][nx] *= 2;
						break;
					}
					else if (map[ny - 1][nx] != 0 && !visit[ny - 1][nx] //위에 있고 합쳐지지 않았고 값이 다르다면
						&& map[ny - 1][nx] != map[ny][nx]) {
						break;
					}
				}
			}
		}
	}
	else if (direction == 1) { //동
		for (int i = 1; i <= N; i++) { //세로
			for (int j = N - 1; j >= 1; j--) { //가로
				int ny = i; //init
				int nx = j;

				while (nx >= 1 && nx <= N - 1) { //nx가 맵 안에 index라면
					if (map[ny][nx] == 0 || visit[ny][nx + 1]) {
						break;
					}
					if (map[ny][nx + 1] == 0) { //오른쪽에 없으면
						map[ny][nx + 1] = map[ny][nx];
						map[ny][nx] = 0;
						nx++;
					}
					else if (map[ny][nx + 1] != 0 && !visit[ny][nx + 1] //오른쪽에 있고 합쳐지지 않았고 값이 같다면
						&& map[ny][nx + 1] == map[ny][nx]) {
						visit[ny][nx + 1] = true;
						map[ny][nx] = 0;
						map[ny][nx + 1] *= 2;
						break;
					}
					else if (map[ny][nx + 1] != 0 && !visit[ny][nx + 1] //오른쪽에 있고 합쳐지지 않았고 값이 다르다면
						&& map[ny][nx + 1] != map[ny][nx]) {
						break;
					}
				}
			}
		}
	}
	else if (direction == 2) { //남
		for (int i = 1; i <= N; i++) { //가로
			for (int j = N - 1; j >= 1; j--) { //세로
				int ny = j; //init
				int nx = i;

				while (ny >= 1 && ny <= N - 1) { //ny가 맵 안에 index라면
					if (map[ny][nx] == 0 || visit[ny + 1][nx]) {
						break;
					}
					if (map[ny + 1][nx] == 0) { //아래에 없으면
						map[ny + 1][nx] = map[ny][nx];
						map[ny][nx] = 0;
						ny++;
					}
					else if (map[ny + 1][nx] != 0 && !visit[ny + 1][nx] //아래에 있고 합쳐지지 않았고 값이 같다면
						&& map[ny + 1][nx] == map[ny][nx]) {
						visit[ny + 1][nx] = true;
						map[ny][nx] = 0;
						map[ny + 1][nx] *= 2;
						break;
					}
					else if (map[ny + 1][nx] != 0 && !visit[ny + 1][nx] //아래에 있고 합쳐지지 않았고 값이 다르면
						&& map[ny + 1][nx] != map[ny][nx]) {
						break;
					}
				}
			}
		}
	}
	else if (direction == 3) { //서
		for (int i = 1; i <= N; i++) { //세로
			for (int j = 2; j <= N; j++) { //가로
				int ny = i; //init
				int nx = j;

				while (nx <= N && nx >= 2) { //nx가 맵 안에 index라면
					if (map[ny][nx] == 0 || visit[ny][nx - 1]) {
						break;
					}
					if (map[ny][nx - 1] == 0) { //왼쪽에 없으면
						map[ny][nx - 1] = map[ny][nx];
						map[ny][nx] = 0;
						nx--;
					}
					else if (map[ny][nx - 1] != 0 && !visit[ny][nx - 1] //왼쪽에 있고 합쳐지지 않았고 값이 같다면
						&& map[ny][nx - 1] == map[ny][nx]) {
						visit[ny][nx - 1] = true;
						map[ny][nx] = 0;
						map[ny][nx - 1] *= 2;
						break;
					}
					else if (map[ny][nx - 1] != 0 && !visit[ny][nx - 1] //왼쪽에 있고 합쳐지지 않았고 값이 다르다면
						&& map[ny][nx - 1] != map[ny][nx]) {
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) { //방문 초기화
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
		}
	}
}

void select_dir(int cnt_num) { //중복조합
	if (cnt_num == 5) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = copy_map[i][j];//배열 초기화
			}
		}
		for (int i = 0; i < 5; i++) {
			play_the_2048(i); //5번 만큼 돌기
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				ans = max(ans, map[i][j]);//최댓값 뽑아내기
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		select_num[cnt_num] = i;
		select_dir(cnt_num + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
		}
	}
	select_dir(0);

	cout << ans << '\n';
	return 0;
}