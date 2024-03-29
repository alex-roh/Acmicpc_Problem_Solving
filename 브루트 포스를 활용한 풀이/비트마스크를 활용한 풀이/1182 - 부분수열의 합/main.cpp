#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define cig(a) cin.ignore(a, '\n')
#define ci(a) cin >> a
#define ci2(a,b) cin >> a >> b
#define gtl(a) getline(cin, a)
#define co(a) cout << a
#define cos(a) cout << a << ' ' // cout with space
#define col(a) cout << a << '\n' // cout with line 
#define cl cout << '\n' // cout only line

#define pb push_back

typedef long long ll;

typedef vector<int> vi;
typedef stack<int> si;
typedef queue<int> qi;
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

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
const int MAX = 2000000000;

using namespace std;

int N, S;
int seq[21];
int pattern;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	 
	ci2(N, S);
	
	rep(i, 0, N){
		ci(seq[i]);
	}
	
	int ans = 0;
	
	// 비트마스크로 생성한 패턴에 맞추어 원소를 더함 
	rep(pattern, 1, (1 << N)){
		int sum = 0;
		rep(i, 0, N){
			if((pattern & (1 << i)) != 0){
				sum += seq[i];	
			}
		}
		if(sum == S) ans++;
	}
	
	col(ans);
	
	return 0;
}
