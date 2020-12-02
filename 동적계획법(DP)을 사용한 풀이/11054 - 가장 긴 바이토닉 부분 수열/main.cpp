#include <iostream>

using namespace std;

int A[1002];
int LR[1002];
int RL[1002];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		LR[i] = 1;
		RL[i] = 1;
	}
	
	// left to right
	for(int i = 2; i <= N; i++){
		int maxVal = 0;
		for(int j = i - 1; j >= 1; j--){
			if(A[j] < A[i] && maxVal < LR[j]){
				maxVal = LR[j];
			}	
		}
		LR[i] += maxVal;
	}
	
	// right to left
	for(int i = N - 1; i >= 1; i--){
		int maxVal = 0;
		for(int j = i + 1; j <= N; j++){
			if(A[j] < A[i] && maxVal < RL[j]){
				maxVal = RL[j];
			}	
		}
		RL[i] += maxVal;
	}
	
	int maxVal = -1;
	for(int i = 1; i <= N + 1; i++){
		for(int j = i + 1; j <= N + 1; j++){
			
			int sum = LR[i] + RL[j];
			if(A[i] == A[j])
				sum--;
			
			if(maxVal < sum){
				maxVal = sum;
			}
			
		}
	}
	
	cout << maxVal;

	return 0;
}
