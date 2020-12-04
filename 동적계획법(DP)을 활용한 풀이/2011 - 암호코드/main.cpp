#include <iostream>
#include <string>

using namespace std;

long long D[5001];
int mod = 1000000;
bool wrongFlag;
string str;

int DFS(int pos){
	
	// 이미 찾았던 경우 
	if(D[pos] != 0)
		return D[pos];
		
	// 잘못된 값이 들어온 경우
	if(wrongFlag){
		return -1;
	} 
	
	// 재귀호출 종료조건 
	if(pos >= str.size()){
		return 1;
	}
	else {
		
		int curNumTen = (str[pos] - '0') * 10 + (str[pos + 1] - '0');
		int curNumOne = str[pos] - '0';
		
		// 10의 자리 수로 묶을 수 있는 경우 
		if(pos != str.size() - 1){
			// 10 초과 26 이하인지 확인
			if(curNumTen >= 10 && curNumTen <= 26){
				D[pos] = (D[pos] + DFS(pos + 2)) % mod;
			}
			// 10 미만인데 이전 자리가 0인 경우 
			if(curNumTen < 10 && pos > 0 && str[pos - 1] - '0' == 0){
				wrongFlag = true;
			}
			else if(curNumTen < 10){
				return 0;
			} 
		}
		
		// 1의 자리 수로 묶을 수 있는 경우
		if(curNumOne != 0)
			return D[pos] = (D[pos] + DFS(pos + 1)) % mod;
		else
			return 0;
	}
	
}

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> str;
	
	DFS(0);
	
	if(wrongFlag)
		cout << 0;
	else 
		cout << D[0];
	
	return 0;
}
