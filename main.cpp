#include <iostream>
#include <string>
#include "Input_Validation_Extended.h"
using namespace std;

void showMenu();
void chooseCalculation(string);
void velocity(double ds, double dt,double v);
void acceleration (double v, double t, double a);
void motion (double Ma, double v, double a, double dt,double Ms, double s, double Mv2, double Mv);


void chooseCalculation (string weChoose)
{
  string dsUnits = "km", dtUnits = "hr";
   double ds, dv, dt;
   double v = ds/dt, a = dv/dt, Ma = v+a*dt;
  if (weChoose == "A" || weChoose == "a")
  {
   
   cout << "\nLet's calculate velocity." << endl;

   do
     {
       cout << "\nPlease enter a number for kilometers: " << endl;
       ds = validateDouble(ds);
       if (ds < 0)
        {
          cout << "\nError, cannot have a negative speed, try again." << endl;
        }
      }while (ds < 0);
      
    do
      {
       cout << "\nPlease enter a number for hours: " << endl;
       dt = validateDouble(dt);
       if (dt < 1)
        {
          cout << "\nError, cannot divide km with a number less than or equal to 0." << endl;
        }
      }while (dt < 1);
  
  velocity(ds, dt, v);
  }
  else if (weChoose == "B" || weChoose == "b")
  {
    cout << "\nLets calculate acceleration." << endl;
    do
    {
      cout << "\nPlease enter a number for meters: " << endl;
      dv = validateDouble(dv);
      if (dv < 0 )
        {
        cout << "\nError, you cannot have a negative measurement, try again. " << endl;
        }
    }while(dv < 0);
    
    do 
    {
      cout << "\nPlease enter a number for seconds: " << endl;
      dt = validateDouble (dt);
      if (dt < 1)
      {
        cout << "\nError, you cannot divide a meters with a number less than or equal to 0. " << endl;
      }
    }while(dt < 1);
    acceleration(dv, dt, a);
  }
  else if (weChoose == "C" || weChoose == "c")
  {
    cout << "\nLets calculate motion. " << endl;
    //First Equation
    do
    {
      cout << "\nPlease enter a number for the initial velocity: " << endl;
      Ma = validateDouble(Ma);
      if (Ma < 0)
      {
        cout << "Invalid input, try another number. " << endl;
      }
    }while (Ma < 0);
    do
    {
      cout << "\nPlease enter a number for the acceleration: " << endl;
      a = validateDouble(a);
      if (a < 0)
      {
        cout << "Invalid input, try another number. " << endl;
      }
    }while (a < 0);
    do 
    {
      cout << "\nPlease enter a number for the time: " << endl;
      dt = validateDouble(dt);
      if (dt < 0)
      {
        cout << "Invalid input, try another number: " << endl;
      }
    }while (dt < 0);
    //Second equation
    motion(Ma, v, a, dt, Ms, s, Mv, Mv2);
      }
    }











int main()
{
  string weChoose = "";
  showMenu();  
  cout << "\nPlease enter one of the letters mentioned above: " << endl;
  weChoose = validateString(weChoose);
  chooseCalculation(weChoose);
}






void showMenu()
{
  cout << "\nMENU" <<endl;
  cout << "A: Velocity calculation" << endl;
  cout << "B: Acceleration Calculation" << endl;
  cout << "C: Motion Calculation" << endl;
  cout << "D: Newton's 2nd Law Calculation" << endl;
  cout << "F: Weight Calculation" << endl;
  cout << "G: Momentum Calculation" << endl;
}

void velocity(double ds, double dt, double v)
{
  string dsUnits = "km", dtUnits = "hr";
  v = ds / dt;
  cout << v << dsUnits << "/" << dtUnits << endl; 
}

void acceleration(double dv, double dt, double a)
{
  string dvUnits = "m", dtUnits = "sec";
  a = dv / dt;
  cout << a << dvUnits << "/" << dtUnits << endl;
}

void motion (double Ma, double v, double a, double dt, double Ms, double s, double t)
{
  //1st equation
  Ma = v + a * dt;
  cout << Ma << endl;
  //2nd equation
  Ms = s + v*dt + (0.5 * a*(dt*dt));
  cout << Ms << endl;
}
