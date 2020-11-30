#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> D(1001, 1000 * 10000);
vector<int> P(1001);

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int numOfCardsToBeCollected;
	cin >> numOfCardsToBeCollected;
	
	for(int i = 1; i <= numOfCardsToBeCollected; i++){
		cin >> P[i];
	}
	
	for(int N = 1; N <= numOfCardsToBeCollected; N++){
		for(int i = 1; i <= N; i++){
			// ���� �ѹ��� ���ŵ��� ���� ��� min �Լ��� ������� �ʰ� �״�� ����
			if(D[N] == 0)
				D[N] = D[N - i] + P[i];
			// ���� �� �� �̻� ���ŵƴٸ� min �Լ��� ����� �ּҰ��� ��
			else
				D[N] = min(D[N], D[N - i] + P[i]);
		}
	}
	
	cout << D[numOfCardsToBeCollected] << "\n";
	
	return 0;
}
