#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	string sentence;
	getline(cin, sentence);
	
	// add "start" indicator to the string
	sentence = "&" + sentence;
	string::iterator cursor = sentence.end();
	cursor--;
	
	int cnt;
	cin >> cnt;
	cin.ignore();
	
	while(cnt--){
		
		string operation;
		getline(cin, operation);
		
		if(operation == "L"){
			// move cursor to the left
			if(*cursor != '&') cursor--;			
		}
		else if(operation == "D"){
			// move cursor to the right
			if(cursor != sentence.end()) cursor++;
			if(cursor == sentence.end()) cursor--;
			
		}
		else if(operation == "B"){
			// erase a character left to the cursor
			if(*cursor != '&'){
				cout << "to be erased : " << *cursor << "\n";
				sentence.erase(cursor);
				cursor--;
			}
		}
		else if (operation[0] == 'P'){
			cursor++;
			sentence.insert(cursor, operation[2]);
		}
		
		cout << "operation is " << operation << ", sentence is " << sentence << ", cursor is " << *cursor << "\n";
	
	}
	
	sentence.erase(0, 1);
	cout << sentence;
	
	return 0;
}
