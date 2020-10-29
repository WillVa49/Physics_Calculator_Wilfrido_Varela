/*This is a file that will hold the functions and definitions.
 Wilfrido Varela    Dr_T 10-28-2020
 */
#include <iostream>
#include <string>
#include "Input_Validation_Extended.h"
#include <iomanip>
using namespace std;
//all of my prototypes are here
void showMenu();
void chooseCalculation(string); //Function prototype
void chooseMotion(string);
void motionMenu();
void velocity(double ds, double dt,double v);
void acceleration (double dv, double dt, double a);
void force (double m, double a, double N);
void weight (double W, double m, double g);
void momentum (double p, double m, double Ma);

void chooseCalculation (string weChoose)    //Definition
{
   double ds, dv, dt, s, Ma, Ms;
   double Mv, v, a, Mv2, m, N, g, W, p;

  if (weChoose == "A" || weChoose == "a")
  {
   
   cout << "\nLet's calculate velocity." << endl;

   do
     {
       cout << "\nPlease enter a number for ds: " << endl;
       ds = validateDouble(ds);
       if (ds < 0)
        {
          cout << "\nError, cannot have a negative speed, try again." << endl;
        }
      }while (ds < 0);
      
    do
      {
       cout << "\nPlease enter a number for dt: " << endl;
       dt = validateDouble(dt);
       if (dt < 1)
        {
          cout << "\nError, cannot divide with a number less than or equal to 0." << endl;
        }
      }while (dt < 1);
  
  velocity(ds, dt, v); //Calls the velocity void function
  }
  else if (weChoose == "B" || weChoose == "b")
  {
    cout << "\nLets calculate acceleration." << endl;
    do
    {
      cout << "\nPlease enter a number for velocity: " << endl;
      dv = validateDouble(dv);
      if (dv < 0 )
        {
        cout << "\nError, you cannot have a negative measurement, try again. " << endl;
        }
    }while(dv < 0);
    
    do 
    {
      cout << "\nPlease enter a number for time: " << endl;
      dt = validateDouble (dt);
      if (dt < 1)
      {
        cout << "\nError, you cannot divide a meters with a number less than or equal to 0. " << endl;
      }
    }while(dt < 1);
    acceleration(dv, dt, a); //Calls the acceleration void function
  }
  else if (weChoose == "C" || weChoose == "c")
  {
    cout << "\nLets calculate motion. " << endl;
  }
  else if (weChoose == "D" || weChoose == "d")
  {
    cout << "\nLets calculate Newtons 2nd Law." << endl;
    cout << "\nPlease enter a number for mass: " << endl;
    m = validateDouble(m);
    cout << "\nPlease enter a number for acceleration:" << endl;
    a = validateDouble(a);
    force(m, a, N); //Calls the force void function

  }
  else if (weChoose == "F" || weChoose == "f")
  {
    cout << "\nLets calculate weight." << endl;
    cout << "\nPlease enter a number for mass: " << endl;
    m = validateDouble(m);
    cout << "\nPlease enter a number for gravity: " << endl;
    g = validateDouble(g);
    weight (W, m , g);  //Calls the weight void function
  }
  else if (weChoose == "G" || weChoose == "g")
  {
    cout << "\nLets calculate momentum." << endl;
    cout << "\nPlease enter a number for mass: " << endl;
    m = validateDouble(m);
    cout << "\nPlease enter a number for velocity: " << endl;
    Ma = validateDouble(Ma);
    momentum (p, m, Ma);  //Calls the momentum void function
  }
  else if (weChoose == "H" || weChoose == "h")
  {
    system("clear"); //Clears the screen
  }
  else if (weChoose == "E" || weChoose == "e")
  {
    cout << "Program ended, have a good day." << endl;
  }
  else
  {
    cout << "\nInvalid input, please try again." << endl;
  }
}



void showMenu()
{
  cout << "MENU" <<endl;
  cout << "A: Velocity calculation" << endl;
  cout << "B: Acceleration Calculation" << endl;
  cout << "C: Motion Calculation" << endl;
  cout << "D: Newton's 2nd Law Calculation" << endl;
  cout << "F: Weight Calculation" << endl;
  cout << "G: Momentum Calculation" << endl;
  cout << "H: Clear the screen" << endl;
  cout << "E: Exit" << endl;
} 

void motionMenu()
{
  cout << "\nMENU" << endl;
  cout << "A: Solve for v" << endl;
  cout << "B: Solve for s" << endl;
  cout << "C: Solve for v^2" << endl;
  cout << "D: solve for v_bar" << endl;
}


void velocity(double ds, double dt, double v)
{
  string dsUnits = " Unit for speed", dtUnits = "Unit for time";
  v = ds / dt;
  cout << fixed << setprecision(4);
  cout << ds << "/" << dt << " = "<< v << dsUnits << "/" << dtUnits << endl; 
}

void acceleration(double dv, double dt, double a)
{
  string dvUnits = " Unit for velocity", dtUnits = "Unit for time";
  a = dv / dt;
  cout << fixed << setprecision(4);
  cout << dv << "/" << dt << " = " << a << dvUnits << "/" << dtUnits << endl;
}

void chooseMotion(string motionInput) //calculation for motion and also gives the other functions.
{
      double v, a, Ma, Ms, Mv2, Mv, s, t;
     
      if (motionInput == "A" || motionInput == "a")
      {
        cout << "\nLets solve for the final velocity. " << endl;
        //First Equation
        do
        {
          cout << "\nPlease enter a number for the initial velocity: " << endl;
          v = validateDouble(v);
            if (v < 0)
            {
              cout << "Invalid input, try another number. " << endl;
            }
        }while (v < 0);
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
          t = validateDouble(t);
          if (t < 0)
          {
            cout << "Invalid input, try another number. " << endl;
          }
        }while (t < 0);
        Ma = v + a * t;
        cout << fixed << setprecision(4);
        cout << v << "+" << a << "*" << t << "=" << Ma << endl;      
      }
      else if (motionInput == "B" || motionInput == "b")
      {
        cout << "\nLets solve for the final distance." << endl;
        //Second equation
        do
        {
          cout << "\nPlease enter a number for the initial distance: " << endl;
          s = validateDouble(s);
          if (s < 0)
          {
            cout << "Invalid input, try another number. " << endl;
          }
        }while (s < 0);
        do
        {
          cout << "\nPlease enter a number for the initial velocity: " << endl;
          v = validateDouble(v);
          if (v < 0)
          {
            cout << "Invalid input, try another number. " << endl;
          }
        }while (v < 0);
        do
        {
          cout << "\nPlease enter a number for the time: " << endl;
          t = validateDouble(t);
          if (t < 0)
          {
            cout << "Invalid input, try another number. " << endl;
          }
        }while (t < 0);
        do
        {
          cout << "\nPlease enter a number for the acceleration: " << endl;
          a = validateDouble(a);
          if (a < 0)
          {
            cout << "Invalid input, try another number. " << endl;
          }
        }while (a < 0);
        
        Ms = s + v * t + (0.5 * a * (t * t));
        cout << fixed << setprecision(4);
        cout << s << "+" << v << "*" << t << "+" << "(" << 0.5 << "*" << a << "*" << "(" << t << "*" << t << ")" << ")" << "=" << Ms << endl;      
      }
      else if (motionInput == "C" || motionInput == "c")
      {
        cout << "\nLets solve for the final velocity squared." << endl;
        //3rd Equation
        do
        {
          cout << "\nPlease enter a number for the initial velocity: " << endl;
          v = validateDouble(v);
          if (v < 0)
          {
            cout << "Invalid input, try another number. " << endl;
          }
        }while (v < 0);
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
          cout << "\nPlease enter a number for the final distance: " << endl;
          Ms = validateDouble(Ms);
          if (Ms < 0)
          {
            cout << "Invalid input, try another number. " << endl;
          }
        }while (Ms < 0);
        do
        {
          cout << "\nPlease enter a number for the initial distance: " << endl;
          s = validateDouble(s);
          if (s < 0)
          {
            cout << "Invalid input, try another number. " << endl;
          }
        }while (s < 0);

        Mv2 = (v * v) + 2 * a * (Ms - s);
        cout << fixed << setprecision(4);
        cout << "(" << v << "*" << v << ")" << "+" << 2 << "*" << a << "*" << "(" << Ms << "-" << s << ")" << "=" << Mv2 << endl;
      }

        else if (motionInput == "D" || motionInput == "d")
        {
          cout << "\nLets find the average velocity." << endl;
        //4th equation
          do
          {
            cout << "\nPlease enter a number for the final velocity: " << endl;
            Ma = validateDouble(Ma);
            if (Ma < 0)
            {
              cout << "invalid input, try another number. " << endl;
            }
          }while (Ma < 0);
          do
          {
            cout << "\nPlease enter a number for the initial velocity: " << endl;
            v = validateDouble(v);
            if (v < 0)
            {
              cout << "invalid input, try another number. " << endl;
            }
          }while (v < 0);

          Mv = (Ma + v) * 0.5;
          cout << fixed << setprecision(4);
          cout << "(" << Ma << "+"<< v << ")" << "*" << 0.5 << " = " << Mv << endl;
        }
        else
        {
          cout << "Invalid input, try again." << endl;
        }
}

void force (double m, double a, double N) //calculation for force
{
  string mUnits = " Unit for mass", aUnits = "Unit for acceleration";
  N = m * a;
  cout << fixed << setprecision(4);
  cout << N << " = " << m << " * " << a << mUnits << "/" << aUnits << endl;
}
void weight (double W, double m, double g) //calculation for weight
{
  string mUnits = " Unit for mass", gUnits = "Unit for gravity";
  W = m * g;
  cout << fixed << setprecision(4);
  cout << W << " = " << m << " * " << g << mUnits << "/" << gUnits << endl;
}
void momentum (double p, double m, double Ma) //calculation for momentum
{
  string mUnits = " Units for mass", MaUnits = "Units for velocity";
  p = m * Ma;
  cout << fixed << setprecision(4);
  cout << p << " = " << m << " * " << Ma << mUnits << "/" << MaUnits << endl;
}


