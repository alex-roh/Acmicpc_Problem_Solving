#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool B[20];
int buttonCnt;

int findApprox(string str) {

	int approx = 0;

	bool isSearchingForMax = false;
	bool isSearchingForMin = false;

	int base = str.size() - 1;
	for (signed int i = 0; i < str.size(); i++) {

		int cur = str[i] - '0';
		cout << "cnr = " << cur << ", ";

		// 1. 무조건 큰 수를 찾아야 하는 경우 
		if (isSearchingForMax) {
			int max = -1;
			for (int j = 0; j = 9; j++) {
				if (B[j] == false && j > max) {
					max = j;
				}
			}
			approx += max * pow(10, base);
			buttonCnt++;
			cout << "searchingForMax, ";
		}
		// 2. 무조건 작은 수를 찾아야 하는 경우 
		else if (isSearchingForMin) {
			int min = 99;
			for (int j = 0; j = 9; j++) {
				if (B[j] == false && j < min) {
					min = j;
				}
			}
			approx += min * pow(10, base);
			buttonCnt++;
			cout << "searchingForMin, ";
		}
		// 3. 아직 확정되지 않은 경우 
		else {
			// 버튼이 없는 경우 
			if (B[cur]) {
				cout << "thereIsNoButton, ";

				// 남아있는 버튼 중 cur과 가장 가까운 근사치를 찾음 
				int shortestDis = 99; int nearestButton = 0;
				for (int j = 0; j <= 9; j++) {
					int dis = abs(cur - j);
					if (dis < shortestDis && B[j] == false) {
						shortestDis = dis;
						nearestButton = j;
					}
				}

				approx += nearestButton * pow(10, base);
				buttonCnt++;

				// 근사치가 버튼보다 크다면 앞으로 무조건 작은 수를 찾음 
				if (nearestButton > cur) {
					isSearchingForMin = true;
				}
				// 근사치가 버튼보다 작다면 앞으로 무조건 큰 수를 찾음 
				else {
					isSearchingForMax = true;
				}

			}
			else {
				approx += cur * pow(10, base);
				buttonCnt++;
				cout << "thereIsAButton, ";
			}
		}
		cout << "approx = " << approx << "\n";
		base--;
	}

	return approx;
}

int main(int argc, char** argv) {

	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	string str = to_string(N);

	// 입력 99, 100, 101에 대한 예외 처리 
	if (N == 99) {
		cout << 1;
		return 0;
	}
	if (N == 100) {
		cout << 0;
		return 0;
	}
	if (N == 101) {
		cout << 1;
		return 0;
	}

	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int index;
		cin >> index;
		B[index] = true;
	}

	int approx = findApprox(str);
	cout << "approx is " << approx << ", buttonCnt is " << buttonCnt << "\n";

	// 근사치가 채널과 같으면
	if (approx == N) {
		cout << buttonCnt << "\n";
	}
	// 근사치가 채널보다 작으면 
	else if (approx < N) {

		while (approx < N) {
			approx++;
			buttonCnt++;
		}
		cout << buttonCnt << "\n";

	}
	// 근사치가 채널보다 크면
	else {

		while (approx > N) {
			approx--;
			buttonCnt++;
		}
		cout << buttonCnt << "\n";

	}

	return 0;
}