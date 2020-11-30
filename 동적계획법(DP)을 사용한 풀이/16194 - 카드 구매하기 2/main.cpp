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
			// 값이 한번도 갱신되지 않은 경우 min 함수를 사용하지 않고 그대로 대입
			if(D[N] == 0)
				D[N] = D[N - i] + P[i];
			// 값이 한 번 이상 갱신됐다면 min 함수를 사용해 최소값을 비교
			else
				D[N] = min(D[N], D[N - i] + P[i]);
		}
	}
	
	cout << D[numOfCardsToBeCollected] << "\n";
	
	return 0;
}
