/* assignment2 of semester 2
    This program will play the Lotto game. This program allows the user to enter their 6 selected 
    numbers and they have a set of options, each performing a specific requirement. 6 selected
    numbers are stored in a 1-Dimensional array.
    Using functions and pointer notations to access array
    
    a. Read the 6 selected numbers from the keyboard. Perform any necessary 
        validation (error-checking) required (e.g. all numbers must be different, range 
        1-42, etc.). 
    b. Display the contents of the 1-D array containing your lotto numbers that you 
        entered. 
    c. Sort the contents of the array in increasing order (i.e. 1st element = smallest 
        number, 2nd element = 2nd smallest number, etc.). You may use any sorting 
        algorithm of your choice. 
    d. Compare your chosen lotto numbers in the 1-D array with the following 
        winning numbers: 
        1 ,3,5,7,9,11 - 42 (Bonus number) 
    e. Display the frequency of the numbers entered each time the user enters a new 
        set of numbers (without exiting the program) on the screen. For example, it 
        might display: 
        number 1 has been selected x times 
        number 7 has been selected x times 
    f. Exit program 
    Author: Ben Joshua Daan
    Date: March 15 2014
*/

#include <stdio.h>
#define SELECTED 6 //part1, part2 and part3 functions
#define LOTTO 6 // global array for fourth function
#define NUMBER1 1
#define NUMBER2 1
#define NUMBER3 1
#define NUMBER4 1
#define NUMBER5 1
#define NUMBER6 1

//Declare prototypes
void part1(int*); // first function
void part2(int*); // second function
void part3(int*); //third function
void part4(int*); // fourth function 
void part5(int*);

main()
{
    char options;
    int values[SELECTED]; // the array name for user input
    //static int values[SELECTED];
    int opt_b_first=0; //to check if the user picks option b in their first try
    int opt_c_first=0; //to check if the user picks option c in their first try
    int opt_d_first=0; //to check if the user picks option d in their first try
    int opt_e_first=0; //to check if the user picks option e in their first try
    
    do
    {
        //Menu
        printf("\n");
        printf("*******************************************************\n");
        puts("Menu");
        puts("a.) Enter six different numbers to play the Lotto");
        puts("b.) Display the six numbers you have selected");
        puts("c.) To sort the numbers you have entered");
        puts("d.) To compare your six selected numbers with the winning numbers");
        puts("e.) Check how many times you have entered the same number");
        printf("f.) Game stops \n \n");
        
        printf("Please pick one of the options above \n");
        printf("*******************************************************\n");
        printf("\n");
        scanf("%1s", &options);
        
        if(options == 'a')
        {
            part1(values); //values is the array of numbers that the user has inputted
            opt_b_first++;/* Makes sure that the user does not pick option b first
                                                        but it increments this variable after option a has finished
                                                        and so allows option b to be executed 
                                                    */
        }
        
        else if(options == 'b')
        {
            if(opt_b_first >0)
            {
                part2(values);//values is the array of numbers that the user has inputted
                opt_c_first++;/* Makes sure that the user does not pick option c first
                                                                but it increments this variable after option b has finished
                                                                and so allows option c to be executed 
                                                            */
            }
            else //if user does enter option b in their first try
            {
                printf("Error! You must pick the options consecutively \n");
                puts("e.g 'a' then option 'b' then option 'c' then option 'd' etc");
            }
        }
        
        else if(options == 'c')
        {
            if(opt_c_first >0)
            {
                part3(values);
                opt_d_first++;/* Makes sure that the user does not pick option d first
                                                                but it increments this variable after option c has finished
                                                                and so allows option d to be executed 
                                                            */
            }
            else //if user does enter option c in their first try
            {
                printf("Error! You must pick the options consecutively \n");
                puts("e.g 'a' then option 'b' then option 'c' then option 'd' etc");
            }
        }
        
        else if(options == 'd')
        {
            if(opt_d_first >0)
            {
                part4(values);
                opt_e_first++;/* Makes sure that the user does not pick option b first
                                                                but it increments this variable after option a has finished
                                                                and so allows option b to be executed 
                                                            */
            }
            else //if user does enter option d in their first try
            {
                printf("Error! You must pick the options consecutively \n");
                puts("e.g 'a' then option 'b' then option 'c' then option 'd' etc");
            }
        }
        
        /*Implement function 5 here! */
        //else if(options == 'e')
        //{
          //  part5(values);
        //}            
        
        
        else if(options!='a'&&options!='b'&&options!='c'&&options!='d'&&options!= 'e'&&options!='f')
        {
            puts("You can only enter options from a,b,c,d,e or f");
            puts("Please enter appropriate options");
        }
    }while (options != 'f');
    puts("Thank you for playing this Lotto game");
    
    flushall();
    getchar();
}//end main()

/*Implement function part1 */
void part1(int *numbers)
{
    //int number1=0;
    //int number2=0;
    //int number3=0;
    //int number4=0;
    //int number5=0;
    //int number6=0;
    int i;
    
    puts("a.) Enter six different numbers to play the Lotto");
    printf("Please enter six different numbers \n");
    
    for(i=0; i<SELECTED; i++)
    {
        scanf("%d", & *(numbers + i));
        /* the if statement checks if the user inputs numbers outside the range of 1 - 42 */
        if (*(numbers + i) < 1 || *(numbers + i) > 42)
        {
            printf("You must enter numbers within the range of 1-42\n");
            printf("The program will restart \n");
            printf("\n"); //for neatness
            break; /*allows the function to be executed again untill user inputs correct
                                                    numbers 
                                        */
        }
        
    }//end for
}//end function part1

/* Implement function part2 */
void part2(int *display)
{
    int i;
    
    puts("b.) Display the six numbers you have selected");
    for(i=0; i<SELECTED; i++)
    {
        printf("The numbers you have entered are: %d \n", *(display + i));
    }//end for
}//end function 2

/*Implement function part3 */
void part3(int *sort)
{
    int min; //looks for the smallest number in the array and places it in the first element
    int temp; //is used for swapping numbers, just a temporary variable
    int i,j;
    
    //start selection sort
    for(i=0; i<SELECTED-1; i++)
    {
        min=i;
        for(j=i+1; j<SELECTED; j++)
        {
            if(sort[j] < sort[min])
            {
                min = j;
            }
        }//end for
        temp = sort[min];
        sort[min] = sort[min];
        sort[min] = sort[i];
        sort[i] = temp;
    }//end for
    
    printf("The sorted numbers are: \n");
    for(i=0; i<SELECTED; i++)
    {
        printf("%d, ", *(sort + i)); //it aranges the numbers in ascending formation
    }
}//end function 3

/*Implement function 4 */
//values are user input
void part4(int *values)
{
    int match = 0; //a counter to see how many matched numbers did the user got
    int bonus= 42; //bonus number of the winning LOTTO numbers
    int bonus_counter; // a counter to see if the user got the bonus number 42
    int lotto_num1[NUMBER1]= {1};
    int lotto_num2[NUMBER2]= {3};
    int lotto_num3[NUMBER3]= {5};
    int lotto_num4[NUMBER4]= {7};
    int lotto_num5[NUMBER5]= {9};
    int lotto_num6[NUMBER6]= {11};
    int i;
    
    bonus_counter = 0;
    
    puts("d.) To compare your six selected numbers with the winning numbers");
    for(i=0; i<LOTTO; i++)
    {
        if(*(values + i) == bonus)
        {
            puts("You also got the bonus number which is 42!");
            bonus_counter++;
        }
        if(1 == *(values + i))
        {
            puts("hi");
            match++;
            printf("Your number %d and the winning number %d matched\n",*(values +i),lotto_num1[NUMBER1]);
        }
        else if(lotto_num2[NUMBER2] == *(values+i))
        {
            puts("how are");
            match++;
            printf("Your number %d and the winning number %d matched\n",*(values +i),lotto_num2[NUMBER2]);
        }
        else if(lotto_num3[NUMBER3] == *(values+i))
        {
            puts("hey ");
            match++;
            printf("Your number %d and the winning number %d matched\n",*(values +i),lotto_num3[NUMBER3]);
        }
        else if(lotto_num4[NUMBER4] == *(values+i))
        {
            puts("Yo ");
            match++;
            printf("Your number %d and the winning number %d matched\n",*(values +i),lotto_num4[NUMBER4]);
        }
        else if(lotto_num5[NUMBER5] == *(values+i))
        {
            puts("sup ");
            match++;
            printf("Your number %d and the winning number %d matched\n",*(values +i),lotto_num5[NUMBER5]);
        }
        else if(*(values+i) == lotto_num6[NUMBER6])
        {
            puts("waddup ");
            match++;
            printf("Your number %d and the winning number %d matched\n",*(values +i),lotto_num6[NUMBER6]);
        }
        
    }//end for()
    if(match == 6)
    {
        puts("Jackpot!");
    }
    else if(match ==5 && bonus_counter == 1)
    {
        puts("You win a new car!");
    }
    else if(match ==5)
    {
        puts("You win a Holiday in Hawaii!");
    }
    else if(match==4 && bonus_counter == 1)
    {
        puts("You got a weekend away");
    }
    else if(match ==4)
    {
        puts("You win a free Night Out");
    }
    else if(match==3 && bonus_counter == 1)
    {
        puts("You win a Cinema Ticket");
    }
    
    else if(match ==0)
    {
        puts("You didnt get any of the matching numbers");
    }
}
/*void part5(*frequency)
{
    int i;
    static freq_check[SELECTED];
    static int frequen=0;
    
    for(i=0; i<SELECTED; i++)
    {
        if(
*/