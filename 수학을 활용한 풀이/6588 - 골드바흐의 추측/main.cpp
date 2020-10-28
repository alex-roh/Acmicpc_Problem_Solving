#include <iostream>

using namespace std; 

bool check[1000001];
int prime[1000001];
int primeCnt;

void fillCheckWithPrimes(){
	
	check[0] = true;
	check[1] = true;
	
	
	for(int i = 2; i < 1000001; i++){
		if(check[i] == false){
			prime[primeCnt++] = i;
			for(int j = i + i; j < 1000001; j += i){
				check[j] = true;
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n;
	
	fillCheckWithPrimes();
	
	while(cin >> n){
		
		if(n == 0) break;
		
		int a, b;
		
		for(int i = 0; i < n; i++){
			if(check[n - prime[i]] == false){
				b = prime[i];
				a = n - prime[i];
				break;
			}
		}
		
		cout << n << " = " << b << " + " << a << "\n";
		
	}
	
	return 0;
}
