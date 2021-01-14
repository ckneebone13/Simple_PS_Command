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



Commands:
-p <pid>
Display process information only for the process whose number is pid. If this option is
not present then use the pid number a 1 (init process). The user is expected to provide pid
number when using –p option. If the user runs “5ps -p” with no value please give an
error message and exit the program.
  
-s
Display the single-character state information about the process. This information is
found in the stat file in process's directory, looking at the third ("state") field. Note that
the information that you read from the stat file is a character string. 

-t
Display the amount of time consumed by this process in hours:min:seconds format. This
information is found in the stat file in process's directory, looking at the "utime" field.
Add to this to the system time, “stime” field . This is the total time consumed by the
process. This time is represented in clock ticks. You must divide my number of clock
ticks per second (system constant) to obtain the number of seconds. It should then be
displayed in hours:min:seconds format. 
-v
Display the amount of virtual memory currently being used (in pages) by this program.
This information is found in the statm file in process's directory, looking at first ("size")
field. 
-c
Display the command-line that started this program. This information is found in the
cmdline file in process's directory. Be careful on this one, because this file contains a list
of null (zero byte) terminated strings. 


