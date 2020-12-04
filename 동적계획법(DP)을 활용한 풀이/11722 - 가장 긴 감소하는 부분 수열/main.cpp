#include <iostream>

using namespace std;

int A[1001];
int D[1001];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> A[i];
		D[i] = 1;	
	}
	
	for(int i = 2; i <= n; i++){
		
		int maxVal = 0;
		
		for(int j = i - 1; j > 0; j--){
			
			if(A[j] > A[i] && maxVal < D[i] + D[j]){
				maxVal = D[j];	
			}
		}
		
		D[i] += maxVal;
		
	}
	
	int maxVal = 1;
	for(int i = 1; i <= n; i++){
		if(maxVal < D[i]){
			maxVal = D[i];
		}
	}
	
	cout << "\n" << maxVal;
	
	return 0;
}
