
## Task 1: Explain briefly how the various characteristics of an embedded system can be fulfilled. Which methods and techniques are used?

### 1. Reactive systems
- "Transformational" in which the output is a function of the input and they end after completing their tasks
- "Reactive" which run in loops and react/interact with stimulus from the enviroment
- E.g. thermometer, vending machines,
- Implemented via loops (for, while)

Arduino:
#define red_light 1
#define yellow_light 2
...
void setup(){
	pinMode(pedRED, OUTPUT);
    pinMode(pedGREEN, OUTPUT);
	...
}
void loop(){
	switch (state){
	case red_light:
		digitalWrite(pedRED, LOW);
		digitalWrite(pedGREEN, HIGH); 
	delay(10000);
	...
	state = yellow_light;
	break;
	}
}

### 2. Real-time systems 
- The time it takes to respond or complete a certain task is essential
- To ensure something is done on time we implement deadlines(the latest time until which a response is required)
- Deadlines can be set up using WCET(worst case execution time) and that can be measured based on testing or analyitic tools like Kronos.
- Soft real-time systems depend on deadlines to be more useful but a failure wouldnt cause major damage or loss (e.g. Video games)
- Hard real-time systems must meet deadlines at all times or risk catastrphic consequences (e.g. air-traffic systems)


### 3. Continuous/discrete/hybrid systems 
- In a continuous system the variables change continuously over time
- E.g. the speed of a vehicle, the data can be described by a differential equation
- In a discrete system the variables change at specific points in time
- E.g. a state machine
- Hybrid systems have characteristics of both continuous and discrete systems 


### 4. Embedded systems 
- A combination of software and hardware that interacts with the real world in a sepcific way
- Uses sensors to pick up data from the enviroment and actors to react to the enviroment based on software
- E.g. the brake system of a car


### 5. Dependable systems 
- Systems that must be trustworthy within the time they are needed
- Reliable, available, safe and secure
- The system performs according to its specifications and avoids hazards
- E.g. Aeroplanes, air traffic control


### 6. Distributed systems 
- A number of autonomous computers linked by a network that communicate via message passing
- Data must be transferable reliably between devices and a failure in one mustn't cause a fault in another


## Task 2: Give an overview of the attributes of dependability and show how they influence each other.

- Reliability: The system meets the all requirements in an acceptable way. We ensure this by using validation and verification. 
The higher the realiability the higher the validation and verification required.
The system is working correctly for the time it is required.
The system must be reliable in a way that a fault or failure does not lead to safety concerns.

- Availability: Scheduling/insuring that the system can react at a specific point in time when it's needed.
The system must be available for use at all times it is needed. 
Adding secuirty such as passwords, face id, fingerprint scanners and two factor authentication lowers avaiability.
The system is available at any given time.

- Safety: Catastrophic failures, operating the system under different conditions, such as external damage, hardware diffectes, etc.
Maintaining a system to keep it safe. 
Fault, a failure somewhere in the system, such as storign a 0 instead of a 1.
Using this fault to compute somthing else gives us an Error.
When the system fails to perform it's requirements, it's known as a System Failure. Not all errors cause system failures.
Faults vary in nature(random/hardware faults, logical/systematic/design faults)
The system is safe for use based on the safety requirement, during it's intended use time.
Hazards: 1. Avoidance; The system is build in a way to ensure hazards cannot arise
2. The system is built to detect and remove hazards before they can cause an accident
3. The system has protective features that minimise the damage caused by an accident
For a system to perform correctly it must be maintained so that it's parts don't wear and tear.

- Security: Outside attacks (accidental or deliberate). Wireless sensors, hacking, emp attacks. If the device is hacked it lowers safety, for e.x. in a car.
The system is immune to external attacks, that may access information or try to change/destroy that information.
A security issue may lead to a safety concern.
Though the system must remail secure, data should be available when needed.
The data must not be able to be altered or accessed by unauthorized individuals.

## Task 3: Give a schematic overview on the main elements of a microcontroller.

A microcontroller usually has a:
CPU,
memory(RAM and ROM), 
I/O ports, 
ADC and DAC converters, 
timers/counters,
BUS to connect everything together.

## Task 4: Which processors are typically used for microcontrollers?

Usually we use microprocessors with low cost
Variants: 1. Simple core developed for the microcontroller
2. Using an older core of microprocessors 

























