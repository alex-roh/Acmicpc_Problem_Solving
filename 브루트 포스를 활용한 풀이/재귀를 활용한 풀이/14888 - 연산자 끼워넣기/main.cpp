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
int arr[101];
int opers[100];
int input[4]; // 0 - plus, 1 - minus, 2 - mult, 3 - div

int minVal = MAX;
int maxVal = -MAX;

void go(int cnt){
	
	if(cnt == N - 1){
		
		int sum = arr[0];
		rep(i, 0, N - 1){
			switch(opers[i]){
				case 0:
					sum = sum + arr[i + 1];
					break;
				case 1:
					sum = sum - arr[i + 1];
					break;
				case 2:
					sum = sum * arr[i + 1];
					break;				
				case 3:
					sum = sum / arr[i + 1];
					break;				
			}
		}
		
		if(sum < minVal) minVal = sum;
		if(sum > maxVal) maxVal = sum;
		
		return; 
	}
	
	rep(i, 0, 4){
		
		if(input[i] > 0){
			opers[cnt] = i;
			input[i]--;
			go(cnt + 1);
			input[i]++;
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci(N);
	
	rep(i, 0, N){
		ci(arr[i]);
	}
	
	rep(i, 0, 4){
		ci(input[i]);
	}
	
	go(0);
	
	col(maxVal);
	co(minVal);
	
	return 0;
}
