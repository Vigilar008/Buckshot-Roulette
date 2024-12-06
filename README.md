1. OUR TEAM
   Liao Wang    3036126953
   Liu Hongkai  3036127763
   Wang Zijie   3036126953
   Wang Jinghan 3036128561


2. A description of our application.
   Buckshot-Roulette is an innovative and exhilarating game that combines elements of strategy, skill, and chance, offering players a unique and thrilling experience. Inspired by the high-stakes tension of traditional Russian roulette and incorporating the dynamic nature of shooting sports, Buckshot-Roulette is designed to test players' nerves, precision, and decision-making abilities.

   In Buckshot-Roulette, players take turns engaging in a series of shooting challenges, each designed to simulate the intense, unpredictable environment of a high-stakes showdown. The game typically involves a specially designed target setup and various types of ammunition, adding layers of complexity and excitement to each round. Players must carefully balance their aim and timing, all while dealing with the psychological pressure of the roulette-style randomization that determines their targets and challenges

   The rules of Buckshot-Roulette are straightforward yet flexible, allowing for a wide range of variations and customizations. This adaptability makes it suitable for casual play among friends as well as competitive tournaments. The game encourages participants to hone their shooting skills, develop strategic thinking, and embrace the thrill of uncertainty.

   Safety is a paramount concern in Buckshot-Roulette, with strict guidelines and protocols in place to ensure that all participants can enjoy the game in a secure and controlled environment. This includes the use of appropriate safety gear, supervised play areas, and adherence to best practices in handling firearms or alternative shooting equipment.

   Whether you're a seasoned marksman or a newcomer looking for an adrenaline-pumping experience, Buckshot-Roulette offers a captivating blend of suspense and excitement. It’s a game that demands focus, fosters camaraderie, and delivers unforgettable moments of triumph and tension.

   and here are What we acheved
       a. first of all, all the rules in part 3.1 have acheved.
       
       b. In Buckshot-Roulette, we offer two distinct game modes designed to cater to different playstyles and preferences: Player vs. Player (PvP) and Player vs.   Environment (PvE). These modes ensure that players can enjoy the game regardless of whether they are looking for competitive interaction with friends or a challenging solo experience against our sophisticated algorithm.                                                                                              In the PvP mode, players can engage in head-to-head matches that test their skills, strategy, and mental fortitude against one another. This mode is perfect for friendly competition, allowing players to experience the thrill of outmaneuvering and outshooting their opponents in real-time. Whether it's a casual match or an intense tournament, the PvP mode fosters camaraderie and rivalry, making each game session uniquely exciting.
       On the other hand, the PvE mode provides an equally engaging experience for solo players. Here, participants take on our advanced AI algorithm, designed to simulate the unpredictability and challenge of a human opponent. The AI adapts to the player's skill level, ensuring that the game remains challenging and stimulating. This mode is ideal for those who prefer to hone their skills alone, practice their strategies, or simply enjoy the game at their own pace without the need for additional players.
       With these two versatile game modes, Buckshot-Roulette accommodates various player scenarios and preferences. Whether you're hosting a game night with friends or looking for a solo challenge, you can always find an exciting and satisfying way to play. So, don’t worry about the number of players available—our game is designed to deliver maximum enjoyment and challenge, no matter the circumstances   

       c. Lastly, Buckshot-Roulette boasts robust memory functions designed to enhance your gaming experience. We understand that life can be unpredictable, and there are times when you may need to pause your game to attend to important matters. Whether it's an unexpected phone call, a sudden appointment, or any other interruption, you can rest assured that your progress in Buckshot-Roulette is safe.
       Our game features an advanced save system that automatically records all relevant data into our secure database whenever you close the game. This includes your current game state, scores, achievements, and any other pertinent information. The next time you open Buckshot-Roulette, you will have the convenient option to resume exactly where you left off. This seamless continuity ensures that you can pick up right from the last moment of action without losing any progress or having to start over.
       The memory function is designed with user convenience in mind, providing a hassle-free way to manage your gaming sessions. Whether you are in the middle of an intense PvP battle or a challenging PvE mission, you can pause the game with confidence, knowing that all your efforts are preserved. This feature not only adds flexibility to your gaming experience but also ensures that you can enjoy the game at your own pace, without feeling rushed or pressured.
       Our commitment to providing a user-friendly and enjoyable experience extends to every aspect of Buckshot-Roulette. The memory function is just one of the many ways we strive to make our game accessible and accommodating to players with busy and dynamic lifestyles. So, go ahead and dive into the thrilling world of Buckshot-Roulette, knowing that your progress is always secure and ready for you whenever you are.


3. How to play our games
   3.1 Basic rules
       a. It is a two player game and participants are given a set amount of lives (default = 4) to survive.
       b. A shotgun is loaded with a disclosed number of bullets, some of which will be blanks.  
       c. Participants will take turns shooting. They can try to aim at the enemy or at yourself - shooting yourself with a blank skips the enemy's turn.
       d. Participants are given items to help out. Use them wisely.
          item1: CIGARETTE = Gives the user an extra life.
          item2: BEER = Racks the shotgun and the bullet inside will be discarded.
          item3: SAW = Shotgun will deal double damage for one turn.
          item4: MAGNIFIER = User will see what bullet is in the chamber.
          item5: HANDCUFFS = Handcuffs the other person so they miss their next turn.
   3.2 Quick DEMO
       video links = https://youtu.be/9pU-0DAcSxM
   3.3 Compilation and execution instructions

       make all
       ./main
       


4. About our program
    4.1 List of features
        a. Generation of random events: 
        b. Data structures for storing data:
            class : shortgun , player (in game.cpp)
            struct: letter (in display.cpp)
        c. Dynamic memory management
            used in storing number of bullet
        d. File input/output
            reading/storing data from Player1_save_data.dat / Player2_save_data.dat / Save_Statue
        e. Program codes in multiple files
            there are four main files in our program: game.cpp / start.cpp / display.cpp / save.cpp and then use main.cpp to run
        f. Proper indentation and naming styles
            you can see that the variable's name in our gp is always showing its usage
        g. In-code documentation
    
    4.2 List of non-standard C/C++ libraries


    4.3 Introduction about each program
        a. start.cpp & game.cpp 
           this program achieve all those rules and support both pvp and pve pattern.
           read players' input and conduct the process of every turn
        b. save.cpp 
           this program save all the data( data of player1, data of player2, game statue) into our game's database
        c. display.cpp
           this program read output from game.cpp&start.cpp and output different interface to show palyers the updated information.

