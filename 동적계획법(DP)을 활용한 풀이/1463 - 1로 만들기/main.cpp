#include <iostream>
#include <climits>
#include <vector>

using namespace std; 

vector<int> arr(1000001, INT_MAX);
int minCnt = INT_MAX;
int input;

void DFS(int n, int cnt){
	
	if(n == 1){
		if(cnt < arr[1]) arr[1] = cnt;
	}
	// 현재 카운트 수가 더 낮은 경우 
	else if(arr[n] > cnt){
		
		arr[n] = cnt;
		cnt++;
		
		if(n % 3 == 0)
			DFS(n / 3, cnt);
		
		if(n % 2 == 0)
			DFS(n / 2, cnt);
		
		DFS(n - 1, cnt);
	}
}

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> input;
	
	DFS(input, 0);
	
	cout << arr[1];
	
	return 0;
}
