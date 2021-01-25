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

const int PL = 1;
const int MN = 2;
const int MU = 3;
const int DI = 4;

int N;
int seq[12];
int operInput[4]; // + - * /
vi oper;

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	
	rep(i, 0, N){
		ci(seq[i]);
	} 
	
	rep(i, 0, 4){
		ci(operInput[i]);
	}
	
	for(int i = 0; i < 4;){
		
		if(operInput[i] == 0){
			i++;
		}
		else{
			switch(i){
				case 0: // µ¡¼À 
					oper.pb(PL);
					break;
				case 1: // »¬¼À 
					oper.pb(MN);
					break;
				case 2: // °ö¼À 
					oper.pb(MU);
					break;
				case 3: // ³ª´°¼À 
					oper.pb(DI);
					break;
			}
			operInput[i]--;
		}
		
	}
	
	sort(oper.begin(), oper.end());
	
	ll minVal = MAX;
	ll maxVal = -MAX;
	
	do{
		
		ll res = 0;
		
		int i = 0;
		rep(j, 0, N - 1){
			
			ll a, b;
			if(i == 0)
				a = seq[i];
			else 
				a = res;
			b = seq[i + 1];
			i++;
			
			switch(oper[j]){
				case PL:
					res = (a + b);
					break;
				case MN:
					res = (a - b);
					break;
				case MU:
					res = (a * b);
					break;
				case DI:
					res = (a / b);
					break;
			}
		}
		
		if(res < minVal)
			minVal = res;
		if(res > maxVal)
			maxVal = res;
			
		
	} while(next_permutation(oper.begin(), oper.end()));
	
	
	col(maxVal);
	col(minVal);
	
	return 0;
}
