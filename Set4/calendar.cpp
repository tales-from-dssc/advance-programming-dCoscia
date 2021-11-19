#include <iostream>

enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

const char* getMonthName(enum Month month)              // Function for getting month name
{
   switch (month) 
   {
      case Month::jan: return "January";
      case Month::feb: return "February";
      case Month::mar: return "March";
      case Month::apr: return "April";      
      case Month::may: return "May";
      case Month::jun: return "June";   
      case Month::jul: return "July";
      case Month::aug: return "August";
      case Month::sep: return "September";
      case Month::oct: return "October";      
      case Month::nov: return "November";
      case Month::dec: return "December";    
      break;
   }
}

class Date{
    int _day;
    Month _month;
    int _year;

    public:
    Date(const int day, const Month month, const int year )
    : _day{day},
      _month{month},
      _year{year}{}
      
    ~Date(){};

    int Get_day(){
        return _day;
    }

    int Get_day() const{
        return _day;
    }

    Month Get_month(){
        return _month;
    }

    Month Get_month() const{
        return _month;
    }

    int Get_year(){
        return _year;
    }

    int Get_year() const{
        return _year;
    }

    void new_month() {
		int nm = static_cast<int>(_month);
        nm = nm + 1; // new_month
		if (nm == 13){ _year += 1; nm = 1;}
		_month = Month(nm); 
	}    

    int is_leap() { return _year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0); }

    friend bool operator==(const Date& lhs, const Date& rhs){
        return lhs.Get_day()==rhs.Get_day() && lhs.Get_month()==rhs.Get_month() && lhs.Get_month()==rhs.Get_month();
    }

    friend bool operator!=(const Date& lhs, const Date& rhs){
        return !(lhs == rhs);
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& d){
        os << d.Get_day() << "/" << getMonthName(d.Get_month())<< "/" << d.Get_year() << std::endl;
        return os;
    }

    void add_one_day();

    void add_days(unsigned int n){
        int i;
        for(i = 0; i < n; ++i){
            add_one_day();
        }
    }
};

void Date::add_one_day(){
    bool leap = (_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0));
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(leap) days_in_month[1] = 29;

    if(_day == days_in_month[int(_month)-1]){ 
        _day = 1;
        new_month();
    }
    else{
        _day++;
    }
}


// main() of the program //
int main() {
	Date d(2, Month::sep, 1999);
    Date d1(1, Month::feb, 2000);

    std::cout<<"\n";
    std::cout << "Default date" << std::endl;
	std::cout<< d;

    std::cout<<"\n";
	std::cout << "Adding 20 days" << std::endl;
	d.add_days(20);
	std::cout<< d;

    std::cout<<"\n";
    std::cout << "New default date" << std::endl;
	std::cout<< d1;

    std::cout<<"\n";
    std::cout << "Adding 28 days" << std::endl;
	d1.add_days(28);
	std::cout<< d1;

    std::cout<<"\n";
    std::cout << "Adding 1 day" << std::endl;
	d1.add_days(1);
	std::cout<< d1;

    std::cout<<"\n";
    std::cout << "Adding 365 day" << std::endl;
	d1.add_days(365);
	std::cout<< d1;

    std::cout<<"\n";
    std::cout << "Date1" << std::endl;
	std::cout<< d1;

    std::cout<<"\n";
    std::cout << "Date2" << std::endl;
	std::cout<< d; 

    std::cout<<"\n";
    std::cout << "Checking if Date1 = Date2" << std::endl;
	std::cout<< (d1==d)<< std::endl;    

    std::cout<<"\n";
    std::cout << "Checking if Date1 != Date2" << std::endl;
	std::cout<< (d1!=d) << std::endl;  

    std::cout<<"\n";
    std::cout << "Checking if Date1 year = "<< d1.Get_year() <<" is leap" << std::endl;
	std::cout<< (d1.is_leap()) << std::endl; 

return 0;
}
