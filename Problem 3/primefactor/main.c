/*
Problem 3, Project Euler
Prorgram: To calculate largest prime factor of a number
Idea: Generate primes upto an upper bound using the 'Sieve of Eratosthenes'. We create an array of numbers
uptil the upper bound, and starting from 2 consecutively cancel multiples of the selected number in the array.
Thus we get an array of primes. After this, we start checked (input_number % prime[UPPER_BOUND] == )0) and return
the first prime which is a divisor of the number.
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define UPPER_BOUND 10000
#define INPUT 600851475143

long long primes[(UPPER_BOUND+1)];

void generate_array(void) {
     long long i;
     for(i = 0; i <= UPPER_BOUND; i++)
         primes[i] = i;
     primes[0] = -1;
     primes[1] = -1; //these are not primes
     return ;
}

void filter_primes(void) {
     long long i, crnt_num, multiplier;
     for(i = 2; i <= (int)sqrt(UPPER_BOUND); i++) {
            multiplier = i;
            while((crnt_num = i * multiplier) <= UPPER_BOUND){
                   primes[crnt_num] = -1;      //if not prime, change to -1
                   multiplier++;
            }
     }
}

long long highest_prime_factor(long long num){
      long long i = UPPER_BOUND,t;
      generate_array();
      filter_primes();
      while(primes[i] == -1) //find highest prime
      i--;
      while((num % primes[i]) != 0){
            i--;
            while(primes[i] == -1)
            i--;
      }
      return primes[i];
}

int main()
{
    long long result;
    result = highest_prime_factor(INPUT);
    printf("%lld",result);
    return 0;
}
