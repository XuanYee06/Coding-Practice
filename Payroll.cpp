#include<iostream>
#include<iomanip>
using namespace std;
void displayLine(){
    for(int i=0;i<105;i++){
        cout<<"-";
    }
    cout<<endl;
}
void getData(int id[],double work[][5]){
    for(int i=0;i<5;i++){
        cout<<"ID: ";
        cin>>id[i];
        cout<<"Hours worked: ";
        cin>>work[i][0];
        cout<<"Rate of Pay (RM per hour): ";
        cin>>work[i][1];
    }
}
void calcPayroll(int id[],double work[][5]){
    for(int i=0;i<5;i++){
        work[i][2]=work[i][0]*work[i][1];
        if(work[i][0]>40)
            work[i][3]=(work[i][0]-40)*work[i][1]*1.5;
        else
            work[i][3]=0;
        work[i][4]=work[i][2]+work[i][3];
    }
}
void highest(int id[],double work[][5]){
    int h=0;
    for(int i=1;i<5;i++){
        if(work[i][3]>work[h][3]){
            h=i;
        }
    }
    cout<<"Staff "<<id[h]<<" have the highest pay overtime of RM"<<work[h][3]<<endl;
    cout<<endl<<"-----------------------------------------------";
}
void printData(int id[],double work[][5]){
    cout<<"Payroll Final Report"<<endl;
    displayLine();
    cout<<left<<setw(7)<<"ID"<<setw(8)<<"HOURS"<<setw(11)<<"RATE(RM)"<<setw(19)
        <<"REGULAR PAY (RM)"<<setw(19)<<"OVERTIME (RM)"<<"TOTAL (RM)"<<endl;
    displayLine();
    for(int i=0;i<5;i++){
        cout<<left<<setw(7)<<id[i];
        for(int j=0;j<5;j++){
            cout<<fixed<<setprecision(1);
            cout<<left<<setw(8)<<work[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    highest(id,work);
}

int main(){
    int id[5];
    double work[5][5];
    cout<<"Payroll Program"<<endl;
    getData(id,work);
    cout<<endl;
    calcPayroll(id,work);
    printData(id,work);
    return 0;
}
