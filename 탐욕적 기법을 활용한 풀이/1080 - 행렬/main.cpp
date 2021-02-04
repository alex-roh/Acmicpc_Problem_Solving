#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr,N,M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

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
int N, M;
vector<string> A;
vector<string> B;

void flip(int x, int y){
	
    rep(i, x, x + 3) {
        rep(j, y, y + 3) {
            A[i][j] = (A[i][j] == '0') ? '1' : '0';
        }
    }
    
}

bool compareTwo(){
	
	rep(i, 0, N){
		rep(j, 0, M){
			if(A[i][j] != B[i][j])
				return false;
		}
	}
	
	return true;
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M); cig(99999);
	
	rep(i, 0, N){
		string str; gtl(str);
		A.pb(str);
	}
	
	rep(i, 0, N){
		string str; gtl(str);
		B.pb(str);
	}
	
	// 그리디 진행
	int cnt = 0;
	
	rep(i, 0, N - 2){
		rep(j, 0, M - 2){
			
			if(A[i][j] != B[i][j]){
				// 3 * 3 행렬 뒤집기
				flip(i, j);
				cnt++;
			}
		
		}
	}
	
	if(compareTwo()) col(cnt);
	else col(-1);
	
	return 0;
}
