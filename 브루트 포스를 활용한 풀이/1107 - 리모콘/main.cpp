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
	
	// -  혹은 + 버튼만으로 가는 경우가 최댓값 
	int minCnt = abs(N - 100);
	
	// 상한경계인 100만까지 브루트 포스로 대입
	for(int i = 0; i <= 1000000; i++){
		
		int cnt = 0;
		string channel = to_string(i);
		
		// 버튼을 눌러서 그 채널에 갈 수 없는 경우 
		if(canGoToChannel(channel) == false)
			continue;
		
		cnt += channel.size();
		
		// - 혹은 + 버튼을 더 눌러서 도착한 경우의 cnt
		cnt += abs(N - stoi(channel));
		
		if(minCnt > cnt){
			minCnt = cnt;
		}
		
	}
	
	cout << minCnt;
	
	return 0;
}
