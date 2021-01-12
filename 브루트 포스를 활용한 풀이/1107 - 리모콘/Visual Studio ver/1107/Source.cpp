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

		// 1. ������ ū ���� ã�ƾ� �ϴ� ��� 
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
		// 2. ������ ���� ���� ã�ƾ� �ϴ� ��� 
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
		// 3. ���� Ȯ������ ���� ��� 
		else {
			// ��ư�� ���� ��� 
			if (B[cur]) {
				cout << "thereIsNoButton, ";

				// �����ִ� ��ư �� cur�� ���� ����� �ٻ�ġ�� ã�� 
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

				// �ٻ�ġ�� ��ư���� ũ�ٸ� ������ ������ ���� ���� ã�� 
				if (nearestButton > cur) {
					isSearchingForMin = true;
				}
				// �ٻ�ġ�� ��ư���� �۴ٸ� ������ ������ ū ���� ã�� 
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

	// �Է� 99, 100, 101�� ���� ���� ó�� 
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

	// �ٻ�ġ�� ä�ΰ� ������
	if (approx == N) {
		cout << buttonCnt << "\n";
	}
	// �ٻ�ġ�� ä�κ��� ������ 
	else if (approx < N) {

		while (approx < N) {
			approx++;
			buttonCnt++;
		}
		cout << buttonCnt << "\n";

	}
	// �ٻ�ġ�� ä�κ��� ũ��
	else {

		while (approx > N) {
			approx--;
			buttonCnt++;
		}
		cout << buttonCnt << "\n";

	}

	return 0;
}