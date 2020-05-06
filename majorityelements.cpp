#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main ()
{

std::vector<int> nums;
nums.push_back(3);
nums.push_back(5);
nums.push_back(3);
map <int,int> mp;

for (int i = 0; i< nums.size() ;i++)
{
  mp[nums[i]]++;
}

for(int i=0;i<nums.size();i++)
{
  if (mp[nums[i]] > (nums.size()/2))
  {
    cout << nums[i];
  }
}








}
