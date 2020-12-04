#include <iostream>
// E limit
#define EL 15
#define SL 28
#define ML 19

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int E, S, M;
	cin >> E >> S >> M;
	int e = 0, s = 0, m = 0;
	int year = 0;
	
	// 한번 반복할 때마다 연도 + 1 
	while(true){
		
		year++;
		
		e += 1;
		if(e > EL) e = 1;
		
		s += 1;
		if(s > SL) s = 1;
		
		m += 1;
		if(m > ML) m = 1;
		
		if(e == E && s == S && m == M)
			break;
		
	}
	
	cout << year;
	
	return 0;
}
