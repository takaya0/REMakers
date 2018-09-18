#include<iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 100
int  n, v[MAX_N], w[MAX_N], W;
const int INF = 10000000;
int dp[MAX_N + 1][MAX_N * MAX_V + 1];
void DP(){
  fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
  dp[0][0] = 0;
  for(int i = 0; i < n; i++){
    for(int k = 0; k <= MAX_N * MAX_V; k++){
      if(k < v[i]){
        dp[i+1][k] = dp[i][k];
      }else{
        dp[i+1][k] = min(dp[i][k], dp[i][k - v[i]] + w[i]);
      }
    }
  }
}

int main(){
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>w[i]>>v[i];
  }
  cin>>W;
  DP();
  int ans;
  for(int i = 0; i<=MAX_N * MAX_V; i++){
    if(dp[n][i] <= W){
      ans = i;
    }
  }
  printf("%d\n",ans);
  return 0;
}
