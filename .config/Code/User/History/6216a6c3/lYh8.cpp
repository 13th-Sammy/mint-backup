#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
using namespace sf; 
using std::cout;
using std::cin;
using std::endl;
int main()
{
    Texture birdTexture, backgroundTexture, pipeTexture;
    float birdVelocity = 0.25; //downwards bird velocity

    birdTexture.loadFromFile("assets/bird.png");  //load bird texture
    Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(700, 450); //set bird texture and initial position to sprite

    backgroundTexture.loadFromFile("assets/background.png"); //load background texture
    Sprite background;
    background.setTexture(backgroundTexture); //set background texture to sprite

    pipeTexture.loadFromFile("assets/pipeb.png");
    Sprite tpipe1, tpipe2, bpipe1, bpipe2;
    //toppipe1
    tpipe1.setTexture(pipeTexture);
    tpipe1.setScale(1,-1);
    tpipe1.setPosition(1600, tpipe1.getGlobalBounds().height);
    //toppipe2
    tpipe2.setTexture(pipeTexture);
    tpipe2.setScale(1,-1);
    tpipe2.setPosition(2600, tpipe2.getGlobalBounds().height);
    //bottompipe1
    bpipe1.setTexture(pipeTexture);
    bpipe1.setPosition(1600, 900 - bpipe1.getGlobalBounds().height);
    //bottompipe2
    bpipe2.setTexture(pipeTexture);
    bpipe2.setPosition(2600, 900 - bpipe2.getGlobalBounds().height);

    RenderWindow window(VideoMode(1600, 900), "Flappy Bird"); //Create a Game Window

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
                    bird.setPosition(bird.getPosition().x, bird.getPosition().y - 125);
            }
        } 

        //Non event based code outside, event based code inside pollevent(event)==true loop

        bird.setPosition(bird.getPosition().x, bird.getPosition().y + birdVelocity); // position of bird goes down every frame

        //To draw pipes
        tpipe1.move(-0.5,0);
        tpipe2.move(-0.5,0);
        bpipe1.move(-0.5,0);
        bpipe2.move(-0.5,0);
        if(tpipe1.getPosition().x <= -tpipe1.getGlobalBounds().width)
        {
            float rightmostX = std::max(tpipe2.getPosition().x, 1600.0f); // Find rightmost pipe position
            tpipe1.setPosition(rightmostX + 600, tpipe1.getPosition().y);
        }
        if(tpipe2.getPosition().x <= -tpipe2.getGlobalBounds().width)
        {
            float rightmostX = std::max(tpipe1.getPosition().x, 1600.0f);
            tpipe2.setPosition(rightmostX + 600, tpipe2.getPosition().y);
        }
        // Same logic for bottom pipes
        if(bpipe1.getPosition().x <= -bpipe1.getGlobalBounds().width)
        {
            float rightmostX = std::max(bpipe2.getPosition().x, 1600.0f);
            bpipe1.setPosition(rightmostX + 600, bpipe1.getPosition().y);
        }   
        if(bpipe2.getPosition().x <= -bpipe2.getGlobalBounds().width)
        {
            float rightmostX = std::max(bpipe1.getPosition().x, 1600.0f);
            bpipe2.setPosition(rightmostX + 600, bpipe2.getPosition().y);
        }
        
        //DRAW EVERYTHING ON SCREEN, CONTINUOUSLY -
        window.clear(); //clear window every frame
        window.draw(background);
        window.draw(tpipe1);
        window.draw(tpipe2);
        window.draw(bpipe1);
        window.draw(bpipe2);
        window.draw(bird); //draw bird, all drawing must be between window.clear and display
        window.display(); // swap front and back buffers, continuity between frames thing
    }
    return 0;
}