#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

#define pb push_back

typedef long long ll;

typedef vector<int> vi;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
const int MAX = 2000000000;

using namespace std;

int N;
int Map[26][26];
bool visited[26][26];
vi houseCnt;

int total;
int cnt;

void DFS(int x, int y){
	
	// 인덱스 범위 초과
	if(x >= N || y >= N || x < 0 || y < 0){
		return;
	}
	
	// 이미 방문했던 집이거나 집이 아닌 경우 
	if(visited[x][y] == true || Map[x][y] == 0){
		return;
	}
	else {

		// 방문으로 처리 
		visited[x][y] = true;
		cnt++;
				
		// 동서남북으로 살펴봄 
		rep(i, 0, 4){
			DFS(x + dx[i], y + dy[i]);
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	cig(99999);
	
	rep(i, 0, N){
		string str;
		gtl(str);
		rep(j, 0, N)
			Map[i][j] = str[j] - '0';
	}
	
	rep(i, 0, N){
		rep(j, 0, N){
			cnt = 0;
			DFS(i, j);
			//cos("return value is"); col(cnt);
			if(cnt != 0){
				houseCnt.pb(cnt);
				total++;
			}
		}
	}
	
	sort(houseCnt.begin(), houseCnt.end());
	
	col(total);
	rep(i, 0, houseCnt.size()){
		col(houseCnt[i]);
	}
	
	return 0;
}
