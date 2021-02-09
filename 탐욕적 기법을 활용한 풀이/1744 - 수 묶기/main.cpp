#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt1(arr,N) cl; rep(i, 0, N){cos(arr[i]);} cl;
#define prt2(arr,N,M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,b,a) for(int i = b; i >= a; i--) /* caution! */
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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
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
int N;
int res;

int oc; // one count

void mult(vi& v){
	
	for(int i = 0; i + 1 < v.size(); i += 2)
		res += v[i] * v[i + 1];
		
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	ci(N);
	
	vi minus;
	vi zero;
	vi plus;
	
	rep(i, 0, N){
		
		int t; ci(t);
		
		if(t > 0) plus.pb(t);
		if(t == 1) oc++;
		if(t == 0) zero.pb(t);
		if(t < 0) minus.pb(t);
		
	} 
	
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end(), greater<int>());	
	
	// 1의 개수만큼 더해줌 
	res = oc;
	
	// 음수  
	mult(minus);
	// 0이 없으면서 마지막 한 원소가 남는 경우 
	if(zero.empty() && minus.size() % 2 != 0)
		res += minus.back();
	
	// 양수 
	mult(plus);
	// 마지막 한 원소가 남는 경우 
	if(plus.size() % 2 != 0)
		res += plus.back();
	
	// 양수의 경우 합이 곱보다 클 수 있음 
	col(res);
	
	// out.close();
	return 0;
}
