#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
struct Company{
    string id;
    double monthcost[12];
    double monthsale[12];
};
double getBranchProfit(Company c){
    double branch=0;
    for(int i=0;i<12;i++){
        branch+=(c.monthsale[i]-c.monthcost[i]);
    }
    return branch;
}
double getMonthProfit(Company c[], int i, int j){
    double month=0;
    for(int y=0;y<i;y++){
        month+=(c[y].monthsale[j]-c[y].monthcost[j]);
    }
    return month;
}
double getTotalProfit(Company c[],int i){
    double total=0;
    for(int p=0;p<i;p++){
        total+=getBranchProfit(c[p]);
    }
    return total;
}   

int main(){
    Company c[1000];
    string inputFile,outputFile;
    int year;
    string header;
    
    cout<<"Enter input file name: ";
    cin>>inputFile;
    cout<<"Enter output file name: ";
    cin>>outputFile;

    ifstream ip(inputFile);

    if(!ip){
        cout<<"ERROR! UNABLE TO OPEN INPUT FILE.";
        return 0;
    }
    ip>>year;
    ip.ignore();
    getline(ip,header);
    int i=0;
    while(ip>>c[i].id){
        for(int j=0;j<12;j++){
            ip>>c[i].monthcost[j];
            ip>>c[i].monthsale[j];
        }
        i++;
    }

    ofstream op(outputFile);
    op<<"Profit Analysis of Company XYZ for the year "<<year<<endl<<endl;
    op<<"Total Profit For Each Branch"<<endl;
    op<<"Branch \t Profit"<<endl;
    for(int x=0;x<i;x++){
        op<<c[x].id<<"\tRM "<<getBranchProfit(c[x])<<endl;
    }
    op<<endl;
    op<<"Total Profit For Each Month"<<endl;
    op<<"Month\tProfit"<<endl;
    string month[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    for(int j=0;j<12;j++){
        op<<month[j]<<"\tRM "<<getMonthProfit(c,i,j)<<endl;
    }

    op<<endl;
    op<<"Yearly Profit: RM "<<getTotalProfit(c,i);
    ip.close();
    op.close();
    return 0;
}
