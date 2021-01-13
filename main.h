/*
		Author: Caraline Kneebone & Shane Combs
		Assignment Number: 1
		Date of Submission: 10/22/2020
		Name of this file: main.h
		Description of the program: This module contains file sharing struct information 
					for the 5ps program.
*/

//struct groups option flag variables, used in options_processing.c
struct options_struct{
    int p_flag;
	int pid;
    int s_flag;
    int t_flag;
    int v_flag;
    int c_flag;
};

//struct sets information for pids, used in file_parser.c
struct information_struct{
    signed int pid;
    char state;
    char* time;
    long int virtual_memory;
    char* cmd;
};

//make option getter global
struct options_struct get_options(int argc, char **argv);

//make information getter global
struct information_struct info(char* path_to_proc);

//make all field collected from the /proc/[pid]/stat file global
//online resource used: https://man7.org/linux/man-pages/man5/proc.5.html
struct stat_parser{//for collecting state and time info
	signed int pid;// process id
	char* comm;//string filename of executable
	char state;//process state
	signed int ppid;//pid of parent of process
	signed int pgrp;//process group id of process
	signed int session;//session id of process
	signed int tty_nr;//controlling terminal of process
	signed int tpgid;//ID of th eforeground process group of the controlling terminal of the process
	unsigned int flags;//kernal flags word of the process
	unsigned long minflt;//number of minor faults the process has made which have not required loading a memory page from disk
	unsigned long cminflt;//number of minor faults that the process's waited for children have made
	unsigned long majflt;//number of major faults the process has made which have required loading a memory page from disk
	unsigned long cmajflt;//number of major faults the proces's waited for children have made
	unsigned long utime;// amount of time that process has been schduled in user mode, measured in clock ticks
	unsigned long stime;//amount of time that process has been scheduled in kernal mode, measured in clock tickets
	long int cutime;//amount of time that process's waited for children have been scheduled in user mode, measured in clock ticks
	long int cstime;//amount of time that this proces's waited for children have been scheduled in kernal mode, measured in clock ticks
	long int priority;//process running real time priority
	long int nice;//processes nice value
	long int num_threads;//number of threads in this process
	long int itrealvalue;//time in jiffies before the next SIGALRM is sent to the process
	unsigned long long int starttime;//the time the process started after system boot, measured in clock ticks
	unsigned long vsize;//virtual memory size in bytes
	long int rss;//number of pages the process has in real memory
	unsigned long rsslim;//current soft limit in bytes on the rss of the process
	unsigned long startcode;//address above which the program text can run
	unsigned long endcode;//address below which th eprogram text can run
	unsigned long startstack;//address of the start of stack
	unsigned long kstkesp;//current value of stack pointer
	unsigned long kstkeip;//current instruction pointer
	unsigned long signal;//bitmap of peding signals
	unsigned long blocked;//bitmap of blocked signals
	unsigned long sigignore;//bitmap of ignored signals
	unsigned long sigcatch;//bitmap of caught signals
	unsigned long wchan;//channel where the process is waiting
	unsigned long nswap;//number of pages swapped
	unsigned long cnswap;//cumulative nswap for child processes
	signed int exit_signal;//signal to be sent to parent when process dies
	signed int processor;//CPU number last executed on
	unsigned int rt_priority;//real time schedule priority
	unsigned int policy;//scheduling policy
	unsigned long long int delayacct_blkio_ticks;//agregated block I/O delays, measured in clock ticks
	unsigned int guest_time;//guest time of th eprocess, measured in clock ticks
	long int cguest_time;//guest time of the process child, measured in clock ticks
};


//make all fields collected from the /proc[pid]/statm file global 
//online resource used: https://man7.org/linux/man-pages/man5/proc.5.html
struct statm_parser{//for collecting virtual memory info
	long int size;//total program size
	long int resident;//resident set size
	long int shared;//number of resident shared pages
	long int text;//text code
	long int lib;//library
	long int data;//data + stack
	long int dt;//dirty pages
};