#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> D(1001);
vector<int> P(1001);
int numOfCardsToBeCollected;
int maxValue = -1;

void DP(int n, int collectedCards){
	
	if(n == 0){
		if(D[collectedCards] > maxValue){
			maxValue = D[collectedCards];
		} 
	}
	else {
		for(int i = 1; i <= n; i++){
			if(collectedCards + i > numOfCardsToBeCollected){
				return;
			}
			// 지불할 금액이 여태 찾은 값보다 더 클 경우에만 캐싱   
			int moneyToPay = D[collectedCards] + P[i];
			int cachedMax = D[collectedCards + i];
			
			if(moneyToPay > cachedMax){
				D[collectedCards + i] = D[collectedCards] + P[i];
				DP(n - i, collectedCards + i);	
			}
		}	
	}	
}

int main(int argc, char** argv) {
	
	freopen("input3.txt", "rt", stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> numOfCardsToBeCollected;
	
	for(int i = 1; i <= numOfCardsToBeCollected; i++){
		cin >> P[i];
	}
	
	DP(numOfCardsToBeCollected, 0);
	
	cout << maxValue;
	
	return 0;
}
