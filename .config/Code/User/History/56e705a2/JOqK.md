# flappy-bird
fuck it, flappy bird.
No Score System, No Random Pipe Heights.

This repository will contain the source code in C++. <br>
Wherever it is compiled, the binary will work on that system. 

For my 2D graphics library, i will be using SFML. <br>
Simple and Fast Multimedia Library (SFML).

RenderWindow class objects are a window. <br>
They need a resolution and window name to be initialised <br>
and automatically open a window upon initialisation.

We will be using while(window.isopen() == true) and putting all our code inside. <br>
An Event class is used to handle events inside this window. <br>
The object of Event class stores things like key-presses. It is updated by a pollevent() method.

Inside window-open, we use pollevent==true loop to constantly check for new events and <br>
update the event object with new events, if any. If the new event was a close signal, <br>
we close the window.

Event based code will be inside pollevent loop, as everytime there is a new event it is fed <br>
to the object event. Other code like graphics rendering will be outside the pollevent loop.

Before window open, load bird texture in object of Texture class. <br>
Then create an object of sprite class, set its texture to birdTexture and give it a screen position. <br>
Inside window-open, outside pollevent - window.draw(bird). All draw() must be between <br>
clear() and display() for smooth display every frame.

We create a downwards bird velocity variable and every frame add it to y coordinate of <br>
bird position using bird.setposition(bird.getposition().x, bird.getposition().y + birdvelocity).

Inside pollevent loop, if space is pressed, bird position goes up by 150 pixels. 

Added background by just creating a sprite and window.draw(background).

Added 2 pipes, 4 sprites of top and bottom and properly set their positions for drawing().

Added gameover if bird falls down. All movement code is inside if gameover==false. <br>
From here, it's about adding collision detection and fine tuning.