# Compilation with GCC and GNU Make

## Objectives

* Implement a build system using GNU's Make and GCC compiler toolsets
* Examine the pre-processor's role in compilation
* Integrate new libraries to a build system

## Introduction to build systems using GNU toolsets 

* The main objective is to translate high level languages into ARM assembly language and subsequent machine code  (binary encoded assembly instructions)
* The toolchain to build and install process are
  * preprocessing
  * assembling
  * compiling
  * linking
  * locating
  * installing
* Installation will require other tools
* The build process
  * source files are taken by the **preprocessor** and transform into new files by evaluating preprocessor directives and perform macro substitution
  * these modified files are then fed into the **compiler proper**, this performs a C programming to assembly code translation
  * next, the **assembler** converts our assembly code into object code, object code looks like confusing binary data and it's not really human readable
  * now, object files need to be combined into a single executable where all references between object files need to be resolved, we call these references symbols, this job is performed by the **linker**
  * finally, the linker provides the linked file to a **relocator** where which will map all the addresses of code and data into the processor's memory space, the final file should be the target executable
* In general, we can think of compilation as converting source files into object code
* Once you compile a project, the executable only work on the architecture you compiled at for
* Native compilation is when you compile your build for the same system you intend to run the executable on
* Cross compilation is when you compile an executable on one system and it is intended to run on another
* GCC contains many tools (compiler, assembler, linker, etc)
  * it is a GNU's compiler collection
  * GNU Make is a tool that controls the generation of executables and other non-source files of a program from the program's source files
  * GNU Make help us manage this whole process of building our executable

## Compiling and Invoking GCC

* Remember, building a software project requires five steps
  * preprocessing
    *  source files are sending through a preprocessor
  * compiling
    * these preprocessed files go through a C to assembly translation by the compiler proper
  * assembling
    * the assembler then converts this output to object code
  * linking
    * the linker combines all objects into a single executable
  * locating
    * the locator assigns addresses
* building and compiling are used interchangeably
* by definition, compilation is the process of converting high level software language to architecture specif binary encoded operations
* GNU's compiler collection (GCC) toolchain strucure
  * gcc, preprocessor and compiler
  * as, assembler
  * ld, linker and locator
* Native compiler
  * gcc-4.8, for code run on the host machine (to simulate and test it's operation)
* Cross compiler
  * arm-none-eabi-gcc, for code run on the target processor (to investigate the architecture specifics of the assembly code)
  * ls -la /usr/bin/arm-none-eabi* will show all tools in the cros-compiler toolchain
* gcc --version, will show which version of gcc is in use
* which gcc, will tell where gcc is installed
* man gcc, will show the manual for running gcc
* extensions are
  * .s for assembly files
  * .o for object files
  * .a for library files
  * extension varies for executable files
* building files with gcc can be done only using the compiler and assembler, but by passing the necessary commands you can also pass control down to the linker file without having to invoke the linker directly
* gcc commands to building are called as such
  * gcc [OPTIONS] [FILE]
    * important options are
      * -c, compile and assemble file, do not link
      * -o <FILE\>, compile, assemble, and link to OUTPUT_FILE
      * -g, generate debugging information in executable
      * -Wall, enable all warning messages
      * -Werror, treat all warning as errors
      * -I <DIR\>, include this <DIR\> to look for header files
      * -ansi or -std=STANDARD, specify which standard version to use
      * -v, verbose output from GCC
* arm commands to building are called as such
  * arm-none-eabi-gcc [FILE] [OPTIONS]
    * important options are
      * -mcpu = [NAME], specifies target ARM Processor and Architecture (ex: cortex-m0plus)
      * -march = [NAME], target ARM Architecture (ex: armv7-m, thumb)
      * -mtune = [NAME], target ARM Processor (ex: cortex-m0plus)
      * -mthumb, generate code in Thumb States (ISA)
      * -marm, generate code in ARM State (ISA)
      * -mthumb-interwork, generate code that supports calling between ARM and Thumb (ISA)
      * mlittle-endian, generate code for little endian mode
      * -mbig-endian, generate code for big endian mode
    * using the following command will stop GCC at compilation proper stage with the -S option
      * arm-none-eabi-gcc -std=C99 -mcpu=cortex-m0plus -mthumb -Wall -S main.c -o main.s -g
        * the -g flag will help debug executables, exclude if you do not want all information
      * cat main.s

## Preprocessor Directives

* Special keywords used by the preprocessor before compilation
* Directives start with '#' sign
* Important Directives
  * #define, #undef
    * used for defining constants, string definitions, preprocessor functions, features or macro functions
    * #define <MACRO-NAME\> <MACRO-VALUE\>  
    * #define <FEATURE-NAME\>  
  * #ifndef, #ifdef, #endif
    * Useful for debugging
    * Turn off large amounts of code
  * #include
    * Includes software defined in other files
    * Declarations get copied into file
  * #warning, #error
  * #pragma
    * Gives a specific instruction to the compiler, controlling compilation from software instead of command line
    * Implementation/Compiler specific (unrecognized pragmas will be ignored)
    * Adds options to compiler for specific function
      * #pragma GCC push_options
    * Causes an error during compilation if code uses these functions
      * #pragma GCC poison printf sprint fprintf
    * Compile a function with a specific architecture
      * #pragma GCC target ("arch=armv6") -or- ("cpu=cortex-m0plus")

* To stop the compiler after preprocessing
  * gcc -E -o main.i main.c
* Compile time switch
  * condition provided at compile time to dictate WHAT should be compiled
  * allow us make our software more portable without maintaining different software repositories
  * uses combination of #if-else and #define directives
  * add extra option to gcc command to define Macro
    * -D<MACRO-NAME\>
    * gcc -DMSP_PLATFORM -o main.out main.c

## Creating header and implementation files

* By using modules and libraries we allow our software to be testable and portable
  * Where do the logical boundaries exists ?
  * What have architecture dependencies ?
  * What have platform dependencies ?
  * What is the purpose of a module ?
  * What is the purpose of the functions ?
  * all these questions will help in the software classification and segmentation process
* Libraries are collection of software (precompiled or direct source)
  * When it comes to compiled libraries there are two types, static libraries and shared libraries
  * Static libraries are directly linked into your output executable
    * installed with the program image as part of the executable
    * create using archiver
    * static libraries are stored within the same executable code in the target
  * Shared libraries are linked dynamically at runtime with your executable
    * pre-installed onto target
    * used for applications with an operating system
    * create with shared flag
    * shared libraries are stored separate from the executable code in target
* Modules are software organization that each module has encapsulated certain functionality within a library
  * create portable code 
  * are use to encapsulate specific functionality, so that they can be easily reused
    * this can contain application specific functions or just constant data
  * each module contain two files
    * implementation files (*.c), contains the function definitions or the actual implementation details
    * header files (*.h), contains the function declarations, macros, & derived data type definitions (structs, enums)
  * Top of header files contains a #ifndef statement
    * it is used to protect against redundant includes
    * #ifndef \__MEMORY_H\_\_
    * #define \__MEMORY_H\_\_
    * #endif \__MEMORY_H\_\_
  * Other include guard is #pragma once
    * a few compilers can handle this one-line include guard
    * it is non-standard, may not be okay for portability
  * Header files are the interface within the software
  * Anything you want to give access to, put in header file
  * Avoid declaring variables in the header file, because every time it is included, a symbol with that name will be declared
  * Make informative function comments in header file
    * function description
    * inputs: type and description
    * return: type and description
  * Regardless of the source of a library, an important reminder is that embedded software needs to be efficient and take up as little code space as possible 
  * If library is precompiled, you should ask yourself
    * is it compiled for my architecture ?
    * was this designed to be optimized for my architecture ?
  * If you have full library source code, you should ask yourself
    * what software features does this use ?
    * what other code does this include ?

## Linkers

* Linking and location occurs in the last phase of our build process
* The job of the linker is to take your compiled object files and to combine them into a single object file, or an executable
* The locator then maps this object into specific address locations producing an executable program that can be installed into your embedded processor
* A typical build process is not linear
* .s files are passing through an assembler to convert into .o files
* In parallel .c and .h files are passing through a compiler to convert into .o files
* Library files .a are passing directly into a linker, this linker also receive .o files
* Then the linker pass those for a locator
* In the locator, another file can be an input to it, this file is called Linker File
* for instance
  * gcc main.c -o main.out -W1, -T, linker_file.lds
* Therefore, the main purpose of the linker is to combine all of objects files into a single executable
  * object code uses symbols to reference other functions/variables
  * the object files have many symbols that need to be tracked and resolved
* Linkers must know name and path to library to link with it
  * static and dynamic libraries get linked at different points
* Using the flag -l or -L we can linking shared libraries
* Standard libraries can be statically or dynamically linked
* Entry and exit points from main are included in a standard library that is automatically included by the linker
* Can stop auto link of standard libs with -nostdlib flag
* Realocatable & Executable files are NOT human readable
* After locating, symbols are removed and direct addresses get assigned into the object code
* The processor understands machine code (binary encoded instructions)
* These must have direct references to memory (addresses, not symbols)
* Linker files posses the details on how to map compiled data into physical memory regions
  * The linker file specifies many items on how to perform this relocation
    * segment name
    * region name
    * memory sizes
      * your program will be split into many memory regions during installation
      * in contrast, your program executable is also broken up into many sections of code and data
      * each code section output from compilation is then mapped into memory regions
      * memory region and compiled memory sections can be used to
        * specifies the location the compiled region should map into physical memory
        * specifies the start address and length of the region for the memory map (in bytes)
        * specifies the access properties of the region
          * RX, read only
          * RW, write only
          * used for security and safety
      * Linker files can calculate memory segments
        * can throw an error if memory space is invalid
    * access permission
  * Linker flags
    * -map [NAME], outputs a memory map file [NAME] from the result of linking
    * -T [NAME], specifies a linker script name [NAME]
    * -o [NAME], place the output in the file name [NAME]
    * -O <#\>, The level of optimizations from [#=0-3] (-O0, -O1, -O2, -O3) 
    * -Os, optimize for memory size
    * -z stacksize=[SIZE] the amount of stack space to reserve
    * -shared, produce a shared library (dynamic linking library)
    * -l [LIB] link with library
    * -L [DIR] include the following library path
    * -Wl, <OPTION\> pass option to linker from compiler
    * -Xlinker <OPTION\> pass option to linker from compiler

## Make

* 
