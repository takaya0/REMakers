#include<iostream>
using namespace std;
#define MAX_K 100000

int dp[MAX_K+1];
int n, a[101], m[101], K;
void DP(){
  memset(dp, -1, sizeof(dp));//-1に初期化
  dp[0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < K; j++){
      if(dp[j] >= 0){
        dp[j] = m[i];
      } else if(j < a[i] || dp[j-a[i]] <= 0){
        dp[j] = -1;
    }else{
      dp[j] = dp[j-a[i]] - 1;
    }
  }
 }
}
int main(){
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>a[i]>>m[i];
  }
  cin>>K;
  DP();
  if(dp[K] >= 0){
    printf("Yes\n");
  }else{
    printf("N0\n");
  }
  return 0;
}
