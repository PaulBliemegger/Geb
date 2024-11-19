# Exercise 3
## 1. What is the difference between a dynamic linked library and a static library?

Static libraries increase size of binary code. They are linked during compile time.
Always loaded and runs with the version it is compiled in.
+ Self contained exectuable
+ Version stability
- Larger binary size
- Updating requires recompilation of entire application

Dynamic libraries stored and versioned seperately, meaning they are not included in the executable. 
They are linked during runtime, and usually only loaded when first called.
+ Memory Efficiency, programs can share library
+ Updating does not require recompilation of application
+ Smaller binary size
+ Modularity
- Complex dependency management
- Slight overhead from runtime linking


## 2. Describe a logging system with your own words

A logging system provides vital information of a running application. 
It helps understanding the state of the application. Is everything running correctly and as expected, or are there errors?
In case of errors, it should provide all the necessary information to replecate the error and find its source.
Logs usually include time stamps, the "location"/service it originates from as well as a log level to identify the importance of the log.

## 3. What is a Design Pattern?

Desing Patterns are concepts, that help you plan and implement software in a more abstract and reusable way.
Through their abstract nature, they are applicable to wider and recurring problems, across projects and systems.
They usually focus on reusability, while keeping best practises and maintainability in mind.

## 4. Name and describe 2 Design Patterns (except façade or adapter)

- [Builder](https://refactoring.guru/design-patterns/builder): Create a complex object step by step. Without a tons of subclasses or complex constructors.
Solution: Move object construction code into its own class. The object construction is then put into seperate Builder classes, 
which define the construction steps. Additionaly Directors can be defined, which contain reusable construction code, as well as define the
order of steps.

- [Mediator](https://refactoring.guru/design-patterns/mediator): Reduce chaotic dependencies and restrict direct communication between 
objects.
Extract individual dependencies between components to a Mediator. Ideally the Mediator already has the dependencies already. Example: Profile Form


# Exercise 4

## 1. What is a precompiled header? Name pros and cons

A precompiled header is used to combine commonly used headers into a single pch.h file. This way they can be precompiled once and then
used in multiple places, instead of doing it repeatedly.
+ Faster compilation time, due to avoidance of preprocessing.
+ Consistency
- Lack of granuality with imports
- More complex setup


## 2. Describe the layer of abstraction with your own words

It means decreasing the complexity of something. With this high concept view, software can be planned without focusing too much
on the exact implementation. Even if the implementation might change, the rest of the program should not be affected.


## 3. Name the SOLID principles and describe them briefly

Single responsibility principle
- A class should be designed to cover one specific functionality. Instead of adding more/different funcitonalities create e.g. a new class.
- Increases Maintainability, Testability and Flexibility

Open/Closed principle principle
- entities should be open for extension, but closed for modification
- Increases Exensibility, Stability and Flexibility

Liskov substitution principle
- Subtypes mus be subsititutable for their base types.
- Polymorphism
- Increasees Realiabillity and Predictability

Interface segregation principle
- clients should not be forced to depend upon interfaces that they do not use
- create multiple smaller, modular interfaces instead of few big ones
- Decoupling
- Avoids innecessary dependencies

Dependeny inversion principle
- depend upon abstractions, [not] concretes
- Loose coupling
- Flexibiliy with changing implementations
- Maintainability
