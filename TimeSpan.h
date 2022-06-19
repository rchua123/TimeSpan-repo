/*
 * Name: Ryan Chua
 * Class: TimeSpan.h
 * TimeSpan header which includes four TimeSpan construtors where to input can be none, (hours),
 * (hours, minutes), or (hours, minutes, seconds). Much of the methods are overloaded operators
 * which will be modified for the uses of TimeSpan objects. Only three variables exist for this
 * class which is double hours, minutes, and seconds.
 */
#ifndef TIMESPAN_H
#define TIMESPAN_H

using namespace std;

class TimeSpan{
    
    public:
        //Constructors
        TimeSpan();
        TimeSpan(double hours);
        TimeSpan(double hours, double minutes);
        TimeSpan(double hours, double minutes, double seconds);

        //Overload Operator Methods
        bool operator==(const TimeSpan& time) const;
        bool operator!=(const TimeSpan& time) const;
        bool operator>(const TimeSpan& time) const;
        bool operator<(const TimeSpan& time) const;
        bool operator>=(const TimeSpan& time) const;
        bool operator<=(const TimeSpan& time) const;
        TimeSpan operator+(const TimeSpan& time) const;
        TimeSpan operator-(const TimeSpan& time) const;
        TimeSpan& operator+=(const TimeSpan& time);
        TimeSpan& operator-=(const TimeSpan& time);
        TimeSpan operator*(const int multiply) const;
        friend ostream& operator<<(ostream& out, const TimeSpan& ts);

        //Getters
        double GetHour() const;
        double GetMin() const;
        double GetSec() const;

    private:
        //Variables
        double hours;
        double minutes;
        double seconds;
    
};
#endif