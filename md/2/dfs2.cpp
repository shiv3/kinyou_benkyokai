#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 100
#define MAX_M 100

int N,M;
char field[MAX_N][MAX_M + 1];


void dfs(int x,int y){
  field[x][y] = '.';
  for( int dx = -1 ;dx <= 1; dx++){
    for( int dy = 01;dy <= 1; dy++){
      int nx = x + dx, ny = y + dy;
      if( 0 <= nx && nx < N && 0 <= ny && ny < M &&
          field[nx][ny] == 'W') dfs (nx,ny);
      }
   }
  return ;
}
void solv(){
  int res = 0;
  for ( int i=0; i< N;i++){
    for(int j=0; j < M; j++){
      if(field[i][j]){
        dfs(i,j);
        res++;
      }
   }
   cout << res << endl;
 }
}

int main(){
  int m,n;
   while(cin >> n >> m ,m | n){
    for( int y = 0; y < m; y++){
      for( int x = 0; x < n; x++){
        cin >> field[x][y];
      }
    }
    solv();
  }
}
