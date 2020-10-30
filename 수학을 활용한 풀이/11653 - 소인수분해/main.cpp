#include <iostream>

using namespace std; 

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	if(n == 1){
		return 0;
	}
	
	int tmp = n;
	for(int i = 2; i <= n; i++){
		while(tmp % i == 0){
			cout << i << "\n";
			tmp /= i;
		}
	}
	
	if(tmp > 1) cout << tmp;
	
	return 0;
}
