#include <iostream>

using namespace std;

int S[1001];
long long D[1001]; // D[i] = A_i를 끝으로 하는 합이 가장 큰 증가수열의 합  

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> S[i];
	}
	
	D[1] = S[1];
	
	for(int i = 2; i <= n; i++){
		long long maxSum = S[i];
		for(int j = i - 1; j > 0; j--){
			if(S[j] < S[i] && maxSum < S[i] + D[j]){
				maxSum = S[i] + D[j];
			}
		}
		D[i] = maxSum;
	}
	
	long long maxVal = -1;
	for(int i = 1; i <= n; i++){  
		if(maxVal < D[i]){
			maxVal = D[i];
		}
	}
	
	cout << maxVal;
	
	return 0;
	
}
