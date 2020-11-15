#include <iostream>
#include <algorithm>
using namespace std;

int card_num;
int card_price[1001] = { 0, }, dp[1001] = { 0, };

int main() {
	cin >> card_num;

	for (int i = 1; i <= card_num; i++) {
		cin >> card_price[i];
	}
	for (int i = 1; i <= card_num; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card_price[j]);
		}
	}
	
	cout << dp[card_num] << '\n';
}