#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

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
			// ����� �ϴ� ī���� ������ collectedCards(�̹� ��) + i��(�� ��)
			int moneyToPay = D[collectedCards] + P[i];
			int cachedMax = D[collectedCards + i];
			
			// ������ �ݾ��� ���� ã�� ������ �� Ŭ ��쿡�� ĳ�� 
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

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> d(n+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
        	cout << "i = " << i << ", j = "<< j << "\n";
            d[i] = max(d[i],d[i-j]+a[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}
