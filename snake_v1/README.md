# Snake V1

## Overview

Snake V1 is a small terminal-based Snake game written in C++. Move the snake around a bounded board, collect food, and avoid the walls and your own tail.

## Implemented Features

- A 30 by 30 play area rendered in the Windows console
- Keyboard movement using WASD or the arrow keys
- Food collection increases the score by 10 and grows the snake
- The game ends when the snake hits a wall or its own tail
- Press Esc to quit the game

## Tech Stack

- C++
- MinGW-w64 `g++` 
- Windows console APIs: `<conio.h>` and `<windows.h>`

## Prerequisites

- Windows
- A C++ compiler with MinGW-compatible support for the Windows headers above
- A terminal opened in the `snake_v1` directory

## Build and Run

From this directory, compile the source and run the resulting executable in PowerShell:

```powershell
g++ .\snakev1.cpp -o .\snakev1.exe
.\snakev1.exe
```

The compile command was verified with the available MinGW `g++`. The game uses Windows-specific console functions, so this command is not expected to work unchanged on non-Windows systems.

## Future Improvements

- Add automated tests for the game logic
- Prevent food from appearing on the snake
- Add a restart option after game over
- Consider a cross-platform input and timing implementation