#include "sumovore.h"
#include "motor_control.h"
//#include "../Robot/Common/TimeDelays.h"
#include "Common/osc.h"

void follow_simple_curves(void);
void no_track(void);
void spin_left(void);
void turn_left(void);
void straight_fwd(void);
void turn_right(void);
void spin_right(void);
void tightTurn(void);


//int last_value;

void motor_control(void)
{

     // very simple motor control
     switch(SeeLine.B)
     {
        case 0b00100u:
        case 0b00010u:
        case 0b01000u:
        case 0b00001u:
        case 0b10000u:
                       //no breaks all above readings end up here
                       follow_simple_curves();
                       break;
        case 0b00000u:
            //tightTurn();
            follow_simple_curves();
                        motors_brake_all();
                       break;
        default:       break;
      } 
}
void tightTurn(void){
    if (SeeLine.b.Center){
        if (SeeLine.b.Left&&!SeeLine.b.CntLeft){            
            straight_fwd();
            if (SeeLine.b.CntLeft){                
                straight_fwd();
                if (SeeLine.B){
                    //no_track();
                    follow_simple_curves();
                } else {
                    spin_left();
                    if(SeeLine.B) follow_simple_curves();
                }
                
            }
            
        }
        if (SeeLine.b.Right&&!SeeLine.b.CntRight){            
            straight_fwd();
            if (SeeLine.b.CntRight){                
                straight_fwd();
                if (SeeLine.B){
                    //no_track();
                    follow_simple_curves();
                } else {
                    spin_right();
                    if(SeeLine.B) follow_simple_curves();
                }
            }
        }     
    }
}

void follow_simple_curves(void)
{
    
     if ( SeeLine.b.Center ) straight_fwd();
     else if (SeeLine.b.Left) spin_left();
     else if (SeeLine.b.CntLeft) turn_left();
     else if (SeeLine.b.CntRight) turn_right();
     else if (SeeLine.b.Right) spin_right();
     else no_track();
    
}
/*
void no_track(void)
{
    for(int i = 0; i <=20; i++)
    {
        straight_fwd();
        _delay(179200ul);
    }
    if ( SeeLine.B) return;
    else 
    {
        for(int i = 0; i <=27; i++)
        {
            spin_right();
            _delay(179200ul);
        }
        for(int i = 0; i <=20; i++)
        {
         straight_fwd();
           _delay(179200ul);
        }
    }
}*/

void spin_left(void)
{
  set_motor_speed(left, rev_fast, 0); 
  set_motor_speed(right, fast, 0); 
}

void turn_left(void)
{
  set_motor_speed(left, stop, 0); 
  set_motor_speed(right, fast, 0); 
}
void straight_fwd(void)
{
  set_motor_speed(left, fast, -35); 
  set_motor_speed(right, fast, 185); 
}
void spin_right(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, rev_fast, 0); 
}
void turn_right(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, stop, 0); 
}
