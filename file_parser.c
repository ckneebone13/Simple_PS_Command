/*
		Author: Caraline Kneebone & Shane Combs
		Assignment Number: 1
		Date of Submission: 10/22/2020
		Name of this file: file_parser.c
		Description of the program: This module will extract strings 
			from the space-separated lists that are read from 
			the stat and statm files.
*/

#include <dirent.h>// required for readdir call
#include <ctype.h>//for isdigit
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int buffsize = 15;

struct stat_parser parse_stat(char* file_path);
struct statm_parser parse_statm(char* file_path);

char* time(unsigned long stime, unsigned long utime);
char* parse_cmd_file(char* file_path);


/*
Function Name: parse_statm()
Input to the method:  pid file path in proc to the statm file
Output(Return value): statm file information
Brief description of the task: parses the statm file of pid and neatly returns all information
*/
struct statm_parser parse_statm(char* file_path){
	struct statm_parser statm_file_info;
	FILE* file = fopen(file_path, "r");
	
	//scan statm file information
	fscanf(file,"%lu %lu %lu %lu %lu %lu %lu", &statm_file_info.size, &statm_file_info.resident, 
	&statm_file_info.shared, &statm_file_info.text, &statm_file_info.lib, &statm_file_info.data, &statm_file_info.dt);
	
	return statm_file_info;
}

/*
Function Name: parse_stat()
Input to the method:  pid file path in proc to the commandline file
Output(Return value): commandline file information
Brief description of the task: parses the commandline file of pid and neatly returns all information
*/
char* parse_cmd_file(char* file_path){
	FILE* file = fopen(file_path, "r");
	
	//allocate command length size
	char* cmd_info = (char*)malloc(buffsize);
	
	//scan cmdline file information
	fscanf(file, "%s", cmd_info);
	
	return cmd_info;
}

/*
Function Name:  time()
Input to the method: time variables from stat file
Output(Return value): time process has been running in  hours:min:seconds format
Brief description of the task: adds stime and utime calculates hours, minutes, and seconds, and returns in desired format
*/
char* time(unsigned long stime, unsigned long utime){
	//allocate time length size
	char* time_format = (char*)malloc(buffsize);
	unsigned long clk_cycle_time = stime + utime;

    //turn clock cycle time into hours, minutes, seconds
	int hr = clk_cycle_time/3600;
    int sec = clk_cycle_time % 3600;
    int min = sec/60;
    sec %= 60;

	//print hours:min:seconds format
	sprintf(time_format, "%.2d:%.2d:%.2d", hr, min, sec);
	return time_format;
}

/*
Function Name: info()
Input to the method: pid file path in proc directory
Output(Return value): pid information from stat and stam files
Brief description of the task: finds all pid information using methods from parser functions
*/
struct information_struct info(char* pid_path){
	struct information_struct pid_info;
	char* path_buff = (char*)malloc(buffsize);
	printf(" ");//"path to proc: %s \n", pid_path)
	sprintf(path_buff, "%s/%s", pid_path, "/stat");
	struct stat_parser stat = parse_stat(path_buff);
	sprintf(path_buff, "%s/%s", pid_path, "/statm");
	struct statm_parser statm = parse_statm(path_buff);
	sprintf(path_buff, "%s/%s", pid_path, "/cmdline");
	char* command_line = parse_cmd_file(path_buff);
	pid_info.pid = stat.pid;
	pid_info.state = stat.state;
	pid_info.time = time(stat.utime, stat.stime);
	pid_info.virtual_memory = statm.size;
	pid_info.cmd = command_line;
	// Free buffers from memory
	free(path_buff);

	return pid_info;
}

/*
Function Name: parse_stat()
Input to the method:  pid file path in proc to the stat file
Output(Return value): stat file information
Brief description of the task: parses the stat file of pid and neatly returns all information
*/
struct stat_parser parse_stat(char* file_path){
	struct stat_parser stat_file_info;
	FILE* file = fopen(file_path,"r");
	
	//scan stat file information
	fscanf(file, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu "
	"%ld %ld %ld %ld %ld %ld %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu "
	"%lu %lu %lu %lu %lu %lu %d %d %u %u %llu %u %ld", 
	&stat_file_info.pid, stat_file_info.comm, &stat_file_info.state, &stat_file_info.ppid, 
	&stat_file_info.pgrp, &stat_file_info.session, &stat_file_info.tty_nr, &stat_file_info.tpgid, 
	&stat_file_info.flags, &stat_file_info.minflt, &stat_file_info.cminflt, &stat_file_info.majflt, 
	&stat_file_info.cmajflt, &stat_file_info.utime, &stat_file_info.stime, &stat_file_info.cutime, 
	&stat_file_info.cstime, &stat_file_info.priority, &stat_file_info.nice, &stat_file_info.num_threads, 
	&stat_file_info.itrealvalue, &stat_file_info.starttime, &stat_file_info.vsize, 
	&stat_file_info.rss, &stat_file_info.rsslim, &stat_file_info.startcode, &stat_file_info.endcode, 
	&stat_file_info.startstack, &stat_file_info.kstkesp, &stat_file_info.kstkeip, 
	&stat_file_info.signal, &stat_file_info.blocked, &stat_file_info.sigignore, &stat_file_info.sigcatch, 
	&stat_file_info.wchan, &stat_file_info.nswap, &stat_file_info.cnswap, &stat_file_info.exit_signal, 
	&stat_file_info.processor, &stat_file_info.rt_priority, &stat_file_info.policy, 
	&stat_file_info.delayacct_blkio_ticks, &stat_file_info.guest_time,&stat_file_info.cguest_time);
	
	return stat_file_info;
}
