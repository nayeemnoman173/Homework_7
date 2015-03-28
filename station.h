///Md Nayeem Al Noman
///Homework-7
///Programming tools for Eanginners and scientists
///https://github.com/nayeemnoman173/Homework_7


//** Libraries
#include <string>

using namespace std;


enum nt_code { CE=1, CI, FA, NP, WR };
enum bd_type { LongPeriod=1, ShortPeriod, Broadband };
enum it_type { HighGain=1, LowGain, Accelerometer };

class Entries {
	
    public :
	
	string NCODE;
	string STAN; 
	string BAND;
	string INST;
	string ORTN;
	string b_Initial;
	string i_Initial;
	
	string uppercase (string U);
    bool IsNCODE(string NCODE);
	bool IsSTAN(string STAN);
    bool IsBAND(string BAND, string& b_Initial);
	bool IsINST(string INST, string& i_Initial);
	bool IsORTN(string ORTN);
	
	
    private :
		
	nt_code str2nt_enum(string NCODE);
	bd_type str2bd_enum(string BAND);
	it_type str2it_enum(string INST);
	
};