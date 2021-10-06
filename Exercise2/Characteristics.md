#### Gordan Konevski (GK): Reactive systems and Real-time systems
#### Thanas Dushku (TD): Continuous/discrete/hybrid systems, Dependable systems 
#### Luis Suarez (LS): Embedded systems, Distributed systems 

### 1. Reactive systems (GK)
- E.g. thermometer, messaging apps, this google docs system
- Could be deadline dependant, especially if the system is exposed to higher risks
- Continuous interaction with the outside world, real-time data acquisition, event trigger response
- Implemented via loops (for, while)
- The steady-state behavior of the system does not terminate (except under the condition of a fatal error)
- Responds to interrupts

### 2. Real-time systems (GK)
- Hard Real-Time systems have heavier consequences than sof real-time systems
- Continuous: Required input/output is predetermined, basically an equation solver
- Discrete: Transforms the input into a more desirable output, i.e. transforms the input from one state to another; e.g. accumulator; Can be casual and non-casual
- Works with deadlines, worst-case execution time is necessary to know beforehand 
- Hybrid Systems: a combination of Continuous and Discrete systems
- RTOS: An operating system that guarantees a certain capability within a specified time constraint, usually a preemptive scheduling system

### 3. Continuous/discrete/hybrid systems (TD)
- In a continuous system the variables change continuously over time, e.g. the speed of a vehicle, the data can be described by a differential equation
- In a discrete system the variables change at specific points in time, e.g. a state machine
- Hybrid systems have characteristics of both continuous and discrete systems 

### 4. Embedded systems (LS)
- An embedded system is a microprocessor-based computer hardware system with software that is designed to perform a dedicated function, either as an independent system or as a part of a large system. At the core is an integrated circuit designed to carry out computation for real-time operations.
- E.g electronic calculators, GPS systems, fitness trackers.

### 5. Dependable systems (TD)
- Systems that must be reliable, available, safe and secure at any point they are needed/used.
- Reflects the user’s trust in that system. Therefore reflects the user's confidence that would not operate witn no fail in normal use.
- E.g. Aeroplanes, air traffic control

### 6. Distributed systems (LS)
- Collection of autonomous computers connected using a communication network.
- E.g: Telephone, Emails, Electronic Banking, Sensor Networking
- The system requires Concurrent Components, a communication network and a synchronization mechanism.
- Is a field of computer science that studies distributed systems and the computer program that runs in a distributed system is called a distributed program.


## Dependable system attributes:
- Reliability: is the probability of a component, or
system, functioning correctly over a given period of
time under a given set of operating conditions.
- Availability: is the probability that the system will be functioning correctly at any given time.
- Safety
- Security



## To-Do
- how can we implement a reactive systems (a:) as a c program, b) as an arduino program
- what is meaing of a deadline? How can we ensure to be within of a deadline? (Examples, tools, …)
- details about embedded systems inlcuding different hw platforms.  (concrete examples of the one in the lecture)
- example of contiuous real world value into discrete one
- final version till next week (upload to team git rep in folder basics subfolder name of person and document name of task)
