#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool B[10];

bool canGoToChannel(string channel){
	for(int i = 0; i < channel.size(); i++){
		int cur = channel[i] - '0';
		if(B[cur]){
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		int brokenButton;
		cin >> brokenButton;
		B[brokenButton] = true;
	} 
	
	// -  Ȥ�� + ��ư������ ���� ��찡 �ִ� 
	int minCnt = abs(N - 100);
	
	// ���Ѱ���� 100������ ���Ʈ ������ ����
	for(int i = 0; i <= 1000000; i++){
		
		int cnt = 0;
		string channel = to_string(i);
		
		// ��ư�� ������ �� ä�ο� �� �� ���� ��� 
		if(canGoToChannel(channel) == false)
			continue;
		
		cnt += channel.size();
		
		// - Ȥ�� + ��ư�� �� ������ ������ ����� cnt
		cnt += abs(N - stoi(channel));
		
		if(minCnt > cnt){
			minCnt = cnt;
		}
		
	}
	
	cout << minCnt;
	
	return 0;
}
