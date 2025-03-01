#include<iostream>
#include<math.h>
using namespace std;

typedef unsigned long long ull;

ull cubo(ull x){
  ull i=1;
  while(i*i*i <= x){
    ++i;
  }
  --i;
  //    cout << i << endl;
  if (i*i*i == x){
    return i;
  }else{
    return INT_MAX;
  }
}

int main(){
  ull n;
  while(cin>>n &&n){
    ull y = 1;
    bool encontre=false;
    while (true){
      ull r = cubo(n + (y*y*y));
      //      cout << "r es: " << r << " y es: " << y << endl;
      if (r != INT_MAX){
	cout << r << " " << y << endl;
	encontre = true;
	break;
      }
      ++y;
      if ((y+1)*(y+1)*(y+1) - y*y*y > n) break;
    }
    if (!encontre){
      cout << "No solution\n";
      continue;
    }
  }
}
