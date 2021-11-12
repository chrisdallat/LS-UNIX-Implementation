<!-- GETTING STARTED -->
## LS (UNIX) Implementation
### Task Description

For each operand that names a file of a type other than directory, my_ls displays its name as well as any requested, associated information. For each operand that names a file of type directory, my_ls displays the names of files contained within that directory, as well as any requested, associated information.

If no operands are given, the contents of the current directory are displayed. If more than one operand is given, non-directory operands are displayed first; directory and non-directory operands are sorted separately and in lexicographical order.

The following options are available:

*  -a: Include directory entries whose names begin with a dot (.).
*  -t: Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
*  /directory name: to show contents of a directory, can include multiple directories in command. 
### Program Usage

NOTE: FOR UNIX SYSTEMS!!
NOTE: FOR LINUX UNCOMMENT COMMENTED-OUT CODE IN C FILES!!

1. From the terminal move to "my_ls" directory and type "make" to compile the program.

   ```sh
   make
   ```
2. You can then run the program with "./my_ls" with any combination of 
    * -a: include to show all files including "." and ".."
    * -t: include to order files by time modified last. i.e -ta/-at/-a -t/-t -a
    * /directory name: to list contents of a directory
   ```sh
   ./my_ls -at
   ```
   ```sh
   ./my_ls /src
   ```
3. The program will then print the relevant files/directories as "ls" terminal command does.

4. You can clean up '.o' files by typing the following command after usage
    ```sh
   'make clean'
   ```




