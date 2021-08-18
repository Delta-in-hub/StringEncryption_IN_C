# StringEncryption_IN_C

## encryption-program
## Alex Carlucci 

Purpose: to encrypt or small strings unig a Key value:

How to use: compile encrypt.c using C compiler.
            On linux run the following command: gcc -o encrypt ecrypt.c
            then run: ./encrypt and folow command line instructions.
            
Functionallity: can be used by two machines to send sensitive messages between eachother.
                any intercepted messages would only appear as a string on random 
                integers, but when plugged into the program again with the correct key will produce the original string
                
              

~~~
gcc test1.c StringEncryption.c -o something
./something
1
~~~

2021/08/18
