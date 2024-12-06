# Buckshot-Roulette

## 1. Our Team
- **Liao Wang**: 3036126953
- **Liu Hongkai**: 3036127763
- **Wang Zijie**: 3036126953
- **Wang Jinghan**: 3036128561

## 2. Overview
**Original game**: [Buckshot-Roulette](https://mikeklubnika.itch.io/buckshot-roulette)

### 2.1 Basic Rules
- Two-player game with a set amount of lives (default = 4).
- A shotgun is loaded with a disclosed number of bullets, including blanks.
- Players take turns shooting, aiming at either the opponent or themselves (shooting self with a blank skips the opponent's turn).
- Special items are available to assist players:
  - **CIGARETTE**: Grants an extra life.
  - **BEER**: Discards the bullet in the shotgun.
  - **SAW**: Doubles damage for one turn.
  - **MAGNIFIER**: Reveals the bullet in the chamber.
  - **HANDCUFFS**: Prevents the opponent from taking their next turn.

### 2.2 Game Modes
- **Player vs. Player (PvP)**: Engage in head-to-head matches testing skills and strategy.
- **Player vs. Environment (PvE)**: Face an advanced AI that adapts to the player's skill level.

### 2.3 Save & Load
- Saves your game progress automatically, allowing you to resume where you left off without losing any data.

### 2.4 Default Settings
- default health
- default item numbers
- default maximum lives
- default maximum blanks

## 3. How to Play Our Game
### 3.1 Quick DEMO
- [Video Demo](https://youtu.be/9pU-0DAcSxM)

### 3.2 Compilation and Execution Instructions
```commandline
make all
./main
```

## 4. About our program
### 4.1 List of Features
- **Generation of Random Events**:
  - Randomly insert bullets into the gun.
  - Computer randomly use items (with certain reasonable rule).
  - Randomly decide that which one moves first.
- **Data Structures for Storing Data**:
  - **class**: `shotgun`, `player` (in `game.cpp`)
  - **struct**: `letter` (in `display.cpp`)
- **Dynamic Memory Management**:
  - Storing default values.
- **File Input/Output**: 
  - Reading/storing data from `Player1_save_data.dat`, `Player2_save_data.dat`, `Save_Statue`, `Shotgun_save_data.dat`.
- **Program Codes in Multiple Files**: 
  - The main files in our program are: `game.cpp`, `start.cpp`, `display.cpp`, `save.cpp`, with `main.cpp` used to run the program.

### 4.2 List of Non-standard C/C++ Libraries
- iostream
- fstream
- sstream
- string
- vector
- algorithm
- random
- ctime
- cstdlib
- unistd.h
