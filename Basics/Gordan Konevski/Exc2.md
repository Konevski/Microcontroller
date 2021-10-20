## 1. Reactive systems
- E.g. thermometer, messaging apps, google docs, etc.
- Could be deadline dependant, especially if the system is exposed to higher risks
- Continuous interaction with the outside world, real-time data acquisition, event trigger response
- Implemented via loops (for, while); An Arduino example:
```
void loop()
{
if (button == 1) {
    green_light();
    delay(DELAY_GREEN);
    yellow_light();
    delay(DELAY_YELLOW);
    red_light();
    delay(DELAY_RED);
  }
  else
    return 0;
}
```
- The steady-state behavior of the system does not terminate (except under the condition of a fatal error)
- Responds to interrupts

## 2. Real-time systems (Continuous/discrete/hybrid systems)
- Hard Real-Time systems have heavier consequences than sof real-time systems
- Continuous: Required input/output is predetermined, basically an equation solver
- Discrete: Transforms the input into a more desirable output, i.e. transforms the input from one state to another; e.g. accumulator; Can be casual and non-casual
- Works with deadlines, worst-case execution time is necessary to know beforehand 
- Hybrid Systems: a combination of Continuous and Discrete systems
- RTOS: An operating system that guarantees a certain capability within a specified time constraint, usually a preemptive scheduling system

### There are also pertinent characteristics relating to the execution environment (source: https://www.sciencedirect.com/topics/computer-science/real-time-computing):
- System loading
- Resource interactions
- Queuing disciplines
- Arbitration mechanisms
- Service latencies
- Interrupt priorities and timing
- Caching, etc.

Interrupt timing example [AVR Example] (source: https://www.visualmicro.com/page/Timer-Interrupts-Explained.aspx):
```
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
    /* E.g. 1Hz with 1024 Pre-Scaler:
		compareMatchReg = [16, 000, 000 / (prescaler * 1)] - 1
		compareMatchReg = [16, 000, 000 / (1024 * 1)] - 1 = 15624
	
	    As this is > 256 Timer 1 Must be used for this..
	*/
    
	TCNT1 = compareMatchReg;   // precalculated preload timer = preload timer
	interrupts++;
	Serial.print("Total Ticks:");
	Serial.println(interrupts);
}

void loop()
{
	// your program here...
}
```

### Terms related to real time system (source: https://www.geeksforgeeks.org/real-time-systems/):
- Job – A job is a small piece of work that can be assigned to a processor and may or may not require resources.
- Task – A set of related jobs that jointly provide some system functionality.
- Release time of a job – It is the time at which job becomes ready for execution.
- Execution time of a job – It is the time taken by job to finish its execution.
- Deadline of a job – It is the time by which a job should finish its execution. Deadline is of two types: absolute deadline and relative deadline.
- Response time of a job – It is the length of time from release time of a job to the instant when it finishes.
- Maximum allowable response time of a job is called its relative deadline.
- Absolute deadline of a job is equal to its relative deadline plus its release time.
- Processors are also known as active resources. They are essential for execution of a job. A job must have one or more processors in order to execute and proceed towards completion. Example: computer, transmission links.
- Resources are also known as passive resources. A job may or may not require a resource during its execution. Example: memory, mutex
- Two resources are identical if they can be used interchangeably else they are heterogeneous.

## 3. Embedded systems
- Software embedded into a technical system that
interacts with the real physical world, controlling some
specific hardware (source: lectures)
- Interaction with the technical system via actors and
sensors (source: lectures)
### different hardware platforms:
- General purpose microprocessor: X86, PowerPC, … +
processor board
- Highly integrated microprocessor: additional I/O on the
chip
- Single-chip microcomputer: I/O, Rom, RAM, …
- Single-chip microcontroller: microcomputer with realtime clock, A/D and D/A converters, …
- Digital signal processor: extremely high throughput,
optimized for numerical operations
- Mixed-signal processor: direct interface to analogous
and digital signals (usually low-cost)
- Bespoken System-on-chip design: FPGAs or ASICs
that may incorporate microprocessors and memory (very
expensive)
- Different MCU types: low cost MCU, medium size MCU, low cost MCU + small CPLD, medium size FPGA

### Levels of abstraction in real-time computing context (source: https://www.sciencedirect.com/topics/computer-science/real-time-computing):
- CPU: The CPU clearly influences the behavior of the program, particularly when the CPU is a pipelined processor with a cache.
- Platform: The platform includes the bus and I/O devices. The platform components that surround the CPU are responsible for feeding the CPU and can dramatically affect its performance.
- Program: Programs are very large and the CPU sees only a small window of the program at a time. We must consider the structure of the entire program to determine its overall behavior.
- Task: We generally run several programs simultaneously on a CPU, creating a multitasking system. The tasks interact with each other in ways that have profound implications for performance.
- Multiprocessor: Many embedded systems have more than one processor—they may include multiple programmable CPUs as well as accelerators. Once again, the interaction between these processors adds yet more complexity to the analysis of overall system performance.

## 4. Dependable systems (source: https://www.sciencedirect.com/topics/computer-science/dependable-system)
- Four techniques used in dependable systems: faults prevention, faults elimination, faults tolerance, faults predicting

### Atributes:
- Dependable systems are typically characterized by the the following attributes:
- Reliability: the system behaves as expected, with very few errors.
- Availability: the system and services are mostly available, with very little or no down time.
- Safety: the systems do not pose unacceptable risks to the environment or the health of users.
- Confidentiality: data and other information should not be divulged without intent and authorization.
- Survivability: The system services should be robust enough to withstand accidents and attacks.
- Integrity: System data should not be modified without intent and authorization.
- Maintainability: Maintenance of system hardware and services should not be difficult or excessively expensive.

## 5. Distributed systems
- Resource sharing - whether it’s the hardware, software or data that can be shared
- Openness - how open is the software designed to be developed and shared with each other
- Concurrency - multiple machines can process the same function at the same time
- Scalability - how do the computing and processing capabilities multiply when extended to many machines
- Fault tolerance - how easy and quickly can failures in parts of the system be detected and recovered
- Transparency - how much access does one node have to locate and communicate with other nodes in the system.

### UDP sending Linux exmaple (source: https://github.com/thomasWeise/distributedComputingExamples/blob/master/sockets/c/UDPClient_linux.c):
```
#include <stdio.h>      //compile: gcc UDPClient_linux.c -o UDPClient_linux
#include <string.h>     //Warning: This program does not perform any error handling.
#include <sys/socket.h> //In any real program, you need to handle errors.
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])  {
  int client;  struct sockaddr_in address;    char data;

  client = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP); //Allocate client socket

  memset(&address, 0, sizeof(address));  //Clear socket address
  address.sin_family      = AF_INET;     //IPv4 address
  address.sin_addr.s_addr = inet_addr("127.0.0.1");//Set to (loopback) IP address
  address.sin_port        = htons(9998); //Make port in network byte order

  data = 2; // then send 1 byte package data to client, with flags=0
  sendto(client, &data, 1, 0, (struct sockaddr *)&address, sizeof(address)); //(*@\clientBox{1+2)}@*)

  close(client);  //(*@\clientBox{4)}@*)
  return 0;
  }
```


