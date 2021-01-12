#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(1001);

int DP(int n){
	
	arr[0] = 1;
	arr[1] = 1;
	
	for(int i = 2; i <= n; i++){
		
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 2]) % 10007;
		
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
