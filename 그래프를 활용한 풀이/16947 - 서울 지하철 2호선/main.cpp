#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c) (a >= 0 && b >= 0 && a < c && b < c)
#define bnd2(a, b, c, d) (a >= 0 && b >= 0 && a < c && b < d)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mp(a,b) make_pair(a, b)

#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

#define pb push_back
#define fst first
#define scd second

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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

int N; 
vi stations[3001];
vi dist(3001, -1);
bool visited[3001];
int cycle;
int mode;

bool findRec(int cur, int before){
	
	// 방문했던 역을 방문하는 경우 사이클 형성 
	if(visited[cur]){
		cycle = cur;
		mode = 2;
		dist[cur] = 0;
		return true;
	}
	
	visited[cur] = true;
	
	rep(i, 0, stations[cur].size()){
		
		int next = stations[cur][i];
		
		// 다음 역이 이전 역이 아닌 경우에만 호출 
		if(next != before && findRec(next, cur)){
			
			// 순환역이 아닌 경우 
			if(mode == 2 && cur == cycle)
				mode = 1;
			else if(mode != 1)
				dist[cur] = 0;
	
			return true;
			
		}
	}
	
	return false;
	
}

int findNearestRec(int cur, int before, int distance){
	
	// 순환선에 있는 역을 방문하는 경우 거리를 반환하고 종료
	if(dist[cur] == 0){
		return distance;
	}
	
	rep(i, 0, stations[cur].size()){
		
		int next = stations[cur][i];
		
		// 다음 역이 이전 역이 아닌 경우에만 호출 
		if(next != before){
			int res = findNearestRec(next, cur, distance + 1);
			if(res != -1){
				return res;
			}
		}	
	}
	
	return -1;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	
	int s1, s2;
	rep(i, 1, N + 1){
		
		ci2(s1, s2);
		stations[s1].pb(s2);
		stations[s2].pb(s1);
		
	}
	
	// step1. 순환선을 찾는다 
	findRec(s1, -1);
	
	// step2. 1부터 N까지 가장 가까운 순환선으로의 거리를 찾는다
	rep(i, 1, N + 1){
		if(dist[i] == 0){
			cos(0); continue;
		}
		else
			cos(findNearestRec(i, -1, 0));
	} 
	
	return 0;
}
