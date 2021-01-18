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

int N, M;
queue<pii> que;
int maze[101][101];
int cost[101][101]; // -1로 초기화됨 
int res = MAX;

void BFS(){
	
	que.push(mp(0, 0));
	cost[0][0] = 0;
	
	while(!que.empty()){
		
		pii p = que.front(); que.pop();
		int x = p.fst;
		int y = p.scd;
		
		if(!bnd2(x, y, N, M)) continue;
		
		rep(i, 0, 4){
			
			int nX = x + dx[i];
			int nY = y + dy[i];
			
			if(!bnd2(nX, nY, N, M)) continue;
			
			int nC;
			if(maze[nX][nY] == 0)
				nC = cost[x][y]; // 빈 방
			else 
				nC = cost[x][y] + 1; // 벽 
			
			// 예전에 온 적이 없음
			if(cost[nX][nY] == -1){
				cost[nX][nY] = nC;
				que.push(mp(nX, nY));
			}
			// 예전에 온 적이 있음 
			else {
				// nC가 더 적은 비용인 경우에만 
				if(nC < cost[nX][nY]){
					cost[nX][nY] = nC;
					que.push(mp(nX, nY));
				}
			}
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(M, N);
	cig(99999);
	
	rep(i, 0, N){
		string str;
		gtl(str);
		rep(j, 0, M){
			maze[i][j] = str[j] - '0';
		}
	}
	
	memset(cost, -1, sizeof(cost));
	
	BFS();
	
	col(cost[N-1][M-1]);
	
	return 0;
	
}

