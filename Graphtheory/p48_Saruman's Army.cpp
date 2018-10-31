#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define MAX_N 1000
using namespace std;
int main(){
  int N, R, x[MAX_N];
  cin >> N >> R;
  for(int i = 0; i < N; i++){
    cin >> x[i];
  }
  sort(x, x + N);
  int i = 0, ans = 0;
  while(i < N){
    int s = x[i];
    while(i < N && x[i] <= s + R){
      i++;
    }
    int p = x[i-1];
    while(i < N && x[i] <= p + R){
      i++;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
