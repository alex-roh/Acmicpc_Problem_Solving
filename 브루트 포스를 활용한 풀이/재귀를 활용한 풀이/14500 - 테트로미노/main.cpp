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

using namespace std;

int P[501][501];
bool visited[501][501];
int N, M;
int maxVal = -1;

void go(int x, int y, int cnt, int sum){
	
	if(cnt == 4){
		if(sum > maxVal)
			maxVal = sum;
	}
	else {
		
		visited[x][y] = true;
		
		rep(i, 0, 4){
			
			int nX = x + dx[i];
			int nY = y + dy[i];
			
			if(bnd2(nX, nY, N, M) && !visited[nX][nY])
				go(nX, nY, cnt + 1, sum + P[nX][nY]);
			
		}
		
		visited[x][y] = false;
		
	}	
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin); 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	
	rep(i, 0, N){
		rep(j, 0, M){
			ci(P[i][j]);
		}
	}
	
	rep(i, 0, N){
		rep(j, 0, M){
			
			// 모든 테트로미노를 놓아 봄 
			go(i, j, 1, P[i][j]);
			
			int sum = 0;
			
			//   □(i,j)
			// □□□
			if(i + 1 < N && j - 1 >= 0 && j + 1 < M){
				sum = P[i][j] + P[i + 1][j] + P[i + 1][j - 1] + P[i + 1][j + 1];
				if(maxVal < sum)
					maxVal = sum;
			}
			
			//   □(i,j)
			//   □□
			//   □
			if(i + 2 < N && j + 1 < M){
				sum = P[i][j] + P[i + 1][j] + P[i + 2][j] + P[i + 1][j + 1];
				if(maxVal < sum)
					maxVal = sum;	
			} 
			
			// (i,j) □□□
			//         □
			if(i < N && j + 2 < M){
				sum = P[i][j] + P[i][j + 1] + P[i][j + 2] + P[i + 1][j + 1];
				if(maxVal < sum)
					maxVal = sum;
			}
			
			//   □(i,j)
			// □□
			//   □
			if(i + 2 < N && j - 1 >= 0){
				sum = P[i][j] + P[i + 1][j] + P[i + 2][j] + P[i + 1][j - 1];
				if(maxVal < sum)
					maxVal = sum;
			}
			 
		}
	}
	
	col(maxVal);
	
	return 0;
}
