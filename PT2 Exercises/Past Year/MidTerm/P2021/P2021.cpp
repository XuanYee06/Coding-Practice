//Past Year (Skill-Based Test II) 2020/2021
//ANSWER

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Name{
	string first,last;
	
	public:
		Name(string f="",string l=""){
			first=f;
			last=l;
		}
		string getN(){
			return first+" "+last;
		}
};

class Product{
	string name,category;
	double price;
	int quantity;
	
	public:
		Product(){
			name="";
			category="";
			price=0.0;
			quantity=0;
		}
		Product(string n,string c,double p){
			name=n;
			category=c;
			price=p;
		}
		string getN(){
			return name;
		}
		string getC(){
			return category;
		}
		double getP(){
			return price;
		}
		int getQ(){
			return quantity;
		}
		void setQ(int q){
			quantity=q;
		}
};

class Customer{
	string address;
	int num;
	Name name;
	Product *p;
	
	public:
		Customer(string f,string l,string a){
			name=Name(f,l);
			num=0;
			address=a;
			p=new Product[10];
		}
		void buy(Product q,int n){
			if(num<10){
				q.setQ(n);
				p[num]=q;
				num++;
			}
			else
				cout<<"Sorry!! You already reached the maximum number of products purchased." << endl;
		}
		void print(){
			double total=0.0;
			cout<<fixed<<setprecision(2);
			cout<<"Name		: "<<name.getN()<<endl;
			cout<<"Adrress  : "<<address<<endl;
			cout<<"Number of products perchased: "<<num<<endl<<endl;
			cout<<"No\tProduct Name\tCategory\tQuantity\tUnit Price(RM)\tAmount(RM)\n";
			for(int i=0;i<num;i++){
				cout<<i+1<<'\t'<<p[i].getN()<<'\t'<<p[i].getC()<<"\t"<<p[i].getQ()<<"\t"
					<<p[i].getP()<<"\t"<<(p[i].getP()*p[i].getQ());
				cout<<endl;
				total+=p[i].getP()*p[i].getQ();
			}
			cout<<"\nTotal price = RM "<<total;
		}
};

int main () {
	Customer cust("Amir", "Jalil", "Masai, Johor");
	Product p1("Jacob", "Biscuit", 14.8);
	Product p2("Twister", "Drink", 7.5);
	Product p3("Ayamas", "Nugget", 18.4);
	Product p4("Oreo", "Biscuit", 3.8);
	cust.buy(p4, 5);
	cust.buy(p2, 4);
	cust.buy(p3, 2);
	cust.buy(p1, 3);
	cust.print();
	
	return 0;
}
