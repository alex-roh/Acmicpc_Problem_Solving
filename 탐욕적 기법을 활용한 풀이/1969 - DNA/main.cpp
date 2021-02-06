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
int N, M; // 문자열의 길이가 M 
vector<string> given;
int appear[128];
char res[51];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// out.open("output.txt);
	
	ci2(N, M); cig(99999);
	
	rep(i, 0, N){
		string str;
		gtl(str);
		given.pb(str);
	}
	
	sort(given.begin(), given.end());
	int error = 0;
	
	rep(i, 0, M){
		
		int cerror = 0;
		
		rep(j, 0, N){
			
			int c = given[j][i];
			appear[c]++;
			cerror++;
		}
		
		int maxVal = -1; int maxK = 0;
		rep(k, (int)'A', (int)'Z'){
			if(maxVal < appear[k]){
				maxVal = appear[k];
				maxK = k;
			}
		}
		
		res[i] = (char) maxK;
		error += cerror - maxVal;
		memset(appear, 0, sizeof(appear));
	}
	
	rep(i, 0, M) co(res[i]);
	cl; co(error);
	
	// out.close();
	return 0;
}
