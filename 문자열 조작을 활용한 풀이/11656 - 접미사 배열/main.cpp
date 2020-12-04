#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string str;
	cin >> str;
	
	vector<string> prefixes;
	
	for(int i = 0; i < str.size(); i++){
		prefixes.push_back(str.substr(i));
	}
	
	sort(prefixes.begin(), prefixes.end());
	
	copy(prefixes.begin(), prefixes.end(), ostream_iterator<string>(cout, "\n"));
	
	return 0;
}
