#include<iostream>
using namespace std;

int gcd(int m,int n){
  if(n == 0){
    return m;
  }else{
    return gcd(n,m%n);
  }
}
int lcm(int m,int n){
  return (m*n)/gcd(m,n);
}

int main(){
  int m,n;
  while(cin >> m >> n ,m|n){
    cout << "gcd:" << gcd(m,n) << endl;
    cout << "lcm:" << lcm(m,n) << endl;
  }
  return 0;
}
