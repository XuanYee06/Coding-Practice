//Past Year (Mid-Term Test II) 2024/2025  
//ANSWER

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class DroneTask{
	string id;
	int duration;
	double percentage;
	bool critical;
	
	public:
		DroneTask(){
			id="UNKNOWN";
			duration=0;
			percentage=0.0;
			critical=false;
		}
		
		DroneTask(string ID, int d, double p, bool c){
			id=ID;
			duration=d;
			percentage=p;
			critical=c;
		}
		DroneTask(string ID, double p){
			id=ID;
			percentage=p;
			duration=0;
			critical=false;
		}
		DroneTask(string data){
			int s=0, e;
			
			e=data.find('|',s);
			id=data.substr(s,e-s);
			s=e+1;
			e=data.find('|',s);
			string dur=data.substr(s,e-s);
			duration=stoi(dur);
			s=e+1;
			e=data.find('|',s);
			string per=data.substr(s,e-s);
			percentage=stod(per);
			s=e+1;
			string cri=data.substr(s);
			if(cri=="true" || cri=="1")
				critical=true;
			else
				critical=false;
		}
		~DroneTask(){
			cout<<"Task ["<<id<<"] is now removed from memory"<<endl;
		}	
		friend void showTaskSummary(DroneTask &);
		bool operator>(const DroneTask &);
		bool operator==(const DroneTask &);
		DroneTask operator+(int);
		friend ostream &operator<<(ostream&, const DroneTask&);
		
		operator int(){ return duration;}
		operator double(){ 
			if(percentage>0.0||percentage<=1.0)
				return percentage;
		}
		operator string(){
			string result=id+"Accuracy: "+to_string(percentage)+"%) - "+to_string(duration)+" s";
			return result;
		}
		operator bool(){
			if(critical==true && percentage>=90)
				return true;
			else
				return false;
		}
};

void showTaskSummary(DroneTask &d){
	cout<<"Task "<<d.id<<": "<<d.duration<<" s, "<<d.percentage
		<<"% accuracy, ";
	if(d.critical==true)
		cout<<"CRITICAL\n";
	else
		cout<<"NON-CRITICAL\n";
}

bool DroneTask::operator>(const DroneTask &d){
	return (this->percentage>d.percentage);
}

bool DroneTask::operator==(const DroneTask &d){
	string i1="";
	string i2="";
	
	for(int i=0;i<this->id.length();i++){
		if(this->id[i]!='-')
			i1+=tolower(this->id[i]);
	}
	
	for(int i=0;i<d.id.length();i++){
		if(d.id[i]!='-')
			i2+=tolower(d.id[i]);
	}
	
	return (i1==i2);
}

DroneTask DroneTask::operator+(int s){
	DroneTask temp=*this;
	temp.duration+=s;
	return temp;
}

ostream &operator<<(ostream &o, const DroneTask&d){
	o<<fixed<<setprecision(1);
	o<<"["<<d.id<<"] "<<d.duration<<" s, "<<d.percentage<<"% accuracy, ";
	if(d.critical==true)
		o<<"CRITICAL\n";
	else
		o<<"NON-CRITICAL\n";
	return o;
}

int main(){
	DroneTask d[4]={DroneTask(),
					DroneTask("T-AX101",150,88.5,true),
					DroneTask("T-AX202",95.2),
					DroneTask("t-bx300|130|93.3|true")};
	
	for(int i=0;i<4;i++){
		showTaskSummary(d[i]);
		cout<<d[i];
	}
	
	cout<<"\n--- Adding 20 seconds to all tasks ---\n";
	for(int i=0;i<4;i++){
		d[i]=d[i]+20;
		cout<<d[i];
	}
	
	int highest=0;
	cout<<"\n--- Most Accurate Task ---\n";
	for(int i=1;i<4;i++){
		if(d[i]>d[highest])
		highest=i;
	}
	cout<<d[highest]<<endl;
	
	cout<<"--- Conversion Results ---\n";
	for(int i=0;i<4;i++){
		string a=d[i];
		double b=d[i];
		double f=b/100;
		int c=d[i];
		bool e=d[i];
		cout<<"Duration (int): "<<c;
		cout<<fixed<<setprecision(1);
		cout<<"\nAccuracy (double): "<<f;
		cout<<fixed<<setprecision(6);
		cout<<"\nString: "<<a<<" (Accuracy: "<<b<<"%) - "<<c<<"s\n";
		cout<<"Is high-priority (bool): ";
		if(e==true)
			cout<<"Yes\n";
		else
			cout<<"No\n";
		cout<<endl;
	}
	
	cout<<"\n--- Task ID Comparison ---\n";
	if(d[1]==d[3])
		cout<<"Same ID\n";
	else
		cout<<"Different ID\n";
	cout<<endl;
	
	return 0;
}
