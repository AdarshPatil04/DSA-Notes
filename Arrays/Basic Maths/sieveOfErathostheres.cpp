/**
 * @brief This program implements the Sieve of Eratosthenes algorithm to count the number of prime numbers less than a given number.
 * 
 * The Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a given limit. It works by iteratively marking prime to all the numbers except 0 and 1 and then starting from 2 making the multiples of each prime as non-prime. This process continues until all the numbers in the range are processed.
 * @param n The upper limit to count the number of prime numbers.
 * @return The count of prime numbers less than n.
 */

#include<bits/stdc++.h>
using namespace std;

// Sieve of Erathostheres
int countPrimes(int n){
    int count = 0;

    // Mark all numbers as prime initially for 0 to n
    vector<bool> prime(n+1, true);

    // Mark 0 and 1 as not prime
    prime[0] = prime[1] = false;

    for(int i = 2; i < n; i++){

        // If prime[i] is true then it is prime
        if(prime[i]){
            count++;

            // Mark all multiples of i as not prime
            for(int j = 2*i; j < n; j+=i){
                prime[j] = false;
            }
        }
    }

    // Return the count of prime numbers
    return count;
}

int main(){
    int n=5000000;

    // Count the number of primes less than n
    cout<<countPrimes(n);
    return 0;
}