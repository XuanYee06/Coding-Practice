//Past Year (Skill-Based Test 1) 2019/2020 Set C
//ANSWER

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student{
	string name, status, matric;
	double gpa, cgpa;
	int credit, ccredit;
	
	public:
		Student(string n="", string m="", double cg=0.0, int cc=0, double g=0.0, int c=0){
			name=n;
			matric=m;
			cgpa=cg;
			ccredit=cc;
			gpa=g;
			credit=c;
			updateCGPA();
		}
		string getName(){
			return name;
		}
		string getStatus()const{
			string status;
			if(cgpa<1.7) status="Fail";
			else if(cgpa>=1.7 && cgpa<2.0) status="Probation";
			else status="Good";
			return status;
		}
		void updateCGPA(){
			cgpa=((gpa*credit)+(cgpa*ccredit))/(credit+ccredit);
		}
		void read(){
			cout<<"Name: ";
			getline(cin,name);
			cout<<"Matric Number: ";
			cin>>matric;
			cout<<"CGPA: ";
			cin>>cgpa;
			cout<<"Total Credit: ";
			cin>>credit;
			cout<<"GPA: ";
			cin>>gpa;
			cout<<"Credit earned this semester: ";
			cin>>ccredit;
			updateCGPA();
		}
		bool operator==(const Student&s){
			return (this->getStatus() == s.getStatus());
		}
		friend void display(const Student&s);
		friend ostream&operator<<(ostream&o, const Student&s);
};

void display(const Student&s){
	cout<<"You are in year ";
	string a=s.matric.substr(1,2);
	int age=20-stoi(a);
	string b=s.matric.substr(3,2);
	string program;
	if(b=="CS")
		program="Computer Science";
	else if(b=="EC")
		program="Engineering Computing";
	else
		program="Non Computing Program";
	
	cout<<age<<" in "<<program<<endl;
}
ostream&operator<<(ostream&o, const Student&s){
	o<<fixed<<setprecision(2);
	o<<"Hello, "<<s.name<<endl;
	display(s);
	o<<"Your matric number is "<<s.matric<<endl;
	o<<"Your current CGPA is "<<s.cgpa<<endl;
	o<<"Your status is "<<s.getStatus()<<endl;
	
	if(s.cgpa>=3.67)
		o<<"CONGRATULATIONS. You are awarded DEANs LIST\n";
	
	return o;
}

int main(){
	cout<<"CGPA Calculator\n\n";
	Student s1;
	Student s2("Hashim Abu", "A17CS1234", 4.0, 18);
	cout<<"<<< Input >>>\n";
	s1.read();
	s1.updateCGPA();
	
	cout<<"\n<<< Output >>>\n";
	cout<<s1<<endl;
	cout<<s2<<endl;
	
	if(s1==s2)
		cout<<"**Note: "<<s1.getName()<<" and "<<s2.getName()<<" have "<<s1.getStatus()<<" status.\n";
	else
		cout<<"**Note: "<<s1.getName()<<" and "<<s2.getName()<<" have different status.\n";
	
	return 0;
}
