### 1. Reactive systems
- E.g. thermometer, messaging apps, this google docs system
- Could be deadline dependant, especially if the system is exposed to higher risks
- Continuous interaction with the outside world, real-time data acquisition, event trigger response
- Implemented via loops (for, while)
- The steady-state behavior of the system does not terminate (except under the condition of a fatal error)
- Responds to interrupts

### 2. Real-time systems
- Hard Real-Time systems have heavier consequences than sof real-time systems
- Continuous: Required input/output is predetermined, basically an equation solver
- Discrete: Transforms the input into a more desirable output, i.e. transforms the input from one state to another; e.g. accumulator; Can be casual and non-casual
- Works with deadlines, worst-case execution time is necessary to know beforehand 
- Hybrid Systems: a combination of Continuous and Discrete systems
- RTOS: An operating system that guarantees a certain capability within a specified time constraint, usually a preemptive scheduling system
