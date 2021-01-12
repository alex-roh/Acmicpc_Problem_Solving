#include <iostream>
#include <vector>
#include <string>

#define STRIKE 1
#define BALL 2
#define ANSCNT 3 

using namespace std;

int numbers [1001][4]; 
int res; 

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	cin >> cnt;
	int cntForWhile = cnt;
	while(cntForWhile--){
		
		string input;
		int strike, ball;
		cin >> input >> strike >> ball;
		
		// �� ������ �������� 123���� 987���� �Ұ����� ���� ���� 
		for(int i = 123; i <= 987; i++){
			
			// 0�� ���ԵǾ� ������ ������
			if(i % 10 == 0 || (i / 10) % 10 == 0)
				continue;
			
			// ���ڰ� �����ϸ� ������ 
			int last = i % 10;
			int middle = (i / 10) % 10;
			int first = (i / 100) % 10;
			if(last == middle || middle == first || first == last)
				continue;
		
			// ���� ���� �����̶�� �����ϰ� strike ���� ball ���� ���� 
			string cur = to_string(i); 
			int currentStrike = 0;
			int currentBall = 0;
			for(int j = 0; j < 3; j++){
				
				if(cur[j] == input[j]){
					currentStrike++;
				}
					
				for(int k = 0; k < 3; k++){
					if(k == j) continue;
					if(cur[k] == input[j])
						currentBall++;
				}
			}
			
			if(currentStrike == strike && currentBall == ball){
				numbers[i][ANSCNT]++;
			}	
			
		}
	}
	
	// �����̶�� ���ݱ��� ������ strike ���� ball ���� ���ƾ� �� 
	for(int i = 123; i <= 987; i++){
		if(numbers[i][ANSCNT] == cnt){
			res++;
		}
	}
	
	cout << res;
	
	return 0;
}
