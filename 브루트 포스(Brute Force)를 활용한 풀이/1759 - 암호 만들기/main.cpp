#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char characters[16];
int L, C;

void printPossiblePasswordRecursive(bool fillVowel, int cntConsonant, string password, int index, int cntCharacter){

	if(cntCharacter == L){
		
		// ������ �����ϴ� ��쿡�� ��� 
		if(fillVowel == true && cntConsonant == 2){
			cout << password << "\n";
		}
		
	}	
	else {
		
		for(int i = index; i < C; i++){

			char current = characters[i];
			
			// ���� ���ڰ� ������ ��� 
			if(current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u'){
				// ���� ������ ã�� ���ߴٸ�
				if(fillVowel == false){
					fillVowel = true;
					printPossiblePasswordRecursive(fillVowel, cntConsonant, password + current, i + 1, cntCharacter + 1);
					fillVowel = false;	
				} 
				else
					printPossiblePasswordRecursive(fillVowel, cntConsonant, password + current, i + 1, cntCharacter + 1);
					
			}
			// ���� ���ڰ� ������ ���
			else {
				// ���� ���� �� ���� ä���� ���ߴٸ�
				if(cntConsonant < 2){
					cntConsonant++;
					printPossiblePasswordRecursive(fillVowel, cntConsonant, password + current, i + 1, cntCharacter + 1);
					cntConsonant--;
				}
				else
					printPossiblePasswordRecursive(fillVowel, cntConsonant, password + current, i + 1, cntCharacter + 1);			
			} 
		}	
	}
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> L >> C;
	for(int i = 0; i < C; i++){
		cin >> characters[i];
	}
	
	sort(characters, characters + C);
	
	bool fillVowel = false;
	int cntConsonant = 0;
	int cntCharacter = 0;
	int index = 0;
	string password = "";

	printPossiblePasswordRecursive(fillVowel, cntConsonant, password, index, cntCharacter);
	
	return 0;
}
