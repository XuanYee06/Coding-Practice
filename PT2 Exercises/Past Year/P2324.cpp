//Past Year (Mid-Term Test II) 2023/2024 
//ANSWER

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Vector{
	int *item;
	int size;
	
	public:
		Vector(){
			item=nullptr;
			size=0;
		}
		Vector(int s){
			size=s;
			item=new int[size];
		}
		Vector(int *in,int s){
			size=s;
			item=new int[size];
			for(int i=0;i<size;i++){
				item[i]=in[i];
			}
		}
		Vector(string a){
			size=a.length();
			item=new int[size];
			for(int i=0;i<size;i++){
				item[i]=a[i]-'0';
			}
		}
		Vector(const Vector &v){
			size=v.size;
			item=new int[size];
			for(int i=0;i<size;i++){
				item[i]=v.item[i];
			}
		}
		~Vector(){delete [] item;}
		operator int(){return size;}
		operator double(){
			double total=0;
			for(int i=0;i<size;i++){
				total+=item[i]*item[i];
			}
			return sqrt(total);
		}
		operator string(){
			string result="";
			for(int i=0;i<size;i++){
				result+=to_string(item[i]);
				if(i!=(size-1))
					result+=", ";
			}
			return result;
		}
		Vector operator*(int a){
			Vector temp=*this;
			for(int i=0;i<size;i++){
				temp.item[i]*=a;
			}
			return temp;
		}
		Vector operator+(const Vector &v){
			Vector temp=*this;
			for(int i=0;i<size;i++){
				temp.item[i]=this->item[i]+v.item[i];
			}
			return temp;
		}
		Vector operator+(int a){
			Vector temp;
			temp.size=size+1;
			temp.item=new int[temp.size];
			for(int i=0;i<size;i++){
				temp.item[i]=this->item[i];
			}
			temp.item[size]=a;
			return temp;
		}
		int &operator[](int i){
			if(i>=0 && i<size)
				return item[i];
		}
		bool operator==(const Vector &v){
			if(this->size!=v.size)
				return false;
			for(int i=0;i<size;i++){
				if(this->item[i]!=v.item[i])
					return false;
			}
			return true;
		}
		bool operator>(Vector &v){
			return (double)*this>(double)v;
		}
		friend void print(string t, Vector&);
};

void print(string t, Vector&v){
	cout<<fixed<<setprecision(4);
	cout<<t<<": ( ("<<(string)v<<"), s: "<<(int)v<<", m: "<<(double)v<<" )\n";
}

int main(){
	int temp[]={6,7,8,9};
	Vector a(temp,4);
	Vector b("678");
	Vector c=b;
	Vector *d=new Vector(b);
	Vector e=*d+1;
	Vector f=c*2;
	Vector g=a+e;
	
	print("a",a);
	print("b",b);
	print("c",c);
	cout<<endl;
	print("d",*d);
	cout<<endl;
	print("e",e);
	print("f",f);
	print("g",g);
	cout<<endl;
	if(a==b)
		cout<<"a is equivalent to b\n";
	else
		cout<<"a is not equivalent to b\n";
		
	if(a>e)
		cout<<"a is greater than e\n";
	else
		cout<<"e is grater than a\n";
	
	delete d;
	return 0;
}
