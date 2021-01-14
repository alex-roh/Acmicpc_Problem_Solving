#include <bits/stdc++.h>

using namespace std;

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

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

using namespace std;

int M[51][51];
bool visited[51][51];
int W, H;

int BFS(int x, int y){
	
	if(visited[x][y] == true){
		return 0;
	}
	
	queue<pii> que;
	que.push(mp(x, y));
	visited[x][y] = true;
	
	while(!que.empty()){
		
		pii cur = que.front();
		que.pop();
		
		// cos("current is ("); cos(x); cos(y); col("),");
		
		rep(i, 0, 8){
			
			int nextX = cur.fst + ddx[i];
			int nextY = cur.scd + ddy[i];
			
			// 아직 방문하지 않았고 범위를 초과하지 않으며 섬이라면 삽입
			if(	   (visited[nextX][nextY] == false) 
				&& (nextX >= 0) && (nextY >= 0) && (nextX < W) && (nextY < H)
				&& (M[nextX][nextY] == 1)
			){
				visited[nextX][nextY] = true;
				que.push(mp(nextX, nextY));
			}	
		}
	}
	
	return 1;
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(W, H);
	
	while(W > 0 && H > 0){
		
		rep(i, 0, H){
			rep(j, 0, W){
				ci(M[i][j]);			
			}
		}
		
		int total = 0;
		rep(i, 0, H){
			rep(j, 0, W){
				if(BFS(i, j) == 1)
					total++;
			}	
		}
		
		col(total);
		
		memset(M, 0, sizeof(M));
		memset(visited, false, sizeof(visited));
		ci2(W, H);
	}
	
	return 0;
	
}
