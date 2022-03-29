#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a, n, digit;

    while(cin >> n){

        a = 0; digit = 0;

        while(true){
			
			digit++;
            a = 10 * a + 1;
            if(a % n == 0)
            	break;
            else
				a %= n; // a mod n을 다음 반복으로 넘김
            	
        }
        
        cout << digit << '\n';

    }

	return 0;
}
