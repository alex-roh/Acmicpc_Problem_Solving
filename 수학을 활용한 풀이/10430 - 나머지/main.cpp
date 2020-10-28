#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// freopen("input.txt", "rt", stdin);
	
	int A, B, C;
	
	cin >> A >> B >> C;
	
	cout << (A + B) % C << "\n";
	cout << ((A % C) + (B % C)) % C << "\n";
	cout << (A * B) % C << "\n";
	cout << ((A % C) * (B % C)) % C << "\n";
	
	return 0;
}
