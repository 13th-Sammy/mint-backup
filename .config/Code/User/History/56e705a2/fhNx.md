# flappy-bird
fuck it, flappy bird.

This repository will contain the source code in C++. <br>
Wherever it is compiled, the binary will work on that system. 

For my 2D graphics library, i will be using SFML. <br>
Simple and Fast Multimedia Library (SFML).

RenderWindow class objects are a window. <br>
They need a resolution and window name to be initialised <br>
and automatically open a window upon initialisation.

We will be using while(window.isopen() == true) and putting all our code inside. <br>
An Event class is used to handle events inside this window. <br>
The object of Event class automatically stores whatever keyboard or mouse input.

Inside window-open, we use pollevent to constantly check for new events and <br>
update the event object with new events, if any. If the new event was a close signal, <br>
we close the window.