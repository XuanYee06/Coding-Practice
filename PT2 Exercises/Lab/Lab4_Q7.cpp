//Lab 4 Question 7

#include <iostream>
#include <cstdlib>
using namespace std;

// Task 1: Complete the definition of class Date.
class Date 
{
	private: 
		string description;
		int day, month, year;
	
	public:	
		Date(string t="", int d=0, int m=0, int y=0){
			description=t;
			day=d;
			month=m;
			year=y;
		}
		void setT(string t){
			description=t;
		}
		void setD(int d){
			day=d;
		}
		void setM(int m){
			month=m;
		}
		void setY(int y){
			year=y;
		}
		string getT(){
			return description;
		}
		int getD(){
			return day;
		}
		int getM(){
			return month;
		}
		int getY(){
			return year;
		}
		Date operator-(const Date &d){
			Date temp;
			temp.day=abs(this->day-d.day);
			temp.month=abs(this->month-d.month);
			temp.year=abs(this->year-d.year);
			return temp;
		}
		friend istream &operator>>(istream &, Date&);
		friend ostream &operator<<(ostream &, const Date&);
};
istream &operator>>(istream &i, Date&d){
	i>>d.day>>d.month>>d.year;
	return i;
}
ostream &operator<<(ostream &o, const Date&d){
	o<<d.description<<": "<<d.day<<"-"<<d.month<<"-"<<d.year;
	o<<endl;
	return o;
}

// Task 2: The following function is partialy given. 
// The function is meant to print the difference between two dates.
// Complete the code of the function.
void displayDiff(Date d) 
{
	cout << "The difference: ";
	if(d.getY()!=0)
		cout<<d.getY()<<" year(s)"<<endl<<endl;
	
	else if(d.getM()!=0)
		cout<<d.getM()<<" month(s)"<<endl<<endl;
	
	else
		cout<<d.getD()<<" day(s)"<<endl<<endl;
}

int main()
{
	// Task 3: Create an array to hold three(3) dates and initialize 
	// the description of each date with specified values.
	Date d[3]={Date("SBT",11,3,2018),
			   Date("Test",30,3,2018),
			   Date("Final",5,6,2018)};
	
	// Task 4: Using a loop and an appropriate functions(s), enter the values
	// of day, month and year from the keyboard for the array
	for (int i=0;i<3;i++){
		cout<<"Enter your date (day, month, year) : ";
		cin>>d[i];
	}
	
	// Task 5: Create two objects named date1 and date2 with the specified data.
	Date date1("TODAY",5,3,2018);
	Date date2("Date of birth",23,11,1999);
	
	// Task 6: Using an appropriate function and another loop, print all the dates 
	// and the difference between date1 and other dates.
	cout<<endl<<date1<<endl;
	cout<<date2;
	displayDiff(date2);
	
	for(int i=0;i<3;i++){
		cout<<d[i];
		displayDiff(d[i]-date1);
	}
		
	return 0;
}
