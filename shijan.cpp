#include<cstdio>
#include<string.h>
#include<cmath>
#include<iostream>
#include<stdlib.h>
using namespace std;
class Date{
	private:
		int day_month_leap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
		int day_month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int _year;
		int _month;
		int _day;
		
	public:
		Date(int year=1980,int month=1,int day=1){
			if(year>=1980&&month>0&&month<13&&day<=getday(year,month)&&day>=0){
				_year=year;
				_month=month;
				_day=day;
			}
			else{
				cout<<"非法日期"<<endl;
				_year=1980;
				_month=1;
				_day=1;
			}
		}	
		
		Date(const Date& d){
			_year= d._year;
			_month=d._month;
			_day=d._day;	
		}
		
		void Display(){
			cout << _year<<"-"<<_month<<"-"<<_day<<endl;
		}
		
		
		~Date(){
			
		}
		bool isleap(int year){
			if(year%4==0&&year%100!=0||year%400==0)
			return true;
			else 
			return false;
		}
		int getday(int year,int month){
			if(isleap(year)){
				int day=day_month_leap[month];
				return day;
			}
			else{
				int day=day_month[month];
				return day;
			}
			
		}
		
		bool Dayisperiod(int year,int month,int day){
			if(year>2005&&year<2008){
				return true;
			}
			else if(year==2005){
				if(month==1&&day>20)
				return true ;
				else if(month>1)
				return true ;
				else 
				return false;
			}
			else if(year==2008){
				if(month==1&&day<20)
				return true ;
				else 
				return false ;
			}
		}
		
		Date operator + (int day){
			Date tmp=*this;
			int zsum=tmp._day+day;
			while(zsum>getday(tmp._year,tmp._month)){
				zsum-=getday(tmp._year,tmp._month);
				tmp._month++;
				if(tmp._month>12){
					tmp._year++;
					tmp._month%=12;
				}
			}
			tmp._day=zsum;
			return tmp;
		}
		
		Date operator +=(int day){
			*this=operator + (day);
			return *this;
		}
		
		Date operator -(int day){
			Date tmp=*this;
			 while(tmp._day<=day){
			 	day-=tmp._day;
			 	if(tmp._month==1){
			 		tmp._year--;
			 		tmp._month=12;
				 }
				 else
				 tmp._month--;
				 tmp._day=getday(tmp._year,tmp._month); 
			 }
			 day-=tmp._day;
			 return tmp;
		}
		
		Date operator -=(int day){
			*this=operator -(day);
			return *this;
		}
		
		Date operator -(Date p){
			this->_day-=p._day;
			this->_month-=p._month;
			this->_year-=p._year;
			return *this;
		}
		
		void outday(Date a,Date b){
			int zsum=0;
			if(dajudge(a,b)){
				while(dajudge(a,b)){
					zsum++;
					a._day++;
				if(a._day>getday(a._year,a._month)){
				a._day-=getday(a._year,a._month);
				a._month++;
				if(a._month>12){
					a._year++;
					a._month%=12;
				}
				}
				}
			}
			else{
				while(dajudge(b,a)){
					zsum++;
					b._day++;
				if(b._day>getday(b._year,b._month)){
				b._day-=getday(b._year,b._month);
				b._month++;
				if(b._month>12){
					b._year++;
					b._month%=12;
				}
			}
				}
			}
			
			cout<<zsum<<endl;
		}
		
		bool dajudge(Date a,Date b){
			if(a._year<b._year)
			return true;
			else if(a._year>b._year)
			return false;
			else {
				if(a._month<b._month)
				return true;
				else if(a._month>b._month)
				return false;
				else {
					if(a._day<b._day)
					return true;
					else if(a._day>b._day)
					return false;
				}
			}
		}
};
int main(){
	Date d(2018,12,31),d1(2019,1,1);
	(d).outday(d,d1);
	d.Display();
}
