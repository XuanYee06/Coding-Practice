//Enter <ENTER> to stop the system.

# include <iostream>
using namespace std;
void getInput(double&,double&,double&);
void disTier(double);
double calcAve(double,double);
void dispSummary(double);

int main(){
    string name,highName="",lowName="";
    double q1,q2,q3,total=0,num=0,totalA=0;
    double highest=0,lowest=100;
    double ave;
    do{
        cout<<"<<<<<<DATA<<<<<<"<<endl;
        cout<<"Name\t:";
        getline(cin,name);
        if(name=="")
            break;
        getInput(q1,q2,q3);
        total=static_cast<int>((q1/100*35)+(q2/100*25)+(q3/100*40));
        dispSummary(total);
        if(total>highest){
            highest=total;
            highName=name;
        }
        if(total<lowest){
            lowest=total;
            lowName=name;
        }
        num++;
        totalA+=total;
    }while(true);
    ave=calcAve(num,totalA);
    
    cout<<"<<<<<RESULTS ANALYSIS<<<<<"<<endl;
    cout<<"Lowest mark : "<<lowest<< " ("<<lowName<<")"<<endl;
    cout<<"Highest mark : "<<highest<< " ("<<highName<<")"<<endl;
    cout<<"Average for "<<num<<" students: "<<ave<<endl;
    return 0;
}

void getInput(double &q1,double &q2,double &q3){
    cout<<"Q1 mark: ";
    cin>>q1;
    cout<<"Q2 mark: ";
    cin>>q2;
    cout<<"Q3 mark: ";
    cin>>q3;
    cin.ignore();
}

void dispTier(double total){
    int tier;
    if(total>=75)
        tier=1;
    else if(total>=40)
        tier=2;
    else
        tier=3;
    cout<<"Tier\t: Tier "<<tier<<endl<<endl;
}

double calcAve(double num,double total){
    return total/num;
}

void dispSummary(double total){
    cout<<"<<<<<SUMMARY<<<<<"<<endl;
    cout<<"Total marks: "<<total<<endl;
    dispTier(total);
}
