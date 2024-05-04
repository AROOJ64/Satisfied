#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include<SFML/System.hpp>
#include "Sound.h"
#include "Menu.h"
#include "Player.h"
#include "Product.h"
#include "Weapon.h"

using namespace std;
using namespace sf;

int pageNum = 10;

void PName(RenderWindow& window, string& name);
void Intro(RenderWindow& window);
void Game_Play(RenderWindow& window);
void End_Game(RenderWindow& window);
void Win_Game(RenderWindow& window);

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Satisfied?", Style::Fullscreen);

    Font font;
    font.loadFromFile("Looking forward to the weekend.ttf");

    Texture menuTex;
    menuTex.loadFromFile("main.png");
    Sprite background;
    background.setTexture(menuTex);
    string name;

    sound soundMenu;
    soundMenu.loadSound("Main-Menu.wav");
    soundMenu.playSound();

    Menu MainMenu(1920, 1080, font);

    while (true) {
        if (pageNum == 10) {
            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) {
                        window.close();
                        break;
                    }

                    if (event.type == Event::KeyPressed) {
                        if (event.key.code == Keyboard::Up) {
                            MainMenu.moveUp();
                        }

                        if (event.key.code == Keyboard::Down) {
                            MainMenu.moveDown();
                        }

                        if (event.key.code == Keyboard::Return) {
                            if (MainMenu.pressed() == 0) {
                                pageNum = 0;
                            }

                            if (MainMenu.pressed() == 1) {
                                pageNum = -1;
                            }
                        }
                    }
                }

                window.clear();
                if (pageNum != 10) {
                    break;
                }
                window.draw(background);
                MainMenu.draw(window);
                window.display();
            }
            if (pageNum == -1) {
                window.close();
                break;
            }

            if (pageNum == 0) {
                PName(window, name);
            }

            if (pageNum == 2) {
                soundMenu.stopSound();
                Intro(window);
            }

            if (pageNum == 3) {
                Game_Play(window);
            }

            if (pageNum == 4) {
                End_Game(window);
            }

            if (pageNum == 5) {
                Win_Game(window);
            }
        }
    }
    return 0;
}

void PName(RenderWindow& window, string& name) {
    if (!name.empty()) {
        name.clear();
    }
    Texture background;
    background.loadFromFile("main2.jpg");
    Sprite bg;
    bg.setTexture(background);
    Font font2;
    font2.loadFromFile("Looking forward to the weekend.ttf");
    
    Text title;
    Text t1;
    Text t2;
    title.setFont(font2);
    t1.setFont(font2);
    t2.setFont(font2);
    title.setCharacterSize(120);
    t1.setCharacterSize(70);
    t2.setCharacterSize(70);
    title.setPosition(10, 10);
    t1.setPosition(20, 20);
    t2.setPosition(20, 200);
    title.setFillColor(Color::Red);
    t1.setFillColor(Color::Red);
    t2.setFillColor(Color::Red);
    title.setString("Enter Your Name");
    title.setStyle(Text::Bold);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed()) {
                window.close();
            }
            if (event.type == Event::TextEntered) {
                name += static_cast<char>(event.text.unicode);
            }
            if (Keyboard::isKeyPressed(Keyboard::Backspace) && name.size() > 0) {
                name.resize(name.size() - 1);
            }
            if (Keyboard::isKeyPressed(Keyboard::Return) && name.size() > 1) {
                pageNum = 2;
                return;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                pageNum = 10;
                return;
            }
        }
        t2.setString(name);
        window.clear();
        window.draw(bg);
        window.draw(title);
        window.draw(t1);
        window.draw(t2);
        window.display();
    }
}

void Intro(RenderWindow& window) {

    sound soundIntro;
    soundIntro.loadSound("gameplay.wav");
    soundIntro.playSound();

    Font font2;
    font2.loadFromFile("Looking forward to the weekend.ttf");

    Text start;
    start.setFont(font2);
    start.setCharacterSize(90);
    start.setPosition(50, 50);
    start.setFillColor(Color::Red);
    start.setString("Intro Scene");
    start.setStyle(Text::Bold);

    Text middle;
    middle.setFont(font2);
    middle.setCharacterSize(30);
    middle.setPosition(1500, 1000);
    middle.setFillColor(Color::Red);
    middle.setString("Click Enter to Skip");

    sf::Texture Background1;
    Background1.loadFromFile("1.png");
    sf::Texture Background2;
    Background2.loadFromFile("2.png");
    sf::Texture Background3;
    Background3.loadFromFile("3.png");
    sf::Texture Background4;
    Background4.loadFromFile("4.png");
    sf::Texture Background5;
    Background5.loadFromFile("5.png");
    sf::Texture Background6;
    Background6.loadFromFile("6.png");
    sf::Texture Background7;
    Background7.loadFromFile("7.png");

    sf::Sprite sprite1;
    sprite1.setTexture(Background1);
    sf::Sprite sprite2;
    sprite2.setTexture(Background2);
    sf::Sprite sprite3;
    sprite3.setTexture(Background3);
    sf::Sprite sprite4;
    sprite4.setTexture(Background4);
    sf::Sprite sprite5;
    sprite5.setTexture(Background5);
    sf::Sprite sprite6;
    sprite6.setTexture(Background6);
    sf::Sprite sprite7;
    sprite7.setTexture(Background7);

    sf::Texture playerTex;
    playerTex.loadFromFile("Full_white.png");

    Player player(playerTex, 100, 800);
    
    sf::Clock clock;
    float Time = 0;
    float DeltaTime = 0;
    float Speed = 15;
    sf::Vector2f Position1(0, 0);
    sf::Vector2f Position2(0, 0);
    sf::Vector2f Position3(0, 0);
    sf::Vector2f Position4(0, 0);
    sf::Vector2f Position5(0, 0);
    sf::Vector2f Position6(0, 0);
    sf::Vector2f Position7(0, 0);

    while (window.isOpen()) {
        float CurrentTime = clock.getElapsedTime().asSeconds();
        DeltaTime = CurrentTime - Time;
        Time = CurrentTime;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (Keyboard::isKeyPressed(Keyboard::Return)) {
                pageNum = 3;
                return;
            }
        }
        Position1.x -= (Speed * 2) * DeltaTime;
        Position2.x -= (Speed * 1.8) * DeltaTime;
        Position3.x -= (Speed * 2) * DeltaTime;
        Position4.x -= (Speed * 1.9) * DeltaTime;
        Position5.x -= (Speed * 2) * DeltaTime;
        Position6.x -= (Speed * 1.9) * DeltaTime;
        Position7.x -= (Speed * 2) * DeltaTime;
        
        if (Position1.x <= -1920) {
            Position1.x = -1920;
        }
        if (Position2.x <= -1920) {
            Position2.x = -1920;
            Speed = 0;
        }
        if (Position3.x <= -1920) {
            Position3.x = -1920;
        }
        if (Position4.x <= -1920) {
            Position4.x = -1920;
        }
        if (Position5.x <= -1920) {
            Position5.x = -1920;
        }
        if (Position6.x <= -1920) {
            Position6.x = -1920;
        }
        if (Position7.x <= -1920) {
            Position7.x = -1920;
        }

        window.clear();
        window.draw(sprite1);
        sprite1.setPosition(Position1);
        window.draw(sprite2);
        sprite2.setPosition(Position2);
        window.draw(sprite3);
        sprite3.setPosition(Position3);
        window.draw(sprite4);
        sprite4.setPosition(Position4);
        window.draw(sprite5);
        sprite5.setPosition(Position5);
        window.draw(sprite6);
        sprite6.setPosition(Position6);
        window.draw(sprite7);
        sprite7.setPosition(Position7);

        if (Speed <= 0)
        {
            sleep(seconds(5));
            pageNum = 3;
            return;           
        }
        player.draw(window);
        window.draw(start);
        window.draw(middle);
        window.display();
    }
}

void Game_Play(RenderWindow& window) {

    sound soundGame;
    soundGame.loadSound("gameplay.wav");
    soundGame.playSound();

    sound rocketFall;
    rocketFall.loadSound("ROCKET FALL.wav");

    sound rocketExplosion;
    rocketExplosion.loadSound("Explosion.wav");

    sf::Texture Background1;
    Background1.loadFromFile("01.png");
    sf::Texture Background2;
    Background2.loadFromFile("02.png");
    sf::Texture Background3;
    Background3.loadFromFile("03.png");
    sf::Texture Background4;
    Background4.loadFromFile("04.png");
    sf::Texture Background5;
    Background5.loadFromFile("05.png");
    sf::Texture Background6;
    Background6.loadFromFile("06.png");

    sf::Sprite sprite1;
    sprite1.setTexture(Background1);
    sf::Sprite sprite2;
    sprite2.setTexture(Background2);
    sf::Sprite sprite3;
    sprite3.setTexture(Background3);
    sf::Sprite sprite4;
    sprite4.setTexture(Background4);
    sf::Sprite sprite5;
    sprite5.setTexture(Background5);
    sf::Sprite sprite6;
    sprite6.setTexture(Background6);

    sf::RectangleShape wall(sf::Vector2f(10, 1080));
    wall.setFillColor(sf::Color::Black);
    wall.setPosition(-10, 0);

    sf::RectangleShape end(sf::Vector2f(10, 1080));
    end.setFillColor(sf::Color::Black);
    end.setPosition(1930, 0);

    sf::Clock clock;
    float Time = 0;
    float DeltaTime = 0;
    float Speed = 50;
    sf::Vector2f Position1(0, 0);
    sf::Vector2f Position2(0, 0);
    sf::Vector2f Position3(0, 0);
    sf::Vector2f Position4(0, 0);
    sf::Vector2f Position5(0, 0);
    sf::Vector2f Position6(0, 0);

    sf::Vector2f Position11(1919, 0);
    sf::Vector2f Position22(1919, 0);
    sf::Vector2f Position33(1919, 0);
    sf::Vector2f Position44(1919, 0);
    sf::Vector2f Position55(1919, 0);
    sf::Vector2f Position66(1919, 0);

    sf::Texture playerTex1;
    playerTex1.loadFromFile("Walking_Black.png");
    sf::Texture playerTex2;
    playerTex2.loadFromFile("Walking_White.png");

    sf::Texture pepsiTex;
    pepsiTex.loadFromFile("Pepsi.png");
    sf::Texture macTex;
    macTex.loadFromFile("Fries.png");
    sf::Texture starbucksTex;
    starbucksTex.loadFromFile("Star.png");
    sf::Texture rocketTex;
    rocketTex.loadFromFile("Rocket.png");

    Player player1(playerTex1, 0, 260);
    Player player2(playerTex2, 0, 800);

    Product pepsi(pepsiTex, 350, 430);
    Product fries(macTex, 800, 120);
    Product star(starbucksTex, 1300, 150);
    Weapon rocket(rocketTex, player2.getPosition().x, 0);
    
    bool pepsiVisible = true;
    bool friesVisible = true;
    bool starVisible = true;
    bool rocketVisible = false;
    float playerSpeed = 60;
    float jumpSpeed = 185.0f;

    while (window.isOpen()) {

        float CurrentTime = clock.getElapsedTime().asSeconds();
        DeltaTime = CurrentTime - Time;
        Time = CurrentTime;

        sf::Event event;

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            player1.jump(jumpSpeed);
            player2.jump(jumpSpeed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player1.move(-playerSpeed);
            player2.move(-playerSpeed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player1.move(playerSpeed);
            player2.move(playerSpeed);
        }
        else {
            player1.move(0.0f);
            player2.move(0.0f);
        }

        player1.update(0.016f, 260.0f);
        player2.update(0.016f, 800.0f);
        rocket.update(0.016f, player2.getPosition());
        pepsi.animate();
        star.animate();
        fries.animate();

        Position1.x -= (Speed) * DeltaTime;
        Position2.x -= (Speed)*DeltaTime;
        Position3.x -= (Speed * 1.5) * DeltaTime;
        Position4.x -= (Speed * 2) * DeltaTime;
        Position5.x -= (Speed * 2.5) * DeltaTime;
        Position6.x -= (Speed * 3) * DeltaTime;
        
        Position11.x -= (Speed) * DeltaTime;
        Position22.x -= (Speed * 1) * DeltaTime;
        Position33.x -= (Speed * 1.5) * DeltaTime;
        Position44.x -= (Speed * 2) * DeltaTime;
        Position55.x -= (Speed * 2.5) * DeltaTime;
        Position66.x -= (Speed * 3) * DeltaTime;
        

        if (Position1.x <= -1919) {
            Position1.x = 1919;
        }
        if (Position2.x <= -1919) {
            Position2.x = 1919;
        }
        if (Position3.x <= -1919) {
            Position3.x = 1919;
        }
        if (Position4.x <= -1919) {
            Position4.x = 1919;
        }
        if (Position5.x <= -1919) {
            Position5.x = 1919;
        }
        if (Position6.x <= -1919) {
            Position6.x = 1919;
        }
        
        if (Position11.x <= -1919) {
            Position11.x = 1919;
        }
        if (Position22.x <= -1919) {
            Position22.x = 1919;
        }
        if (Position33.x <= -1919) {
            Position33.x = 1919;
        }
        if (Position44.x <= -1919) {
            Position44.x = 1919;
        }
        if (Position55.x <= -1919) {
            Position55.x = 1919;
        }
        if (Position66.x <= -1919) {
            Position66.x = 1919;
        }

        window.clear();
        window.draw(sprite1);
        sprite1.setPosition(Position1);
        window.draw(sprite1);
        sprite1.setPosition(Position11);
        window.draw(sprite2);
        sprite2.setPosition(Position2);
        window.draw(sprite2);
        sprite2.setPosition(Position22);
        window.draw(sprite3);
        sprite3.setPosition(Position3);
        window.draw(sprite3);
        sprite3.setPosition(Position33);
        window.draw(sprite4);
        sprite4.setPosition(Position4);
        window.draw(sprite4);
        sprite4.setPosition(Position44);
        window.draw(sprite5);
        sprite5.setPosition(Position5);
        window.draw(sprite5);
        sprite5.setPosition(Position55);
        window.draw(sprite6);
        sprite6.setPosition(Position6);
        window.draw(sprite6);
        sprite6.setPosition(Position66);
        
        if (pepsi.isColliding(player1.GetPlayerBounds()) && pepsiVisible == true || fries.isColliding(player1.GetPlayerBounds()) && friesVisible == true || star.isColliding(player1.GetPlayerBounds()) && starVisible == true) {
            
            if (pepsi.isColliding(player1.GetPlayerBounds()) == true) {
                pepsiVisible = false;
            }
            else if (fries.isColliding(player1.GetPlayerBounds()) == true) {
                friesVisible = false;
            }
            else if (star.isColliding(player1.GetPlayerBounds()) == true) {
                starVisible = false;
            }
            rocketVisible = true;
            rocket.setPosition(player2.getPosition().x, 0);
        }

        if (pepsiVisible) {
            pepsi.draw(window);
        }
        if (friesVisible) {
            fries.draw(window);
        }
        if (starVisible) {
            star.draw(window);
        }
        if (rocketVisible) {
            soundGame.stopSound();
            rocketFall.playSound();
            rocket.draw(window);
            rocket.animate();
            rocket.move(20);
            
            if (rocket.isColliding(player2.GetPlayerBounds())) {
                rocketFall.stopSound();
                rocketExplosion.playSound();
                rocketVisible = false;
                pageNum = 4;
                return;
            }

        }

        if (wall.getGlobalBounds().intersects(player1.GetPlayerBounds()) || wall.getGlobalBounds().intersects(player2.GetPlayerBounds())) {
            sf::Vector2f startPosition1(0, 260);
            sf::Vector2f startPosition2(0, 800);
            player1.setPosition(startPosition1);
            player2.setPosition(startPosition2);
        }

        if (end.getGlobalBounds().intersects(player1.GetPlayerBounds()) || end.getGlobalBounds().intersects(player2.GetPlayerBounds())) {
            pageNum = 5;
            return;
        }

        player1.draw(window);
        player2.draw(window);
        window.draw(wall);
        window.draw(end);
        window.display();
    }
}

void End_Game(RenderWindow& window) {
    Texture background;
    background.loadFromFile("main2.jpg");
    Sprite bg;
    bg.setTexture(background);
    Font font2;
    font2.loadFromFile("Looking forward to the weekend.ttf");

    Text start;
    start.setFont(font2);
    start.setCharacterSize(90);
    start.setPosition(20, 20);
    start.setFillColor(Color::Red);
    start.setString("Are you Satisfied?");
    start.setStyle(Text::Bold);

    Text middle;
    middle.setFont(font2);
    middle.setCharacterSize(30);
    middle.setPosition(20, 200);
    middle.setFillColor(Color::Red);
    middle.setString({"Most of the brands we used to love, contribute to the daily killing of thousands of innocent lives.\nThe little we can do is to boycott.\n"
                      "These children don’t deserve what they are experiencing.\n"
                      "Remember these children, teenagers and old people all have names.\nThey all have families and they are not just numbers.\n"
                      "Roses are red?! It is but not in Gaza, every thing is red especially humans blood."});
    middle.setStyle(Text::Bold);

    Text end;
    end.setFont(font2);
    end.setCharacterSize(100);
    end.setPosition(20, 600);
    end.setFillColor(Color::Red);
    end.setString("         ARE YOU SATISFIED?");
    end.setStyle(Text::Bold);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed()) {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Return) || Keyboard::isKeyPressed(Keyboard::Escape)) {
                pageNum = 10;
                return;
            }
        }
        window.clear();
        window.draw(bg);
        window.draw(start);
        window.draw(middle);
        window.draw(end);
        window.display();
    }
}

void Win_Game(RenderWindow& window) {
    Texture background;
    background.loadFromFile("main2.jpg");
    Sprite bg;
    bg.setTexture(background);
    Font font2;
    font2.loadFromFile("Looking forward to the weekend.ttf");

    Text start;
    start.setFont(font2);
    start.setCharacterSize(90);
    start.setPosition(20, 20);
    start.setFillColor(Color::Red);
    start.setString("You Won");
    start.setStyle(Text::Bold);

    Text middle;
    middle.setFont(font2);
    middle.setCharacterSize(30);
    middle.setPosition(20, 200);
    middle.setFillColor(Color::Red);
    middle.setString({ "Thank you for boycotting the products that contribute in the killing of alot of people.\n"
                      "By boycotting their products, you hinder the enemy that kill alot of people.\n"
                      "By boycotting you give hope to the helpless victims and their families.\n"
                      "And for that thank you." });
    middle.setStyle(Text::Bold);

    Text end;
    end.setFont(font2);
    end.setCharacterSize(100);
    end.setPosition(20, 600);
    end.setFillColor(Color::Red);
    end.setString("         YOU SHOULD BE SATISFIED.");
    end.setStyle(Text::Bold);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed()) {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Return) || Keyboard::isKeyPressed(Keyboard::Escape)) {
                pageNum = 10;
                return;
            }
        }
        window.clear();
        window.draw(bg);
        window.draw(start);
        window.draw(middle);
        window.draw(end);
        window.display();
    }
}