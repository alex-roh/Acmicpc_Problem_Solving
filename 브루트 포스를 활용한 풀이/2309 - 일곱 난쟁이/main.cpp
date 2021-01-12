#include <iostream>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int N[10];

int totalSum;
int p1, p2;

void findTwoPeople(){
	// 잘못된 두 난쟁이를 찾음	
	for(int i = 1; i <= 8; i++){
		for(int j = i + 1; j <= 9; j++){
			int sumOfTwo = N[i] + N[j];	
			if((totalSum - sumOfTwo) == 100){
				p1 = i;
				p2 = j;
				return;
			}
		}
	}
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i = 1; i <= 9; i++){
		cin >> N[i];
		totalSum += N[i];
	}
	
	sort(N + 1, N + 9 + 1);
	findTwoPeople();
	
	for(int i = 1; i <= 9; i++){
		if(i == p1 || i == p2)
			continue;
		cout << N[i] << "\n";
	}
	
	return 0;
}
