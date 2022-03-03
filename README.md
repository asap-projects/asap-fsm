# C++ template-based finite state machines

![Start Now!!](doc/_static/logo.png "ASAP Logo")

[![Build Matrix](https://github.com/asap-projects/asap-fsm/actions/workflows/cmake-build.yml/badge.svg?branch=master)](https://github.com/asap-projects/asap-fsm/actions/workflows/cmake-build.yml)

## [Project Documentation](https://asap-projects.github.io/asap-fsm/)

## Overview

This is a C++ template-based implementation of state machines. The FSM has a 
set of possible states and a set of rules that govern transitions between 
the current state and some other state upon receiving an event.

A state can be an arbitrary object, which type is used to distinguish it from
other states. Therefore, there is no need to maintain a list of known states
(in an enumeration for example). We also don't want to enforce any
relationship between those types to keep them completely independent. The
state machine is a variadic template that gets to know its states through the
parameter pack and stores them in a tuple.

Transitions from the current state to other states are triggered by events.
This requires that all the state types have a `Handle` method that accepts an
event of the type of event being handled. To avoid creating unnecessary
dependencies between the state types and the state machine type, a state's
`Handle` method will return an object of a specific type (an action) that
will describe what action should the machine take.

Events are produced outside the state machine and fed into it by an external
event loop which calls the state machine's `Handle` method. The latter
dispatches the event to the current state, which returns a specific action
that gets executed to eventually transition to a new state.

Examples and detailed documentation of the API can be found at the
[Project Documentation](https://asap-projects.github.io/asap-fsm/) pages.

## Getting the code

```bash
git clone --recurse-submodules -j4 https://github.com/asap-projects/asap-fsm.git
```

NOTES:

- -j4 requests git to parallelize cloning of repos. Needs a relatively recent 
  version of git. If that is not available, simply do not use this option.

## Requirements

Make sure you have a C++ compiler with C++-17 capabilities at least. Gnu, Clang 
and MSVC all can do that with a recent version.

## Enabling husky/commitlint/standard-version

Only one time after the project is cloned, do the following:

```bash
npx husky install
npm install -g @commitlint/cli @commitlint/config-conventional
npm install -g standard-version
```

## Building

```bash
mkdir _build && cd _build && cmake .. && cmake --build .
```

or just use one of the predefined `CMake` presets. Detailed instructions and 
many useful commands are listed 
[here](https://abdes.github.io/asap/master/html/01-getting-started/useful-commands.html).

### CMake configurable build options 

```cmake
# Project options
option(BUILD_SHARED_LIBS        "Build shared instead of static libraries."              ON)
option(ASAP_BUILD_TESTS         "Build tests."                                           OFF)
option(ASAP_BUILD_EXAMPLES      "Build examples."                                        OFF)
option(ASAP_WITH_GOOGLE_ASAN    "Instrument code with address sanitizer"                 OFF)
option(ASAP_WITH_GOOGLE_UBSAN   "Instrument code with undefined behavior sanitizer"      OFF)
option(ASAP_WITH_GOOGLE_TSAN    "Instrument code with thread sanitizer"                  OFF)
option(ASAP_WITH_VALGRIND       "Builds targets with valgrind profilers added"           OFF)
```
