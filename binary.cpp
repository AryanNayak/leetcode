#include <iostream>
using namespace std;

int decToBinary(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }


    for (int j = i - 1; j >= 0; j--)
      {  if (binaryNum[j] == 1)
        {
          binaryNum[j]= 0;
        }
        else
        {
          binaryNum[j] =1;
        }
      }
    int finalNumber = 0;

for (int k = 0; k < i; k++)
{
    int num = binaryNum[k];
    if (num != 0) {
        while (num > 0) {
            finalNumber *= 10;
            num /= 10;
        }
        finalNumber += binaryNum[k];
    } else {
        finalNumber *= 10;
    }
}

return finalNumber;


}


void binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;

    int temp = num;

    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;


    }

    cout << dec_value;
}



int main()
{
    int n ;

    cin >> n;
    int ans;
    ans = decToBinary(n);
    binaryToDecimal(ans);
    return 0;
}
