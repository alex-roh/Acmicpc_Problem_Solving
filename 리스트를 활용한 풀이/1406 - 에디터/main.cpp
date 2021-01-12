#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	string sentence;
	getline(cin, sentence);
	
	// add "start" indicator to the string
	sentence = "&" + sentence;
	
	list<char> mylist;	
	for(int i = 0; i < sentence.size(); i++) mylist.push_back(sentence[i]);
	
	list<char>::iterator cursor = mylist.end();
	cursor--;
	
	int cnt;
	cin >> cnt;
	cin.ignore();
	
	while(cnt--){
		
		if(cursor == mylist.end()) cursor--;
		
		string operation;
		getline(cin, operation);
		
		if(operation == "L"){
			// move cursor to the left
			if(*cursor != '&') cursor--;
		}
		else if(operation == "D"){
			// move cursor to the right
			if(cursor != mylist.end()) cursor++;
		}
		else if(operation == "B"){
			// erase a character that is left to the cursor
			if(*cursor != '&'){
				cursor = mylist.erase(cursor);
				cursor--;
			}
		}
		else if (operation[0] == 'P'){
			cursor = mylist.insert(++cursor, operation[2]);
		}
	}
	
	mylist.pop_front();
	for(list<char>::iterator iter = mylist.begin(); iter != mylist.end(); iter++)
		cout << *iter;
	
	return 0;
}
