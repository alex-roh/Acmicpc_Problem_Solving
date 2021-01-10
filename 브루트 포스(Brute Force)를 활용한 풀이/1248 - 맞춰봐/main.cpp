#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
const int MAX = 2000000000;

using namespace std;

int N;
char S[11][11];
vector<vector<int>> ans;
bool isPrinted;

void findSequenceRecursive(int index, vector<int>& sequence, vector<int>& partialSum){
	
	if(index > N && isPrinted == false){
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
			// �κ����� ĳ�� 
			if(index > 1)
				partialSum[index] = sequence[index] + partialSum[index - 1];
			else 
				partialSum[index] = sequence[index];
			
			// �ٸ� ��쿡 ���� ���ȣ��
			findSequenceRecursive(index + 1, sequence, partialSum);
			return;
		}
		
		// sequence[index]�� 1(-1)���� 10(-10)���� �־ 
		for(int i = 1; i <= 10; i++){
			
			// sequence[index]�� ������ ��� 
			if(hint == '-'){
				sequence[index] = -i;
			}
			// sequence[index]�� ����� ��� 
			else {
				sequence[index] = i;
			}
			
			// �κ����� ĳ�� 
			if(index > 1)
				partialSum[index] = sequence[index] + partialSum[index - 1];
			else 
				partialSum[index] = sequence[index];
			
		
			// ������ �����ϴ��� Ȯ��
			bool okay = true;
			for(int j = 1; j <= index; j++){
				for(int k = j; k <= index; k++){	
					if(j == k) continue; 
					char shouldBe = S[j][k];
				
					int result;
				
					if(j == 1)
						result = partialSum[k];
					else
						result = partialSum[k] - partialSum[j - 1];
					
					// ������ �����ϴ� ���
					if((result == 0 && shouldBe == '0')
						|| (result < 0 && shouldBe == '-')
						|| (result > 0 && shouldBe == '+')){}
					// ������ �������� �ʴ� ��� 
					else {
						okay = false;
						break;
					}
				}
				if(okay == false) break;
			} 
		
			if(okay == true){
				findSequenceRecursive(index + 1, sequence, partialSum);	
			}
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
	
	vector<int> sequence(N, -11);
	vector<int> partialSum(N, -11);
	
	findSequenceRecursive(1, sequence, partialSum);
	
	return 0;

}

