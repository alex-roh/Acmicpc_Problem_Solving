#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int matrix[11][11];
int cities[11];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> matrix[i][j];			
		}
	}
	
	for(int i = 1; i <= N; i++){
		cities[i] = i;
	}
	
	int min = INT_MAX;
	
	do {
		// 현재 순열에서 비용을 계산 
		int startCity, srcCity, destCity, lastCity;
		bool isOkay = true;
		
		int cost = 0;
		startCity = cities[1];
		
		// if(startCity != 1) break;
		
		for(int i = 1; i + 1 <= N; i++){
			srcCity = cities[i];
			destCity = cities[i + 1];
			if(matrix[srcCity][destCity] != 0){
				cost += matrix[srcCity][destCity];
			}
			else {
				isOkay = false;
				break;
			}
		}
		
		// 마지막 도시에서 첫번째 도시로 돌아올 수 있는지 살펴봄
		lastCity = cities[N];
		if(isOkay && matrix[lastCity][startCity] != 0){
			cost += matrix[lastCity][startCity];
			if(cost < min) min = cost;
		} 
		
	} while(next_permutation(cities + 1, cities + N + 1));
	
	cout << min;
	
	return 0;
}
