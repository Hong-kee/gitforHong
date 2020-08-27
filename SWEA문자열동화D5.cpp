#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2, s3;
	int T,L,cnt,ans=0,i=0;

	cin >> T;

	while (T--) {
		cin >> L;
		
		cin >> s1;
		cin >> s2;
		cin >> s3;

		ans = 0;
		for (int i = 0; i < L; i++) {
			cnt = 0;
			if (s1[i] != s2[i]) {
				cnt++;
			}
			if (s1[i] != s3[i]) {
				cnt++;
			}
			if (s2[i] != s3[i]) {
				cnt++;
			}

			if (cnt == 0) {
				cnt = 1;
			}
			ans += cnt -1;
		}
		cout << '#' << ++i << ' ' << ans << '\n';
	}
}