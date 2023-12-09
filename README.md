# IOLS

This is an educational implementation of IO-Link (not yet finished).  
It follows the specification as strictly as possible.

***Everyone is welcome to join!***

## Goals
- Deeper unterstanding of [IO-Link](https://io-link.com/en/index.php)
- Traceability: Requirements → Behaviour → Tests → Code → Reports
- Automated: Build, Test and Release
- Clean Code (see: https://clean-code-developer.de/)
- [BDD](https://de.wikipedia.org/wiki/Behavior_Driven_Development) as a Behaviour- and Test-Driven Process
  - BDD Tool: [Cucumber](https://cucumber.io/) with [cucumber-cpp](https://github.com/cucumber/cucumber-cpp)
  - Test Framwork: [googletest](https://github.com/google/googletest)
- GitHub workflows as CI/CD (see it at work: [Actions](https://github.com/erichstuder/IOL/actions))
- [CMake](https://de.wikipedia.org/wiki/CMake) as build management tool
- [Docker](https://de.wikipedia.org/wiki/Docker_(Software)) Container as build and test environment
- [Doxygen](https://de.wikipedia.org/wiki/Doxygen) for structural documentation
- Have Fun!

## How to start
On Linux (Windows users may use [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)) with Docker installed `sudo ./run_cucumber.sh -C` execute to build and test
(see [run_cucumber.sh](https://github.com/erichstuder/IOL/blob/main/run_cucumber.sh)).
  
See [local_setup.sh](https://github.com/erichstuder/IOL/blob/main/local_setup.sh) how to install headers for code completion.

## Some Rules
- Every name.feature file needs a step file named: name__step.cpp
- Every step folder needs a cucumber.wire file. Although they are all identical.
- Don't use white-spaces in file names.
