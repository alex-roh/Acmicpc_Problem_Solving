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
int matrix[101][101]; 
int bridge[101][101];
int visited[101][101];

queue<pii> bridgeQue;

int cnt;

void DFS(int x, int y){
	
	visited[x][y] = true;
	matrix[x][y] += cnt;
	
	rep(i, 0, 4){
		
		int nX = x + dx[i];
		int nY = y + dy[i];
		
		if(bnd(nX, nY, N) && !visited[nX][nY] && matrix[nX][nY] == 1)
			DFS(nX, nY);
	}
	
}

int BFS(){
	
	while(!bridgeQue.empty()){
		
		pii xy = bridgeQue.front(); bridgeQue.pop();
		int x = xy.fst;
		int y = xy.scd;
		
		rep(i, 0, 4){
			
			int nX = x + dx[i];
			int nY = y + dy[i];
			
			if(!bnd(nX, nY, N)) continue;
			
			// nX, nY에 다른 섬의 다리가 놓여 있다면 종료
			if(bridge[x][y] != 0 && bridge[nX][nY] != 0 &&
				matrix[x][y] != matrix[nX][nY]){
				return bridge[nX][nY] + bridge[x][y];
			}
			// nX, nY에 같은 섬의 다리가 놓여 있다면 skip
			// nX, nY가 바다라면 다리를 놓음 
			else if(matrix[nX][nY] == 0){
				
				matrix[nX][nY] = matrix[x][y];     // 해당 구역을 자기 섬으로 칠함 
				bridge[nX][nY] = bridge[x][y] + 1; // 다리를 놓음 
				bridgeQue.push(mp(nX, nY));
			
			}
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	
	rep(i, 0, N){
		rep(j, 0, N){
			ci(matrix[i][j]);	
		}
	}
	
	// DFS로 서로 다른 섬을 마킹함 
	rep(i, 0, N){
		rep(j, 0, N){
			if(!visited[i][j] && matrix[i][j] == 1){
				DFS(i, j);
				cnt++;
			}
		}
	}
	
	// BFS로 각각의 섬 모든 부분에 다리를 붙여봄
	rep(i, 0, N){
		rep(j, 0, N){
			if(matrix[i][j] > 0)
				bridgeQue.push(mp(i, j));
		}
	} 
	
	col(BFS());
	
	return 0;
}
