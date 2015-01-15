#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF  256

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
unsigned char encode(unsigned char, unsigned char, int);


int main()
{
  char str[8];
  unsigned char input[MAX_BUF], out;
  int choice,i,x, key, hold ,nums[MAX_BUF];

  printf("\nYou may:\n");
  printf("  (1) Encrypt a message \n");
  printf("  (2) Decrypt a message \n");
  printf("\n  what is your selection: ");
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d", &choice);

  switch (choice) {

    case 1:// encrypt
	printf("Please enter a plain text message: \n");        // prompts user for input and calls fget
	fgets(input, sizeof(input), stdin);
	printf("Please enter a numeric KEY: \n");               // prompts user for a key an calls scanf
	scanf("%i", &key);
	if (key <= 0||key>255){                                 // checks to see if the given key is in valid range
	        printf("you must enter a valid number");
	        exit(1);
	}
	for(i = 0; i < strlen(input)-1;i++){                    // loops through each char in input and encrypts it then prints it
	        out = encode(input[i], key, i);
	        printf("%d ",out);
	}
	//printf("-1");                                           // prints a -1 so the user can copy paste the output directly to the decrypt section(testing only)
	
      break;

    case 2:
        printf("Please enter an encrypted message: \n");        // prompts user for the encrypted message
        hold = 0;                                               // intialize hold variable
        for (i = 0; i<sizeof(nums); i++){                       // loops through input using scanf to retreive ints 
                if (hold == -1)
                        break;
                scanf("%d", &hold);
                nums[i]= hold;                                  // stores the int
        }
	printf("Please enter a numeric KEY: \n");               // grabs the key from the user
	scanf("%d", &key);      
	if (key <= 0||key>255){                                 // checks to see if the given key is in valid range
	        printf("you must enter a valid number");
	        exit(1);
	}
        for(i = 0; i < sizeof(nums); i++){                      // loops through the stored ints and decrypts them back to chars and prints them
                if (nums[i] == -1)
                        break;
	        out = encode(nums[i], key, i); 
	        printf("%c",out);
	}
      break; 
        
    default:
		
      break;
  }

  return 0;
}


unsigned char encode(unsigned char pt, unsigned char key, int count)
{
	unsigned char result;                                                           // declaring our return variable
	result = pt;                                                                    // setting it equal to our input paramater 
	int i;
	if ((count%3) == 0){                                                            // if counter mod 3 = 0
		for(i = 0; i< 8; i+=2){			                                // loop through all other bits starting at 0	
			if(((getBit(pt,i))^(getBit(key,i))) == 0)                       // if the input xor the key bit = 0
				result = clearBit(result,i);                            // set it to 0
			else if (((getBit(pt,i))^(getBit(key,i))) == 1)                 // if the input xor the key bit = 1
				result = setBit(result,i);                              // set it to 1						
		}
	}
	else if((count%3) == 1){                                                        // if the counter mod 3 = 1
		for(i = 1; i< 8; i+=2){			                                // loop through all other bits starting at 1	
			if(((getBit(pt,i))^(getBit(key,i))) == 0)                       // if the input xor the key bit = 0
				result = clearBit(result,i);                            // set it to 0
			else if (((getBit(pt,i))^(getBit(key,i))) == 1)                 // if the input xor the key bit = 1
				result = setBit(result,i);	                        // set it to 1					
		}
	}
	else if((count%3) == 2){                                                        // if the counter mod 3 = 2
		for(i = 0; i< 8; i++){						        // loop through all other bits starting at 1	
			if(((getBit(pt,i))^(getBit(key,i))) == 0)                       // if the input xor the key bit = 0
				result = clearBit(result,i);                            // set it to 0
			else if (((getBit(pt,i))^(getBit(key,i))) == 1)                 // if the input xor the key bit = 1
				result = setBit(result,i);		                // set it to 1				
		}
	}
	return result;                                                                  // return our new Encrypted bit
}


/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n)   
{ 
	c = (c&(1<<n))>>n;
	return c;
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)   
{ 	
	c = c|(1<<n);
	return c;
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n) 
{ 
	c = c & (~(1<<n));
	return c;
}



