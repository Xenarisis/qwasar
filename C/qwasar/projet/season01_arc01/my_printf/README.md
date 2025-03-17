# Welcome to My Printf
***

## Task
The challenge is to reproduce the function printf with some of the flag of printf ( %d, %o, %u, %x, %c, %s, %p).

## Description
I made a programm that identify the flags and write character per character and that return the size of all the character that has been write .

## Installation
For this project i had to do a Makefile with make, make re, make fclean.... and with his flags: -Wall -Wextra -Werror.

## Usage
my_printf:
I start the project with the function my_printf that has a restrict char* as an argument and ... as an argument for stdarg so a list is created and start just after, 
after that a loop will start, it will read one by one each character given and verify if there a start of flag so a '%', if there no '%' it will write it 
and go to next character if yes there is a '%' it will go to next character and call the function get_flag with the list and the character that we read.
after the loop end it will return the size of what has been write and end the list.

get_flag:
So now we have a the character that will designated the flag and we have the list now we will do a pointer on function with a struct, so a loop will start and it will 
compare the character that we have with what we have in the pointeur on function. so now we know what the flag is and the pointeur on fuction will call it automatically
with the list and after that it will return.

convert:
So for the conversion first we will create a const char* variable who will have all the number we have int the 8, 10 and 16, and we will create an int variable "index" and 
another one "negative" .
So we will verify if the number is negative if yes negative = 1 and the number is now positive, and we will verify if the number = 0 if yes we return 1, and now a loop will 
be create to get the result after we get the restult we will reverse it to get the correct order and we will remade the number negative if negative = 1.
and we will return the index to get the size .

print_d:
First we will add a new argument at the list that will be a int vriable and we will create a buffer, now we will create a int variable that will represent the length 
and call the funtion convert with the argument the base of the argument so 10 and the buffer. 
After that the conversion has been done we will write it directly in the terminal with the buffer and the length of the argument and we will write it.
And we return the length of the the argument to the size.

print_o:
First we will add a new argument at the list that will be a int variable and we will create a buffer, now we will create a int variable that will represent the length 
and call the funtion convert with the argument the base of the argument so 8 and the buffer. 
After that the conversion has been done we will write it directly in the terminal with the buffer and the length of the argument and we will write it.
And we return the length of the the argument to the size.

print_u:
First we will add a new argument at the list that will be a unsigned int variable and we will create a buffer, now we will create a unsigned int variable that will represent the length 
and call the funtion convert with the argument the base of the argument so 10 and the buffer. 
After that the conversion has been done we will write it directly in the terminal with the buffer and the length of the argument and we will write it.
And we return the length of the the argument to the size.

print_x:
First we will add a new argument at the list that will be a unsigned int variable and we will create a buffer, now we will create a unsigned int variable that will represent the length 
and call the funtion convert with the argument the base of the argument so 16 and the buffer.
Now we will verify in the buffer if there character between 'a' and 'z' and made it go in the uppercase.
After that we will write it directly in the terminal with the buffer and the length of the argument and we will write it.
And we return the length of the the argument to the size.

print_c:
First we will add a new argument at the list who are a int variable and we will transform it as a char variable and we will write it and return 1 because it's the size of a chr variable.

print_s:
First we will add a new argument at the list who are a char* variable and create a char* variable to contain it and we will verify if there something in the char* variable,
if there nothing we will write "(null)" and return 6 because it's the size of what we have write o if there something it will write it in the terminal with the char* variable and the length 
of the char* variable.
After that it will return the length of the char* variable.

print_p:
First we will add a new argument at the list that will be a void* variable and we will create a buffer, now we will create a unsigned long variable who will take what there are in the void* variable 
and call the funtion convert with the unsigned long variable the base of the argument so 16 and the buffer with an nit variable who will take the length.
After that wi will write 0x and the buffer and reutrn just after the length with the size of 0x so 2.

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
