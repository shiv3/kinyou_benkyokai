#include<iostream>
using namespace std;
#define MAX_N 5

int n;
int a[MAX_N];
int k;

bool dfs(int i,int sum){
  if ( i== n ) return sum == k;
  if (dfs(i+1 ,sum)) return true;
  if (dfs(i+1,sum + a[i])) return true;

  return false;
}

int main(){
  cout<<"n:";
  cin >> n;
  for(int i = 0; i < n ; i++){
    cin  >> a[i];
  }
  cout<<"k:";
  cin >> k;
  if( dfs(0,0  ) ) cout << "Yes" << endl;
  else cout << "No" << endl;
}
