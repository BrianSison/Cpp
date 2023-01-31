#include <vector>
#include <iostream>

using namespace std;
int
main ()
{
  vector <float> v1(5);
  vector <float> v2={5, 0.5, 2.3, 4.7,0};
  //your code
  float input;
  cin >> input;
  for(int x=0;x<5;x++){
      v1[x]=input+v2[x];
      cout << v1[x] << " ";
  }
 float sum=0;
 for(int x=0;x<5;x++){
     sum+=v1[x];
     cout << sum << endl;
 }
  cout << "sum: " << sum;
  cout << "\navg: " << sum/5;
  return 0;
}