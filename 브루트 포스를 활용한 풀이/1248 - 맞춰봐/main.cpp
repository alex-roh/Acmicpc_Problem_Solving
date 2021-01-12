#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

using namespace std;

int N;
char S[11][11];
vector<int> sequence(30);
bool isPrinted;

bool check(int index){
	
	// ������ �����ϴ��� Ȯ�� 
	int partialSum = 0;
	for(int i = index; i >= 1; i--){
		partialSum += sequence[i];
		
		if(S[i][index] == '0'){
			if(partialSum != 0) return false;
		}
		else if(S[i][index] == '-'){
			if(partialSum >= 0) return false;
		}
		else if(S[i][index] == '+'){
			if(partialSum <= 0) return false;
		}
	}
	
	return true;
	
}

void findSequenceRecursive(int index){
	
	if(isPrinted) return;
	
	if(index > N){
		for(int i = 1; i <= N; i++){
			cout << sequence[i] << " ";
		}
		cout << "\n";
		isPrinted = true;
	}
	else {
		
		char hint = S[index][index];
		
		// sequence[index]�� 0�� ���
		if(hint == '0'){
			sequence[index] = 0;
			return findSequenceRecursive(index + 1);
		}
		
		// sequence[index]�� 1(-1)���� 10(-10)���� �־ 
		for(int i = 1; i <= 10; i++){
			
			// sequence[index]�� ������ ��� 
			if(hint == '-')
				sequence[index] = -i;
			// sequence[index]�� ����� ��� 
			else 
				sequence[index] = i;
			
			if(check(index))
				findSequenceRecursive(index + 1);
		}
	}
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string inputStr;
	cin >> N;
	cin.ignore(99999, '\n');
	getline(cin, inputStr);
	
	int index = 0;
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j++){
			S[i][j] = inputStr[index++];
		}
	}
	
	findSequenceRecursive(1);
	
	return 0;

}

