#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
using namespace sf; 
using std::cout;
using std::cin;
using std::endl;
int main()
{
    Texture birdTexture, backgroundTexture;
    birdTexture.loadFromFile("assets/bird.png");  //load bird texture
    Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(300, 450); //set bird texture and initial position to sprite
    backgroundTexture.loadFromFile("assets/background.png"); //load background texture
    Sprite background;
    background.setTexture(backgroundTexture); //set background texture to sprite
    float birdVelocity = 0.25; //downwards bird velocity
    //Create a Game Window
    RenderWindow window(VideoMode(1600, 900), "Flappy Bird");
    while (window.isOpen() == true)
    {
        //add game logic here
        Event event; //stores events like key-presses
        while(window.pollEvent(event) == true) //enters loop if there are new events, updates event object
        {
            if(event.type == Event::Closed)
                window.close(); //if closed signal, close window, loop won't repeat
            else if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Space)
                    bird.setPosition(bird.getPosition().x, bird.getPosition().y - 150);
            }
        } 
        //Non event based code outside, event based code inside pollevent(event)==true loop
        bird.setPosition(bird.getPosition().x, bird.getPosition().y + birdVelocity); // position of bird goes down every frame
        //DRAW EVERYTHING ON SCREEN, CONTINUOUSLY -
        window.clear(); //clear window every frame
        window.draw(background);
        window.draw(bird); //draw bird, all drawing must be between window.clear and display
        window.display(); // swap front and back buffers, continuity between frames thing
    }
    return 0;
}