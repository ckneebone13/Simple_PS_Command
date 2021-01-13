# Simple_PS_Command

Input Example:
5ps -p 1234 -s -t –c -v

Output Example:
1234: R time=00:03:14 sz=123607 [myprog -x -y file1 myoption]


To Run:
Download to a linux system: file_parser.c, main.h, options_processing.c, 5ps.c, and run5script

Run the following command ONLY once to turn our compile script into and executable.:
chmod +x run5pscript

To complile the program run the following command:
./run5pscript

To run the program, run the following command, replace <commands> with those specified in the assignment instructions.
./5ps <commands>


This programs successfully runs all commands except for -s.
When -s is run a symbol appears instead of the state. Please see demo for details.



