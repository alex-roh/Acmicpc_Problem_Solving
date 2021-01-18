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

queue<pii> que;
int S; 
int N = 1001;
int CS[1001][1001]; // Ŭ������ - ȭ�鿡 �ִ� �̸�Ƽ�ܱ��� �����ϴ� �� �ɸ��� �ð� 
					// CS[?][S]�� 0�� �ƴϰ� �Ǹ� ���� 
int res = MAX;

void update(int c, int s, int nC, int nS){
	
	if(!bnd(nC, nS, N)) return;
	if(nC == 0 && nS == 1) return;
	if(CS[nC][nS] != 0) return;
	
	que.push(mp(nC, nS));
	CS[nC][nS] = CS[c][s] + 1;
	
}

void BFS(){
	
	que.push(mp(0, 1)); // Ŭ������ 0 / ȭ�� 1�� �ʱ������̹Ƿ� 
	CS[0][1] = 0;
	
	while(!que.empty()){
		
		pii cs = que.front(); que.pop();
		int c = cs.fst;
		int s = cs.scd;
		
		if(s == S) {
			if(CS[c][s] < res)
				res = CS[c][s];
		}
		
		int nC, nS;
		
		// 1. ȭ�鿡 �ִ� �̸�Ƽ���� Ŭ�����忡 ������	
		nC = s;
		nS = s;
		update(c, s, nC, nS);
		
		// 2. Ŭ�����忡 �ִ� �̸�Ƽ���� ȭ�鿡 �ٿ�����
		if(c != 0) {
			nC = c;
			nS = s + c;
			update(c, s, nC, nS);	
		}
		
		// 3. ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� ������
		if(s != 0){
			nC = c;
			nS = s - 1;
			update(c, s, nC, nS);	
		} 
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(S);
	BFS();
	col(res);
	
	return 0;
}
