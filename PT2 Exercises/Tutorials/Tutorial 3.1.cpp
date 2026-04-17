// Tutorial 3.1
#include <iostream>
using namespace std;

// * ---------------------------------------------------------------------------------------------
// * Task 1: Declare and define the class Line
// * ---------------------------------------------------------------------------------------------
class Line{
  private:
	double m;  // the slope of the line
	double c;  // the y-intercept

  public:
	Line(){
		m=0;
		c=0;
	}
	Line(double _M,double _C){
		m=_M;
		c=_C;
	}
	Line(double x1,double y1,double x2,double y2){
		m=(y2-y1)/(x2-x1);
		c=(y1-(m*x1));
	}
	~Line(){
		cout<<"The object is being destroyed."<<endl;
	}
	double getm(){
		return m;
	}
	double getc(){
		return c;
	}
	void setm(double M){
		m=M;
	}
	void setc(double C){
		c=C;
	}
	void print(){
		cout<<"Eq.   y="<<m<<"x";
		if(c<0)
			cout<<"-"<<c;
		else if(c>0)
			cout<<"+"<<c;
		cout<<endl<<endl;
	}
};

int main(){
	// * ---------------------------------------------------------------------------------------------
	// * Task 2: Create the object 'line1'
	// * ---------------------------------------------------------------------------------------------
	Line line1(2,5);
	line1.print();

	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Create the object 'line2'
	// * ---------------------------------------------------------------------------------------------
	Line line2(0,0,2,8);
	line2.print();

	// * ---------------------------------------------------------------------------------------------
	// * Task 4: Create the object 'line3'
	// * ---------------------------------------------------------------------------------------------
	Line line3;
	double slope, intercept;

	cout << "Enter the slope and y-intercept of the line  m  c => ";
	cin >> slope >> intercept;
	cout << endl;
	line3.setm(slope);
	line3.setc(intercept);
	line3.print();
  
	return 0;
}
