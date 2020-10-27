#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#define a 97
#define A 65
#define zero 48
#define nine 57

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	string inputStr; 
	
	while(getline(cin, inputStr)){
		vector<int> countVec(4, 0);
		for(int i = 0; i < inputStr.size(); i++){
			
			char current = inputStr[i];
			
			// ������ ��� 
			if(current == ' '){
				countVec[3]++;
			}
			// ������ ��� 
			else if(current >= zero && current <= nine){
				countVec[2]++;
			}
			// �빮���� ��� 
			else if((int) current < a && (int) current >= A){
				countVec[1]++;
			}
			// �ҹ����� ��� 
			else if((int) current >= a){
				countVec[0]++;
			}
			
		}
		copy(countVec.begin(), countVec.end(), ostream_iterator<int>(cout, " "));
		cout << "\n";
	}
	
	return 0;
}
