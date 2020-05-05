#include<iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;

int main ()
{
string s;


cin >> s;


if(s.length() == 1)
{
  cout << "-1" ;
}


for (int i=0;i<s.length();i++)
{

  for (int j=i+1;j<s.length();j++)
  {
    if(s[i]==s[j])
    {
      break;
    }
    else
    {
      if(j == s.length()-1)
      {
        cout << i;
        exit(0);
      }
      else
      {
        continue;
      }
    }

  }
}



}
