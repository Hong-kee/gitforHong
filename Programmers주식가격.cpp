#include <iostream>
#include <vector>
using namespace std;

vector<int>prices, answer;
int num;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> num;
		prices.push_back(num);
	}

	for (int i = 0; i < prices.size(); i++) {
		int idx = i + 1 , days = 0;

		for (int j = idx; j < prices.size(); j++) {
			days++;
			if (prices[i] > prices[j]){
				break;
			}
		}
		answer.push_back(days);
	}

	for (int i = 0; i < 5; i++) {
		cout << answer[i] << ' ';
	}
}