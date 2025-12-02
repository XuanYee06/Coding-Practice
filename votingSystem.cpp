#include <iostream>
using namespace std;
int main(){
  int age;
  cout<<"Please enter your age: ";
  cin>>age;
  if(age>=0 && age<=17)
    cout<<"You can't vote";
  else if(age>=18 && age <=65)
    cout<<"You can vote without helper";
  else if(age>=66)
    cout<<"You can vote with helper";
  else
    cout<<"Invalid input. Age must be a positive integer.";
return 0;
}
