#include <iostream>

using namespace std;

int res;

void funcRecursive(int current){
	
	if(current == 0){
		res++;
	}
	else if(current > 0){
		
		for(int i = 1; i <= 3; i++){
			funcRecursive(current - i);
		}
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	cin >> cnt;
	while(cnt--){
		int n;
		cin >> n;
		funcRecursive(n);
		cout << res << "\n";
		res = 0;
	}
	
	return 0;
}
