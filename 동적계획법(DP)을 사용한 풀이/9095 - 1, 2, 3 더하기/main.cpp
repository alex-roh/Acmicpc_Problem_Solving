#include <iostream>
#include <vector>

using namespace std;

int DP(int n){
	
	vector<int> D(n + 1);
	
	D[0] = 0;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	
	if(n <= 3) return D[n];
	
	for(int i = 4; i <= n; i++){
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}
	
	return D[n];
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int testCasesCnt;
	cin >> testCasesCnt;
	
	while(testCasesCnt--){
		int n;
		cin >> n;
		cout << DP(n) << "\n";
	}
	
	return 0;
}
