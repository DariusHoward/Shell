Shell Program(uab_sh)
 
Project Description 

You will write a simple shell in C called uab_sh. . 
The requirements are as follows:
1) Your shell executable file should be named uab_sh and your shell source code should be mainly in shell.c (you are free to add additional source code files, make sure that your Makefile works/compiles and generates an executable named uab_sh in the same top level directory as the Makefile) [30 points] 
2) The shell should run continuously, and display a prompt when waiting for input. When the shell is invoked by executing the executable uab_sh, it should provide a prompt uab_sh > and waits for any input from the keyboard. [10 points] 
3) The uab_sh shell should read a line from stdin one at a time. This line should be parsed out into a command and all its arguments. In other words, tokenize it. You may assume that the only supported delimiter is the whitespace character. [10 points] 
4) After parsing and lexing the command, your shell should execute it. The shell should create a new process corresponding to the input entered using fork/exec. Additionally, you can assume that the newline character denotes the end of the input. If a newline character is entered without any other text or followed by white space, the shell should just display the prompt on the next line. The new process created should be able to read keyboard input and display output to the terminal. You can assume that these programs are executed only in the foreground, i.e., the shell program will wait for the child process to complete and when the child process completes successfully it will display the command prompt. [10 points]
 5) A command can either be a reference to an executable OR a built-in shell command. Executing commands that are not shell built-ins is done by invoking fork() and then invoking exec(). You may NOT use the system() function, as it just invokes the /bin/sh shell to do all the work. 
CS 433/533 Operating Systems Homework-1 Here is a sample interaction with the shell (assuming hello and fibonacci are in one of the directories defined by the PATH environment variable): 
uab_sh > hello Hello World! 
uab_sh > fibonacci 10 
The first 10 values: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 
uab_sh > fibonacci 
How many elements you want to display: 7 
The first 7 value: 0, 1, 1, 2, 3, 5, 8 
*** Hello World and Fibonacci sequence calculator must be implemented *** [20 points] 
6) Implement the following buit-in commands: [20 points] 
a)	list – list all the files in the current directory. The default directory is the directory where the shell program was invoked 
b)	cd – change the current directory to the . The default directory would be the directory where the shell program was invoked 
c)	help – display the internal commands and a short description on how to use them d. quit – quit the shell program




El Dario Howard 
Acknowledgments

Getting Started

Prerequisites

Have a computer or system that can run C code. 

Make sure you have all of the files in the gitlab project in one folder.

Instructions
Open command prompt or a terminal go to the directory where you have the folder with all the files.

Type the keystrokes below: 
make 
After that type the keystrokes below:  
make exec
Once that is done your screen should be the same as what is typed below:
uab_sh > 

Running the test 

echo "#\!/bin/sh" > hello.sh
echo $NAME


Screenshots/Sample Session 
Located in gitlab project folder

djh1997@uab.edu

