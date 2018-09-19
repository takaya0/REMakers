#include<iostream>
#include<math.h>
using namespace std;
#define MAX_N 1000
int n, a[MAX_N], dp[MAX_N];
int DP(){
  int res = 0;
  for(int i = 0; i < n; i++){
    dp[i] = 1;
    for(int k = 0; k < i; k++){
      if(a[k] < a[i]){
        dp[i] = max(dp[i], dp[k] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  return res;
}
int main(){
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>a[i];
  }
  printf("%d\n", DP());
  return 0;
}
