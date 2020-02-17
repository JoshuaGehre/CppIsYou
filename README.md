# CppIsYou
CppIsYou is a puzzle game, vaguely based on the idea of the game BabaIsYou. However, in CppIsYou the level is the code of the game itself. You will need to have at least some basic knowledge about the C++ programming language for all levels, while certain levels utilize more advanced mechanics. Note that this game was not designed for everyone to be able to complete all levels on their own, but instead use this mechanic as best I could. 
CppIsYou consist of 12 regular levels, 3 extra levels that are similar to another level but use some other mechanics and will probably be more difficult. Plus there is Level 0 of figuring out how to run this game in the first place.

**Warning:** This game will expose you to some very bad coding behaviors you should never use in any other situation when programming!

# How to play
After cloning this repository run Setup.sh this will copy the Move.sh and Restart.sh script into the folders of each level.

If you want to play a level, first run the Restart.sh script this will create a copy of the code of the level.
Your goal then is to get the game to call the levelComplete() method, by only repeatedly executing Move.sh with different arguments. Each time CppIsYou.cpp will be compiled, executed with the same arguments you provided to the bash script, this will cause the game to load and modify its own code, after that the compiled version will be deleted again!
If you create a version of the source code that does not compile you can no longer progress and will need to restart the level. You can of course reset the level using Restart.sh at any point in time.

As you will modify the code of the game while playing, I cannot guarantee for the safety of any code you might be able to create while playing. Play this game at your own risk!

# Help other people to pass Level 0
This puzzle game was completely made on Linux and meant to be played from the command line, requiring the g++ compiler.
If you know how to create equivalent scripts so that people for example on Windows are also able to play this please let know.

# Credits
In case anyone else decides to create levels for this game.

| Level | Creator |
| ----- | ------- |
| 1 - 12 | Joshua Gehre |
| 1 Extra | Joshua Gehre |
| 3 Extra | Joshua Gehre |
| 8 Extra | Joshua Gehre |
