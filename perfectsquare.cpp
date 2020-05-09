#include<iostream>
using namespace std;

 bool isPerfectSquare(int num)
 {
   int i=1;
   for ( long long int sum = 0; sum < num; i =i+2) {
         sum = sum+i;
         if (sum == num)
             return true;
     }
     return false;

 }



int main()
{

cout << isPerfectSquare(9);

}
