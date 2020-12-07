#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int>& f, const pair<int, int>& s){
	
	if(f.first == s.first)
		return f.second < s.second;
	else
		return f.first < s.first;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt;
	cin >> cnt;
	
	vector<pair<int, int>> vec(cnt);
	
	for(int i = 0; i < cnt; i++){
		
		int x, y;
		cin >> x >> y;
		vec[i] = make_pair(x, y);
	}
	
	sort(vec.begin(), vec.end(), comp);
	
	for(int i = 0; i < cnt; i++){
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
	
	return 0;
}
