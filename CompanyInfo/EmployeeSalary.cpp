#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
struct Employee{
    string name,department;
    double basic;
    int hour;
    double overtime,total;
};
int readInput(Employee e[]){
    int num=0;
    ifstream inp("input.txt");
    if(!inp){
        cout<<"ERROR!";
        return 0;
    }
    while(inp>>e[num].department>>e[num].basic>>e[num].hour){
        inp.ignore();
        getline(inp,e[num].name);
        num++;
    }
    inp.close();
    return num;
}
double determineRate(string department){
    if(department=="Quality")
        return 11.5;
    else if(department=="Production")
        return 10.0;
    else if(department=="Accounting")
        return 12.5;
    else if(department=="Engineering")
        return 15.0;
    else
        return 0.0;
}
void display(Employee e[],int num){
    cout<<fixed<<setprecision(2);
    
    for(int i=0;i<num;i++){
        e[i].overtime=determineRate(e[i].department)*e[i].hour;
        e[i].total=e[i].overtime+e[i].basic;
    }
    for(int i=0;i<100;i++){
        cout<<"-";
    }
    cout<<endl;
    cout<<left<<setw(25)<<" NAME"<<setw(20)<<"DEPARTMENT"<<setw(10)<<"BASIC(RM)"
        <<setw(10)<<"OT(HOUR)"<<setw(10)<<"OT PAY(RM)"<<"SALARY(RM)"<<endl;
    for(int i=0;i<100;i++){
        cout<<"-";
    }
    cout<<endl;
    for(int i=0;i<num;i++){
        cout<<left<<setw(25)<<e[i].name<<setw(20)<<e[i].department<<setw(10)
            <<e[i].basic<<setw(10)<<e[i].hour<<setw(10)<<e[i].overtime<<setw(10)
            <<e[i].total<<endl;
    }
    for(int i=0;i<100;i++){
        cout<<"-";
    }
    cout<<endl;
}
void displaya(Employee e[],int num){
    string dept[]={"Production","Quality","Engineering","Accounting"};
    double total,salary;
    cout << left << setw(25) << "DEPARTMENT" << setw(25)
         << "TOT. OT PAY (RM)" << "TOT. SALARY (RM)" << endl;
    for(int j=0;j<4;j++){
        total=0;
        salary=0;
        cout<<fixed<<setprecision(2);
        for(int i=0;i<num;i++){
            if(e[i].department==dept[j]){
                total+=e[i].overtime;
                salary+=e[i].total;
            }
        }
        cout<<left<<setw(30)<<dept[j]<<setw(25)<<total<<salary<<endl;
    }
    for(int i=0;i<100;i++){
        cout<<"-";
    }
}
int main(){
    Employee e[50];
    int num=readInput(e);
    display(e,num);
    displaya(e,num);
    return 0;
}
