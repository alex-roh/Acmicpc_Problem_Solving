#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long C[100001]; 

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> C[i];
	}
	
	sort(C + 1, C + N + 1);
	
	int maxIndex = 0, maxCnt = 0;
	
	int cnt = 0, pos = 1;
	long long before = C[pos];
	
	while(pos != N + 1){ 
		
		long long cur = C[pos];
		
		// 현재 보고 있는 수가 이전 수와 다르다면 
		if(cur != before){	 
			if(maxCnt < cnt){
				maxCnt = cnt;
				maxIndex = pos - 1; // 현재 수 바로 이전의 수 
			} 
			cnt = 1;
		}
		else {
			cnt++;
		}
		
		before = cur;
		pos++;
		
	}
	
	if(maxCnt < cnt){
		maxCnt = cnt;
		maxIndex = pos - 1; // 현재 수 바로 이전의 수 
	} 
	
	cout << C[maxIndex];
	
	return 0;
}
