#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
const ll MAX = 99999999;

using namespace std;

string str;
bool isUsed[11];
int k;
ll minVal = MAX;
ll maxVal = -MAX;

void DFS(int before, int index, string ans){
	
	if(index >= k){
		
		ll ansLong = stoll(ans);
		if(ansLong < minVal) minVal = ansLong;
		if(ansLong > maxVal) maxVal = ansLong;
		
	}
	else {
		for(int i = 0; i < 10; i++){
		 	
		 	if(isUsed[i] == true) continue;
		 	
			if((str[index] == '<' && before < i)
				|| (str[index] == '>' && before > i)){
				
				isUsed[i] = true;
				DFS(i, index + 1, ans + to_string(i));
				isUsed[i] = false;	
			}
				
		}	
	}
}


int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> k;
	string tempStr;
	cin.ignore(99999, '\n');
	getline(cin, tempStr);
	
	for(int i = 0; i < tempStr.size(); i++){
		if(tempStr[i] == ' ') continue;
		else str += tempStr[i];
	}
	
	// 첫번째 수가 0-9인 경우마다 함수 호출 
	for(int i = 0; i < 10; i++){
		isUsed[i] = true;
		DFS(i, 0, to_string(i));
		isUsed[i] = false;
	}
	
	string ansMax = to_string(maxVal);
	string ansMin = to_string(minVal);
	
	if(ansMax.size() < k + 1){
		ansMax = '0' + ansMax;
	}
	if(ansMin.size() < k + 1){
		ansMin = '0' + ansMin;
	}
	
	cout << ansMax << "\n";
	cout << ansMin << "\n";
	
	return 0;
}
