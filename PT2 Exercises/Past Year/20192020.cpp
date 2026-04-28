//Past Year (Skill-Based Test 1) 2019/2020 Set B

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

class Person{
	string name,ic;
	int activity;
	double height,weight,bmr,calories;
	
	public:
		Person(string n="",int a=0,double h=0,double w=0,string IC=""){
			name=n;
			ic=IC;
			activity=a;
			height=h;
			weight=w;
		}
		string getN()const{
			return name;
		}
		string getGender()const{
			string gender;
			string num=ic.substr(11,1);
			int n=stoi(num);
			if(n%2==0)
				gender="female";
			else
				gender="male";
			return gender;
		}
		int getAge()const{
			string year=ic.substr(0,2);
			
			int full,y=stoi(year);
			
			if(y>=27)
				full=1900+y;
			else
				full=2000+y;
			return 2026-full;
		}
		void calcCalorie(string gender,int age){
			if(gender=="male")
				bmr=(10*weight)+(6.25*height)-(5*age)+5;
			else
				bmr=(10*weight)+(6.25*height)-(5*age)-161;
			
			if(activity==1)
				calories=bmr*1.2;
			else if(activity==2)
				calories=bmr*1.375;
			else if(activity==3)
				calories=bmr*1.55;
			else if(activity==4)
				calories=bmr*1.725;
			else if(activity==5)
				calories=bmr*1.9;
		}
		void read(){
			cout<<"<<< Input >>>\n";
			cout<<"Name: ";
			getline(cin,name);
			cout<<"NRIC Number (without hypen'-'): ";
			getline(cin,ic);
			cout<<"Height (in meter): ";
			cin>>height;
			cout<<"Weight (in kg): ";
			cin>>weight;
			cout<<"Choose the activity level: 1-Sedentary, 2-Lightly Active, 3-Moderately Active, 4-Very Active, 5-Extra Active\n";
			cout<<"Activity level (1-5): ";
			cin>>activity;
			cout<<endl;
			
			calcCalorie(getGender(),getAge());
		}
		bool operator==(const Person&p){
			if(activity==p.activity)
				return true;
			else
				return false;
		}
		friend void dispInfo(const Person&);
		friend ostream &operator<<(ostream&, const Person&);
};

void dispInfo(const Person& p) {
    cout << "Your gender is " << p.getGender() << endl;
    cout << "Your age is " << p.getAge() << " years old" << endl;
}
ostream &operator<<(ostream&o, const Person&p){
	cout<<fixed<<setprecision(2);
	o<<"<<< Output >>>\n";
	o<<"Hello, "<<p.getN()<<endl;
	o<<"Your gender is "<<p.getGender()<<endl;
	o<<"Your age is "<<p.getAge()<<" years old\n";
	o<<"Your height is "<<p.height<<" cm\n";
	o<<"Your weight is "<<p.weight<<" kg\n";
	o<<"Your BMR is "<<p.bmr<<" kcal/day\n";
	o<<"Your calories based on activity level is "<<p.calories<<" kcal/day\n\n";

	return o;
}

int main(){
	Person p1,p2("Alisa Hashim",2,150,50.00);
	
	cout<<"Calorie Calculator\n\n";
	p1.read();
	cout<<p1;
	
	cout<<"**Note: "<<p1.getN()<<" and "<<p2.getN();
	if(p1==p2)
		cout<<" have same activity level."<<endl;
    else
        cout<<" have different activity level."<<endl;
        
    return 0;
}
