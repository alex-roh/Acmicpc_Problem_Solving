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

int N, cnt;
vector<string> problems;
bool inserted[200];
int indexOf[200];
vi value(10);

const int MAX = 2000000000;

int solveProblem(int n){
	
	int res = 0;
	int base = 1;
	
	for(int i = problems[n].size() - 1; i >= 0; i--){
		
		int index = problems[n][i] - '0';
		res = res + (value[indexOf[index]] * base);
		base *= 10;
		
	}
	
	return res;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	cig(99999);
	
	rep(i, 0, N){
		
		string str;
		gtl(str);
		
		rep(i, 0, str.size()){
		
			// 해당 알파벳의 고유한 값 
			int index = str[i] - '0';
			
			if(inserted[index] == false){			
				inserted[index] = true;
				indexOf[index] = cnt++; // 고유한 값을 0 ~ 10까지의 수에 매칭시킴 
			}
		}
		
		problems.pb(str);
			
	}
	
	rep(i, 0, 10){
		value[i] = i;
	}
	
	int max = -1;
	
	do{
		int sum = 0;
		
		// N개 문제를 풀어서 그 결과를 sum에 저장 
		rep(i, 0, problems.size()){
			sum += solveProblem(i);		
		}
		
		if(max < sum){
			max = sum;
		}
		
	} while(next_permutation(value.begin(), value.end()));
	
	col(max);
	
	return 0;
}
