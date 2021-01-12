#include <iostream>
#include <string>

using namespace std;

long long D[5001];
int mod = 1000000;
bool wrongFlag;
string str;

int DFS(int pos){
	
	// �̹� ã�Ҵ� ��� 
	if(D[pos] != 0)
		return D[pos];
		
	// �߸��� ���� ���� ���
	if(wrongFlag){
		return -1;
	} 
	
	// ���ȣ�� �������� 
	if(pos >= str.size()){
		return 1;
	}
	else {
		
		int curNumTen = (str[pos] - '0') * 10 + (str[pos + 1] - '0');
		int curNumOne = str[pos] - '0';
		
		// 10�� �ڸ� ���� ���� �� �ִ� ��� 
		if(pos != str.size() - 1){
			// 10 �ʰ� 26 �������� Ȯ��
			if(curNumTen >= 10 && curNumTen <= 26){
				D[pos] = (D[pos] + DFS(pos + 2)) % mod;
			}
			// 10 �̸��ε� ���� �ڸ��� 0�� ��� 
			if(curNumTen < 10 && pos > 0 && str[pos - 1] - '0' == 0){
				wrongFlag = true;
			}
			else if(curNumTen < 10){
				return 0;
			} 
		}
		
		// 1�� �ڸ� ���� ���� �� �ִ� ���
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
