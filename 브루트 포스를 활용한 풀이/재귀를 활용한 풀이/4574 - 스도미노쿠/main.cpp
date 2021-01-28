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

int rdx[2] = {0, 1};
int rdy[2] = {1, 0};
int tc = 1;
int B[11][11];
bool domino[11][11];
int block[10] = {0, 1, 1, 1, 4, 4, 4, 7, 7, 7};
vector<pii> toBeFilled;

bool checkBound(int a, int b, int N, int M){
    return (a >= 1 && b >= 1 && a < N && b < M);
} 

void printB(){

	cos("Puzzle"); col(tc);
    rep(i, 1, 10){
        rep(j, 1, 10){
            co(B[i][j]);
        }
        cl;
    }

}

// 스도쿠 조건을 위배하지 않으면 true를 반환 
bool check(int x, int y, int num){

    // 속한 행과 열을 검사
    rep(i, 1, 10){
        if(B[x][i] == num) 
            return false;
        if(B[i][y] == num)
            return false;
    }

    // 속한 정사각형을 검사 
    int row = block[x];
    int col = block[y];

    vb nums(10, false);
    nums[num] = true;

    rep(i, row, row + 3){
        rep(j, col, col + 3){

            int val = B[i][j];
            if(val == 0) continue;

            if(nums[val]) {
                return false;
            }
            else nums[val] = true;

        }
    }

    return true;

}

bool go(int index){

    // 빈칸을 모두 채운 것이므로 true를 반환 
    // if(isEnd) return true;
	if(index == toBeFilled.size()){
    	printB();
		return true;
	}

    pii pos = toBeFilled[index];
    int x = pos.fst;
    int y = pos.scd;

    // 이미 해당 칸을 채워넣었다면 지금 위치를 건너뜀 
    if(B[x][y] != 0) {
    	if(go(index + 1))
    		return true;
	}
	else {

		rep(k, 0, 2){
	
	        int nx = x + rdx[k];
	        int ny = y + rdy[k];
	
	        if(!checkBound(nx, ny, 10, 10)) continue;
	        if(B[nx][ny] != 0) continue;
	
	        // 2 x 1 도미노에 대해 모든 경우의 수를 넣어 봄 
	        rep(i, 1, 10){
	
	            rep(j, 1, 10){
	
	                if(i == j || domino[i][j]) continue;
	                if(check(x, y, i) && check(nx, ny, j)){
	                
	                	B[x][y] = i;
	                	B[nx][ny] = j;
	
	                	domino[i][j] = true;
	                	domino[j][i] = true;
	
	                	// 찾은 (i, j)가 스도쿠 조건을 만족하면 인덱스를 1 증가시켜 재귀 호출 
	                	if(go(index + 1))
	                    	return true;
	
	            		B[x][y] = 0;
	                	B[nx][ny] = 0;
	                	domino[i][j] = false;
	                	domino[j][i] = false;
						
					}
	
	            }
	            
	        }
	    }
	}

    return false;

}

void getInputAndCallGo(){

    int cnt;
    ci(cnt);

    while(cnt){
    	
    	memset(domino, false, sizeof(domino));
    	memset(B, 0, sizeof(B));
    	toBeFilled.clear();

        cig(99999);
        string str;
        int row, col;

        rep(i, 0, cnt){

            gtl(str);

            int num1, num2;

            num1 = str[0] - '0';
            row = str[2] - 'A' + 1;
            col = str[3] - '0';

            B[row][col] = num1;

            num2 = str[5] - '0';
            row = str[7] - 'A' + 1;
            col = str[8] - '0';

            B[row][col] = num2;

            domino[num1][num2] = true;
            domino[num2][num1] = true;

        }

        gtl(str);

        int pos = 0;

        for(int index = 1; index < 10; ){

            if(str[pos] == ' ') {
                pos++;
            }
            else if(str[pos] >= 'A' && str[pos] <= 'Z'){
                row = str[pos] - 'A' + 1;
                pos++;
            }
            else if(str[pos] >= '0' && str[pos] <= '9'){
                col = str[pos] - '0';
                B[row][col] = index;
                pos++;
                index++;
            }

        }

        // 채워넣어야 하는 빈칸의 위치를 toBefilled 벡터에 집어넣음 
        rep(i, 1, 10){
            rep(j, 1, 10){
                if(B[i][j] == 0)
                    toBeFilled.pb(mp(i, j));
            }
        }
        
        go(0);
        tc++;

        ci(cnt);

    }

}


int main(int argc, char** argv) {

    // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getInputAndCallGo();

    return 0;

}
