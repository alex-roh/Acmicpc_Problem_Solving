#include <iostream>
#include <vector>
#include <climits>
#include <string>
#define R 1
#define G 2
#define B 3

using namespace std;

bool RGB[4];
int costForHouses[1001][4];
int D[1001][4];
int minVal = INT_MAX;
int houseCnt;

void DFS(int index, int colorBefore, int cost){
	
	if(index > houseCnt){
		if(cost < minVal){
			minVal = cost;
		}
	}
	else {
		for(int color = 1; color <= 3; color++)
		{
			if(color == colorBefore)
				continue;
			else {
				int newCost = cost + costForHouses[index][color];
				if(D[index][color] == 0 || D[index][color] > newCost){
					D[index][color] = newCost;	
					DFS(index + 1, color, newCost);	
				}	
			}
		}
	}
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> houseCnt;
	
	for(int i = 1; i <= houseCnt; i++){	
		int rCost, gCost, bCost;
		cin >> rCost >> gCost >> bCost;
		costForHouses[i][1] = rCost;
		costForHouses[i][2] = gCost;
		costForHouses[i][3] = bCost;
	}
	
	DFS(1, 0, 0);
	
	cout << minVal;
	
	return 0;
}

