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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int MAX = 2000000000;

int N;

char B[101][101];
char cB[101][101];
int tB[101][101];
int cnt;

void BFS(int i, int j, char pB[][101]){
	
	++cnt;
	
	queue<pii> que;
	que.ps(mp(i, j));
	tB[i][j] = cnt;

	while(!que.emt()){
		
		pii cur = que.frt(); que.pp();
		
		int x = cur.fst;
		int y = cur.scd;
		
		rep(i, 0, 4){
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(!bnd(nx, ny, N, N)) continue;
			if(tB[nx][ny] != 0) continue;
			if(pB[nx][ny] != pB[x][y]) continue;
			
			tB[nx][ny] = cnt;
			que.ps(mp(nx, ny));
			
		}
		
	}
	
}

void initGlobal(){
	cnt = 0;
	memset(tB, 0, sizeof(tB[0][0]) * 101 * 101);
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N); cig(99999);
	
	rep(i, 0, N){
		string row;
		gtl(row);
		rep(j, 0, N){
			B[i][j] = cB[i][j] = row[j];
			if(row[j] == 'G')
				cB[i][j] = 'R';
		}
	}
	
	// 정상 
	initGlobal();
	rep(i, 0, N){
		rep(j, 0, N){
			if(tB[i][j] == 0) BFS(i, j, B);
		}
	}
	
	int res1 = cnt;
	
	// 적록색약 
	initGlobal();
	rep(i, 0, N){
		rep(j, 0, N){
			if(tB[i][j] == 0) BFS(i, j, cB);
		}
	}
	
	int res2 = cnt;
	
	cos(res1); cos(res2);
	return 0;
	
}

