//Past Year (Mid-Term Test II) 2022/2023
//ANSWER

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class WordNumber{
	string data;
	
	public:
		WordNumber(string d="zero"){
			data=d;
		}
		WordNumber(int a){
			if(a>=0 && a<=9){
				if(a==0) data="zero";
				else if(a==1) data="one";
				else if(a==2) data="two";
				else if(a==3) data="three";
				else if(a==4) data="four";
				else if(a==5) data="five";
				else if(a==6) data="six";
				else if(a==7) data="seven";
				else if(a==8) data="eight";
				else if(a==9) data="nine";
			}
		}
		void setD(string d){
			data=d;
		}
		operator int()const{
			if (data == "zero" || data == "Zero" || data == "ZERO") return 0;
	        if (data == "one" || data == "One" || data == "ONE") return 1;
	        if (data == "two" || data == "Two" || data == "TWO") return 2;
	        if (data == "three" || data == "Three" || data == "THREE") return 3;
	        if (data == "four" || data == "Four" || data == "FOUR") return 4;
	        if (data == "five" || data == "Five" || data == "FIVE") return 5;
	        if (data == "six" || data == "Six" || data == "SIX") return 6;
	        if (data == "seven" || data == "Seven" || data == "SEVEN") return 7;
	        if (data == "eight" || data == "Eight" || data == "EIGHT") return 8;
	        if (data == "nine" || data == "Nine" || data == "NINE") return 9;
        	return 0;
		}
		bool operator>(const WordNumber&w){
			return (int)*this>(int)w;
		}
		int operator+(int n){
			return n+(int)*this;
		}
		string operator+(string n){
			return data+n;
		}
		WordNumber operator+(const WordNumber&w){
			int sum=(int)*this+(int)w;
			return WordNumber(sum);
		}
		friend void printObject(const WordNumber&);
};

void printObject(const WordNumber &w){
	cout<<"("<<w.data<<", "<<(int)w<<")\n";
}

void printArray(WordNumber w[],int s){
	for(int i=0;i<s;i++)
		printObject(w[i]);
}

int main(){
	WordNumber w[4]={WordNumber(),
					 WordNumber(1),
					 WordNumber(2),
					 WordNumber("three")};
	
	printArray(w,4);
	cout<<"\nTo modify the objects with user inputs\n";
	string a;
	for(int i=0;i<4;i++){
		cout<<"Enter a number in word=> ";
		cin>>a;
		for(int i=0;i<a.length();i++)
			a[i]=tolower(a[i]);
		w[i].setD(a);
		cout<<endl;
	}
	
	cout<<"Modified objects\n";
	printArray(w,4);
	
	WordNumber total=w[0];
	WordNumber largest=w[0];
	for(int i=1;i<4;i++){
		if(w[i]>w[largest])
			largest=i;
		total=total+w[i];
	}
	cout<<"\nThe sum: ";
	printObject(total);
	cout<<"\nThe largest: ";
	printObject(largest);
	
	string str;
	cout<<"\nTo add object with a string\n";
	cout<<"Enter a string => ";
	cin>>str;
	cout<<"The result of adding object with the input string\n";
	cout<<total+str;
	
	return 0;
}
