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
const int LIMIT = 1000000000LL;

ll S, T;

typedef pair<ll, string> plls;

bool checkBnd(ll ns){
	return (ns <= LIMIT && ns >= 0);
}

string BFS(){
	
	queue<plls> que;
	que.ps(mp(S, ""));
	
	// 제한이 너무 크기 때문에 배열 대신 set을 사용 
	set<ll> st;
	st.insert(S);
	
	while(!que.emt()){
		
		plls cur = que.frt(); que.pp();
		
		ll s = cur.fst;
		string path = cur.scd;
		
		if(s == T) return path;
		
		// *
		if(checkBnd(s * s) && st.count(s * s) == false){
			que.ps(mp(s * s, path + "*"));
		}
		
		// +
		if(checkBnd(s + s) && st.count(s + s) == false){
			que.ps(mp(s + s, path + "+"));
		}
		
		// -
		if(checkBnd(s - s) && st.count(s - s) == false){
			que.ps(mp(s - s, path + "-"));
		}
		
		// /
		if(s == 0) continue;
		if(checkBnd(s / s) && st.count(s / s) == false){
			que.ps(mp(s / s, path + "/"));
		}
		
	}
	
	return "-1";
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(S, T);
	
	if(S == T){
		co(0); return 0;
	}
	else
		co(BFS());
	
	return 0;
}
