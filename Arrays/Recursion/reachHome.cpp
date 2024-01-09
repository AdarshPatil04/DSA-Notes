/**
 * @brief This program demonstrates the use of recursion to print the path from a source to a destination.
 * 
 * The program defines a function called reachHome that takes a source and destination as input and recursively prints the path from the source to the destination.
 * It starts from the source and increments it until it reaches the destination.
 * The base case is when the source is equal to the destination, in which case it prints "Reached home".
 * The program then calls the reachHome function in the main function, passing the source and destination as arguments.
 */

#include<bits/stdc++.h>
using namespace std;

// reachHome function takes source and destination as input and recursively prints the path from source to destination.
void reachHome(int src, int des){
    cout<<"Source"<<src<<"Destination"<<des<<endl;

    // base case
    if(src == des){
        cout<<"Reached home"<<endl;
    }

    // processing
    src++;

    // recursive case
    reachHome(src, des);
}

int main(){
    int des = 5;
    int src = 0;

    // calling the reachHome function
    reachHome(src, des);
    return 0;
}