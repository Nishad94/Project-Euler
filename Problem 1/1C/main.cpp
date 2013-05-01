/*
  Project Euler
  Problem 1
  C++
*/

/*
Sum(S) of multiples of a number k uptil n: k +2k +3k +4k...+ int(n-1/k)*k.
(n/k)*k is an integral value just lesser than or equal to n.
S = k(1+2+3+4+...+p), where p = n-1/k
S = k.p.(p+1) / 2
*/

/*
Compute:
To calculate the sum of multiples of 2 numbers(n1,n2) below the LIMIT,
we need to add sum of multiples of the 2 numbers and subtract common terms.
The common terms are simply multiples of n1*n2
*/

#include <iostream>
#define NUM1 3
#define NUM2 5          // Sum of multiples of 3 and 5 are to be calculated below 1000
#define LIMIT 1000

using namespace std;

class Total {

     public:
         long long sum(int k, int n){
         p = (n - 1) / k;
         S = k * p * (p+1) / 2;
         return S;
         }

         long long compute(int n1, int n2,int l){
         long long result, upper_bound = l;
         result = sum(n1,l) + sum(n2,l) - sum(n1*n2,l);
         return result;
         }

    private:
       long long p, S;

};

int main()
{
    Total t1;
    cout << t1.compute(NUM1,NUM2,LIMIT) << endl;
    return 0;
}
