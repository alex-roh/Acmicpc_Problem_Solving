#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int DL[100001];
int DR[100001];
int A[100001];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	// 숫자가 하나 들어오면 하나를 선택하고 반환 
	if(N == 1){
		int ans;
		cin >> ans;
		cout << ans;
		return 0;
	}
	
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	
	DL[1] = A[1];
	DR[N] = A[N];
		
	for(int i = 2; i <= N; i++){
		DL[i] = A[i];
		if(DL[i] < DL[i - 1] + A[i]){
			DL[i] = DL[i - 1] + A[i];
		}
		
	}
		
	for(int i = N - 1; i >= 1; i--){
		DR[i] = A[i];
		if(DR[i] < DR[i + 1] + A[i]){
			DR[i] = DR[i + 1] + A[i];
		}
	}
	
	int maxVal = DL[1];
	for(int i = 2; i <= N; i++){
		if(maxVal < DL[i]){
			maxVal = DL[i];
		}
	}
	
	for(int i = 2; i <= N - 1; i++){
		if(maxVal < DL[i - 1] + DR[i + 1]){
			maxVal = DL[i - 1] + DR[i + 1];
		}
	}
	
	cout << maxVal << '\n';
	
	return 0;
}
