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
    float birdVelocity = 0.25; 
    bool gameover = false;

    // Load Bird
    birdTexture.loadFromFile("assets/bird.png"); 
    Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(700, 450); 

    // Load Background
    backgroundTexture.loadFromFile("assets/background.png"); 
    Sprite background;
    background.setTexture(backgroundTexture); 

    // Load pipes
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

    //Create a Game Window
    RenderWindow window(VideoMode(1600, 900), "Flappy Bird"); 

    // Game Logic inside this while loop
    while (window.isOpen() == true)
    {
        // Event Handler Loop
        Event event;
        while(window.pollEvent(event) == true) 
        {
            // Checks for Close Signal
            if(event.type == Event::Closed)
                window.close(); 

            // Checks for Game Over and Restarts Game
            if (gameover == true)
            {   
                if(event.type == Event::KeyPressed)
                {
                    if(event.key.code == Keyboard::Space)
                    {
                        bird.setPosition(bird.getPosition().x, bird.getPosition().y - 125);
                        gameover = false;
                    }    
                }
            }
            
            // Checks for Space press
            else if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Space)
                    bird.setPosition(bird.getPosition().x, bird.getPosition().y - 125);
            }
        } 

        // Non Event based code under -

        // If gameover == false, all movement code inside -
        if(gameover == false)
        {
            // Bird Gravity -
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

            // If bird falls down, further movement stops
            if (bird.getPosition().y > 900) 
                gameover = true;

            // Collision detection
            if(bird.getGlobalBounds().intersects(tpipe1.getGlobalBounds()) ||
            bird.getGlobalBounds().intersects(tpipe2.getGlobalBounds()) ||
            bird.getGlobalBounds().intersects(bpipe1.getGlobalBounds()) ||
            bird.getGlobalBounds().intersects(bpipe2.getGlobalBounds()))
                gameover = true;
        }
        
        // Draw everything on Screen continuously -
        window.clear(); // This clears screen every frame
        // All Draw must be between clear() and display()
        window.draw(background);
        window.draw(tpipe1);
        window.draw(tpipe2);
        window.draw(bpipe1);
        window.draw(bpipe2);
        window.draw(bird);
        window.display(); // This swaps front and back buffers for continuity
    }
    return 0;
}