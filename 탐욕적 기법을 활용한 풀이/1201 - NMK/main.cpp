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

int N, M, K;
vi group[501];

void print(){
	
	rep(i, 0, M){
		reverse(group[i].begin(), group[i].end());
		for(auto x : group[i])
			cos(x);
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	ci2(N, M); ci(K);
	
	// 불가능한 경우 -1
	if(N - M + 1 < K || M * K < N){
		col(-1);
		return 0;
	} 
	
	vi num(N);
	rep(i, 0, N)
		num[i] = i + 1;
		
	// 1. K개가 들어있는 그룹으로 묶음 
	int gi = 0;
	rep(i, 0, K){
		group[gi].pb(num[i]);
	}
	
	gi++;
	
	// 2. N - K개에서 M - 1개의 그룹을 만듦
	if(M - 1 == 0){
		print();
		return 0;
	} 
	
	int s = (N - K) / (M - 1);
	int r = (N - K) % (M - 1);
	
	int i = K;
	while(i < N){
		
		int ns = s + (r > 0 ? 1 : 0); // 나머지가 있는 경우 s에 1을 더함
		int cnt = 0;
		
		while(cnt < ns){
			group[gi].pb(num[i]);
			i++; cnt++;
		}
		
		gi++; r--;
	
	}
	
	print();
	
	// out.close();
	return 0;
}
