#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#define a 97

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	string inputStr; 
	getline(cin, inputStr);
	
	vector<int> countVec(26, -1);
	
	for(int i = 0; i < inputStr.size(); i++){
		
		char current = inputStr[i];
		int index = (int) current - a;
		if(countVec[index] == -1) countVec[index] = i;
	}
	
	copy(countVec.begin(), countVec.end(), ostream_iterator<int>(cout, " "));
	
	return 0;
}
