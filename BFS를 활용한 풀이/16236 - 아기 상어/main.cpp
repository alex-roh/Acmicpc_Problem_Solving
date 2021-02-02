#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr,N,M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define irep(i,a,b) for(vector<int>::iterator i = a; i != b; i++)
#define pirep(i,a,b) for(vector<pii>::iterator i = a; i != b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,b,a) for(int i = b - 1; i >= a; i--)
#define mp(a,b) make_pair(a, b)

#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

// ofstream out
#define fco(a) out << a
#define fco(a) out << a
#define fcos(a) out << a << ' '
#define fcol(a) out << a << '\n' 
#define fcl out << '\n'

#define frt front
#define ps push
#define pp pop
#define emt empty
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

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

int N; // 공간의 크기
int M; // 물고기의 마리수
int B[21][21];
int dist[21][21];
int sx, sy; // 아기 상어의 시작 위치
int bsize = 2; // 아기 상어의 크기 
int eatenFish = 0;

bool isPossibleToEat(int x, int y){
	return (B[x][y] > 0 && B[x][y] < bsize);
}

bool isPriorTo(int x, int y, int cx, int cy){
	return (x < cx || (x == cx && y < cy));
}

pii moveByBFS(int cx, int cy){
	
	memset(dist, -1, sizeof(dist[0][0]) * 21 * 21);
	
	queue<pii> que;
	que.ps(mp(cx, cy));
	dist[cx][cy] = 0;
	
	pii resPair = mp(-1, -1);
	int resDist = MAX;
		
	while(!que.emt()){
		
		pii cur = que.frt(); que.pp();
		
		int x = cur.fst;
		int y = cur.scd;
		
		// 먹을 수 있는 물고기를 발견	 
		if(isPossibleToEat(x, y) && dist[x][y] <= resDist){
			
			if(resPair == mp(-1, -1) || isPriorTo(x, y, resPair.fst, resPair.scd)){
				resDist = dist[x][y];
				resPair = mp(x, y);	
			}
			
			continue;
		}
		
		// 위 - 아래 - 왼쪽 - 오른쪽 순으로 탐색 
		rep(i, 0, 4){
		
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!bnd(nx, ny, N, N)) continue;
			if(B[nx][ny] > bsize) continue;		
		
			if(dist[nx][ny] == -1){
				
				dist[nx][ny] = dist[x][y] + 1;
				que.ps(mp(nx, ny));

			}
			
		} 
		
	}
	
	return resPair;
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	
	ci(N);
	rep(i, 0, N){
		rep(j, 0, N){
			
			ci(B[i][j]);
			
			if(B[i][j] == 9){
				sx = i; sy = j;
				B[i][j] = 0;
			}
			else if(B[i][j] > 0){
				M++;
			}
			
		}
		
	}
	
	int res = 0;
	while(true){
		
		pii newPos = moveByBFS(sx, sy);
		
		sx = newPos.fst;
		sy = newPos.scd;
		
		if(sx == -1 && sy == -1)
			break;
			
		eatenFish++;
		B[sx][sy] = 0;
		res += dist[sx][sy];
		
		// 먹은 물고기 수가 사이즈가 같은 경우 
		if(eatenFish == bsize) {
			bsize++;
			eatenFish = 0; // 초기화 -> 빼먹어서 틀림 
		}
		
	}
	
	col(res);
	
	return 0;
}
