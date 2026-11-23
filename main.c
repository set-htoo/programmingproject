#include <stdio.h>
#include <stdlib.h>

void exit(int status);

int main(){
    // declare choice type from user
    int choice;

    //declare input variables
    int temperature;
    float vibration;
    const int K = (1 % 7) + 1;

    // validate the menu loop
    do {
        // show menu
        printf("Choose an option:\n");
        printf("[1] Start monitoring\n[2] Show latest session\n[3] Show group thresholds\n[4] Exit\nChoice: "); 
        scanf("%d",&choice);

        // add new line for clearer menu loop
        printf("\n");

        // notifies the user of invalid choice
        if(choice<1 || choice>4) printf("Invalid option! Choose from [1] to [4].\n\n");

    } while(choice<1 || choice>4);

    // maybe here i should replace the if with a switch case? or idk
    
    if(choice == 1){
        
        // validation loop for spindle temperature
        do{
            // prompt user for spindle temperature
            printf("Please enter spindle temperature (°C): ");
            scanf("%d", &temperature);
            printf("\n");
            
            // notifies the user of invalid temperature
            if(temperature<0 || temperature>150) printf("Invalid temperature! Enter a temperature from 0 to 150.\n\n");
            
        } while(temperature<0 || temperature>150);

        // validation loop for vibration velocity 
        do {
            // prompt user for vibration velocity
            printf("Please enter vibration velocity (mm/s): ");
            scanf("%f",&vibration);
            printf("\n");
            
            // notifies the user of invalid vibration velocity
            if(vibration < 0.0 || vibration > 50.0) printf("Invalid vibration velocity! Enter a value from 0.0 to 50.0 mm/s\n\n");
            
        } while(vibration < 0.0 || vibration > 50.0);

        
        if(temperature >= (80 + K) || vibration >= (7.1 + 0.1*K) || (temperature >= (60+K) && (vibration >= 4.5))){
            printf("The machine is in a CRITICAL condition");
            // might have to add a counter value for the 3 time ting
        } else if(temperature >= (60+K) || (vibration >= 4.5)) {
            printf("The machine is in a WARNING condition");
            // reduce speed by 20%
            // schedule inspection
        } else {
            printf("The machine is in a NORMAL condition");
            // loop this entire thing including the menu
        }
        
        
    } else if(choice == 2){
        // show statistics
        // display the temperature and vibration velocity
        // display the condition
        // display the counter??? ask robert
        

    } else if(choice == 3){
        // thresholds? maybe i have to show the boundaries like 0-150 and 0.0-50.0
        // mainly stuff like what triggers the critical/warning/normal conditions calculated with K

    } else if(choice == 4){
        printf("Monitoring Program stopped.");
        exit(0);
    }

    return 0;
}
