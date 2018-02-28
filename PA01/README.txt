Programming Assignment #1

Please read this entire document before proceeding with this assignment. If you have any questions, check to make sure they are not answered in this document first. Do not be surprised if you are asked if you read the document already before receiving help. It is common for students to not thoroughly read the documentation.

In this assignment, you will need to compile, run and test code that completes various tasks involving array iteration in C. Please read this document in full to understand how to do PA01.


#####Breakdown of Files Included#####
1. answer01.c: this file has the 5 functions that you will need to complete for this homework. You have been given the "skeleton" for each function and must fill in the parts necessary for each one to do its job.
2. answer01.h: this is a "header" file and it contains an explanation of each function you will need to complete for this assignment
3. pa01.c: it's important to test code that you write to make sure it works. Therefore this file is included to help you get started with testing your code. Feel free to modify the code in this file as you wish to make sure your code is working as it should.
4. README: this file.

#####Description of Task#####
As mentioned before, the tasks you need to complete for each function are thoroughly described in answer01.h. It's best to start out by reading through that file. Once you understand the tasks required, write your code for each function in answer01.c. To test this code, modify, compile and run pa01.c based on the functions you would like to test.

#####Iterating Over Arrays In C#####
In computer science, to iterate means to access every element of a "collection" once. The most basic "collection" is an array as it is of fixed size and elements are stored sequentially. An easy way to iterate over an array is to use a for loop with an "index" variable that accesses each array element:

int index;
for(index=0; index < arrayLength; index++){
	//perform action with array[index];
}

#####Assignment Submission#####
To submit your assignment, upload your completed answer01.c to Blackboard in the specified section. 

If you are using ACCESS to complete this assignment, you will need to download your code from ACCESS and combine each function file into one answer01.c file (do not submit each function's C file from ACCESS). Be sure to double check that your code works when it is combined into one file this way.

#####Grading#####
Each function is weighted equally in your grade for this assignment, therefore each function is worth 20% of the assignment grade. If a function does not work properly, you will not earn any credit for that function. In this sense, each function is pass or fail. Overall, make sure your program has no compilation warnings or else you will fail the entire assignment.

You can write your assignments on any computer using whichever tools you'd like, but you should make sure they work on lab computers as they will be graded on them.

#####A Note on ACCESS#####
We are allowing everyone to use ACCESS for this assignment so they can get familiar with it. In the future ACCESS may not be open to some or all of the students. As an incentive to try it out for the first time, we will be giving you 0.5% extra credit toward your final grade for using it on this assignment. 

Even though ACCESS compiles, runs and tests the code for you, make sure you understand how to compile and run your code outside of ACCESS. ACCESS will not be used for all assignments, it is simply to help students ease into using various tools useful for software development. 


#####Compiling Your Program#####

The remainder of this document is to help you complete the tasks for the assignment. Firstly, you must compile, run and test your program.

In this course we use the gcc compiler. You can compile your program by typing the following into the terminal (make sure you are in your PA01 directory):

 > gcc -Wall -Wshadow -g pa01.c answer01.c -o pa01
 
 Gcc can take many different arguments, but the ones above are the ones we will use most often in this course. The arguments mean:
 1. -Wall, turn on all *common* compilation warnings. You will fail the assignment if your solution has 1 or more compilation warnings.
 2. -Wshadow, in addition to common warnings, warn if a variable declaration "shadows" the declaration of another variable. Variable shadowing may occur if you declare a variable once in a function (or file, if it is a global variable) and declare another variable with the same name again.
 3. -g, turn on debugging symbols. This produces a larger executable program; however, you can use this program in a debugger. Learning how to use gdb will be very useful in this course.
 4. pa01.c answer01.c. These are the files that you are compiling and linking into a computer program. You only ever compile ".c" files. You never compile ".h" files. Each ".c" file is compiled separately (gcc does this internally), and multiple ".c" files are linked together into a single computer program. Compiling and linking are two different steps, but here we are doing both steps with a single instruction. The "int main(...)" function must appear in precisely one of those ".c" files (in this case pa01.c). In order to get full credit for this assignment, it cannot appear in answer01.c.
 5. -o pa01, create an "output file" (or object file) pa01. By default gcc will produce a file called "a.out", and we are just telling gcc to name that file "pa01" instead.
 
 #####Running your Program#####
 Once your program is compiled, you can run it by simply typing into the terminal:

 > ./pa01
 
 Note that this should print:

   Welcome to ECE264, we are working on PA01.

As it is printed by a printf statement in pa01.c. You are encouraged to modify pa01.c in order to test the behavior of each function you are writing in answer01.c

The file (technically: compilation unit) pa01.c "knows" about the functions in answer01.c, because it "includes" the declarations for those functions, which are written in the file "answer01.h". Declarations and are not compiled into code, but instead, they merely describe the existence of some compilable function in some compilation unit somewhere. In this case, the functions declared in answer01.h are defined in the compilation unit "answer01.c".

In future assignments you may only be provided with "answerXY.h" header file with declarations. In such a case you will need to write your answerXY.c file from scratch and write your own test-cases and main function separately.


#####Testing Your Program#####
It is your responsibility to test your program and ensure that it works. Testing programs is an important skill in computer programming, and when you develop your own programs you will have to make sure your programs have no errors. It is not okay to simply accept that your program has bugs or pretend your code is perfect without even trying to test it. You should deal with your program's issues head-on.

For this assignment we have not included any tests outside of the ones provided on ACCESS and already provided in pa01.c. Passing these tests does not mean it is perfect, but that it does pass a few test we put it through. You can modify pa01.c if you want to write extra tests.

The most important thing to understand is to test your code as you go. To generate testing code, you will need to think about the functions are you are developing and figure out how you can show that the functions work ALL of the time. You may need to test all of the code yourself in future assignments.
 

#####Summary#####
-To compile your code:
> gcc -Wall -Wshadow -g pa01.c answer01.c -o pa01

- Run (you will need to write your own tests to be certain of accuracy)
 > ./pa01
 
 - Upload answer01.c to Blackboard


