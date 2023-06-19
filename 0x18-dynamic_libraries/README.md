# 0x18. C - Dynamic libraries
>project Done in 1 Day

![Betty style](https://img.shields.io/badge/betty-style%20guide-purple?style=round-square)

## Learning Objectives
> needed to be [explaied](https://fs.blog/feynman-learning-technique/) after the project.
* What is a dynamic library, how does it work, how to create one, and how to use it
* What is the environment variable `$LD_LIBRARY_PATH` and how to use it
* What are the differences between static and shared libraries
* Basic usage `nm`, `ldd`, `ldconfig`

## Resources
* [What is difference between Dynamic and Static library (Static and Dynamic linking)](https://www.youtube.com/watch?v=eW5he5uFBNM)
* [create dynamic libraries on Linux](https://medium.com/@The_Mad_Zaafa/creating-and-using-dynamic-libraries-c-a9d344822ed0)
* [Technical Writing](./TECH.md)

## Tasks

+ [x] 0\. A library is not a luxury but one of the necessities of life <br/>_**[libdynamic.so](libdynamic.so)**_ contains the functions with the following prototypes from previous projects in this repository:<br/>
  ```c
  int _putchar(char c);
  int _islower(int c);
  int _isalpha(int c);
  int _abs(int n);
  int _isupper(int c);
  int _isdigit(int c);
  int _strlen(char *s);
  void _puts(char *s);
  char *_strcpy(char *dest, char *src);
  int _atoi(char *s);
  char *_strcat(char *dest, char *src);
  char *_strncat(char *dest, char *src, int n);
  char *_strncpy(char *dest, char *src, int n);
  int _strcmp(char *s1, char *s2);
  char *_memset(char *s, char b, unsigned int n);
  char *_memcpy(char *dest, char *src, unsigned int n);
  char *_strchr(char *s, char c);
  unsigned int _strspn(char *s, char *accept);
  char *_strpbrk(char *s, char *accept);
  char *_strstr(char *haystack, char *needle);
	```
  <br/>__Example__:<br/>
  ```c
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ ls -la lib*
  -rwxrwxr-x 1 julien julien 13632 Jan  7 06:25 libdynamic.so
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ nm -D libdynamic.so 
  0000000000000a90 T _abs
  0000000000000aa9 T _atoi
  0000000000202048 B __bss_start
                   w __cxa_finalize
  0000000000202048 D _edata
  0000000000202050 B _end
  00000000000011f8 T _fini
                   w __gmon_start__
  0000000000000900 T _init
  0000000000000bd7 T _isalpha
  0000000000000c04 T _isdigit
  0000000000000c25 T _islower
  0000000000000c46 T _isupper
                   w _ITM_deregisterTMCloneTable
                   w _ITM_registerTMCloneTable
                   w _Jv_RegisterClasses
  0000000000000c67 T _memcpy
  0000000000000caa T _memset
  0000000000000ce9 T _putchar
  0000000000000d0e T _puts
  0000000000000d4a T _strcat
  0000000000000dcf T _strchr
  0000000000000e21 T _strcmp
  0000000000000e89 T _strcpy
  0000000000000eeb T _strlen
  0000000000000f15 T _strncat
  0000000000000fa5 T _strncpy
  0000000000001029 T _strpbrk
  000000000000109d T _strspn
  0000000000001176 T _strstr
                   U write
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ cat 0-main.c
  #include "main.h"
  #include <stdio.h>

  /**
   * main - check the code
   *
   * Return: Always EXIT_SUCCESS.
   */
  int main(void)
  {
      printf("%d\n", _strlen("My Dyn Lib"));
      return (EXIT_SUCCESS);
  }
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ gcc -Wall -pedantic -Werror -Wextra -L. 0-main.c -ldynamic -o len
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ ldd len 
      linux-vdso.so.1 =>  (0x00007fff5d1d2000)
      libdynamic.so => not found
      libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f74c6bb9000)
      /lib64/ld-linux-x86-64.so.2 (0x0000556be5b82000)
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ ldd len
      linux-vdso.so.1 =>  (0x00007fff41ae9000)
      libdynamic.so => ./libdynamic.so (0x00007fd4bf2d9000)
      libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd4beef6000)
      /lib64/ld-linux-x86-64.so.2 (0x0000557566402000)
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ ./len 
  10
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$
+ [x] 1\. Without libraries what have we? We have no past and no future <br/>_**[1-create_dynamic_lib.sh](1-create_dynamic_lib.sh)**_ creates a dynamic library called `liball.so` from all the `.c` files that are in the current directory.<br/>__Example__:<br/>
  ```c
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ ls *.c
  abs.c   isalpha.c  islower.c  memcpy.c  putchar.c  strcat.c  strcmp.c  strlen.c   strncpy.c  strspn.c
  atoi.c  isdigit.c  isupper.c  memset.c  puts.c     strchr.c  strcpy.c  strncat.c  strpbrk.c  strstr.c
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ ./1-create_dynamic_lib.sh 
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$ nm -D --defined-only liball.so 
  0000000000000a90 T _abs
  0000000000000aa9 T _atoi
  0000000000202048 B __bss_start
  0000000000202048 D _edata
  0000000000202050 B _end
  00000000000011f8 T _fini
  0000000000000900 T _init
  0000000000000bd7 T _isalpha
  0000000000000c04 T _isdigit
  0000000000000c25 T _islower
  0000000000000c46 T _isupper
  0000000000000c67 T _memcpy
  0000000000000caa T _memset
  0000000000000ce9 T _putchar
  0000000000000d0e T _puts
  0000000000000d4a T _strcat
  0000000000000dcf T _strchr
  0000000000000e21 T _strcmp
  0000000000000e89 T _strcpy
  0000000000000eeb T _strlen
  0000000000000f15 T _strncat
  0000000000000fa5 T _strncpy
  0000000000001029 T _strpbrk
  000000000000109d T _strspn
  0000000000001176 T _strstr
  bekalue@BEKALU-PC:~/0x18. Dynamic libraries$
  ```
+ [x] 2\. Let's call C functions from Python <br/>_**[100-operations.so](100-operations.so)**_ contains C functions that can be called from Python.<br/>The functions have the following prototypes:<br/>
  ```c
	int add(int a, int b); /* Addition */
	int sub(int a, int b); /* Subtraction */
	int mul(int a, int b); /* Multiplication */
	int div(int a, int b); /* Division */
	int mod(int a, int b); /* Modulo */
	```
	__Example__:
	```c
	bekalue@BEKALU-PC:~/0x18$ cat 100-tests.py
	import random
	import ctypes
	
	cops = ctypes.CDLL('./100-operations.so')
	a = random.randint(-111, 111)
	b = random.randint(-111, 111)
	print("{} + {} = {}".format(a, b, cops.add(a, b)))
	print("{} - {} = {}".format(a, b, cops.sub(a, b)))
	print("{} x {} = {}".format(a, b, cops.mul(a, b)))
	print("{} / {} = {}".format(a, b, cops.div(a, b)))
	print("{} % {} = {}".format(a, b, cops.mod(a, b)))
	bekalue@BEKALU-PC:~/0x16. Doubly linked lists$ python3 100-tests.py 
	66 + -76 = -10
	66 - -76 = 142
	66 x -76 = -5016
	66 / -76 = 0
	66 % -76 = 66
	bekalue@BEKALU-PC:~/0x18$ python3 100-tests.py 
	-34 + -57 = -91
	-34 - -57 = 23
	-34 x -57 = 1938
	-34 / -57 = 0
	-34 % -57 = -34
	bekalue@BEKALU-PC:~/0x18$ python3 100-tests.py 
	-5 + -72 = -77
	-5 - -72 = 67
	-5 x -72 = 360
	-5 / -72 = 0
	-5 % -72 = -5
	bekalue@BEKALU-PC:~/0x18$ python3 100-tests.py 
	39 + -62 = -23
	39 - -62 = 101
	39 x -62 = -2418
	39 / -62 = 0
	39 % -62 = 39
	bekalue@BEKALU-PC:~/0x18$
+ [x] 3\. Code injection: Win the Giga Millions! <br/>_**[101-make_me_win.sh](101-make_me_win.sh)**_ runs two commands on the same server where the [Giga Millions](https://github.com/holbertonschool/0x18.c) program runs so that the numbers `9, 8, 10, 24, 75 + 9` would win the Jackpot.
   + You can’t modify the program [gm](https://github.com/holbertonschool/0x18.c/blob/master/gm) itself as Master Sysadmin Sylvain (MSS) always checks its `[MD5](https://github.com/holbertonschool/0x18.c/blob/master/101-md5_gm) before running it
   + The system is an `Linux Ubuntu 16.04`
   + The server has internet access
   + the mole will be only able to run two commands from a shell script, without being detected by MSS
   + the shell script should be maximum 3 lines long. You are not allowed to use `;`, `&&`, `||`, `|`, ` (it would be detected by MSS), and have a maximum of two commands
   + The mole has only the authorization to upload one file on the server. It will be your shell script
   + The mole will run your shell script this way: `mss@gm_server$ . ./101-make_me_win.sh`
   + The mole will run your shell script from the same directory containing the program `gm`, exactly 98 seconds before MSS runs `gm` with my numbers: `./gm 9 8 10 24 75 9`
   + MSS will use the same terminal and session than mole
   + Before running the `gm` program, MSS always check the content of the directory
   + MSS always exit after running the program `gm`
   + TL;DR; This is what is going to happen
   ```bash
   mss@gm_server$ . ./101-make_me_win.sh
   mss@gm_server$ rm 101-make_me_win.sh
   mss@gm_server$ ls -la
   . .. gm
   mss@gm_server$ history -c
   mss@gm_server$ clear
   mss@gm_server$ ls -la
   . .. gm
   mss@gm_server$ md5sum gm
   d52e6c18e0723f5b025a75dea19ef365  gm
   mss@gm_server$ ./gm 9 8 10 24 75 9
   --> Please make me win!
   mss@gm_server$ exit
   ```
   Tip: `LD_PRELOAD`
