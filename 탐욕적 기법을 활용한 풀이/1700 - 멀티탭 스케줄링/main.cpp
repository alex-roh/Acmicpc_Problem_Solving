#include <bits/stdc++.h>

using namespace std;

#define bnd(a,b,c,d) (a >= 0 && b >= 0 && a < c && b < d)
#define prt(arr,N,M) cl; rep(i, 0, N){ rep(j, 0, M){ cos(arr[i][j]); } cl; } cl;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,b,a) for(int i = b; i >= a; i--)
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
bool isToBeUsed[101];

void printPlug(set<int> &plugs){
	
	cos("plugs =");
	for(auto x : plugs){
		cos(x);
	}	
	cl;
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	int N, K;
	ci2(N, K);
	
	vi names;
	set<int> plugs;
	
	rep(i, 0, K){
		int e; ci(e);
		names.pb(e);
	}
	
	int cnt = 0;
	
	rep(i, 0, K){
		
		int e = names[i];
		
		// 멀티탭에 꽂혀 있는 경우 
		if(plugs.count(e)) {
			continue;
		}
		
		// 멀티탭에 꽂을 수 있는 경우 
		if(plugs.size() < N){
			plugs.insert(e);
			continue;
		}
		
		// names[i]를 넣기 위해 멀티탭에서 반드시 하나를 빼야 하는 경우			
		if(plugs.size() == N){
			
			int last = -1;
			rep(j, i + 1, K){
				
				if(plugs.count(names[j]) && !isToBeUsed[names[j]]){
					isToBeUsed[names[j]] = true;
					last = names[j];
				}
				
			}
			
			bool isNever = false;
			for(auto x : plugs){
				if(!isToBeUsed[x]){
					plugs.erase(x);
					isNever = true;
					break;
				}
			}
			
			if(isNever == false)
				plugs.erase(last);
			
			memset(isToBeUsed, false, sizeof(isToBeUsed));
			plugs.insert(e);
			cnt++;
			
		}
		
	}

	col(cnt);
	
	// out.close();
	return 0;
}

