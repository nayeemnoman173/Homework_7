///Md Nayeem Al Noman
///Homework-6
///Programming tools for Eanginners and scientists
///https://github.com/nayeemnoman173/Homework_7

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <fstream>
#include <ctype.h>

#include "station.h"
#include "earthquake.h"

using namespace std;


// OPENING INPUT FILE

void open_input(ifstream& input, string inputFileName) {
	
	input.open(inputFileName.c_str());
	
	cout << "Opening file:" << " " << inputFileName.c_str() << endl;
	
    if (input.fail()) {
        cout << "Error reading the file  " << inputFileName << endl;
        exit(EXIT_FAILURE);
    }
}


// PROCESSING HEADER INFORMATION

void processHeader (int EN, string EQID, string DAY, string Month_Name, string YEAR,
				   string TIME, string T_ZONE, string EQ_NAME, string LAT, string LON, 
				   string MAG_TYPE, string MAG, string E_CODE) {
	
    ofstream outputFile;
    string outputFileName = "nayeem.out" ;
    if (EN == 0)
		outputFile.open(outputFileName.c_str()); 
    else
		outputFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
	
	cout << "Header Read Correctly" << endl;
	outputFile << "# " << DAY << " " << Month_Name << " " << YEAR << "  "<< TIME << " " 
	<< T_ZONE << " " << MAG_TYPE << "  " << MAG << " " << EQ_NAME
	<< " [" <<EQID << "] " << " (" << LAT <<" , " << LON << " " << E_CODE << ")" << endl;
}

// PRINTING TO FILE

void PrintToFile(string marray[300], int T_Signal) {
    
    ofstream outputFile;
    string outputFileName = "nayeem.out" ;
    
    outputFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
	
    outputFile << T_Signal;
    outputFile << endl;
	
    for (int i = 0 ; i < 300; i++) { 
        if (marray[i].length() > 1) outputFile << marray[i] << endl;;
	}
}
		

// PRINTING ERROR TO A LOG FILE

void printError(int EN, int V_Entries, int IV_Entries, int T_Signal, 
                bool a, bool b, bool c, bool d, bool e, bool B1, bool B2, bool B3){
	
    ofstream outputErrorFile;
    string outputFileName = "nayeem.log" ;
    if (EN > 0)
		outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
    else
		outputErrorFile.open(outputFileName.c_str()); 
	
    if (B1 == false) {
        outputErrorFile << "Error # Wrong Date Format !" << endl;
        cout << "Error # Wrong Date Format !" << endl;
    }
    else if (B2 == false){
        outputErrorFile << "Error # Either Magnitude_Type or Magnitude Is Wrong !" << endl;
        cout << "Error # Either Magnitude_Type or Magnitude Is Wrong !" << endl;
    }
    else if (B3 == false) {
        outputErrorFile << "Error # Either Time Format or Time Zone Is Wrong !" << endl;
        cout << "Error # Either Time Format or Time Zone Is Wrong !" << endl;
    }
    else if (a == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Network" << endl;
        cout << "Entry # " << EN << " Invalid Network" << endl;
    }
    else if (b == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Station" << endl;
        cout << "Entry # " << EN << " Invalid Station" << endl;
    }
    else if (c == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Band type" << endl;
        cout << "Entry # " << EN << " Invalid Band type" << endl;
    }
    else if (d == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Instrument" << endl;
        cout << "Entry # " << EN << " Invalid Instrument" << endl;
    }
    else if (e == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Orientation" << endl;
        cout << "Entry # " << EN << " Invalid Orientation" << endl;
    }
	
}


int main()
{
	int EN = 0;
    string line;
    string inputFileName;
	
	cout << "WELCOME" << endl;
    cout << "Please Provide Input File Name : "<< endl;
	
    cin >> inputFileName ;
    ifstream input;
    open_input(input, inputFileName);
	
	ofstream outputErrorFile;
    string outputFileName = "nayeem.log" ;
    outputErrorFile.open(outputFileName.c_str());
    cout << "Processing input ...." <<endl;
    outputErrorFile << "Processing input ...." <<endl;
    outputErrorFile.close();
    string marray[300];
    for (int i =0; i< 300; i++) marray[i] = "P" ;
    
    outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
    outputErrorFile << "Please provide the Input File Name : "<< endl;
    outputErrorFile.close();
	
	Entries Signal;
	Earthquake Event;
	getline(input, Event.EQID);
	
	string line_2;
	getline(input, line_2);
	istringstream ass(line_2);
	ass >> Event.DATE >> Event.TIME >> Event.T_ZONE;
	
	string line_3;
	getline(input, line_3);
	Event.EQ_NAME=line_3;
	
	string line_4;
	getline(input, line_4);
	istringstream bss(line_4);
	bss >> Event.LON >> Event.LAT >> Event.DEP >> Event.MAG_TYPE >> Event.MAG;
	
	
	string Month_Name, DAY, YEAR;
    int V_Entries = 0;
    int IV_Entries = 0;
    int T_Signal = 0;
    bool a=true, b=true, c=true, d=true, e=true, B1, B2, B3; 
	
    // CHECKING HEADER 
	
    if (Event.IsDATE(Event.DATE, Event.DAY, Month_Name, Event.YEAR)) B1 = true;
    else B1 = false;
	
    if (Event.IsMAG(Event.MAG_TYPE, Event.MAG)) B2 = true;
    else B2 = false;
	
    if (Event.IsTIME (Event.TIME, Event.T_ZONE)) B3 = true;
    else B3 = false;
	
    if (B1 && B2 && B3) {
		
        outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
        outputErrorFile << "Header Read Correctly "<< endl;
        outputErrorFile.close();
		
        processHeader (EN, Event.EQID, Event.DAY, Month_Name, Event.YEAR, Event.TIME,
					 Event.T_ZONE, Event.EQ_NAME, Event.LAT, Event.LON, 
					 Event.MAG_TYPE, Event.MAG, Event.E_CODE);
		
    }
    else {
		
        outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
        outputErrorFile << "Header Infromation Is Not Correct " << endl;
        outputErrorFile.close();
		
        printError(EN, V_Entries, IV_Entries, T_Signal, a, b, c, d, e, B1, B2, B3);
		
        exit(EXIT_FAILURE);
        
    }
	
    EN = 1;
    while (getline(input, line) && !line.empty()) {
        
        istringstream n (line);
        n >> Signal.NCODE;
        n >> Signal.STAN;
        n >> Signal.BAND;
        n >> Signal.INST;
        n >> Signal.ORTN;
		
        if (Signal.IsNCODE(Signal.NCODE)) {
            Signal.NCODE = Signal.uppercase(Signal.NCODE);
            a = true;
        }
        else a = false;
		
        if (Signal.IsSTAN(Signal.STAN)) {
            Signal.STAN = Signal.uppercase(Signal.STAN);
            b = true;
        }
        else b = false;
		
        if (Signal.IsBAND(Signal.BAND, Signal.b_Initial)) {
            Signal.BAND = Signal.b_Initial;
            c = true;
        }
        else c = false;
		
        if (Signal.IsINST(Signal.INST, Signal.i_Initial)) {
            Signal.INST = Signal.i_Initial;
            d = true;
        }
        else d = false;
		
        if (Signal.IsORTN(Signal.ORTN)) {
            Signal.ORTN = Signal.uppercase(Signal.ORTN);
            e = true;
        }
        else e = false;
        
        if ((a) && (b) && (c) && (d) && (e)) {
			
            string or_1 = Signal.ORTN; 
            for (int unsigned i = 0 ; i < or_1.length(); i++) {
				
                marray[T_Signal] = Event.EQID + "." + Signal.NCODE + "." + Signal.STAN + "." 
				+ Signal.uppercase(Signal.BAND) + Signal.uppercase(Signal.INST) + or_1[i] ;
                T_Signal += 1;
				
            }
			
			V_Entries ++;
        }
        else {
            printError(EN, V_Entries, IV_Entries, T_Signal, 
					   a, b, c, d, e, B1, B2, B3);
            IV_Entries ++;
        }
		
        EN++;
    }
	
	PrintToFile(marray, T_Signal);
	
	outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);

    outputErrorFile << "Total Invalid_Entries Ignored = " << IV_Entries << endl;
	outputErrorFile << "Total Valid_Entries Read = "   << V_Entries  << endl;
    outputErrorFile << "Total_Signals Produced = "    << T_Signal    << endl;
    outputErrorFile << "Finished " << endl;
    outputErrorFile.close();
	
    cout << "Total Invalid_Entries Ignored = " << IV_Entries << endl;
	cout << "Total Valid_Entries Read = "   << V_Entries   << endl;
    cout << "Total_Signals Produced = "    << T_Signal    << endl;
    cout << "Finished" << endl;
}	


