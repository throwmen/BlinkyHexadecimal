#include "mbed.h"
#include <iostream>
#include <string>

using namespace std;

// Blinking rate in milliseconds
#define BLINKING_RATE     50ms

UnbufferedSerial pc(USBTX, USBRX, 9600);

int r, g, b;

int main()
{
    // Initialise the digital pin LED1 as an output
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);

    ledR.period(0.01);

    string pwmR;
    string pwmG;
    string pwmB;

    while (true) {

        cout << "Introduzca un número entre 00 y FF" << endl;
        cin >> pwmR;

        cout << "Introduzca un número entre 00 y FF" << endl;
        cin >> pwmG;

        cout << "Introduzca un número entre 00 y FF" << endl;
        cin >> pwmB;

        string hexadecimal = "#" + pwmR + pwmG + pwmB;
        const char *hexChar = hexadecimal.c_str();
        std::sscanf(hexChar, "#%02x%02x%02x", &r, &g, &b);

        ledR.write(1.0f - (float)r / 255.0f);
        ledG.write(1.0f - (float)g / 255.0f);
        ledB.write(1.0f - (float)b / 255.0f);
        
        ThisThread::sleep_for(BLINKING_RATE);
    }
}