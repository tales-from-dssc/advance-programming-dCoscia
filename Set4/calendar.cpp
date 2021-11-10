#include <iostream>

enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
class Date{
    int _day;
    Month _month;
    int _year;

    public:
    Date(const int day, const Month month, const int year )
    : _day{day},
      _month{month},
      _year{year}{}

    int Get_day(){
        return _day;
    }

    Month Get_month(){
        return _month;
    }

    int Get_year(){
        return _year;
    }

    void new_month() {
		int nm = static_cast<int>(_month);
        nm = nm + 1; // new_month
		if (nm == 13){ _year += 1; nm = 1;}
		_month = Month(nm); 
	}    

    int is_leap() { return _year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0); }
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

// Function for getting month name //
const char* getMonthName(enum Month month) 
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

// Function for printing the date //
void PrintMyDate(Date d){
    std::cout << d.Get_day() << "/" << getMonthName(d.Get_month())<< "/" << d.Get_year() << std::endl;
}

// main() of the program //
int main() {
	Date d(2, Month::sep, 1999);
    Date d1(1, Month::feb, 2000);

    std::cout<<"\n";
    std::cout << "Default date" << std::endl;
	PrintMyDate(d);

    std::cout<<"\n";
	std::cout << "Adding 20 days" << std::endl;
	d.add_days(20);
	PrintMyDate(d);

    std::cout<<"\n";
    std::cout << "New default date" << std::endl;
	PrintMyDate(d1);

    std::cout<<"\n";
    std::cout << "Adding 28 days" << std::endl;
	d1.add_days(28);
	PrintMyDate(d1);

    std::cout<<"\n";
    std::cout << "Adding 1 day" << std::endl;
	d1.add_days(1);
	PrintMyDate(d1);

    std::cout<<"\n";
    std::cout << "Adding 365 day" << std::endl;
	d1.add_days(365);
	PrintMyDate(d1);

}

