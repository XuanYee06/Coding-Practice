#include <iostream>
using namespace std;

//-----------------------------------------------------------------------
// Class declaration
//-----------------------------------------------------------------------

class Point{
private:
    double x, y;

public:
    Point(double, double);
    Point(const Point &obj);
    Point();
    void print() const;
    void input();
    Point add(const Point &);
    Point operator+(const Point &a);
    friend Point addPoint(const Point &, const Point &);
    Point divide(double b);
    Point operator/(double b);
    friend Point dividePoint(const Point &, double);
};

Point::Point(double X, double Y){
	x=X;
	y=Y;
}
Point::Point(const Point &obj):Point(obj.x,obj.y){}
Point::Point(){
	x=0;
	y=0;
}
void Point::print() const{ //preventing changes of the values
	cout<<"("<<x<<","<<y<<")\n";
}
void Point::input(){
	cin>>x>>y;
}
Point Point::add(const Point &a){
	return Point(x+a.x,y+a.y);
}
Point Point::operator+(const Point &a){
	return Point(x+a.x,y+a.y);
}
Point addPoint(const Point &p1, const Point &p2){
	return Point(p1.x+p2.x,p1.y+p2.y);
}
Point Point::divide(double b){
	return Point(x/b,y/b);
}
Point Point::operator/(double b){
	return Point(x/b,y/b);
}
Point dividePoint(const Point &p,double b){
	return Point(p.x/b,p.y/b);
}
//-----------------------------------------------------------------------
// The main function
//-----------------------------------------------------------------------

int main(){
    int nPoint;
    cout << "How many points you want to enter => ";
    cin >> nPoint;
    cout << endl;
	Point *p=new Point[nPoint];
    
    for(int i=0;i<nPoint;i++){
    	cout<<"Enter the coordinates (x and y) => ";
    	p[i].input();
	}

	cout<<endl;
	
    Point sum1, sum2, sum3;

    cout << "Printing all points" << endl;
    
	for(int i=0;i<nPoint;i++){
		p[i].print();
	}
	
    cout << endl;

    cout << "Printing the middle point with three different ways" << endl;
    for(int i=0;i<nPoint;i++){
    	sum1=sum1.add(p[i]);
	}
	sum1=sum1.divide(nPoint);
	sum1.print();
	
	for(int i=0;i<nPoint;i++){
		sum2=sum2+p[i];
	}
	sum2=sum2.divide(nPoint);
	sum2.print();
	
	for(int i=0;i<nPoint;i++){
		sum3=addPoint(p[i],sum3);
	}
	sum3=dividePoint(sum3,nPoint);
	sum3.print();
    
    return 0;
}
