/*
 * Author: John Bumgardner
 * ECE 209 - Program 1
 * This program functions as a calculator. Users can enter numbers and perform various operations on them. 
 * Grading preference: EOS Linux
 */


#include <stdio.h>
#include <math.h>
int main()
{
	char command = ' '; //no command was received
	double EARLIER = 0.0; //stores the earlier value
	double LATER = 0.0;  //stores the later value
	while(command != 'q') //goes into loop if user wishes to continue looping
	{
		double tmp; //stores inputted value
		int status = scanf("%lf",&tmp); //tells whether a double in inputted
		if(status == 1) //means a double was inputted
		{
			//store input value into later and later into earlier - gets rid of old earlier value
			EARLIER = LATER; 
			LATER = tmp;

		}
		else //a command or a non valid character was inputted
		{

		
			if (EOF==scanf("%c",&command)) 
			{
				// You are at the end of file, set command=’q’ to force the program to quit
				command = 'q';

			}
 			else 
 			{
    			// You got a character
    			if(command == 'p') //print the values
    			{
					//print the values
    				printf("%.3lf\n", EARLIER);
					printf("%.3lf\n", LATER);
    			}
    			else if(command =='a') //add the values
    			{
			        LATER = LATER + EARLIER; //store the sum in later
    				printf("=%.3lf\n", LATER); //print output
    			}
    			else if(command =='s') //subtract the values
    			{
			        LATER = LATER - EARLIER; //store difference in later
    				printf("=%.3lf\n", LATER); //print output
    			}
    			else if(command == 'x') //multiply the values
    			{
    				LATER = LATER * EARLIER;
    				printf("=%.3lf\n", LATER);
    			}
    			else if(command == 'd') //divide the values
    			{
			        if(EARLIER != 0) //makes sure the divisor is not zero before performing arithmetic
    				{
    					LATER = LATER / EARLIER;
    					printf("=%.3lf\n", LATER); //output quotient
    				}
    				else // when the divisor is 0
    				{
				        printf("Divide by zero error.\n"); //print an error message
    				}
    			}
    			else if(command == '^') //exponent
    			{
			        LATER = pow(LATER, EARLIER); //use power function in the math library to take exponent
    				printf("=%.3lf\n", LATER); //output result
    			}
    			else if(command == 'w') //swap the values
    			{
			        tmp = LATER; //use temporary variable to help swap
    				LATER = EARLIER;
    				EARLIER = tmp;
				//no output produced

    			}
    			else if(command == 'c') //clear the values in calculator
    			{
    				EARLIER = 0;
    				LATER = 0;
    			}
    			else if(command == 't') //get rid of the digits past the decimal spot
    			{
			        EARLIER = (int)EARLIER; //cast into an integer but then force back into a double
    				LATER = (int)LATER;
    			}
    			else if(command == 'b') //truncate and display in binary
    			{
			      //set integer variables to pass into functions
			      int iEarly = EARLIER;
			      int iLate = LATER;
			  
			     //print 2's complement binary representation of values stored in EARLIER and LATER

                  //convert earlier and print it

                  int firstSigBit = 0;
                  int index;
                  for(index = 1; index < 32; ++index) //use to move through number of bits 
                  {
                    int tmp = iEarly << index; //shift bits to show next bit
                    if(tmp < 0) //check the new value's sign
                    {
                        printf("1"); //if negative, print 1
                        firstSigBit = 1; //start printing zeroes after
                    }
                    else if(tmp > 0 && !firstSigBit) //if it's negative, but you haven't printed a one yet
                    {
                        printf(""); 
                    }
                    else
                        printf("0");
                  }
                  printf("\n");

                  //convert later to binary and print it

                  firstSigBit = 0;
                  for(index = 1; index < 32; ++index)
                  {
                    tmp = iLate << index;
                    if(tmp < 0)
                    {
                        printf("1");
                        firstSigBit = 1;
                    }
                    else if(tmp > 0 && !firstSigBit)
                    {
                        printf("");
                    }
                    else
                        printf("0");
                  }
                  printf("\n");
    		    }
    			else if(command == 'm') //performs modulo operator
    			{
			  //satisfies part 6 of the program - orignal operation.
    			
			  //truncate the integers
    		       	int iEARLIER = (int)EARLIER;
    	       		int iLATER = (int)LATER;
    				LATER = iEARLIER % iLATER;
    				printf("=%.3lf\n", LATER);
			       
				/*
				 *Test File part6.txt
				 *6
				 *3
				 *m
			         *61
				 *2
				 *m
				 *12
				 *5
				 *m
				 */
				
    			}
    			else if(command == 'h') //displays a brief explanation for 
    			{
    				printf("x = multiplies numbers entered.\n");
    				printf("d = divides numbers entered - catches divide by zero\n");
    				printf("a = adds numbers entered.\n");
    				printf("s = subtracts most recent entered number from first entered number.\n");
    				printf("^ = calcuates the most recent number to the power of the first number.\n");
    				printf("w = swaps the two numbers, replacing the first entered number with the second entered number, and vice versa.\n");
    				printf("c = deletes the entered numbers.\n");
    				printf("t = gets rid of the numbers after the decimal point.\n");
    				printf("b = removes decimal part and converts to binary.\n");
    				printf("p = prints numbers entered.\n");
    				printf("h = prints a brief description of all functions.\n");
    				printf("q = quits the calculator and displays last numbers.\n");
    				printf("m = performs the modulus operator, finding the remainder.\n");
    			
    			}
    			else if(command == 'q')
    			{
                    continue;
			     //exists because if this statement does not exist, the else statement fires - saying the q is not supported
    			}
    			else 
    			{
			          //error message
    				printf("The operator %c is not supported.\n", command);
    			}
			}

		}
	}

	//print the final values on exiting the loop
	printf("%.3lf\n", EARLIER);
	printf("%.3lf\n", LATER);


	return 0;
}
