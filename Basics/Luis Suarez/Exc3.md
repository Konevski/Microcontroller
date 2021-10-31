# Waterfall

## Phases of Waterfall (Source) https://www.lucidchart.com/blog/waterfall-project-management-methodology

**Requirement gathering and documentation** -
In this stage, you should gather comprehensive information about what this project requires. You can gather this information in a variety of ways, from interviews to questionnaires to interactive brainstorming. By the end of this phase, the project requirements should be clear, and you should have a requirements document that has been distributed to your team.

**System design** -
Using the established requirements, your team designs the system. No coding takes place during this phase, but the team establishes specs such as programming language or hardware requirements.

**Implementation** -
Coding takes place in this phase. Programmers take information from the previous stage and create a functional product. They typically implement code in small pieces, which are integrated at the end of this phase or the beginning of the next.

**Testing** -
Once all coding is done, testing of the product can begin. Testers methodically find and report any problems. If serious issues arise, your project may need to return to phase one for reevaluation.

**Delivery/deployment** -
In this phase, the product is complete, and your team submits the deliverables to be deployed or released.

**Maintenance** -
The product has been delivered to the client and is being used. As issues arise, your team may need to create patches and updates may to address them. Again, big issues may necessitate a return to phase one.

## Benefits of waterfall project 
Although most companies use some combination of project management styles, a 2017 report from LiquidPlanner showed that 25.5% of manufacturing companies currently use waterfall. What makes this methodology successful for so many teams?

**Keeps training simple** -

This methodology could ensure your project’s success even if there are unanticipated changes in bandwidth. Because waterfall project management emphasizes thorough documentation, you can easily and seamlessly add new team members to any project. There’s no need to intuit what an absent programmer was trying to do, as everything—from the project’s conception to its completion—is recorded. New team members can simply refer to documentation to get quickly up to speed.


# V-Model

## Phases  (source: https://www.tutorialspoint.com/sdlc/sdlc_v_model.htm)

V-Model has validation and verification phases

1. **Verification Phases**

**Business Requirement Analysis** - This is the first phase in the development cycle where the product requirements are understood from the customer’s perspective. This phase involves detailed communication with the customer to understand his expectations and exact requirement. This is a very important activity and needs to be managed well, as most of the customers are not sure about what exactly they need. The acceptance test design planning is done at this stage as business requirements can be used as an input for acceptance testing.

**System Design** - Once you have the clear and detailed product requirements, it is time to design the complete system. The system design will have the understanding and detailing the complete hardware and communication setup for the product under development. The system test plan is developed based on the system design. Doing this at an earlier stage leaves more time for the actual test execution later.

**Architectural Design** - Architectural specifications are understood and designed in this phase. Usually more than one technical approach is proposed and based on the technical and financial feasibility the final decision is taken. The system design is broken down further into modules taking up different functionality. This is also referred to as High Level Design (HLD).
The data transfer and communication between the internal modules and with the outside world (other systems) is clearly understood and defined in this stage. With this information, integration tests can be designed and documented during this stage.

**Module Design** - In this phase, the detailed internal design for all the system modules is specified, referred to as Low Level Design (LLD). It is important that the design is compatible with the other modules in the system architecture and the other external systems. The unit tests are an essential part of any development process and helps eliminate the maximum faults and errors at a very early stage. These unit tests can be designed at this stage based on the internal module designs.

**Coding Phase** - The actual coding of the system modules designed in the design phase is taken up in the Coding phase. The best suitable programming language is decided based on the system and architectural requirements.
The coding is performed based on the coding guidelines and standards. The code goes through numerous code reviews and is optimized for best performance before the final build is checked into the repository.

2. **Validation Phases**

**Unit Testing** - Unit tests designed in the module design phase are executed on the code during this validation phase. Unit testing is the testing at code level and helps eliminate bugs at an early stage, though all defects cannot be uncovered by unit testing.

**Integration Testing** - Integration testing is associated with the architectural design phase. Integration tests are performed to test the coexistence and communication of the internal modules within the system.

**System Testing** - System testing is directly associated with the system design phase. System tests check the entire system functionality and the communication of the system under development with external systems. Most of the software and hardware compatibility issues can be uncovered during this system test execution.

**Acceptance Testing** - Acceptance testing is associated with the business requirement analysis phase and involves testing the product in user environment. Acceptance tests uncover the compatibility issues with the other systems available in the user environment. It also discovers the non-functional issues such as load and performance defects in the actual user environment.

## _**The difference between waterfall and V model is that in waterfall model the software testing is done after the completion of development phase while in V model, each phase in the development cycle has a directly associated testing phase.**_

## Agile

a) **Size of the developer team**: Small

b) **Complexity of the project**: Simple

c) **Known requirements**: Not too important

d) **Change of requirements**: Possible and easy

e) **Time To Market**: Really fast

f) **Knowledge of IT (customer)**: High

g) **Average number of iteration**: More than one

## Waterfall

a) **Size of the developer team**: Medium

b) **Complexity of the project**: Simple

c) **Known requirements**: Yes

d) **Change of requirements**: Not possible

e) **Time To Market**: Moderate

f) **Knowledge of IT (customer)**: Very little

g) **Average number of iteration**: One

## V-Model

a) **Size of the developer team**: Large

b) **Complexity of the project**: Complex

c) **Known requirements**: Yes

d) **Change of requirements**: Yes

e) **Time To Market**: Slow

f) **Knowledge of IT (customer)**: No

g) **Average number of iteration**: One
