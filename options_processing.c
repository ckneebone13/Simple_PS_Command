/*
		Author: Caraline Kneebone & Shane Combs
		Assignment Number: 1
		Date of Submission: 10/22/2020
		Name of this file: options_processing.c
		Description of the program: This module processes the command line options, 
            setting state variables to record what the options specify.
*/

#include <stdio.h>
#include <unistd.h>// required for getopt call
#include <stdlib.h>
#include "main.h"

/*
	Function Name: get_options
	Input to the method: read args from command line
	Output(Return value): return user options
	Brief description of the task: determins user commands entered in command line
*/

struct options_struct get_options(int argc, char **argv) {
    struct options_struct options;
    struct options_struct* pOptions = &options;

    pOptions->pid;
    pOptions->p_flag = 0;
    pOptions->s_flag = 0;
    pOptions->t_flag = 0;
    pOptions->c_flag = 0;
    pOptions->v_flag = 0;

    int option;
    char * pid;

    while((option = getopt(argc, argv, "p:stvc")) != -1) {//include all commands here: p, s, t, v, c
        switch (option) {
            case 'p':
                pOptions->p_flag = 1;
                pOptions->pid = atoi(optarg);
                continue;
            case 's':
                pOptions->s_flag = 1;
                continue;
            case 't':
                pOptions->t_flag = 1;
                continue;
            case 'v':
                pOptions->v_flag = 1;
                continue;
            case 'c':
                pOptions->c_flag = 1;
                continue;
        }
    }
    return options;
}


