///Md Nayeem Al Noman
///Homework-7
///Programming tools for Eanginners and scientists
///https://github.com/nayeemnoman173/Homework_7


//Libraries
#include <string>
#include <sstream>
#include "earthquake.h"
#include "station.h"

using namespace std;


///CHECKING DATE FORMAT:

bool Earthquake::IsDATE(string Date, string& Day, string& Month_Name, string& Year) {
	
	for (int i = 0 ; i< 4; i++) Year += Date[i+6];
	if (!isdigit(Date[3]) && !isdigit(Date[4]))  
		return false;
    
    for (int i = 0 ; i< 2; i++) Day += Date[i+3];
	
	int d ; std::istringstream(Day) >> d;
    if (d<1 || d >31) return false;
	
    string Month ;
    for (int i = 0; i< 2; i++) Month += Date[i];
	
	int n ; std::istringstream(Month) >> n;
		
    if      ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)1))  Month_Name = "January";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)2))  Month_Name = "February";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)3))  Month_Name = "March";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)4))  Month_Name = "April";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)5))  Month_Name = "May";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)6))  Month_Name = "June";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)7))  Month_Name = "July";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)8))  Month_Name = "August";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)9))  Month_Name = "September";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)10)) Month_Name = "October";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)11)) Month_Name = "November";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)12)) Month_Name = "December";
    else return false;
	
    return true;
}

// CHECKING TIME AND TIME ZONE FORMAT:

bool Earthquake::IsTIME (string TIME, string TIME_ZONE){
    
    if (TIME_ZONE.length() != 3) return false;
    
    string hh, mm, ss;
	int h, m, s;
    for (int i = 0; i< 2; i++) {
        hh += TIME[i];
        mm += TIME[i+3];
        ss += TIME[i+6];
    }
	
    if (isdigit(hh[0]) == 0 || isdigit(hh[1]) == 0 ) return false;
    if (isdigit(mm[0]) == 0 || isdigit(mm[1]) == 0 ) return false;
    if (isdigit(ss[0]) == 0 || isdigit(ss[1]) == 0 ) return false;
	
	std::istringstream(hh) >> h;
    if (h < 0 || h > 24) return false;
	
    std::istringstream(mm) >> m;
    if (m < 0 || m > 59) return false;
	
    std::istringstream(ss) >> s;
    if (s < 0 || s > 59.999) return false;
	
    return true;
}


mag_type Earthquake::str2mag_enum(string MAG_TYPE) {
	
    if (MAG_TYPE == "ML") return ML;   
    else if (MAG_TYPE == "MS") return Ms;
    else if (MAG_TYPE == "MB") return Mb;
    else if (MAG_TYPE == "MW") return Mw;
}

/// CHECKING MAGNITUDE TYPE AND VALUE:

bool Earthquake::IsMAG(string& MAG_TYPE, string MAG) {
	
	int n;
	bool isMag;
	istringstream(MAG) >> n;
	if (n < 0) return false;
	
	Entries Signal;
    mag_type magr = str2mag_enum(Signal.uppercase(MAG_TYPE));
    
	
    switch (magr) {
        case ML :
		{ isMag = true; MAG_TYPE = "ML" ; break;}
        case Ms :
		{ isMag = true; MAG_TYPE = "Ms" ; break;}
        case Mb :
		{ isMag = true; MAG_TYPE = "Mb" ; break;}
        case Mw : 
		{ isMag = true; MAG_TYPE = "Mw" ; break;}
        default :
			return false;
    }
	
    return isMag;
}