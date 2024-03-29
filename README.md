# C++ template-based finite state machines

<div align="center">

-+- Build Status -+-

_develop_

[![Build status - develop][build-status-develop-badge]][build-matrix]

_master_

[![Build status - master][build-status-master-badge]][build-matrix]

-+-

[![Latest release][release-badge]][latest-release]
[![Commits][last-commit-badge]][commits]
[![Linux][linux-badge]][latest-release]
[![Windows][windows-badge]][latest-release]
[![Mac OS][macos-badge]][latest-release]
[![License][license-badge]][license]
[![CII Best Practices][openssf-badge]][openssf-project]

</div>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#project-documentation">Project Documentation</a> •
  <a href="#getting-started">Getting Started</a> •
  <a href="#Contributing">Contributing</a> •
  <a href="#credits">Credits</a> •
</p>

## Key Features

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

## Project Documentation

We have detailed guides for setting up an efficient development environment, the
development process, project structure, etc. Take a look at the available guides
[here](https://abdes.github.io/asap/asap_master/html/project-development/index.html).

In addition to that, specific documentation for the API, its usage and APIs, is
provided in the project GitHub Pages site
[here](https://asap-projects.github.io/asap-fsm/asap_fsm_master/html/).

## Getting Started

It is strongly recommended that you take some time to browse the project
documentation to familiarize yourself with its structure and development
workflows.

Make sure you have a C++ compiler with C++-17 capabilities at least. Gnu, Clang
and MSVC all can do that with a recent version.

```bash
git clone --recurse-submodules -j4 https://github.com/asap-projects/asap-fsm.git
```

```bash
mkdir _build && cd _build && cmake .. && cmake --build .
```

or just use one of the predefined `CMake` presets. Detailed instructions are in
the project documentation, and many useful commands are listed
[here](https://abdes.github.io/asap/asap_master/html/getting-started/useful-commands.html).

## CMake configurable build options

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

## Contributing

If you would like to contribute code you can do so through GitHub by forking the
repository and sending a pull request. When submitting code, please make every
effort to follow existing conventions and style in order to keep the code as
readable as possible.

By contributing your code, you agree to license your contribution under the
terms of the BSD-3-Clause or a more permissive license. All files are released
with the BSD-3-Clause license.

Read the [developer guides](https://abdes.github.io/asap/asap_master/html/).

### Submitting a PR

- For every PR there should be an accompanying issue which the PR solves
- The PR itself should only contain code which is the solution for the given
  issue
- If you are a first time contributor check if there is a suitable issue for you

## Getting updates from upstream [`asap`](https://github.com/abdes/asap)

In order to pull and merge updates from the upstream project, make sure to add
it to the repo's remotes and disable pulling/merging tags from the upstream. We
want tags to be limited to those made in this repo, not in the upstream.

```bash
git remote add upstream https://github.com/abdes/asap.git
git config remote.upstream.tagopt --no-tags
```

## Credits

- The multitude of other open-source projects used to implement this project or
  to get inspiration - credits in the source code or the documentation as
  appropriate

[build-matrix]: https://github.com/asap-projects/asap-fsm/actions/workflows/cmake-build.yml?branch=master
[build-status-develop-badge]: https://github.com/asap-projects/asap-fsm/actions/workflows/cmake-build.yml/badge.svg?branch=develop
[build-status-master-badge]: https://github.com/asap-projects/asap-fsm/actions/workflows/cmake-build.yml/badge.svg?branch=master
[cleanup-thumb]: https://asciinema.org/a/JOXq0l9CLZMolNcGhOnc84tNO.svg
[cleanup-video]: https://asciinema.org/a/JOXq0l9CLZMolNcGhOnc84tNO?autoplay=1
[commits]: https://github.com/asap-projects/asap-fsm/commits
[customize-thumb]: https://cdn.loom.com/sessions/thumbnails/bedff4e1532441a6af6497653e52cede-with-play.gif
[customize-video]: https://www.loom.com/embed/bedff4e1532441a6af6497653e52cede
[from-template-thumb]: https://cdn.loom.com/sessions/thumbnails/087f217b73454728900baa8b1487f358-with-play.gif
[from-template-video]: https://www.loom.com/embed/087f217b73454728900baa8b1487f358
[hello-world-thumb]: https://cdn.loom.com/sessions/thumbnails/ff20f1771a6d448c8fd7b6e53e117c93-with-play.gif
[hello-world-video]: https://www.loom.com/embed/ff20f1771a6d448c8fd7b6e53e117c93
[last-commit-badge]: https://img.shields.io/github/last-commit/asap-projects/asap-fsm
[latest-release]: https://github.com/asap-projects/asap-fsm/releases/latest
[license-badge]: https://img.shields.io/github/license/asap-projects/asap-fsm
[license]: https://opensource.org/licenses/BSD-3-Clause
[linux-badge]: https://img.shields.io/badge/OS-linux-blue
[macos-badge]: https://img.shields.io/badge/OS-macOS-blue
[openssf-badge]: https://bestpractices.coreinfrastructure.org/projects/5922/badge
[openssf-project]: https://bestpractices.coreinfrastructure.org/projects/5922
[project-docs-thumb]: https://cdn.loom.com/sessions/thumbnails/131bd53f1a004387b09bbeeb80a41f3e-with-play.gif
[project-docs-video]: https://www.loom.com/embed/131bd53f1a004387b09bbeeb80a41f3e
[project-docs]: https://abdes.github.io/asap/asap_master/html/index.html
[release-badge]: https://img.shields.io/github/v/release/asap-projects/asap-fsm
[windows-badge]: https://img.shields.io/badge/OS-windows-blue
