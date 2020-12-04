#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	// freopen("input.txt", "rt", stdin);
	
	string A, B, C, D;
	
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	
	string AB = A + B;
	string CD = C + D;
	
	long long ab = stol(AB);
	long long cd = stol(CD);
	
	long long res = ab + cd;
	
	cout << res;
	
	return 0;
}
