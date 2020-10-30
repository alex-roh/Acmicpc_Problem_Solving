#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

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
	
	int n;
	cin >> n;
	cin.ignore();
	
	while(n--){
	
		vector<int> arr;
		string str;
		getline(cin, str);
		
		int num;
		stringstream stream(str);
		while(stream >> num){
			arr.push_back(num);
		}
		
		int size = arr.size();
		long long sum = 0;
		for(int i = 1; i < size - 1; i++){
			for(int j = i + 1; j < size; j++){
				int gcdRes = gcd(arr[i], arr[j]);
				
				sum += gcdRes;
			}			
		}
		
		cout << sum << "\n";
		
	}
	
	return 0;
}
