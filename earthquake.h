///Md Nayeem Al Noman
///Homework-6
///Programming tools for Eanginners and scientists
///https://github.com/nayeemnoman173/Homework_7


//Libraries
#include <string>


using namespace std;


enum months { January=1, February, March, April, May, June , July, August, September, October, November, December };
enum mag_type { ML=1, Ms, Mb, Mw };


class Earthquake {

	public :
	
	string EQID;
	string DATE;
	string DAY;
	string YEAR;
	string TIME;
	string T_ZONE;
	string EQ_NAME;
	string LAT;
	string LON;
	string DEP;
	string MAG_TYPE;
	string MAG;
	string E_CODE;
	
	bool IsDATE(string Date, string& Day, string& Month_Name, string& Year);
	bool IsTIME (string TIME, string TIME_ZONE);
	bool IsMAG(string& MAG_TYPE, string MAG);
	
	
    private :
	
	mag_type str2mag_enum(string MAG_TYPE);
		
	
};