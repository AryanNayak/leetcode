#include<iostream>
#include<string.h>
using namespace std;

int main ()
{
  string ransomNote;
  string magazine;
  cin >> magazine;
  cin >> ransomNote;
  int n =0;
  int flag =0;
  for (int i=0;i<ransomNote.length();i++)
  {
for(int j=0;j<magazine.length();j++)
{
  if(ransomNote[i] == magazine[j])
  {
     n = magazine.length();
    if(ransomNote.substr(i,n) == magazine)
    {
      cout << true;
      flag = 1;
      break;
    }
  }
}
  }

  if (flag==0)
  {
    cout << false;
  }

return 0;






}
