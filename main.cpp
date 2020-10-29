//Practice with Functions   Wilfrido Varela, Dr_T   10/28/2020
#include "Functions.h" //Reference to the header file


int main()
{
  string weChoose = ""; //option local to int main()
  string motionInput = ""; //option to choose from the motion menu
  //do-while is used to loop until "E" or "e is pressed by the user. Exits the program."
  do
  {
    showMenu();  //Calls the menu function
    cout << "\nPlease enter one of the letters mentioned above: " << endl;
    weChoose = validateString(weChoose);
    chooseCalculation(weChoose); 
    if (weChoose == "C" || weChoose == "c") //If the user chooses "C" or "c", the motion menu.
    {
      motionMenu();
      cout << "\nWhat option do want to choose: " << endl;  
      motionInput = validateString(motionInput);
      chooseMotion(motionInput);
    }
  }while (weChoose != "E" && weChoose != "e");  //DeMorgan's Law is applied here
}
