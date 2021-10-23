 ### 1. Embedded Systems

- Electronic calculators, GPS systems, fitness trackers.
- Central heating systems
- Engine management systems in vehicles
- Domestic appliances, such as dishwashers, TVs and digital phones
- ATM
- Digital watches
- FPGAS
- Microcontroller 
- Stm microcontroller 

### Advantages & Disadvantages

- They tend to require less power. Some devices run from batteries.
- Fitness trackers are embedded systems, but the software can often be upgraded by connecting the device to a PC and installing the new software.


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
### 2. Distributed systems (LS)

- Collection of autonomous computers connected using a communication network.
- Telephone, Emails, Electronic Banking, Sensor Networking
- The system requires Concurrent Components, a communication network and a synchronization mechanism.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
## 3. Reactive systems
- Market flow, Streaming, google docs,
- Should respond in consistent and timely manner.
- Will detect problems quickly and mitigate it effectively
- Implemented via loops (for, while):
```
int main () {
   /* local variable definition */
   int a = 10;
   /* while loop execution */
   while( a < 20 ) {
      printf("value of a: %d\n", a);
      a++;
      if( a > 15) {
         /* terminate the loop using break statement */
         break;
      }		
   }
   return 0;
```
- Responds to interrupts
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
## 4. Real-time systems
- RTOS: Provide the primitives real-time scheduling policies, inter process communication and run-time monitoring. There a number of RTOSs, e.g. RT-Mach, VxWORKS, Solaris, Lynx.
- Air Traffic Control Systems
- Networked Multimedia Systems
- Hard Real-Time operating system: These operating systems guarantee that critical tasks be completed within a range of time
- Soft real-time operating system: This operating system provides some relaxation in the time limit.
- Satellite tracking, video conferencing 
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
### 5. Dependable systems 
- A safety and dependability case has to be approved by the regulator.
- Has to create the evidence to convince a regulator that the system is dependable, safe, and secure.
- Nuclear systems
- Security, Availability, Reliability, Safety and Resilience.

