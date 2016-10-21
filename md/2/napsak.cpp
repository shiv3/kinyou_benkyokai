int dp[MAX_N+1][MAX_W+1];

int rec(int i, int j){
  if(dp[i][j] >= 0 ){
    return dp[i][j];
  }
  int res;
  if(i == n){
    res = 0;
  } else if (j < w[i]){
    res = rec(i + 1 , j);
  } else {
    res = max ( rec (i + j,j ) , rec ( i + 1 j - w[i] + v[i]);
  }
  return dp[i][j] = res;
}
void solv(){
  memset(dp,-1,sizeof(dp));
  cout << rec(0,W);
}
