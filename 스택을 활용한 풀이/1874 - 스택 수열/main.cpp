#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	stack<int> mystack;
	string res;
	int pos = 1, input;
	
	while(cin >> input){
		
		if(!mystack.empty() && mystack.top() > input){
			cout << "NO";
			return 0;
		}
		
		while(mystack.empty() || mystack.top() < input){
			res += "+\n";
			mystack.push(pos);
			pos++;
		}
		
		res += "-\n";
		mystack.pop();
		
	}
	
	cout << res;
	
	return 0;
}
