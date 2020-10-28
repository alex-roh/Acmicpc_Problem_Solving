#include <iostream>

using namespace std;

bool checkPrime(int num){
	
	if(num == 1) return false;
	
	for(int i = 2; i * i <= num; i++){
		
		if(num % i == 0){
			return false;
		}
	}
	
	return true;
	
}

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int n;
	int cnt = 0;
	
	cin >> n;
	
	while(n--){
	
		int current;
		cin >> current;
		
		if(checkPrime(current)) cnt++;
		
	}
	
	cout << cnt;
	
	return 0;
}
