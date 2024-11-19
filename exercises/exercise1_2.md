# Exercise 1 - Answers
## 1. What is the difference between git and github?

Git is the underlying Version Control System, whereas Github (or e.g. Gitlab) are providers who whost Git for you.
They usually offer way more than just git functionalities. For example Github Actions.

## 2. Name 3 benefits of a version control system

1.  When using commits properly it allows to look at previous implementations (old commits) 
in case you might need parts of them again.

2.   Allows for reverting to previous commits easily, in case critical errors were introduced.
In the same sense, working on your own local branch minimizes the risk of messing up already tested states.

3.  Collaboration. People can work on the same project (or technically even the same file) with less risk of conflicts. 
If conflicts emerge they can be resolved more easily.

## 3. Name 3 alternatives to git

1. Perforce
Centralized VCS. Used in the gaming industry (especially due to its solid handling of large (binary?) files). Scales well with bigger repositories.
2.  Mercurial
Also distributed like Git. Supposedly simpler/more user friendly than Git.
3. Subversion
Also Centralized.  Good for large files as well.

## 4. Name 2 differences between git and other version control systems

1. Centralised (Perforce, Subversion) vs Distributed (Git, Mercurial)
	- Centralised:
	 Single source of truth stored on a server.
	 Less complex due to single source of truth.
	 - Distributed:
	 Collaborator has their own local copy of the repository.
	 No single source of failure.
2. Simpler Merging and Branching
	- Creating branches and merging them again is a lot more lightweight than in other Centralised VCS.

## 5. Name known issues related to game engines (Unreal, Unity) and version control systems

- Large file size handling: 
Using Git to handle large file sizes (especially non code related files) can be difficult, as each version of them is stored. (LFS can help here)
- Multiple people working on a single complex/generated file e.g. a Scene or Assets: 
This can create a merge conflict which is hard to resolve (if not impossible). Proper versioning of these can also be hard.
- Large repositories in general: 
Having to download different versions with different sizes can create a lot of overhead with downloading etc.

# Exercise 2 - Answers

## 1. Describe a logging system with your own words

A logging system's main function is to help you see the state of your program. Is everything working correctly? If not, what are the issues?
In order to achieve these there usually are multiple log levels.
- Informative logging that tells you important steps that are running.
- Warnings that some non ideal behaviours are occurring.
- Errors that have occurred and should be fixed. 
It is very important that logs are easily readable and important information is directly visible. E.g. where is the log called from? when/why did it happen?


## 2. What is the difference between git submodules and git subtrees?

A git submodule links to other git repositories, whereas a git subtree fully integrates the other repository into the main one.
So in a sense the submodule is less strictly connected than if it were a subtree.
E.g. commits are in separate histories with submodules than subtrees

## 3. What is a build system in C++? Name 3 build systems

A build system is a set of tools used to automate the building process. This includes compiling and linking sources.
It simplifies the building process in general as well as helping you build the program across multiple platforms.

- Make: widely used
- Cmake: good for cross platform
- Premake: used to generate project files for different IDEs

## 4. What is a package manager in C++? Name 3 package manager

It is a tool that helps you manage libraries or dependencies (packages).
It can install, update and remove them, instead of having to include and remove them manually.

- CPM.cmake: is based on CMake.
- vcpkg: is developed by Microsoft.
- Conan: is a very common option.