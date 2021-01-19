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

int N;

typedef struct _Node {
	
	int self;
	int left;
	int right;
	
} Node;

Node tree[10001];

int root;
int col = 1;
bool isHaveParent[10001]; // 부모 노드 존재여부 
vi nodesAtThisDepth[10001]; 

void inorderTraverse(int node, int depth){
	
	if(node == -1) return;
	
	inorderTraverse(tree[node].left, depth + 1);
	nodesAtThisDepth[depth].pb(col++);
	inorderTraverse(tree[node].right, depth + 1);
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	
	rep(i, 0, N){
		int m, l, r;
		ci2(m, l);
		ci(r);
		tree[m].self = m;
		tree[m].left = l;
		tree[m].right = r;
		if(l != -1) isHaveParent[l] = true;
		if(r != -1) isHaveParent[r] = true;
	}
	
	// 루트 노드를 검색
	rep(i, 1, N + 1){
		if(isHaveParent[i] == false){
			root = i;
			break;
		}
	} 
	
	inorderTraverse(root, 1);
	
	// 최대 너비를 검색 
	int maxDepth = 0;
	int maxWidth = -1;
	bool isWidthOne = true;
	
	rep(i, 1, N + 1){
		int size = nodesAtThisDepth[i].size();
		
		if(size <= 1) continue; 
		else isWidthOne = false;
		
		int s = nodesAtThisDepth[i].front(); // 맨 처음값
		int e = nodesAtThisDepth[i].back();  // 맨 끝값
		
		if(maxWidth < (e - s) + 1){
			maxWidth = (e - s) + 1;
			maxDepth = i;
		}
		
	} 
	
	if(!isWidthOne){
		cos(maxDepth);
		col(maxWidth);	
	}
	else{
		// 1이 정답 
		cos(1);
		col(1);
	}
	
	return 0;
}
