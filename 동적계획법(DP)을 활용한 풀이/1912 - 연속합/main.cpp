#include <iostream>
#include <vector>

using namespace std;

int D[100001];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	cin >> cnt;

	int firstVal;
	cin >> firstVal;
	D[1] = firstVal;
	int max = D[1];

	for(int i = 2; i <= cnt; i++){
		int input;		
		cin >> input;
		D[i] = input;
		
		int lastVal = D[i - 1];
		
		if(D[i] + lastVal > D[i]){
			D[i] += lastVal;
		}
		
		if(D[i] > max){
			max = D[i];
		}
		
	}
	
	cout << max;
	
	return 0;
}
