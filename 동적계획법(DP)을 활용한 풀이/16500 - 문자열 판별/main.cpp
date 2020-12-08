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
	int L = S.size(); // ���ڿ��� ����; 
	
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
				
				// �ܾ �����ϴ� ��� 
				if(canBeWord == words[k]){
					
					// �� �ܾ ������ ������ ���ڿ��� �ܾ�� ���� �����ؾ� ��
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
