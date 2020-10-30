#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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
	
	int startPoint;
	cin >> startPoint;
	
	vector<int> diffDistances;
	
	while(n--){

		int distOfSister;
		cin >> distOfSister;

		int diff = abs(distOfSister - startPoint);
		diffDistances.push_back(diff);

	}
	
	for(int i = 0; i < diffDistances.size() - 1; i++){
		
		int gcd = getGcd(diffDistances[i], diffDistances[i + 1]);
		diffDistances[i + 1] = gcd;
		
	}
	
	cout << diffDistances[diffDistances.size() - 1];
	
	return 0;
}
