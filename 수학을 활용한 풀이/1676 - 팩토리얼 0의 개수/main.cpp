#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int factors[501];

void factorization(int n){
	
	int cur = n;
	
	for(int i = 2; i <= n;){	
		if(cur <= 1) break;
		if(cur % i == 0){
			cur /= i;
			factors[i]++;
		}
		else i++;
	}
	
}

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		factorization(i);
	}
	
	cout << min(factors[2], factors[5]);
	
	return 0;
}

