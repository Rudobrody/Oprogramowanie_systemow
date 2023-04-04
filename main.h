
#ifndef main_CL
#define main_CL


#include "setup.h"
#include "stdlib.h"
#include "R_P_LCD_TMSLAB.h"
#include "R_P_KEYBOARD_TMSLAB.h"
#include "R_P_LEDBAR_TMSLAB.h"
#include "square.h"

#ifdef TMSLAB_C2000
#include "F2837xD_device.h"
#include "systemInit.h"
#endif


void SetUpPeripherials();
void EnableInterrupts();
void InitData();
void ClearScreen();
void DrawPixels(int Key);
void klawiatura(unsigned char klawisz);
void wybierz_pozycje(int ktora_pozycja);
void czy_potwierdzil(unsigned klawisz);
void przeksztalc_na_wspolrzedne(int dziesiatki_x, int jednosci_x, int dziesiatki_y, int jednosci_y);

class UAR
{
    float m_out;
    float m_in;
    
public:
    void setInput(float input){m_in=input;}
    void calculate(){m_out=m_in;}
    float getOutput(){return m_out;}
}


class PI:public UAR
{
float m_Tp, m_Kp, m_Ki; 
float m_sum, m_Smin, m_Smax;

public:
PI(float Kp, float Ti,float Tp, float Smin, float Smax);
}


PI::PI(float Kp, float Ti, float Tp, float Smin, float Smax)
{
m_Tp=Tp;
m_Kp=Kp;
m_Ki=Kp*Tp/Ti;
m_in=0;
m_out=0;
m_sum=0;
m_Smin=Smin;
m_Smax=Smax;
}

PI::calculate()
{
m_sum+=m_in*m_Ki;
if(m_sum>m_Smax)m_sum=m_Smax;
if(m)
}
#endif
