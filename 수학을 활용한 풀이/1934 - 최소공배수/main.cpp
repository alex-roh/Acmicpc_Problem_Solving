#include <iostream>

using namespace std;

int getLcm(int gcd, int a, int b){
	
	int lcm = (a * b) / gcd;
	return lcm;
	
}

int getGcd(int a, int b){
	
	while(b != 0){
		int r = a % b;
		a = b;
		b = r;	
	}
	
	return a;
	
}

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	// freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	
	while(n--){
		
		int a, b;
		cin >> a >> b;
		
		int gcd = getGcd(a, b);
		int lcm = getLcm(gcd, a, b);
		
		cout << lcm << "\n";
		
	}
	
	return 0;
}
