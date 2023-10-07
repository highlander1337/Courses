# Introduction to embedded systems

* Useful links

[(898) A Few Embedded Systems Tips for Beginners - YouTube](https://www.youtube.com/watch?v=j3SwYvuR8oc&ab_channel=JacobSorber)

[(898) 5 Things Every New Embedded Systems Engineer Should Know - YouTube](https://www.youtube.com/watch?v=MERQitqaWoA&ab_channel=ZygalStudios)

[(898) What is an Embedded system? - YouTube](https://www.youtube.com/watch?v=Vt7kXpAaqGo&ab_channel=EmbeddedInventor)

## What is an embedded system ?

* An embedded system is a computerized system that is purpose built for its application

* It has limited resources

  * Processing
  * Memory
  * Peripherals

* Target embedded systems usually use printed circuit board technology for hardware implementation

  * Typically the hardware is a combination of processing core and external circuits for  the processor to interact with
  * A software installer combines these two pieces by loading software image into the processor's memory

* With respect to design and implementation

  * Specific design decisions will be made in each embedded application for levels of performance, power, and timing

  * By directly quantifying these characteristics, you can begin to create a list of functional specifications

  * These specs provide detailed criteria needed to evaluate the capabilities of different target platforms

  * This analysis is dependent on the hardware architecture and how efficient your coding is

  * Target embedded systems usually use printed circuit board technology for hardware implementation

    * This includes your processor and your power converters
    * An external programmer is connected to the embedded systems processor, in order to install a target application into the internal memory
    * Modern designs have begun to integrate extra onboard programmer debugger hardware to simplify this process

  * A host machine is responsible for developing and compiling and coordinate the install which is equally as important as development of the system PCB itself. 

    * The host machine is where your software files live. 

    * An embedded software engineer will focus in becoming an expert on the host development environment, the tools and most importantly, the processor

* One solution for the processing core would be a microcontroller

  * microprocessors and microcontrollers are not the same
    * A microcontroller is a microprocessor with added functionality such as memory and peripheral hardware
    * The processor part of the microcontroller is called the CPU or the Central Processing Unit. 
      * This is a piece of hardware that runs our software by fetching and executing assembling instructions for memory.
      * These instructions perform math and logic operations as well as coordinating data movement.
      * The CPU has many sub components with many responsibilities. Many registers, general purpose and special purpose, store operations data and systems state
      * An Arithmetic Logic Unit, or the ALU, performs the fundamental low level assembly operations, an Interrupt Controller coordinates a synchronous event request of the processor
      * Lastly a Debug interface is used to help troubleshoot installed programs
    * The CPU and its subsystems interact with other microcontroller resources through one or more buses
      * A bus controller aids the processor in this data transmission between memory and peripherals
    * Memory holds data that we operate on as well as the program that we're executing. This data is stored in a combination of flash and Random Access Memory or RAM
    * A clock system provides synchronizations across all these components
    * And to wrap up on trip power management hardware is used for regulation and monitoring
    * A variety of peripheral hardware maybe included in a micro controller. 
      * Some typical peripheral functionality you will see include communication, analog signal processing, input and output, timing and processor support

## What is embedded software engineering ?

The goal of embedded software engineering is to design high quality software that could help prevent bugs and even provide reusability of code while holding principles such as

* Maintanability
* Testability
* Portability
* Robustness

To do this, embedded software engineers often use a set of tools, for instance

* Flow diagrams
  * Shows functional behavior
  * Algorithm based
  * Conditional decisions
  * High level function calls
* Software block diagrams
  * Software diagrams can depict graphical software representations like
    * block diagram
    * process flow diagrams
    * abstraction and layer diagrams
      * Low level devices drivers that interact with hardware
      * Software to help boot or start the system
      * An operating system to schedule processes and manages resources
      * Shared libraries that many software components use
      * Higher level software reflecting user applications
  * Software that directly interacts with hardware is called bare-metal firmware
    * A firmware engineer requires deep knowledge of the hardware, not only for configuration of the bare-metal but also for hardware timing and limitations related to their software design
    * A software engineer's role will be to try and segment the hardware interface into something referred to as a HAL or Hardware Abstraction Layer
* Simulators
* Emulators
* Compilers
* Installers
* Debuggers

There are many embedded software languages use in the industry such as C, C++, Java and Ada. But C-Programming is the most widely used language for embedded software design

Typical embedded engineers actually write a form of C called Embedded C.  Embedded C differs from C because it puts a focus on the following features. Efficient memory management, timing centric operations, direct hardware/IO control, code size constraints, and optimized execution.

In general, you can think of Embedded C as optimum features in minimum space and time.

## What is software configuration management ?

Software engineers often need to know

* how code is tested and tracked
* how you can access and make changes to the code

Software configuration management, is a process that is used by software teams to develop software projects

Developing software can require a lot of process, such as

* Used directly by software engineers in development
  * Software requirements
  * Environment Information
  * Software Build and Release
  * Software Review
  * Version Control
* Used to help organize and support software projects
  * Testing
  * Support
  * Documentation
  * Defect Tracking
  * Task Management

SCM is important to a project because it  describes how software will be developed and organized. You can think of SCM as the overall project development environment. Getting yourself organized before a project starts by defining your decisions for the components of SCM. It can help spread the work across a team, and provide effective communication.

code for configuration management

* git init
* git config --global user.email "you@example.com"
* git config --global user.name "Your Name"
* git add <FILE\> or git add *
* git commit -m "some description"
* git status
* git branch <NAME\>
* git checkout <NAME\>
* git clone
* git pull
* git push

## Which development kit should i choose for my project ?

Questions to ask

* How much memory will i need for my application ?
* How fast does the application need to run ?
* What kind of mathematical support do i need ?

Look at Product Brief

* Concise overview of a product
* Talks about use cases
* Gives more detailed feature specifications
* Nice on the eyes

Look at data sheets

* Electrical
* Timing
* Environmental
* Physical Package

Look at technical reference manuals

* Configuration details
* Operation descriptions
* Used to write Bare-Metal Firmware
