#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char** argv) {

	// freopen("input.txt", "rt", stdin);
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string inputStr;
	getline(cin, inputStr);
	
	string outputStr;
	
	for(int i = 0; i < inputStr.size(); i++){
		
		char current = inputStr[i];
		int ascii = (int) current;
		int order;
		
		// 대문자인 경우 
		if(ascii >= (int) 'A' && ascii <= (int) 'Z'){
			ascii += 13;
			(ascii > (int) 'Z') ? (ascii = ascii - (int) 'Z' + (int) 'A' - 1) : (ascii);
			outputStr += (char) ascii;
			
		}
		// 소문자인 경우
		else if(ascii >= (int) 'a' && ascii <= (int) 'z'){
			ascii += 13;
			(ascii > 'z') ? (ascii = ascii - (int) 'z' + (int) 'a' - 1) : (ascii);
			outputStr += (char) ascii;
		} 
		else {
			
			outputStr += current;
			
		}
	}
	
	cout << outputStr;

	return 0;
}
