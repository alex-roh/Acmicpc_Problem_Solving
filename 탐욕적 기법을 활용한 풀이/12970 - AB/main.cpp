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
int N, K;

void prtAns(int b, vi& cnt){
	
	int i;
	
	for(i = 0; i < b; i++){
		
		while(cnt[i]--)
			co('A');
		co('B');
		
	}
	
	// 맨 마지막 A를 출력 
	while(cnt[i]--)
		co('A');
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	ci2(N, K);
	
	// 예외 처리 
	if(K == 0){
		rep(i, 0, N - 1)
			co("B");
		co("A");
		return 0;
	}
	
	rep(i, 0, N + 1){
		
		int a = i;
		int b = N - a;
		
		if(a * b < K) continue;
		
		vi cnt(b + 1); // B 사이에 넣을 A의 개수 
		
		// A를 어디에, 몇 개 넣을 것인지 그리디하게 결정 
		rep(j, 0, b + 1){
			
			int sub = b - j;
			
			while(K > 0){
				if(K - sub < 0) break;
				K -= sub;
				cnt[j]++;
				a--;
			}
			
			if(K == 0){
				cnt[b] = a;
				prtAns(b, cnt);
				return 0;			
			}
		
		}

	}
	
	col(-1);
	
	// out.close();
	return 0;
}
