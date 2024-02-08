# - COMING SOON -
# Space Shooter

## Overview
Top-to-bottom scrolling shooter game made **for fun** and **leisure**, using the Simple and Fast Multimedia Library (SFML).

## Features
- **Gameplay**: Use W, A, S, D to pilot your ship, and SPACE to fire.
- **Objective**: The less you die, the more fun you have.

## Getting Started

### Prerequisites
Ensure you have CMake installed on your system before attempting to build Space Shooter.

- [CMake](https://cmake.org/download/) (Version 3.21 or higher)

SFML is fetched and configured into the build by default. No need to have it installed. It also links statically.

- [SFML](https://www.sfml-dev.org/download.php) (Simple and Fast Multimedia Library)


### Building Space Shooter
To build Space Shooter on your local machine, follow these steps:

1. **Clone the Repository**  
   Open a terminal and clone the Space Shooter repository using Git:
   ```bash
   git clone https://github.com/ApostolosBouz/sfml-space-shooter.git
   ```
   Navigate into the project directory:
   ```bash
   cd sfml-space-shooter
   ```

2. **Generate Build System**  
   Use CMake to generate the build system files. From the root of the project directory, run:
   ```bash
   cmake -S . -B build
   ```
   This command configures the project and generates a build system in the `build` directory.

3. **Build the Project**  
   Compile the project with the following command:
   ```bash
   cmake --build build
   ```
   This compiles the game into an executable.

4. **Or you know**  
    Omit 1-3 and use [VSCode](https://code.visualstudio.com/) like a normal person.

5. **Run Space Shooter**  
   After compiling, you can run Space Shooter from the `bin` directory.

## Reporting Issues
While I am not currently accepting pull requests, bug reports and critisism are highly appreciated.  
If you encounter any bugs or issues, please open an issue on GitHub with detailed information about the problem, or repro steps if applicable.

## License
Space Shooter is open source and available under the MIT License. See the LICENSE file for more details.
