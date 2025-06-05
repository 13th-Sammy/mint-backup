#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<random>
using namespace sf; 
using std::cout;
using std::cin;
using std::endl;
int main()
{
    Texture birdTexture, backgroundTexture, pipeTexture;
    float birdVelocity = 0.25; 
    bool gameover = false;
    int score = 0;
    bool scored1 = false, scored2 = false; // Track if we've scored from each pipe pair

    // Random number generator for pipe gaps
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> gapDist(300, 600); // Gap center between 300-600 pixels from top
    const float GAP_SIZE = 200; // Space between top and bottom pipes

    // Load Bird
    birdTexture.loadFromFile("assets/bird.png"); 
    Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(700, 450);

    // Load Background
    backgroundTexture.loadFromFile("assets/background.png"); 
    Sprite background;
    background.setTexture(backgroundTexture); 

    // Generate random gap positions for two pipes
    float gap1 = gapDist(gen);
    float gap2 = gapDist(gen);

    // Load pipes
    pipeTexture.loadFromFile("assets/pipeb.png");
    Sprite tpipe1, tpipe2, bpipe1, bpipe2;
    tpipe1.setTexture(pipeTexture);
    tpipe1.setScale(1,-1);
    tpipe1.setPosition(1600, gap1 - GAP_SIZE/2);
    //toppipe2
    tpipe2.setTexture(pipeTexture);
    tpipe2.setScale(1,-1);
    tpipe2.setPosition(2600, gap2 - GAP_SIZE/2);
    //bottompipe1
    bpipe1.setTexture(pipeTexture);
    bpipe1.setPosition(1600, gap1 + GAP_SIZE/2);
    //bottompipe2
    bpipe2.setTexture(pipeTexture);
    bpipe2.setPosition(2600, gap2 + GAP_SIZE/2);

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
                        // Set bird to initial position
                        bird.setPosition(700, 450);
                        // Set pipes to initial position
                        gap1 = gapDist(gen);
                        gap2 = gapDist(gen);
                        tpipe1.setPosition(1600, gap1 - GAP_SIZE/2);
                        tpipe2.setPosition(2600, gap2 - GAP_SIZE/2);
                        bpipe1.setPosition(1600, gap1 + GAP_SIZE/2);
                        bpipe2.setPosition(2600, gap2 + GAP_SIZE/2);
                        // Reset Score 
                        score = 0;
                        scored1 = false;
                        scored2 = false;
                        // Change flag so it enters motion block again
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

            // Check if bird passed pipe1 and hasn't scored yet
            if(!scored1 && bird.getPosition().x > tpipe1.getPosition().x + tpipe1.getGlobalBounds().width)
            {
                score++;
                scored1 = true;
            }
            // Check if bird passed pipe2 and hasn't scored yet
            if(!scored2 && bird.getPosition().x > tpipe2.getPosition().x + tpipe2.getGlobalBounds().width)
            {
                score++;
                scored2 = true;
            }
            
            //To draw pipes
            tpipe1.move(-0.5,0);
            tpipe2.move(-0.5,0);
            bpipe1.move(-0.5,0);
            bpipe2.move(-0.5,0);
            if(tpipe1.getPosition().x <= -tpipe1.getGlobalBounds().width)
            {
                float rightmostX = std::max(tpipe2.getPosition().x, 1600.0f);
                float newGap = gapDist(gen);
                tpipe1.setPosition(rightmostX + 600, newGap - GAP_SIZE/2);
                bpipe1.setPosition(rightmostX + 600, newGap + GAP_SIZE/2);
                scored1 = false;
            }
            if(tpipe2.getPosition().x <= -tpipe2.getGlobalBounds().width)
            {
                float rightmostX = std::max(tpipe1.getPosition().x, 1600.0f);
                float newGap = gapDist(gen);
                tpipe2.setPosition(rightmostX + 600, newGap - GAP_SIZE/2);
                bpipe2.setPosition(rightmostX + 600, newGap + GAP_SIZE/2);
                scored2 = false;
            }

            // If bird falls down or goes way up, further movement stops
            if (bird.getPosition().y > 900 || bird.getPosition().y < 0) 
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

        // Show score on console
        static int lastScore = -1;
        if (score != lastScore) 
        {
        cout << "Score: " << score << endl;
        lastScore = score;
        }
    }
    return 0;
}