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

int N, M;
int maze[101][101];
int cost[101][101]; // (x, y)까지 오는 데 걸린 비용 
bool visited[101][101];

int BFS(int x, int y){
	
	queue<pii> que;
	que.push(mp(x, y));
	visited[x][y] = true;
	cost[x][y] = 1;
	
	while(!que.empty()){
		
		pii pos = que.front(); que.pop();
		int curX = pos.fst;
		int curY = pos.scd;
		
		// 도착 지점에 온 경우 
		if(curX == N && curY == M){
			return cost[curX][curY];
		}
		
		rep(i, 0, 4){
			
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];		
			
			if(nextX >= 1 && nextY >= 1 && nextX <= N && nextY <= M
				&& maze[nextX][nextY] == 1 && visited[nextX][nextY] == false){
				
				visited[nextX][nextY] = true;
				cost[nextX][nextY] = cost[curX][curY] + 1;
				que.push(mp(nextX, nextY));
				
			}
		}
		
	}
	
	return -1;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	cig(99999);
	
	rep(i, 1, N + 1){
		string str;
		gtl(str);
		rep(j, 0, M){
			maze[i][j + 1] = str[j] - '0';
		}
	}
	
	col(BFS(1, 1));
	
	
	return 0;
}
