#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char characters[16];
int L, C;

void printPossiblePasswordRecursive(bool fillVowel, int cntConsonant, string password, int index, int cntCharacter){

	if(cntCharacter == L){
		
		// 조건을 만족하는 경우에만 출력 
		if(fillVowel == true && cntConsonant == 2){
			cout << password << "\n";
		}
		
	}	
	else {
		
		for(int i = index; i < C; i++){

			char current = characters[i];
			
			// 현재 문자가 모음인 경우 
			if(current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u'){
				// 아직 모음을 찾지 못했다면
				if(fillVowel == false){
					fillVowel = true;
					printPossiblePasswordRecursive(fillVowel, cntConsonant, password + current, i + 1, cntCharacter + 1);
					fillVowel = false;	
				} 
				else
					printPossiblePasswordRecursive(fillVowel, cntConsonant, password + current, i + 1, cntCharacter + 1);
					
			}
			// 현재 문자가 자음인 경우
			else {
				// 아직 자음 두 개를 채우지 못했다면
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
