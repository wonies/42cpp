#ifndef __HARL_H
#define __HARL_H

#include <iostream>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Harl()
    {
        funcs[0] = &Harl::debug;
        funcs[1] = &Harl::info;
        funcs[2] = &Harl::warning;
        funcs[3] = &Harl::error;
    }
    void (Harl::*funcs[4])( void );
    void complain( std::string level );
};

#endif