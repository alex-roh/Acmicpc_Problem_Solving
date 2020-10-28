#include <iostream>

using namespace std;

int lcm(int gcd, int a, int b){
	
	int lcm = (a * b) / gcd;
	return lcm;
	
}

int gcd(int a, int b){
	
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
	
	int a, b;
	
	cin >> a >> b;
	
	int gcdRes = gcd(a, b);
	int lcmRes = lcm(gcdRes, a, b);
	
	cout << gcdRes << "\n" << lcmRes;
	
	return 0;
}
