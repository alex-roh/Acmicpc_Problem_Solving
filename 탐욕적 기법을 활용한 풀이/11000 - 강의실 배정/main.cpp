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

#define fco(a) out << a
#define fco(a) out << a
#define fcos(a) out << a << ' '
#define fcol(a) out << a << '\n' 
#define fcl out << '\n'

#define tp top
#define frt front
#define ps push
#define pp pop
#define emt empty
#define pb push_back
#define fst first
#define scd second

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef stack<int> si;
typedef queue<int> qi;
typedef deque<int> di;
typedef priority_queue<int, vector<int>> pqi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

// ofstream out
const int MAX = 2000000000;

typedef struct _Cls {
	
	int s, t;
	
} Cls;

bool sortByS(Cls fst, Cls scd){
	return fst.s < scd.s;
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	int N;
	ci(N);
	vector<Cls> c(N);
	
	rep(i, 0, N){
		int s, t;
		ci2(s, t);
		c[i] = {s, t};
	}
	
	// 시작 시간이 이른 순으로 정렬 
	sort(c.begin(), c.end(), sortByS);
	
	// 끝나는 시간이 이른 순으로 들어갈 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> pq; 
	int res = 0;
	
	rep(i, 0, N){
		
		int s = c[i].s;
		int t = c[i].t;
		
		if(pq.emt() || s < pq.tp()){
			pq.ps(t);
		}
		else {
			pq.pp();
			pq.ps(t);
		}
		
	}
	
	col(pq.size());
	
	// out.close();
	return 0;
}

