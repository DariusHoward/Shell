/*
 *El Dario Howard
 * BlazerID: djh1997
 *uab_sh > is a program that has the commands cd, help, list, hello, fibonacci and quit.
 *
 * This program is a shell and runs all the commands above as a shell would. 
 * 
 * 
 * For the program I used the following resources below:
 * https://gitlab.cs.uab.edu/djh1997/CS332-Project2
 *https://github.com/brenns10/lsh/blob/master/src/main.c
 *https://brennan.io/2015/01/16/write-a-shell-in-c/
 *https://github.com/brenns10/lsh/blob/master/src/main.c
 *https://www.tutorialspoint.com/How-can-I-get-the-list-of-files-in-a-directory-using-C-Cplusplus
 *
 */

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

/*
 * shell commands for the uab_sh
 */

int cd(char **args);
int help(char **args);
int quit(char **args);
int hello();
int fibonacci();
int list();



/*
 *strings for the commands
 */

char *commands[] = {
  "cd",
  "help",
  "quit",
  "hello",
  "fibonacci",
  "list",
  
};
int (*usablecommands[]) (char **) = {
  &cd,
  &help,
  &quit,
  &hello,
  &fibonacci,
  &list,
 

};
/*
 *amount of commands
 */
int commandsammount() {
    return sizeof(commands) / sizeof(char *);
}


/**
 *cd function to change directory
 */
int cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "uab_sh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("uab_sh");
        }
    }
    return 1;
}

/**
 *help function shows what commands you can use in the shell
 */
int help(char **args)
{
    int i;

    printf("cd – change current directory to another directory\n");
    printf("help – display commands that can be used in shell.  \n");
    printf("list – lists files in directory.\n");
    printf("hello – executes helloworld program.\n");
    printf("fibonacci – executes the fibonacci program.\n");
    printf("quit – quit the shell program.\n");
    printf("\nHere are the commands:\n");

    for (i = 0; i < commandsammount(); i++) {
        printf(" - %s\n", commands[i]);
    }
    return 1;
}

/**
 *quit allows you to quit the shell
 */
int quit(char **args)
{
    return 0;
}

int list()
{
   char command[50] = "ls -l";
   system(command);
   return 1;
}



int hello(){
   printf( "Hello World! \n");
}

int fibonacci() {
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i) {
        printf("%d,\n ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 1;
}

/**
 * launchs a program and waits for it to terminate
 */
int launch(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // child process
        if (execvp(args[0], args) == -1) {
            perror("uab_sh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // error forking
        perror("fork");
    } else {
        //parent
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

/**
 *executes the program created
 */
int execute(char **args)
{
    int i;

    if (args[0] == NULL) {

        return 1;
    }

    for (i = 0; i < commandsammount(); i++) {
        if (strcmp(args[0], commands[i]) == 0) {
            return (*usablecommands[i])(args);
        }
    }

    return launch(args);
}

#define RLBUFSIZE 1024
/**
  * read in lines of input
  */
char *readline(void)
{
    int bufsize = RLBUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "uab_sh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {

        c = getchar();

        if (c == EOF) {
            exit(EXIT_SUCCESS);
        } else if (c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // reallocate if buffer has been exceeded
        if (position >= bufsize) {
            bufsize += RLBUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "uab_sh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define TOKBUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
/*
 *splits the lines
 */
char **split(char *line)
{
    int bufsize = TOKBUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token, **backup;

    if (!tokens) {
        fprintf(stderr, "uab_sh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += TOKBUFSIZE;
            backup = tokens;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                free(backup);
                fprintf(stderr, "uab_sh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}


void loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("uab_sh > ");
        line = readline();
        args = split(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}


int main(int argc, char **argv)
{

    loop();


    return EXIT_SUCCESS;
}
