/*
		Author: Caraline Kneebone & Shane Combs
		Assignment Number: 1
		Date of Submission: 10/22/2020
		Name of this file: 5ps.c
		Description of the program: Emulate a simplier version of the ps command.
*/


#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*
	main of 5ps checks flags set in options_processing.c to 
	know which attributes of pid to print
*/
int main(int argc, char *argv[]){
	//instantiate struct to send main arguments and receive options processing command information	
	struct options_struct user_options = get_options(argc, argv);
	char* path_to_proc = (char*)malloc(10);
	//setting path for pid within proc directory
	sprintf(path_to_proc, "/proc/%i", user_options.pid);
	//instantiate struct to send pid file path and receive pid information
	struct information_struct pinformation = info(path_to_proc);
	//free buffers from memory
	free(path_to_proc);
	
	//for any command used, print the pid number first
	if(user_options.s_flag == 1 || user_options.t_flag == 1 || 	user_options.v_flag == 1 || user_options.c_flag == 1){
		printf("%i:\t", pinformation.pid);
	}

	if(user_options.s_flag == 1){//state info requested - always print second
		printf("s: %c\t", pinformation.state);
	}

	if(user_options.t_flag == 1){//time info requested
		printf("time=%s\t", pinformation.time);
	}

	if(user_options.v_flag == 1){//virtual memory info requested
		printf("sz=%ld\t", pinformation.virtual_memory);
	}

	if(user_options.c_flag == 1){//commandline info requested
		printf("[%s]\t", pinformation.cmd);
	}

	printf("\n");
}

