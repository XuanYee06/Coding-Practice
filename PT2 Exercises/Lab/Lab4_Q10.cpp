//Lab 4 Question 10

#include<iostream>
#include <cmath>
using namespace std;

class Particle{
	int x, y, z, radius;
	
	public:
		Particle(){
			x=0;
			y=0;
			z=0;
			radius=0;
		}
		void read(){
			cout<<"Center: ";
			cin>>x>>y>>z;
			cout<<"Radius: ";
			cin>>radius;
		}
		void print(){
			cout<<"Center: ("<<x<<","<<y<<","<<z<<")\n";
			cout<<"Radius: "<<radius<<endl;
		}
		double operator-(const Particle &p){
			Particle temp;
			temp.x=p.x-(this->x);
			temp.y=p.y-(this->y);
			temp.z=p.z-(this->z);
			
			return sqrt(pow(temp.x,2)+pow(temp.y,2)+pow(temp.z,2));
		}
		friend bool collision(Particle &, Particle &);
};

bool collision(Particle &p1, Particle &p2){
	if((p1.radius+p2.radius)>(p1-p2))
		return true;
	else
		return false;
}

int main(){
	Particle p1, p2;
	cout<<"Enter data for the first particle: \n";
	p1.read();
	cout<<"\nEnter data for the second particle: \n";
	p2.read();
	cout<<endl;
	
	if(collision(p1,p2)==true){
		cout<<"The particles are colliding.\n\n";
		p1.print();
		cout<<endl;
		p2.print();
	}
	else
		cout<<"No collision detected.\n";
	
	return 0;
}
