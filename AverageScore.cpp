//Find the average for the highest 4 scores out of 5 scores

#include <iostream>
using namespace std;
void getScore(double&);
void calcAverage(double, double, double, double, double);
double findLowest(double, double, double, double, double);
int main(){
    double s1, s2, s3, s4, s5;
    getScore(s1);
    getScore(s2);
    getScore(s3);
    getScore(s4);
    getScore(s5);
    calcAverage(s1, s2, s3, s4, s5);
    return 0;
}

void getScore(double &s){
    cout<<"Enter your test score: ";
    cin>>s;
    
    while(s<0 || s>100){
        cout<<"Score must be value 0-100.\n"<<"Please enter a value 0-100: ";
        cin>>s;
    }
}

void calcAverage(double s1, double s2, double s3, double s4, double s5){
    double lowest;
    lowest=findLowest(s1, s2, s3, s4, s5);
    double total=s1 + s2 + s3 + s4 + s5 - lowest;
    double average= total/4;
    cout<<"Average of the 4 highest score is: "<<average<<endl;
}

double findLowest(double s1, double s2, double s3, double s4, double s5){
    double lowest=s1;
    if(s2<lowest)
        lowest=s2;
    if(s3<lowest)
        lowest=s3;
    if(s4<lowest)
        lowest=s4;
    if(s5<lowest)
        lowest=s5;
    return lowest;
}
