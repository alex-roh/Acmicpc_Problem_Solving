#include <iostream>
#include <string>

using namespace std; 

bool canConsist[101]; 
string words[101];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string S;
	cin >> S; 
	int L = S.size(); // 문자열의 길이; 
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> words[i];
	}
	
	canConsist[L] = true;
	
	// O(L * N)
	for(int i = L - 1; i >= 0; i--){
		
		string toBeMatched = S.substr(1, i - 1);
		string canBeWord;
		
		for(int j = i; j < L; j++){
			canBeWord += S[j];
			for(int k = 1; k <= N; k++){ 
				
				// 단어를 형성하는 경우 
				if(canBeWord == words[k]){
					
					// 그 단어를 제외한 나머지 문자열이 단어로 형성 가능해야 함
					if(canConsist[i + canBeWord.size()]){
						canConsist[i] = true;
					}
				}
			}
		}
	}
	
	cout << canConsist[0];
	
	return 0;
}
