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

## 2. Real-time systems
- Hard Real-Time systems have heavier consequences than sof real-time systems
- Continuous: Required input/output is predetermined, basically an equation solver
- Discrete: Transforms the input into a more desirable output, i.e. transforms the input from one state to another; e.g. accumulator; Can be casual and non-casual
- Works with deadlines, worst-case execution time is necessary to know beforehand 
- Hybrid Systems: a combination of Continuous and Discrete systems
- RTOS: An operating system that guarantees a certain capability within a specified time constraint, usually a preemptive scheduling system


### 3. Continuous/discrete/hybrid systems
### 4. Embedded systems
### 5. Dependable systems 
### 6. Distributed systems 
### 7. Dependable system attributes:

### Terms related to real time system (https://www.geeksforgeeks.org/real-time-systems/):

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
