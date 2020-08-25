/*�ߺ��������� Ǯ��*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int select_num[5];
int map[21][21];
int copy_map[21][21];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//��,��,��,��
bool visit[21][21];

void play_the_2048(int idx) {
	int direction = select_num[idx];

	if (direction == 0) { //��
		for (int i = 1; i <= N; i++) { //����
			for (int j = 2; j <= N; j++) { //����
				int ny = j; //init
				int nx = i;

				while (ny <= N && ny >= 2) { //ny�� �� �ȿ� index���
					if (map[ny][nx] == 0 || visit[ny - 1][nx]) {
						break;
					}
					if (map[ny - 1][nx] == 0) { //���� ������
						map[ny - 1][nx] = map[ny][nx];
						map[ny][nx] = 0;
						ny--;
					}
					else if (map[ny - 1][nx] != 0 && !visit[ny - 1][nx] //���� �ְ� �������� �ʾҰ� ���� ���ٸ�
						&& map[ny - 1][nx] == map[ny][nx]) {
						visit[ny - 1][nx] = true;
						map[ny][nx] = 0;
						map[ny - 1][nx] *= 2;
						break;
					}
					else if (map[ny - 1][nx] != 0 && !visit[ny - 1][nx] //���� �ְ� �������� �ʾҰ� ���� �ٸ��ٸ�
						&& map[ny - 1][nx] != map[ny][nx]) {
						break;
					}
				}
			}
		}
	}
	else if (direction == 1) { //��
		for (int i = 1; i <= N; i++) { //����
			for (int j = N - 1; j >= 1; j--) { //����
				int ny = i; //init
				int nx = j;

				while (nx >= 1 && nx <= N - 1) { //nx�� �� �ȿ� index���
					if (map[ny][nx] == 0 || visit[ny][nx + 1]) {
						break;
					}
					if (map[ny][nx + 1] == 0) { //�����ʿ� ������
						map[ny][nx + 1] = map[ny][nx];
						map[ny][nx] = 0;
						nx++;
					}
					else if (map[ny][nx + 1] != 0 && !visit[ny][nx + 1] //�����ʿ� �ְ� �������� �ʾҰ� ���� ���ٸ�
						&& map[ny][nx + 1] == map[ny][nx]) {
						visit[ny][nx + 1] = true;
						map[ny][nx] = 0;
						map[ny][nx + 1] *= 2;
						break;
					}
					else if (map[ny][nx + 1] != 0 && !visit[ny][nx + 1] //�����ʿ� �ְ� �������� �ʾҰ� ���� �ٸ��ٸ�
						&& map[ny][nx + 1] != map[ny][nx]) {
						break;
					}
				}
			}
		}
	}
	else if (direction == 2) { //��
		for (int i = 1; i <= N; i++) { //����
			for (int j = N - 1; j >= 1; j--) { //����
				int ny = j; //init
				int nx = i;

				while (ny >= 1 && ny <= N - 1) { //ny�� �� �ȿ� index���
					if (map[ny][nx] == 0 || visit[ny + 1][nx]) {
						break;
					}
					if (map[ny + 1][nx] == 0) { //�Ʒ��� ������
						map[ny + 1][nx] = map[ny][nx];
						map[ny][nx] = 0;
						ny++;
					}
					else if (map[ny + 1][nx] != 0 && !visit[ny + 1][nx] //�Ʒ��� �ְ� �������� �ʾҰ� ���� ���ٸ�
						&& map[ny + 1][nx] == map[ny][nx]) {
						visit[ny + 1][nx] = true;
						map[ny][nx] = 0;
						map[ny + 1][nx] *= 2;
						break;
					}
					else if (map[ny + 1][nx] != 0 && !visit[ny + 1][nx] //�Ʒ��� �ְ� �������� �ʾҰ� ���� �ٸ���
						&& map[ny + 1][nx] != map[ny][nx]) {
						break;
					}
				}
			}
		}
	}
	else if (direction == 3) { //��
		for (int i = 1; i <= N; i++) { //����
			for (int j = 2; j <= N; j++) { //����
				int ny = i; //init
				int nx = j;

				while (nx <= N && nx >= 2) { //nx�� �� �ȿ� index���
					if (map[ny][nx] == 0 || visit[ny][nx - 1]) {
						break;
					}
					if (map[ny][nx - 1] == 0) { //���ʿ� ������
						map[ny][nx - 1] = map[ny][nx];
						map[ny][nx] = 0;
						nx--;
					}
					else if (map[ny][nx - 1] != 0 && !visit[ny][nx - 1] //���ʿ� �ְ� �������� �ʾҰ� ���� ���ٸ�
						&& map[ny][nx - 1] == map[ny][nx]) {
						visit[ny][nx - 1] = true;
						map[ny][nx] = 0;
						map[ny][nx - 1] *= 2;
						break;
					}
					else if (map[ny][nx - 1] != 0 && !visit[ny][nx - 1] //���ʿ� �ְ� �������� �ʾҰ� ���� �ٸ��ٸ�
						&& map[ny][nx - 1] != map[ny][nx]) {
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) { //�湮 �ʱ�ȭ
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
		}
	}
}

void select_dir(int cnt_num) { //�ߺ�����
	if (cnt_num == 5) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = copy_map[i][j];//�迭 �ʱ�ȭ
			}
		}
		for (int i = 0; i < 5; i++) {
			play_the_2048(i); //5�� ��ŭ ����
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				ans = max(ans, map[i][j]);//�ִ� �̾Ƴ���
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