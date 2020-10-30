#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

long long findTwo(long long n) 
{ 
    long long count = 0; 
  
    for (long long i = 2; i <= n; i *= 2) 
        count += n / i; 
  
    return count; 
} 
  
long long findFive(long long n) 
{ 
    long long count = 0; 
  
    for (long long i = 5; i <= n; i *= 5) 
        count += n / i; 
  
    return count; 
} 
  
int main() { 
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    long long n, m;
    cin >> n >> m;
	
	long long two = 0, five = 0;

	five += findFive(n);
	two += findTwo(n);
	
	five -= findFive(n - m);
	two -= findTwo(n - m);
	
	five -= findFive(m);
	two -= findTwo(m);
    
    cout << min(two, five); 
    
    return 0; 
} 
