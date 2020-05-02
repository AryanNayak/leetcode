#include<iostream>
#include<string>
using namespace std;

int main ()
{
  string J;
  string S;

  cin >> J ;
  cin >> S;
  int c=0;


  for (int i=0;i<J.length();i++)
  {
    for (int j=0;j<S.length();j++)
    {
      if(J[i]==S[j])
      {
        c++;
      }
    }
  }


cout << c;

return 0;



}
