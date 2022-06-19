/*
 * Name: Ryan Chua
 * Class: assignment2.cpp
 * This is a tester class to test the methods in the TimeSpan Class.
 */
#include <iostream> 
#include <sstream> 
#include <cassert>
#include "TimeSpan.h"

using namespace std;

// testing constructor

void test1() {
    TimeSpan ts(1, 20, 30); 
    stringstream ss;
    ss << ts;
    assert(ss.str() == "1:20:30");
    TimeSpan ts2(4, -20, -90);
    ss.str(""); 
    ss << ts2;
    assert(ss.str() == "3:38:30");
    TimeSpan ts3(1.5, 30.5, -90);
    ss.str(""); 
    ss << ts3;
    assert(ss.str() == "1:59:00");
    TimeSpan ts4(0, 0.07, 0); 
    ss.str("");
    ss << ts4;
    assert(ss.str() == "0:00:04");
}


// testing equality, addition, subtraction, multiplication
void test2() {
    TimeSpan ts(1, 20, 30);
    TimeSpan ts2(1, 20, 30);
    TimeSpan ts3(0, 0, 0); 
    //cout << ts + ts + ts << endl;
    assert(ts == ts2); 
    assert(!(ts != ts2)); 
    assert(ts != ts3);
    assert((ts + ts + ts) == (ts2 * 3)); 
    
    assert((ts * 5) == (ts2 * 4) + ts2); 
    assert((ts * 5) == (ts2 * 6) - ts2); 
    assert((ts + ts - ts) == ((ts2 * 2) - ts)); 
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);
}


void test3(){
    //cout << TimeSpan() << endl;
    TimeSpan ts0 = TimeSpan();
    cout << ts0 << endl;
    TimeSpan ts1 = TimeSpan(1.5);
    cout << ts1 << endl;
    TimeSpan ts2 = TimeSpan(3.3,43);
    cout << ts2 << endl;
    TimeSpan ts3 = TimeSpan(1.2,-8,19);
    cout << ts3 << endl;
    
    //ts4 is to test equality and inequality
    TimeSpan ts4(-1,134,9);
    bool TestEqual = (ts3==ts4);
    if(TestEqual == 1){
        cout << "TestEqual: They are equal" << endl; 
    }
    else{
        cout << "TestEqual: They are NOT equal" << endl; 
    }

    bool TestInEqual = (ts3 != ts4);
    if(TestInEqual == 1){
        cout << "TestInEqual is true" << endl; 
    }
    else{
        cout << "TestInEqual is false" << endl; 
    }

    bool TestGreater = (ts3 > ts4);
    if(TestGreater == 1){
        cout << "ts3 is larger" << endl; 
    }
    else{
        cout << "ts4 is larger" << endl; 
    } 

    bool TestLess = (ts3 < ts4);
    if(TestLess == 1){
        cout << "ts3 is smaller" << endl; 
    }
    else{
        cout << "ts4 is smaller" << endl; 
    } 

    bool TestGreaterEqual = (ts3 >= ts4);
    if(TestGreaterEqual == 1){
        cout << "ts3 is greater or equal" << endl; 
    }
    else{
        cout << "ts4 is greater" << endl; 
    }  
}
void test4(){
    TimeSpan ts1(-0.54);
    cout << ts1 << endl;
    cout << "Hour: " << ts1.GetHour() << "\nMin: " << ts1.GetMin() << "\nSec: " << ts1.GetSec() << endl;
    
    TimeSpan ts2(-1.5,60.5);
    cout << ts2 << endl;
    cout << "Hour: " << ts2.GetHour() << "\nMin: " << ts2.GetMin() << "\nSec: " << ts2.GetSec() << endl;
    
    TimeSpan ts3(-1.5,10,-93);
    cout << ts3 << endl;
    cout << "Hour: " << ts3.GetHour() << "\nMin: " << ts3.GetMin() << "\nSec: " << ts3.GetSec() << endl;

    //Test adding, subtract, and multiply
    cout << "Adding(+): "<< ts1 + ts2 << endl;
    cout << "Subtracting(-): "<< ts1 - ts2 << endl;
    //cout << "Adding(+=): "<< (ts1 += ts2) << endl;
    cout << "Subtracting(-=): "<< (ts1 -= ts2) << endl;
}
void testAll() { 
    test1();
    test2();
    //test3();
    //test4();
}

int main() { 
    testAll();
    cout << "Done." << endl;
    return 0;
}