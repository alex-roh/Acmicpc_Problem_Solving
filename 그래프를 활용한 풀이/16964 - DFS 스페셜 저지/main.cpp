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
typedef vector<bool> vb;
typedef stack<int> si;
typedef queue<int> qi;
typedef deque<int> di;
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

vi DFS;
vi resDFS;
vi graph[100001];
int depth[100001];
bool visited[100001];

void testDFS(int v, int dpth){
	
	if(visited[v]){
		return;
	}
	
	visited[v] = true;
	depth[v] = dpth;
	
	for(auto& nextV : graph[v]){
		
		if(visited[nextV] == false){
			testDFS(nextV, dpth + 1);
		}
		
	}
	
}


int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	
	rep(i, 0, N - 1){
		int a, b;
		ci2(a, b);
		graph[a].pb(b);
		graph[b].pb(a);
	} 
	
	rep(i, 0, N){
		int a;
		ci(a);
		DFS.pb(a);
	}
	
	if(DFS[0] != 1){
		col(0);
		return 0;
	}
	
	testDFS(1, 0);
	memset(visited, false, sizeof(visited));
	
	int before = DFS[0];
	visited[before] = true;
	 
	rep(i, 1, N){
		
		int cur = DFS[i];
		visited[cur] = true;
		
		int diff = depth[before] - depth[cur];
		if(diff < 0) diff *= -1;
		
		// cur과 before이 1만큼 차이나지 않으면 before이 그 경로의 맨 끝이어야 함 
		if(diff != 1){
			for(auto& x : graph[before]){
				if(!visited[x]) {
					col(0);
					return 0;
				}
			}
		}
		
		before = cur;
	}
	
	col(1);
	
	return 0;
	
}
