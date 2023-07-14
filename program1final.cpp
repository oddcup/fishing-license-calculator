// John Quiruz, Fishing License Pricing Tool, Jul 6 2023, program 1
// This program will help the user calculate how much it will cost them 
// to go fishing as well as other outdoor recreational activities
//****************************************************************************
#include <iostream>
#include <cctype>
using namespace std;

const float YOUTH_COMBO {10.00}; // Cost for youth combination license
const float YOUTH_FISHING {5.00}; // Cost for youth fishing license
const float YOUTH_FISH_KIT {5.00}; // Cost for fishing kit
const float RES_FISHING {44.00}; // Residential fishing license price
const float RES_COMBO {73.00}; // Residential combination license price
const float RES_SHELLFISH {10.00}; // Residential shellfish license price
const float NONRES_FISHING {110.50}; // Non-residential Fishing cost
const float NONRES_SHELLFISH {28.00}; // Non-residential Shellfish cost
const float ONE_DAY_COST {23.00}; // One day pass fishing cost
const float TWO_DAY_COST {42.00}; // Two day pass fishing cost
const float THREE_DAY_COST {59.50}; // Three day pass fishing cost
const int ADDITIONAL_INFO {1}; // Menu choice number one
const int ADD_LICENSE {2}; // Menu choice number two 
const int FINALIZE {3}; // Menu choice number three. Also terminates program

int main() 
{   
    int menu_choice {0}; //The menu choice that the program reads in
    int age {0}; //The age of the license holder
    int is_youth {0}; // This remembers whether the user is youth or not
    int is_resident {1}; //This remembers whether the user is resident or not
    char resident {' '}; //This variable reads in user's residency
    float price_total {0};    //This is the total of the price when licenses 
			      //are calculated
    char license_type {' '}; //License type either annual or day pass expected
    char annual_license_type {' '}; //This holds the choice of fishing, combo,
				    //or shellfish choice for annual pass
    int num_days {0}; //Number of days the day pass is for
    char add_fish_kit {' '};
    char add_combo {' '};
    char add_fishing {' '};
    char add_shellfish {' '}; 
    
    //Displays the welcome message and menu
    cout << "\nWelcome to the Fishing License Calculator!" << endl;
    cout << "\nMAIN MENU";
    cout << "\n1. Additional information (1)";    //Prints a price chart for 
						  //various licenses
    cout << "\n2. Add license (2)";    //Gets information and determines the 
				       //price based on licenses chosen
    cout << "\n3. Finalize or Exit (3)" << endl;    //Echos the total price 
						    //of entered licenses 
						    //and quits

    //Gets the menu choice from the user
    cout << "\nPlease enter numeric menu choice: ";    //Prompts user to 
						       //enter menu choice
    cin >> menu_choice;    //Reads in menu choice from user
    while (menu_choice < 1 || menu_choice > 3)    //If this condition is met, 
						  //the input is invalid
    {
        cout << "Error! Please enter 1, 2, or 3: ";    //Displays error 
						       //message and 
						       //valid inputs
        cin >> menu_choice;    //Read in menu choice from user
    }
    while (menu_choice != FINALIZE)
    {
	//This will show information about license types and license
	//prices if the user chooses menu option one
        if (menu_choice == ADDITIONAL_INFO)
	{
            cout << "\n'Additional Info' is under maintenance."; //This is
						//is an extra feature that
						//is not required but I want
						//to add
	    cout << "\nPlease check back later!" << endl;
	}
	//When the choice is to add license, read in information
	else if (menu_choice == ADD_LICENSE)    //If this condition is met, 
	    		     //start add license process
        {
            cout << "\nYou chose 'Add license'.";    //Confirms they chose to 
						 //add license

            //Ask the user if they are a resident
            cout << "\nAre you a resident? Please enter 'Y' or 'N': "; //Asks 
								      //user 
								      //for 
								 //residency
            cin >> resident;    //Reads in user's input
            while ('Y' != resident && 'N' != resident) //If these conditions 
						      //are met, input 
						      //is invalid
            {
                cout << "Error! Please enter 'Y' or 'N': ";  //Confirms that 
							 //input is invalid
                cin >> resident;    //Read in new input for residency status
            }
            if ('Y' == resident)    //If this condition is met, the 
				//user is a resident
                cout << "\nYou are a resident.";    //Confirms that they are 
						//a resident
            else
	    {
		is_resident = 0;
                cout << "\nYou are not a resident. "; //Confirms that they 
						      //are not a resident
		cout << "Non-resident charge will be applied.";
	    }

            //Ask for the user's age
            cout << "\nPlease enter the age of the license holder: ";
	                                         //Asks 
						 //the user for age integer
            cin >> age;    //Reads in users age integer
            while (age < 1 || age > 120)    //If this condition is met, 
					//invalid input was entered
            {
		//Displays error and correct range
                cout << "Error! Please enter correct age (1 - 120): ";
                cin >> age;    //Read in new age input
            }
	    
	    //Check to see if the age entered is youth
            if (age > 12 && age < 17)
	    {
		is_youth = 1;
                cout << "\nBased on the age ("; //Displays message 
						//confirming the user's age
                cout << age;
                cout << "), a youth license will be applied." << endl;
	    }
	    else
	    {
		cout << "\nThe license holder is ";
		cout << age;
		cout << " years old. " << endl;
	    }

   	    //Ask the user what type of pass they would like
	    cout << "Enter 'A' for Annual or 'D' for Day Passes: "; // Prompts 
					    //the user for type of license
	    cin >> license_type; //Reads in the user's license choice 
            while (!isalpha(license_type))
	    {
	        cout << "Invalid input! "
		     << "Please provide alphabetical character: ";
                cin >> license_type;
             
	    }	    

	    //Check to see if they want a day[s] pass
            if ('D' == license_type)
	    {
		//They chose to add a day pass
	        cout << "\nYou have selected Day Passes." << endl;
		//Adk for the type of day pass
	        cout << "Please enter the number of days (1-3): ";
	        cin >> num_days; //Read in the number of days for day pass
		if (num_days == 1)
		{
	            price_total += ONE_DAY_COST;
                    cout << "\nAdded Single-Day Fishing Pass to the total!";
		    cout << endl;
		    
		}
		else if (num_days == 2)
		{
                    price_total += TWO_DAY_COST;
		    cout << "\nAdded 2-Day Fishing Pass to the total!";
		    cout << endl;
		}
		else 
		{
                    price_total += THREE_DAY_COST;
		    cout << "\nAdded 3-Day Fishing Pass to the total!";
		    cout << endl;
		}
	    }
            else
	    {	
		//They selected to add an annual pass
	        cout << "\nYou have selected an annual pass." << endl;
		//Checks if the user is youth
		if (is_youth == 1)
                {
	            cout << "What type of annual license "
			 << "would you like to purchase?" << endl;
		    //Asks what type of annual license
		    cout << "Enter 'F' for Fishing or 'C' for Combination: ";
		    //Reads in the type of annual license they want
		    cin >> annual_license_type;
		    //Checks to see if the input is not an alpha
		    while (!isalpha(annual_license_type))
		    {
			//Error, they need to enter an alpha
                        cout << "Invalid Input! Please enter 'F' or 'C': ";
			cin >> annual_license_type; //Read in new input
		    }
		    //If they chose to add a combination license, do this
		    if ('C' == annual_license_type)
		    {
			//If they chose combo license, add it to the total
                        price_total += YOUTH_COMBO;
			//Confirms they added an annual combination
			//license for youth
		        cout << "\nYouth Annual Combination License ";
			cout << "just added to price total ";
			cout << "(Shellfish incl'd.)!";
                    }
		    else
		    {
			//Adds the annual fishing license for youth to
			//the total price
		        price_total+= YOUTH_FISHING;
			//Confirms that it was added to the total
	                cout << "\nYouth Fishing License "
		             << "just added to price total!";
		    }
		    //Asks if they want to add a fishing kit
		    cout << "\nDo you want to add a fishing kit for youth";
		    //Asks for decision
		    cout << "\nEnter 'Y' for Yes or 'N' for No: ";
		    cin >> add_fish_kit; //Reads in decision
		    if ('Y' == add_fish_kit) //If the decision is yes do this
		    {
			//Add the fishing kit price to the total
	                price_total += YOUTH_FISH_KIT;
			//Confirms they added the fishing kit to total
			cout << "\nAdded a youth fishing kit "
	                     << "to the total!" << endl;
		    }
		}
		else if (is_resident == 1) //Checks if they are a resident
		{
	            //Asks the type of license
                    cout << "What type of annual license would you ";
		    cout << "like to purchase?" << endl;
		    cout << "Enter 'F' for Fishing, 'C' for Combination, ";
		    cout << "or 'S' for Shellfish: "; 
		    cin >> annual_license_type; //Reads in their decision
		    //Loop this condition if the input is invalid
		    while (!isalpha(annual_license_type))
		    {
                        cout << "Invalid input! "
			     << "Please enter 'F', 'C', or 'S': ";
			//Displays error message if input is incorrect
			cin >> annual_license_type; //Reads in a new input
		    }
		    //Executes this code if they want a fishing license
		    if ('F' == annual_license_type)
		    {
			//Confirms that they want a fishing license
                        cout << "\nYou have selected "
			     << "an annual fishing license.";
			//Asks if they want to add a shellfish license
			cout << "\nWould you like to add "
			     << "a shellfish permit? ";
			//Asks for the decision
			cout << "\nEnter 'Y' for Yes or "
			     << "'N' for No: ";
			//Reads in the decision 
			cin >> add_shellfish;
			//Executes this code if they want to add a 
			//shellfish license
			if ('Y' == add_shellfish)
			{
			    //Add shellfish and fishing license price
			    //to the total
                            price_total = price_total + RES_SHELLFISH 
				          + RES_FISHING;
			    //Confirms that they added licenses to the total
			    cout << "\nAdded annual residential "
				 << "fishing license and ";
			    cout << "shellfish permit to the total!" << endl;
			}
			//Do this if no additional license is wanted
			else
			{
		            //Add only the fishing license to the total
                            price_total += RES_FISHING;
			    //Confirmation that the cost has been
			    //added to the total
			    cout << "\nAdded annual residential "
				 << "fishing license";
			    cout << " to the total!";
			    cout << endl;
			}
		    }
		    //Executes this code if they want a 
		    //combination license
		    if ('C' == annual_license_type)
		    {
			//Confirms that they want a combo license
                        cout << "\nYou have selected an "
			     << "annual combination license.";
			//Asks them if they want to add a shellfish license
			cout << "\nWould you like to add a "
			     << "shellfish permit? ";
			//Asks them to enter Y or N
			cout << "\nEnter 'Y' for Yes or 'N' for No: ";
			//Reads in decision
			cin >> add_shellfish;
			//Execute this if Y
			if ('Y' == add_shellfish)
			{
			    //Adds the cost of a shellfish license
			    //and combo license to the total cost
                            price_total = price_total + RES_SHELLFISH 
				          + RES_COMBO;
			    //Confirms that the licenses were added
			    //to the total
			    cout << "\nAdded annual residential "
				 << "combination license";
			    cout << " and shellfish permit to the total!" 
				 << endl;
			}
			//Execute if they don't want to add an
			//additional license
			else
			{
			    //Adds combo license to the total
                            price_total += RES_COMBO;
			    cout << "\nAdded annual residential combination"
			         << " license to the total!" << endl;
			}
		    }
		    //Executes this if they want a shellfish license
		    if ('S' == annual_license_type)
		    {
			    //Confirms they want a shellfish permit
			    cout << "\nYou have selected an annual shellfish";
			    cout << " license.";
			    //Asks if they want to add a fishing license
			    cout << "\nWould you like to add a "
				 << "fishing license?";
			    //Prompts them to say yes or no
			    cout << "\nEnter 'Y' for Yes or 'N' for NO: ";
			    cin >> add_fishing;
			    //If they want to add a fishing license
			    //execute the following code
			    if ('Y' == add_fishing)
			    {
                                price_total = price_total + RES_FISHING 
					      + RES_SHELLFISH;
				//Adds the licenses to the total cost
				cout << "\nAdded annual residential "
				     << "shellfish ";
				cout << "license and fishing license "
				     << "to the total!" << endl;
			    }
			    //Execute if they want to add combo license
			    else
			    {
				//Asks if they want to add a combo 
                                cout << "\nWould you like to add a "
				     << "combination license?";
				//Reads in Y or N
				cout << "\nEnter 'Y' for Yes or 'N' for No: ";
				cin >> add_combo; //Reads in their decision
				//Execute if they want to add combo permit
				if ('Y' == add_combo)
				{
				    //Add licenses to the total
                                    price_total = price_total + RES_SHELLFISH 
					          + RES_COMBO;
				    //Confirms that the costs have been added
				    //to the total cost
				    cout << "\nAdded annual "
					 << "residential shellfish ";
				    cout << "license and combination "
					 << "license to ";
				    cout << "total!" << endl;
				}
				//Execute if they don't want to add any 
				//additional licenses
				else
				{
			            //Adds cost of shellfish license to
				    //the total
                                    price_total += RES_SHELLFISH;
				    //Confirms
				    cout << "\nAdded annual "
					 << "residential shellfish ";
				    cout << "license to the total!" << endl;
				}
			    }
		    }
		}
		//Execute this if the user is not a resident
		else if (0 == is_resident)
		{
                    cout << "What type of annual license would you ";
		    //Asks user the type of annual license they want to add
		    cout << "like to purchase?" << endl;
		    cout << "Enter 'F' for Fishing or 'S' for Shellfish ";
		    //Informs them their options
		    cout << "(combination prohibited): ";
		    cin >> annual_license_type; //Reads in their decision
		    //If they want a fishing license execute this code
		    if ('F' == annual_license_type)
		    {
                        cout << "\nYou have selected an "
			     << "annual fishing license.";
			cout << "\nWould you like to add a "
			     << "shellfish permit?";
			cout << "\nEnter 'Y' for Yes or 'N' for No: ";
			//Reads in their decision to add a
			//shellfish permit
			cin >> add_shellfish;
			//If they want to add a shellfish license
			//do this
			if ('Y' == add_shellfish)
			{
			    //Adds licenses to the total
                            price_total = price_total + NONRES_FISHING 
				          + NONRES_SHELLFISH;
			    //Confirms that the costs have been added
			    cout << "\nAdded annual non-residential "
				 << "fishing license ";
			    cout << " and shellfish permit "
				 << "to the total!" << endl;
			}
			//Execute this if they don't want a shellfish
			//license added
			else
			{
                            price_total += NONRES_FISHING;
			    cout << "\nAdded annual non-residential "
				 << "fishing license ";
			    cout << "to the total!" << endl;
			}
		    }
		    //Execute this if they want a shellfish license
		    if ('S' == annual_license_type)
		    {
                        cout << "\nYou have selected an "
			     << "annual shellfish license.";
			cout << "\nWould you like to add a "
		             << "fishing license?";
			cout << "\nEnter 'Y' for Yes or 'N' for No: ";
			//Reads in if they want to add an additional
			//fishing license
			cin >> add_fishing;
			//If yes, add cost of both licenses to total
			if (add_fishing == 'Y')
			{
			    //Add licenses to the total
                            price_total = price_total + NONRES_FISHING 
				          + NONRES_SHELLFISH;
			    cout << "\nAdded annual non-residential "
				 << "shellfish license ";
			    cout << "and fishing license "
				 << "to the total!" << endl;
			}
			//Execute if they don't want to add an
			//additional license
			else
			{
			    //Adds the shellfish license cost 
			    //to the total cost
                            price_total += NONRES_SHELLFISH;
			    cout << "\nAdded annual non-residential "
				 << "shellfish license ";
			    cout << "to the total!" << endl;
			}
		    }
		}

	    }
	    //Resets youth status upon running through the program
            is_youth = 0;
	    //Resets the residential status upon running through program
	    is_resident = 1; //Assumes user is a resident initially
        }
	//Displays Main Menu
        cout << "\nMAIN MENU";
	//Prints a price and license type chart
        cout << "\n1. Additional information (1)";
	//Gets information and determines price based on
	//license type chosen
        cout << "\n2. Add license (2)";
	//Displays the total price and terminates program
        cout << "\n3. Finalize or Exit (3)" << endl;

        //Gets the menu choice from the user
        cout << "\nPlease enter numeric menu choice: ";
        cin >> menu_choice;
	//Validates menu choice input
        while (menu_choice < 1 || menu_choice > 3)
        {
	    //Displays error message
            cout << "Error! Please enter 1, 2, or 3: ";
	    //Read in menu choice
            cin >> menu_choice;
        }
    } //When the user chooses the 'finalize' option, the loop breaks
    //Displays the total price of licenses accumulated
    cout << "\nYour total is: $";
    cout << price_total;
    cout << "\nThank you for using the "
	 << "Fishing License Calculator.\n\n";
    //Goodbye message

return 0;
}
