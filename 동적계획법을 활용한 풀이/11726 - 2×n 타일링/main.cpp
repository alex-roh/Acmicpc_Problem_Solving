#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr(1001);

long long DP(int n){
	
	// 2x1인 경우 2x1 타일 하나로밖에 만들 수 없음 
	arr[1] = 1;
	// 2x2인 경우 2x1 타일 2개 or 1x2 타일 2개
	arr[2] = 2; 
	
	for(int i = 3; i <= n; i++){
		
		// arr[i - 1] -> 맨 오른쪽에  2x1 타일이 1개 오는 경우
		// arr[i - 2] -> 맨 오른쪽에 1x2 타일이 2개 오는 경우 
		// 연산값이 굉장히 크기 때문에 연산 도중 계속 10007로 모듈로 연산 
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
		
	}
	
	return arr[n];
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	cout << DP(n);
	
	return 0;
}
