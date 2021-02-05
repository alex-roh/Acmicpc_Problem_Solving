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

typedef struct _J{
	int w, p;
} J;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	int N, K;
	ci2(N, K);
	
	multiset<int> bags;
	vector<J> jems(N);
	
	rep(i, 0, N){
		int w, p;
		ci2(w, p);
		jems.pb({w, p});		
	}

	// 1. 가격이 제일 높은 순으로 정렬
	// 2. 가격이 같으면 무게가 가벼운 걸 앞으로 
	sort(jems.begin(), jems.end(), [](J f, J s){
		return f.p > s.p;
	}); 
	
	rep(i, 0, K){
		int c; ci(c);
		bags.insert(c);
	}
	
	ll res = 0;
	
	rep(i, 0, N){
		
		J jem = jems[i];	
		int jw = jem.w;
		int jp = jem.p;
		
		// 보석을 담을 수 있는 가장 작은 가방을 구함 
		auto it = bags.lower_bound(jw);
		if(it == bags.end()) continue;
			
		// 보석을 담을 가방이 있으면
		res += jp;
		bags.erase(it);
			
	}
	
	col(res);
	
	// out.close();
	return 0;

}
