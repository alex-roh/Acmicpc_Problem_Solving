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
#define col cout << '\n' // cout only line

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

vector<string> paper;
int N, M; // ��, �� 

int solve(){
	
	int maxVal = -1;
	
	// ��Ʈ ������ �����Ͽ� �ش� ���Ͽ� ���� ���ΰ��� �հ� ���ΰ��� ���� ���� 
	rep(pattern, 0, 1 << (N * M)){
		
		int sum = 0;
		
		// �������� ����
		rep(j, 0, N){
			
			int currentZero = 0; // ���� ����(0)�� 
			
			rep(k, 0, M){
			
				int index = j * M + k; // 1���� �迭�� ��Ÿ���� ���� ���� �ε��� 

				if((pattern & (1 << index)) == 0){
					// ���� �߰�
					currentZero = currentZero * 10 + (paper[j][k] - '0');	
				}
				else {
					// ���� ����� �ʱ�ȭ 
					sum += currentZero;
					currentZero = 0;
				}
			}
			sum += currentZero;
		}
		
		// ���θ� ����	
		rep(k, 0, M){
			
			int currentOne = 0;
			
			rep(j, 0, N){
				
				int index = j * M + k;
				
				if((pattern & (1 << index)) == (1 << index)){
					// ���� �߰�
					currentOne = currentOne * 10 + (paper[j][k] - '0'); 
				}
				else {
					// ���� ����� �ʱ�ȭ
					sum += currentOne;
					currentOne = 0; 
				}
			}
			sum += currentOne;
		}
	
		maxVal = max(maxVal, sum);
		
	}
	
	return maxVal;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ci2(N, M);
	cig(99999);
	rep(i, 0, N){
		string str;
		gtl(str);
		paper.pb(str);
	}
	
	cout << solve();
	
	return 0;
}
