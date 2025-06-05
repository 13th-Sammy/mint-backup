# flappy-bird
My First Game, and First Project

# General Info
Language - C++ <br>
To Compile, Run > g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system <br>
Multimedia Library used - Simple and Fast Multimedia Library (SFML)

# Code Structure
> Load all sprites <br>
> gameover flag set to false <br>
> Open Game Window <br>
> While (Game Window is Open), write all game code inside <br>
> Event Handler loop to check for events like close signal,<br>
restart (changes gameover from true to false), or space-press <br>
> Out side event handler loop - if (gameover == false), all <br>
movement code inside + conditions for setting gameover = true, <br>
such as bird going off screen or collision. <br>
> Then, draw all sprites every frame with window.draw() while <br>
inside gamewindow==open loop. type it between window.clear() and <br>
window.display(); to clear screen and swap front-back buffers respectively 

Random Pipes Implementation - <br>
> Create random number generator within range, <br>
this is y position of gap <br>
> y of gap -/+ gapsize/2 = pipe y position; <br>
- for up, top pipes and + for down, bottom pipes <br>
> Implement these y values in setPosition(x, y) for movement, <br>
restart, and initial position codes for pipe sprites

Scoring System Implementation - <br>
> Create a score variable <br>
> If bird-position.x is pipe-position.x + pipe-width, score++ <br>
> Two bool variables check if score has increased for either pipe, <br>
and only if they are false, the score check is done. They are <br>
set to false everytime a pipe recycles and set to true everytime the <br>
bird scores <br>
> Additional adjustments to restart block to reset score <br>
> Simple terminal output for now