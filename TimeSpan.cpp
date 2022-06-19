/*
 * Name: Ryan Chua
 * Class: TimeSpan.cpp
 * This TimeSpan class is used to check the amount of time you have based on the inputs that
 * are given. If the user inputs hours and minutes, based on the input, it will give you 
 * a the amount of hours, minutes, and seconds in this form (hours:minutes:seconds), example:
 * 1:02:03. A user is able to compare two TimeSpan objects using '==','!=','<','>','<=','>=' or
 * add and subtract two TimeSpan objects. The User can also multiply an integer with a TimeSpan
 * object.
 */
#include<iostream>
#include<cmath>
#include "TimeSpan.h"

using namespace std;

/**
* TimeSpan Constructor {empty}
* Pre-Conditions: none
* initializes hours,minutes, seconds to 0.
*/
TimeSpan::TimeSpan(){
    hours = 0;
    minutes = 0;
    seconds = 0;
}

/**
* TimeSpan Constructor {1 parameter}
* Pre-Conditions: none
* Given the hours, this constructor converts the hours to the respective time for
* this->hours, this->minutes, and this->seconds.
* @param hours takes in a double hour which manipulates this-> time variables.
*/
TimeSpan::TimeSpan(double hours){
    //Utilizes the trunc operator because we always want hours to be an integer.
    this->hours = trunc(hours);
    /*
    * This formula for variable 'minutes' is a bit confusing so I will explain with an example.
    * Lets say hours = 2.5. Then to isolate the .5, we will subtract the hours (2.5) with the
    * truncated hours (2). Multiply by 60 in order to get the minutes. The reason why I trunc() minutes
    * is to calculate the seconds variable.
    */
    minutes = trunc((hours - this->hours) * 60);
    /*
    * Seconds variable is similiar. To give an example, lets say hours = 1.56. Then again we want to 
    * isolate 0.56 by subtracting hours and trunc(hours) or this->hours. Since we are working with
    * seconds, we instead multiply by 3600 which gives 2016. By subtracting 60 times the 
    * truncated minutes we get seconds. And round() is for when seconds is also a decimal.
    */
    seconds = round((hours-this->hours)*3600-(60*minutes));
}

/**
* TimeSpan Constructor {2 parameters}
* Pre-Conditions: none
* This constructor will take an hours and minutes input. If hours is a rational number, the 
* decimal portion will affect the minutes variable. Similarly if the minutes is larger than
* 60, then hours will increment. If minutes is also a rational, seconds will be affected too.
* @param hours takes in a double hours.
* @param minutes takes in a double minutes.
*/
TimeSpan::TimeSpan(double hours, double minutes){
    //Same logic as the previous, but minutes is also manipulating hours now, so add (minutes/60). 
    this->hours = trunc(hours + (minutes/60));
    /*
    * convert everything to minutes, and subtract untructated hours: (hours*60+minutes) with
    * the truncated hours times 60: (this->hours*60).
    */
    this->minutes = trunc((hours*60+minutes)-(this->hours*60));
    /*
    * Take the untruncated part of minutes: (hours*60+minutes)-(this->hours*60) and subtract
    * with the truncated: this->minutes and multiply the difference by 60 to get seconds.
    */
    seconds = round(((hours*60+minutes)-(this->hours*60)- this->minutes)*60);
}

/**
* TimeSpan Constructor {3 parameters}
* Pre-Conditions: none
* This contructor takes in hours, minutes, and seconds. Just like the 2 parameter constructor, 
* depending on the input, one input might affect another variable.
* @param hours takes in a double hours.
* @param minutes takes in a double minutes.
* @param seconds takes in a double seconds.
*/
TimeSpan::TimeSpan(double hours, double minutes, double seconds){
    /*
     * Similar to this->hours in the 2 parameter constructor, but instead seconds also affects hours.
     * Divide seconds by 3600 to convert to hours and add it to this->hours.
     */
    this->hours = trunc(hours + (minutes/60) + (seconds/3600));
    //Again, convert seconds to minutes by dividing by 60 and add to minutes.
    this->minutes = trunc((hours*60)+minutes+(seconds/60)-(this->hours*60));
    //Subtract untruncated minutes with this->minutes to get the decimal portion out and multiply that by 60.
    this->seconds = round(((hours*60)+minutes+(seconds/60)-(this->hours*60)-this->minutes)*60);
}

/**
* Overloaded '==' operator method
* Compares the two TimeSpan objects to see if the hours, minutes and seconds are the same.
* Pre-Condition: Must be comparing two TimeSpan objects.
* @param time TimeSpan object that gets compared to *this TimeSpan object.
* @return true if they are equal and false if otherwise.
*/
bool TimeSpan::operator==(const TimeSpan& time) const{
    return (hours == time.hours) && (minutes == time.minutes) && (seconds == time.seconds);
}

/**
* Overloaded '!=' operator method
* Compares the two TimeSpan objects to see if the hours, minutes and seconds are not the same.
* Pre-Condition: Must be comparing two TimeSpan objects.
* @param time TimeSpan object that gets compared to *this TimeSpan object.
* @return true if they are not equal and false if otherwise.
*/
bool TimeSpan::operator!=(const TimeSpan& time) const{
    return !((hours == time.hours) && (minutes == time.minutes) && (seconds == time.seconds));
}

/**
* Overloaded '>' operator method
* Compares the two TimeSpan objects to see if *this TimeSpan is larger than time object.
* Pre-Condition: Must be comparing two TimeSpan objects.
* @param time TimeSpan object that gets compared to *this TimeSpan object.
* @return true if *this TimeSpan is larger. False if time object is larger.
*/
bool TimeSpan::operator>(const TimeSpan& time) const{
    return (hours > time.hours) || (hours == time.hours && minutes > time.minutes) || 
           (hours == time.hours && minutes == time.minutes && seconds > time.seconds);
}

/**
* Overloaded '<' operator method
* Compares the two TimeSpan objects to see if *this TimeSpan is smaller than time object.
* Pre-Condition: Must be comparing two TimeSpan objects.
* @param time TimeSpan object that gets compared to *this TimeSpan object.
* @return true if *this TimeSpan is smaller. False if time object is smaller.
*/
bool TimeSpan::operator<(const TimeSpan& time) const{
    return (hours < time.hours) || (hours == time.hours && minutes < time.minutes) || 
           (hours == time.hours && minutes == time.minutes && seconds < time.seconds);
}

/**
* Overloaded '>=' operator method
* Compares the two TimeSpan objects to see if *this TimeSpan is larger than or equal to time object.
* Utilizes the overload '>' and '==' operator to simplify the code.
* Pre-Condition: Must be comparing two TimeSpan objects.
* @param time TimeSpan object that gets compared to *this TimeSpan object.
* @return true if *this is larger than or equal to time. False if time object is larger.
*/
bool TimeSpan::operator>=(const TimeSpan& time) const{
    return (*this > time) || (*this == time);
}

/**
* Overloaded '<=' operator method
* Compares the two TimeSpan objects to see if *this TimeSpan is smaller than or equal to time object.
* Utilizes the overload '<' and '==' operator to simplify the code.
* Pre-Condition: Must be comparing two TimeSpan objects.
* @param time TimeSpan object that gets compared to *this TimeSpan object.
* @return true if *this is smaller than or equal to time. False if time object is smaller.
*/
bool TimeSpan::operator<=(const TimeSpan& time) const{
    return (*this < time) || (*this == time);
}

/**
* Overloaded '+' operator method
* This method adds two TimeSpan objects together and puts the sum in another TimeSpan object.
* Using the new values, another TimeSpan object is made to give the correct/ideal time using the
* new values.
* Pre-Condition: Must be adding two TimeSpan objects.
* @param time TimeSpan object that gets added to *this TimeSpan object.
* @return the ConvertedSum TimeSpan object.
*/
TimeSpan TimeSpan::operator+(const TimeSpan& time) const{
    TimeSpan sum;
    sum.hours = hours + time.hours;
    sum.minutes = minutes + time.minutes;
    sum.seconds = seconds + time.seconds;

    //Use this ConvertedSum TimeSpan object to get the ideal time using the sum.
    TimeSpan ConvertedSum(sum.hours,sum.minutes,sum.seconds);
    return ConvertedSum;
}

/**
* Overloaded '-' operator method
* This method subtracts two TimeSpan objects together and puts the difference in another TimeSpan object.
* Using the new values, another TimeSpan object is made to give the correct/ideal time using the
* new values.
* Pre-Condition: Must be subtracting two TimeSpan objects.
* @param time TimeSpan object that gets subtracted with *this TimeSpan object.
* @return the ConvertedDifference TimeSpan object.
*/
TimeSpan TimeSpan::operator-(const TimeSpan& time) const{
    TimeSpan difference;
    difference.hours = hours - time.hours;
    difference.minutes = minutes - time.minutes;
    difference.seconds = seconds - time.seconds;
    
    //Similar to ConvertedSum, but it is the difference instead.
    TimeSpan ConvertedDifference(difference.hours,difference.minutes,difference.seconds);
    return ConvertedDifference;
}

/**
* Overloaded '+=' operator method
* This method modifies *this TimeSpan by adding time TimeSpan object to itself. This method utilizes
* the overloaded '+' method.
* Pre-Condition: Must be adding two TimeSpan objects.
* @param time TimeSpan object that gets added to *this TimeSpan object.
* @return Since this method allows for modification (due to & and no const), return *this.
*/
TimeSpan& TimeSpan::operator+=(const TimeSpan& time){
    *this = *this + time;
    return *this;
}

/**
* Overloaded '-=' operator method
* This method modifies *this TimeSpan by subtracting time TimeSpan object to itself. This method 
* utilizes the overloaded '-' method.
* Pre-Condition: Must be subtracting two TimeSpan objects.
* @param time TimeSpan object that gets subtracted with *this TimeSpan object.
* @return Since this method allows for modification (due to & and no const), return *this.
*/
TimeSpan& TimeSpan::operator-=(const TimeSpan& time){
    *this = *this - time;
    return *this;
}

/**
* Overloaded '*' operator method
* This method creates mult TimeSpan object to hold to product of both *this and an integer input.
* Pre-Condition: none.
* @param multiply an integer that is multiplied with *this.
* @return The ConvertedMult TimeSpan object.
*/
TimeSpan TimeSpan::operator*(const int multiply) const{
    TimeSpan mult;
    mult.hours = hours * multiply;
    mult.minutes = minutes * multiply;
    mult.seconds = seconds * multiply;

    //Similar to ConvertedSum, but it is the product instead.
    TimeSpan ConvertedMult(mult.hours,mult.minutes,mult.seconds);
    return ConvertedMult;
}

/**
* Overloaded '<<' operator method
* This method modifies the output so that the output looks like a time, i.e 1:02:03 which
* the first number is hour, the second number is minutes and the third number is seconds.
* If minutes and or seconds is a negative, then display the abs(minutes) and abs(seconds), so 
* that the negative doesn't look something like this: 0:-10:-04. We want the negative to be
* displayed once and in front. That is why hours is not in abs().
* Pre-Condition: none.
* @param out overloads cout.
* @param ts TimeSpan object that allows the variables/methods in the class to be called.
* @return sets up hours, minutes, seconds in that order 0:00:00.
*/
ostream& operator<<(ostream& out, const TimeSpan& ts){
    //makes sure if minutes and seconds are single digit, add a 0 in front.
    if((ts.minutes > -10 && ts.minutes < 10) && (ts.seconds > -10 && ts.seconds < 10)){
        out << ts.hours << ":0" << abs(ts.minutes) << ":0" << abs(ts.seconds);
    }
    else if(ts.minutes > -10 && ts.minutes < 10){
        out << ts.hours << ":0" << abs(ts.minutes) << ":" << abs(ts.seconds);
    }
    else if(ts.seconds > -10 && ts.seconds < 10){
        out << ts.hours << ":" << abs(ts.minutes) << ":0" << abs(ts.seconds);
    }
    else{
        out << ts.hours << ":" << abs(ts.minutes) << ":" << abs(ts.seconds);
    }
    return out;
}

double TimeSpan::GetHour() const{
    return hours;
}

double TimeSpan::GetMin() const{
    return minutes;
}

double TimeSpan::GetSec() const{
    return seconds;
}