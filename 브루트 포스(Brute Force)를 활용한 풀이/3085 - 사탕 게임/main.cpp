#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int maxCnt = -1;
char B[51][51];

void findChangedMax(int i, int j){
	
	int cnt;
	char cur, next; 
	
	// i�࿡ ���� ���Ӻκ��� �˻� 
	cnt = 1;
	for(int k = 1; k < N; k++){
		cur = B[i][k];
		next = B[i][k + 1];
		if(cur == next){
			cnt++;
		}
		else {
			cnt = 1;
		}
		if(maxCnt < cnt)
			maxCnt = cnt;
	}
	
	// j�࿡ ���� ���Ӻκ��� �˻� 
	cnt = 1;
	for(int k = 1; k < N; k++){
		cur = B[k][j];
		next = B[k + 1][j];
		if(cur == next){
			cnt++;
		}
		else {
			cnt = 1;
		}
		if(maxCnt < cnt)
			maxCnt = cnt;
	}
		
}

void findLargestSequence(){
	// ���� �� ���� �κ��� ã��
	for(int i = 1; i <= N; i++){
		findChangedMax(i, i);
	}
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> B[i][j];
		}
	}
	
	findLargestSequence();
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			
			// ������ ������ ��ȯ 
			if(j != N && B[i][j] != B[i][j + 1]){
				swap(B[i][j], B[i][j + 1]);
				findChangedMax(i, j);
				findChangedMax(i, j + 1);
				swap(B[i][j], B[i][j + 1]);
			}
			// �Ʒ��� ������ ��ȯ
			if(i != N && B[i][j] != B[i + 1][j]){
				swap(B[i][j], B[i + 1][j]);
				findChangedMax(i, j);
				findChangedMax(i + 1, j);
				swap(B[i][j], B[i + 1][j]);
			}
		}
	}
	
	cout << maxCnt;
	
	return 0;
}
