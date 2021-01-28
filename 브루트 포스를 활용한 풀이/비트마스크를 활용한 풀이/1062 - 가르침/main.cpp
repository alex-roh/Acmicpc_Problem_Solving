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

int N, K;
bool apb[26];
vector<string> words;
int antic_pattern; 

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, K);
	cig(99999);
	
	// a, n, t, i, c를 배울 수 없는 경우 
	if(K < 5){
		col(0);
		return 0;
	}
	
	rep(i, 0, N){
		string str;
		gtl(str);
		words.pb(str);
	}
	
	// a, n, t, i, c는 무조건 가르쳐야 함 
	
	int toBeOne;
	
	toBeOne = 'a' - 'a';
	antic_pattern |= (1 << toBeOne);
	
	toBeOne = 'n' - 'a';
	antic_pattern |= (1 << toBeOne);
	
	toBeOne = 't' - 'a';
	antic_pattern |= (1 << toBeOne);
	
	toBeOne = 'i' - 'a';
	antic_pattern |= (1 << toBeOne);
	
	toBeOne = 'c' - 'a';
	antic_pattern |= (1 << toBeOne);
	
	int maxCnt = -1;
	
	rep(pattern, 0, 1 << 26){
		
		// a, n, t, i, c를 가르치지 않는 경우는 skip 
		if((pattern & antic_pattern) != antic_pattern) continue;
		
		// 현재 패턴에 K개의 알파벳이 들어가 있는지 검사 
		int apbCnt = 0;
		rep(i, 0, 26){
			if((pattern & (1 << i)) != 0) apbCnt++;
			if(apbCnt > K) break;
		}	 
		
		if(apbCnt != K) continue;
		
		int wrdCnt = 0;
			
		// 현재 패턴에서 셀 수 있는 단어를 검사 
		rep(j, 0, N){
			
			bool isCanCount = true;
			string word = words[j];
		
			// 첫 anta와 끝 tica를 빼고 계산 
			rep(k, 4, word.size() - 4){
			
				char c = word[k];	
				int index = c - 'a';
				if((pattern & (1 << index)) == 0) {
					isCanCount = false;
					break;
				}
				
			}
			
			if(isCanCount) 
				wrdCnt++;
			
		}
		
		if(wrdCnt > maxCnt)
			maxCnt = wrdCnt; 
		
	}
	
	col(maxCnt);
	
	return 0;
}
