# TimeSpan

Goals: Understanding operator overloading
Design and implement `TimeSpan` class which represents a duration in hours, minutes and seconds.

### Displayed Meaning
2:12:07 2 hours, 12 minutes, 7 seconds
-0:10:43 Minus 10 minutes and 43 seconds

The seconds and minutes must be between 0 and 59. The hours can be 0 to any number. 
When `TimeSpan` is printed, the minutes and seconds should always have 2 digits.

The constructor for `TimeSpan` can take 0, 1, 2, or 3 parameters. In addition to integer value, the 
constructor should also be able to handle double values and convert them as accurately as possible

TimeSpan(1.5, -10, 93) same as 1:21:33
TimeSpan(1.5) same as 1:30:00

Implement the following operators to work with `TimeSpan`:
- Displaying: `operator<<`
- Equality: `operator==`, `operator!=`
- Comparison: `operator>`, `operator<`, `operator>=`, `operator<=`
- Addition/Subtraction: `operator+`, `operator-`, `operator+=`, `operator-=`
- Integer Multiplication

Integer multiplication allows us to multiply a TimeSpan with an integer and is not commutative. 
The other operators work on two given TimeSpan values and are commutative
- `TimeSpan ts3(1.5, 30.5, -90);` 
- `TimeSpan ts4;`
- `ts4 = ts3 * 5;`
- `// below line won't compile`
- `// ts4 = 5 * ts3;`

## Compile and Run

```
g++ -std=c++11 -g -Wall -Wextra assignment2.cpp timespan.cpp -o assignment2
./assignment2
```

