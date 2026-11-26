#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h> // just to fix the degree symbol and to put a flashy wait sequence


void exit(int status);

int main(){

    // because the degrees celcius symbol is pissing me off, not ai generated
    SetConsoleOutputCP(CP_UTF8);


    // declare choice type from user

    // choice is what the user will choose in the menu, crit_count is the counter that increments when critical condition is reached.
    int choice, crit_count, status, session_count;
    // status stores the status number of the machine. 1 for critical, 2 for warning, 3 for normal. this is used in displaying the statistics of the machine

    // declare input variables
    float temperature, vibration;
    const int K = (1 % 7) + 1;

    // add an overall loop that encases all -- including the start menu. I don't think the vibration velocity and stuff will be volatile?
    do{
        // validate the menu loop 
        do {
            // show menu
            printf("Choose an option:\n\n");
            printf("[1] Start monitoring\n[2] Show latest session\n[3] Show group thresholds\n[4] Exit\n\nChoice: "); 
            scanf("%d",&choice);

            // add new line for clearer menu loop
            printf("\n");

            // notifies the user of invalid choice
            if(choice<1 || choice>4) printf("Invalid option! Choose from [1] to [4].\n\n");

        } while(choice<1 || choice>4);

        

        if(choice == 1){
        
            // validation loop for spindle temperature
            do{
                // prompt user for spindle temperature
                printf("Please enter spindle temperature (\u00B0C): ");
                scanf("%f", &temperature);
                printf("\n");
            
                // notifies the user of invalid temperature
                if(temperature < 0.0 || temperature > 150.0) printf("Invalid temperature! Enter a temperature from 0 to 150.\n\n");
            
            } while(temperature < 0.0 || temperature > 150.0);
                // this leaves us with the temperature value


            // validation loop for vibration velocity 
            do {
                // prompt user for vibration velocity
                printf("Please enter vibration velocity (mm/s): ");
                scanf("%f",&vibration);
                printf("\n");
            
                // notifies the user of invalid vibration velocity
                if(vibration < 0.0 || vibration > 50.0) printf("Invalid vibration velocity! Enter a value from 0.0 to 50.0 mm/s\n\n");
            
            } while(vibration < 0.0 || vibration > 50.0);
                // this leaves us with the vibration velocity value

            // selection for the state of the machine
            if(temperature >= (80 + K) || vibration >= (7.1 + 0.1*K) || (temperature >= (60+K) && (vibration >= 4.5))){
                printf("The machine is in a CRITICAL condition.\n\n");
                status = 1; // 1 is to show "CRITICAL" when prompted to with choice = 2
                // might have to add a counter value for the 3 time ting

            } else if(temperature >= (60+K) || (vibration >= 4.5)) {
                printf("The machine is in a WARNING condition.\n\n");
                status = 2; // 2 is to show "WARNING" when prompted to with choice = 2
                //unnecessary waiting thing
                printf("Please wait while necessary action is taken.\n");
                Sleep(2000);

                // should i do this? -- reduce speed by 20%
                printf("The vibration velocity has been reduced by 20%.\n");
                vibration = vibration*0.8;
                printf("The vibration speed is now %.2f.\n", vibration);

                // schedule inspection--maybe open a calendar where the user can select date and time to schedule inspection
                printf("idk bro\n\n");
            

            } else {
                printf("The machine is in a NORMAL condition.\n\n");
                status = 3;
            }
        
        
        } else if(choice == 2){

            // show statistics >> the temperature and vibration velocity
            printf("The current sensor readings and status of the machine are:\n");
            printf("Spindle temperature: %.2f\n",temperature);
            printf("Vibration velocity %.2f\n", vibration);
        
            // select condition of machine 
            switch(status){
                case 1:
                    printf("The machine is in the CRITICAL condition.\n\n");
                    break;
                
                case 2: 
                    printf("The machine is in the WARNING condition.\n\n");
                    break;
                
                case 3: 
                    printf("The machine is the NORMAL condition.\n\n");
                    break;

                default:
                    printf("There are no recent sessions. Please start monitoring to record your first session.\n\n");
            }

            printf("Total monitoring sessions: \n\n", session_count); 

            // display the counter of how many monitoring sessions??? ask robert!! (maybe it's ambiguous?)

        } else if(choice == 3){
            // thresholds? maybe i have to show the boundaries like 0-150 and 0.0-50.0
            // mainly stuff like what triggers the critical/warning/normal conditions calculated with K

        } else if(choice == 4){
            printf("Monitoring Program stopped.\n\n");
            exit(0);
        }
    } while(1); //yo dont forget about this bro; wait maybe we can use this to infinite loop until user types 4?


    return 0;
}
