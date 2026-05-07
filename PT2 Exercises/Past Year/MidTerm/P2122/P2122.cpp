//Past Year (Skill-Based Test) 2021/2022  
//ANSWER

#include <iostream>
#include <string>

using namespace std;

class Line{
	int m, c;
	
	public:
		Line(int M=1, int C=0){
			m=M;
			c=C;
		}
		void read(){
			cout<<"Enter the slope (m) and y-intercept of a line (c) => ";
			cin>>m>>c;
		}
		Line operator-(const Line&l){
			Line temp;
			temp.m=this->m-l.m;
			temp.c=this->c-l.c;
			return temp;
		}
		bool operator!=(const Line&l){
			if((this->m*l.m)!=-1) return true;
			else return false;
		}
		string toString()const{
			string a="y=";
			if(m==1) a+="x";
			else if(m==-1) a+="-x";
			else if(m==0){
				if(c>0) a+=c;
				else if(c<0) a+="-"+to_string(c);
				else a+="0";
			}
			
			if(c>0) a+="+"+to_string(c);
			else if(c<0) a+=to_string(c);
			else if(c==0) a+="+0";
			
			return a;
		}
		friend void printLines(const Line&l);
};

void printLines(const Line&l){
	string a=l.toString();
	cout<<" slope (m) = "<<l.m<<", y-intercept (c) = "<<l.c<<", equation: "<<a<<endl;
}

int main(){
	Line l[3]={Line(1,5)};
	
	cout<<"ORIGINAL LINES\n";
	
	for(int i=0;i<3;i++){
		cout<<"Line "<<(i+1);
		printLines(l[i]);
	}
	cout<<"\nSet the second line from user input\n";
	l[1].read();
	l[2]=l[0]-l[1];
	
	cout<<"\n\nUPDATED LINES\n";
	for(int i=0;i<3;i++){
		cout<<"Line "<<(i+1);
		printLines(l[i]);
	}
	
	cout<<"\n\n";
	
	if(l[0]!=l[2])
		cout<<"The first line is not perpendicular to the last line\n";
	else
		cout<<"The first line is perpendicular to the last line\n";

	return 0;
}
