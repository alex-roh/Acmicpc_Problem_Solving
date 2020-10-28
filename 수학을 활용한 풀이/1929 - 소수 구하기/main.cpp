#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// freopen("input.txt", "rt", stdin);
	
	int m, n;
	int primeCnt = 0;
	cin >> m >> n;
	
	vector<int> prime(1000001);
	vector<bool> check(1000001);
	
	for(int i = 2; i <= n; i++){	
		if(check[i] == false){
			if(i >= m) prime[primeCnt++] = i;
			for(int j = i * 2; j <= n; j += i){
				check[j] = true;
			}
		}
	}
	
	for(int i = 0; i < primeCnt; i++){
		cout << prime[i] << "\n";
	}
	
	return 0;
}
