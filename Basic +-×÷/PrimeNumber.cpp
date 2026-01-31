//Write a program to print prime number from 1-10*

#include <iostream>
using namespace std;
int main(){
  for(int i=1; i<=10; i++){
    bool isPrime=true;

    if(i<2){
      isPrime=false;
    }

    else{
      for(int j=2; j*j<=i; j++){
        if(i%j==0){
          isPrime=false;
        }
      }
    }

    if(isPrime)
      cout<<i<<" ";
  }
}
