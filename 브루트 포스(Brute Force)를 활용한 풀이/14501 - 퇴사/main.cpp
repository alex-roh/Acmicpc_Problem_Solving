#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _Task {
	int time;
	int pay;
} Task;

Task tasks[20];
int N;
int maxVal = -1;

void DFS(int day, int sum){
	
	// N + 1일째에 상담이 완벽하게 종료되는 경우 
	if(day == N + 1){
		if(sum > maxVal)
			maxVal = sum;
	}
	else if(day > N + 1) return;
	else {
		
		// 현재 날짜에 상담하는 경우
		DFS(day + tasks[day].time, sum + tasks[day].pay);
		
		// 현재 날짜에 상담하지 않는 경우 
		DFS(day + 1, sum);
		
	}
	
}


int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> tasks[i].time >> tasks[i].pay;
	}

	DFS(1, 0);
	
	cout << maxVal;
	
	return 0;
}
