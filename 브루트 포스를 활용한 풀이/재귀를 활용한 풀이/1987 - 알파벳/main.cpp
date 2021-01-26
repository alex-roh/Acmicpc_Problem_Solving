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

int R, C; 
char B[21][21];
bool visited[27];
int maxCnt = -1;

void go(int x, int y, int cnt){
	
	int alphabet = B[x][y] - 'A';
	visited[alphabet] = true;
	
	rep(i, 0, 4){
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(!bnd2(nx, ny, R, C)) continue;
		
		int nAlphabet = B[nx][ny] - 'A';
		
		if(visited[nAlphabet]) continue;
		
		go(nx, ny, cnt + 1);
		
	}
	
	visited[alphabet] = false;
	
	if(maxCnt < cnt)
		maxCnt = cnt;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(R, C);
	cig(99999);
	
	rep(i, 0, R){
		
		string str;
		gtl(str);
		
		rep(j, 0, C){
			
			B[i][j] = str[j];
			
		}
	}
	
	go(0, 0, 1);
	
	col(maxCnt);
	
	return 0;
}
