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

## RTOS Code Example
```
QueueHandle_t qh = 0;
TaskHandle_t mytaskhendler = NULL;
TaskHandle_t mytaskhendler_1 = NULL;
TaskHandle_t mytaskhendler_2 = NULL;

void mytask1(void*p)
{
    while (1) {
        int s= 0;
        printf ("Interface Connected Succesfully\n",s ++);
        vTaskDelay(1000);
      if (s==1)
        vTaskDelete(mytaskhendler_2);
        
}
void Sending_inf(void* P)
{
    int count = 0 ;
        while(1){
        printf("Sensors Sending Information: %d\r\n", count ++); // counting and sending the inf
        if (! xQueueSend(qh, &count, 1000)) {

            printf("Information not Received\n");
        }
        vTaskDelay(3000); // second delay 
    }
    
}

void Receiving_inf(void* P)
{
    int i = 0;
    while (1) {

        if (!xQueueReceive(qh, &i, 1000)) { // receiving the inf from the sensors and connecting them

            printf("Receiving Information to the Control Unit \n");
        }
        else{
            puts("Information Failed to Receive\n");

        }
int main_blinky()
{
    qh = xQueueCreate(5, sizeof(int));
    xTaskCreate(Sending_inf, "task2", 200, (void*)0, 1, &mytaskhendler);
    xTaskCreate(Receiving_inf, "task3", 200, (void*)0, 1, &mytaskhendler_1);
    xTaskCreate(mytask1, "task1", 200, (void*)0, 4, &mytaskhendler_2);
     vTaskStartScheduler();
    return -1;
}
```
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
### 5. Dependable systems 
- A safety and dependability case has to be approved by the regulator.
- Has to create the evidence to convince a regulator that the system is dependable, safe, and secure.
- Nuclear systems
- Security, Availability, Reliability, Safety and Resilience.

### Atributes:
- Dependable systems are typically characterized by the the following attributes:
- Reliability: the system behaves as expected, with very few errors.
- Availability: the system and services are mostly available, with very little or no down time.
- Safety: the systems do not pose unacceptable risks to the environment or the health of users.
- Confidentiality: data and other information should not be divulged without intent and authorization.
- Survivability: The system services should be robust enough to withstand accidents and attacks.
- Integrity: System data should not be modified without intent and authorization.
- Maintainability: Maintenance of system hardware and services should not be difficult or excessively expensive.


