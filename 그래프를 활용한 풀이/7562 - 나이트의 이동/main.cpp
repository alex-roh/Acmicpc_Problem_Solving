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

int posX[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int posY[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };

bool visited[301][301];
int dist[301][301];

int N;
int srcX, srcY;
int dstX, dstY;

int BFS(){
	
	queue<pii> que;
	que.push(mp(srcX, srcY));
	visited[srcX][srcY] = true;
	
	while(!que.empty()){

		pii cur = que.front(); que.pop();	
		int curX = cur.fst;
		int curY = cur.scd;
		
		if(curX == dstX && curY == dstY){
			return dist[curX][curY];
		}
		
		rep(i, 0, 8){
			
			int nextX = curX + posX[i];
			int nextY = curY + posY[i];

			if(nextX >= 0 && nextY >= 0 && nextX < N && nextY < N
				&& visited[nextX][nextY] == false){
				
				visited[nextX][nextY] = true;
				dist[nextX][nextY] = dist[curX][curY] + 1;
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
	
	int tstCase;
	ci(tstCase);
	
	rep(i, 0, tstCase){
		
		ci(N);
		ci2(srcX, srcY);
		ci2(dstX, dstY);

		col(BFS());

		memset(dist, 0, sizeof(dist));	
		memset(visited, false, sizeof(visited));
	}
	
	return 0;
}
