# Buckshot-Roulette

## 1. Our Team
- **Liao Wang**: 3036126953
- **Liu Hongkai**: 3036127763
- **Wang Zijie**: 3036126953
- **Wang Jinghan**: 3036128561

## 2. Application Description
**Buckshot-Roulette** is an innovative and exhilarating game that combines elements of strategy, skill, and chance, offering players a unique and thrilling experience. Inspired by the high-stakes tension of traditional Russian roulette and incorporating the dynamic nature of shooting sports, Buckshot-Roulette tests players' nerves, precision, and decision-making abilities.

In the game, players take turns engaging in a series of shooting challenges designed to simulate the unpredictable environment of a high-stakes showdown. It involves a specially designed target setup and various types of ammunition, adding complexity and excitement to each round. Players must balance their aim and timing while dealing with the psychological pressure of roulette-style randomization.

### Achievements
- **Rule Compliance**: All rules outlined in part 3.1 have been achieved.
- **Game Modes**: 
  - **Player vs. Player (PvP)**: Engage in head-to-head matches testing skills and strategy.
  - **Player vs. Environment (PvE)**: Face an advanced AI that adapts to the player's skill level.

### Memory Function
Buckshot-Roulette features a robust memory function that saves your game progress automatically, allowing you to resume where you left off without losing any data.

### Conclusion
Whether you’re a seasoned marksman or a newcomer, Buckshot-Roulette offers a captivating blend of suspense and excitement, fostering camaraderie and unforgettable moments.

## 3. How to Play Our Game
### 3.1 Basic Rules
- Two-player game with a set amount of lives (default = 4).
- A shotgun is loaded with a disclosed number of bullets, including blanks.
- Players take turns shooting, aiming at either the opponent or themselves (shooting self with a blank skips the opponent's turn).
- Special items are available to assist players:
  - **CIGARETTE**: Grants an extra life.
  - **BEER**: Discards the bullet in the shotgun.
  - **SAW**: Doubles damage for one turn.
  - **MAGNIFIER**: Reveals the bullet in the chamber.
  - **HANDCUFFS**: Prevents the opponent from taking their next turn.

### 3.2 Quick DEMO
- [Video Demo](https://youtu.be/9pU-0DAcSxM)

### 3.3 Compilation and Execution Instructions
make all
./main

## 4. About our program
### 4.1 List of Features
- **Generation of Random Events**: 
- **Data Structures for Storing Data**:
  - **Class**: `shotgun`, `player` (in `game.cpp`)
  - **Struct**: `letter` (in `display.cpp`)
- **Dynamic Memory Management**: Used for storing the number of bullets.
- **File Input/Output**: 
  - Reading/storing data from `Player1_save_data.dat`, `Player2_save_data.dat`, `Save_Statue`.
- **Program Codes in Multiple Files**: 
  - The main files in our program are: `game.cpp`, `start.cpp`, `display.cpp`, `save.cpp`, with `main.cpp` used to run the program.
- **Proper Indentation and Naming Styles**: Variable names reflect their usage clearly.
- **In-code Documentation**: Provides clarity and understanding of the code.

### 4.2 List of Non-standard C/C++ Libraries
*(Details to be provided)*

### 4.3 Introduction About Each Program
- **start.cpp & game.cpp**: 
  - These programs achieve all rules and support both PvP and PvE patterns. They read player input and manage the process of each turn.
  
- **save.cpp**: 
  - This program saves all data (Player 1 data, Player 2 data, game status) into the game's database.

- **display.cpp**: 
  - This program reads output from `game.cpp` and `start.cpp`, providing different interfaces to show players the updated information.
