#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
const int month=12;
const int br=5;

void readFile(char filename[],double a[br][month],string store[br]){
    ifstream inFile;
    inFile.open(filename);
    int s;
    for(int i=0;i<br;i++){
        for(int j=0;j<month;j++){
            inFile>>s;
            a[i][j]=s*1000;
        }
        inFile.ignore();
        getline(inFile,store[i]);
    }
    inFile.close();
}

double grandTotalSales(double a[br][month]){
    double total=0;
    for(int i=0;i<br;i++){
        for(int j=0;j<month;j++){
            total+=a[i][j];
        }
    }
    return total;
}
double averageMonthlySales(double a[br][month]){
    double t=grandTotalSales(a);
    return t/12;
}
double monthTotalSales(double a[br][month],int m){
    double total=0;
    for(int i=0;i<br;i++){
        total+=a[i][m];
    }
    return total;
}
double storeTotalSales(double a[][month],int s){
    double total=0;
    for(int i=0;i<month;i++){
        total+=a[s][i];
    }
    return total;
}
void indicesHighest(double a[][month],int &r,int &c){
    r=0,c=0;
    for(int i=1;i<br;i++){
        for(int j=1;j<month;j++){
            if(a[i][j]>a[r][c]){
                r=i;
                c=j;
            }
        }
    }
}
int main(){
    string mo[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG",
                    "SEP","OCT","NOV","DEC"};
    double sale[br][month];
    string store[br];
    char inputName[50],outputName[50];
    ofstream output;
    cout<<"Enter input file name: ";
    cin>>inputName;
    cout<<"Enter output file name: ";
    cin>>outputName;
    output.open(outputName);
    int row,col;
    double totalsalemonth,storetotal;
    
    readFile(inputName,sale,store);
    output<<fixed<<setprecision(2)<<right;
    output<<"Grand total of sales over all stores: RM "<<grandTotalSales(sale)<<endl;
    output<<"Average sales per month:             RM "<<averageMonthlySales(sale)<<endl<<endl;
    output<<"The highest sales:"<<endl;
    output<<"-----------------"<<endl;
    indicesHighest(sale,row,col);
    output<<"Store: "<<store[row]<<endl;
    output<<"Month: "<<mo[col]<<endl;
    output<<"Sales: RM  "<<sale[row][col]<<endl<<endl;
    output<<"Total sales by month:"<<endl;
    output<<"Month"<<setw(10)<<"Sales"<<endl;
    output<<"-----"<<setw(10)<<"-----"<<endl;
    for(int i=0;i<month;i++){
        totalsalemonth=monthTotalSales(sale,i);
        output<<mo[i]<<setw(10)<<"RM  "<<totalsalemonth<<endl;
    }
    output<<endl;
    output<<"Total sales by store:"<<endl;
    output<<"Store"<<setw(20)<<"Total Sales"<<endl;
    output<<"-----"<<setw(20)<<"-----------"<<endl;
    int profit;
    for(int i=0;i<br;i++){
        storetotal=storeTotalSales(sale,i);
        output<<store[i]<<setw(20)<<"RM  "<<storetotal<<endl;
    }
    output<<endl;
    output<<"Profitable stores:"<<endl;
    output<<"-----------------"<<endl;
    for(int i=0;i<br;i++){
        if(storeTotalSales(sale,i)>=600000)
            output<<store[i]<<endl;
    }
    output.close();
    return 0;
}
