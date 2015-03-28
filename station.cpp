///Md Nayeem Al Noman
///Homework-6
///Programming tools for Eanginners and scientists
///https://github.com/nayeemnoman173/Homework_7

//Libraries
#include <string>
#include "station.h"


using namespace std;


string Entries::uppercase (string U) {
    string res = U;
    for (int i=0; i < (int)res.size(); i++)
        res[i] = toupper(res[i]);
    return res;
}

nt_code Entries::str2nt_enum(string NCODE) {
	
    if (NCODE == uppercase("CI")) return CI;   
    else if (NCODE == uppercase("CE")) return CE;
    else if (NCODE == uppercase("FA")) return FA;
    else if (NCODE == uppercase("NP")) return NP;
    else if (NCODE == uppercase("WR")) return WR;
	
}


///CHECKING NETWORK CODE:

bool Entries::IsNCODE(string NCODE) {
	
	
    nt_code NCode1 = str2nt_enum(NCODE);
	
    switch (NCode1) {
        case CI :
		{ return true; break;}
        case CE :
		{ return true; break;}
        case FA :
		{ return true; break;}
        case NP : 
		{ return true; break;}
        case WR :
		{ return true; break;}
        default :
			return false;
    }
	
}


///CHECKING STATION NAME:

bool Entries::IsSTAN(string STAN){
	
    bool isStan = false;
    if (STAN.length() == 3 || STAN.length() == 5) {
        if (STAN.length() == 3) {
            for (int i =0; i< 3; i++){
                if (isalpha(STAN[i]) && isupper(STAN[i])) isStan = true;
                else return false;
            }
        }
        else if (STAN.length() == 5) {
            for (int i =0; i< 5; i++){
                if (isdigit(STAN[i])) isStan = true;
                else return false;
            }
        }
    }
    else return false;
    return isStan;
}


bd_type Entries::str2bd_enum(string BAND){
	
    if (BAND == uppercase("Long-Period")) return LongPeriod;   
    else if (BAND == uppercase("Short-Period")) return ShortPeriod;
    else if (BAND == uppercase("Broadband")) return Broadband;
}

// CHECKING BAND NAME

bool Entries::IsBAND(string BAND, string& b_Initial) {
    bool isBand = false;
    bd_type bandName1 = str2bd_enum(uppercase(BAND));
	
    switch (bandName1) {
        case LongPeriod : { isBand = true; b_Initial = "L"; return true; }
        case ShortPeriod : { isBand = true; b_Initial = "B"; return true; }
        case Broadband : { isBand = true ; b_Initial = "H"; return true; }
    }
    return isBand;
}


it_type Entries::str2it_enum(string INST) {
	
    if (INST == uppercase("High-Gain")) return HighGain;   
    else if (INST == uppercase("Low-Gain")) return LowGain;
    else if (INST == uppercase("Accelerometer")) return Accelerometer;
	
}

// CHECKING INSTRUMENT TYPE AND NAME

bool Entries::IsINST(string INST, string& i_Initial) {
	
    bool isInst = false;
    it_type instrumentName1 = str2it_enum(uppercase(INST));
    
    switch (instrumentName1) {
        case HighGain : { isInst = true ; i_Initial= "H"; return true; }
        case LowGain : { isInst = true ; i_Initial= "L"; return true; }
        case Accelerometer : { isInst = true ; i_Initial= "N"; return true; }
    }
    return isInst;
}



// CHECKING ORIENTATION OF SIGNAL

bool Entries::IsORTN(string ORTN){
    
    bool isAlp = false;
    bool isNum = false;
    string ORT = "123ENZ";
	
    for (int unsigned i = 0 ; i < ORTN.length(); i++){
        if      (ORTN[i] == ORT[0]) isNum = true;
        else if (ORTN[i] == ORT[1]) isNum = true;
        else if (ORTN[i] == ORT[2]) isNum = true;
        else if (ORTN[i] == ORT[3]) isAlp = true;
        else if (ORTN[i] == ORT[4]) isAlp = true;
        else if (ORTN[i] == ORT[5]) isAlp = true;
        else return false;
    }
	
    if ((isAlp) && (isNum)) return false;
    else return true;
	
}