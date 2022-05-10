#include "Game.h"

#include "../UsefullFunction.hpp"

Game::Game(const float& _window_width, const float& _window_height)
: sf::RenderWindow(sf::VideoMode(1280, 720), "PoP Cat Banditto", sf::Style::Close | sf::Style::Titlebar)
{
    loadResources();
}

void Game::run()
{
    Grid grid(this, T_illuminati, T_reptiloid, T_muskFace, T_muskSmoke, T_oatmealShut, T_oatmealPop);

    sf::SoundBuffer music;
    music.loadFromFile("res/sfx/he_man_whatsup_instrumental.ogg");
    sf::Sound music_player(music);
    music_player.setLoop(true);
    music_player.setVolume(30);

    sf::Sprite bg_sprite(T_background);
    bg_sprite.setScale(float(getSize().x) / T_background.getSize().x, (float)getSize().y / T_background.getSize().y);
    sf::Color bg_color(bg_sprite.getColor().r - 50u, bg_sprite.getColor().g - 50u, bg_sprite.getColor().b - 50u, 255u);
    bg_sprite.setColor(bg_color);

    sf::Sprite frame_sprite(T_frame);
    frame_sprite.setPosition(grid.getX(), grid.getY());
    frame_sprite.setScale(grid.getW() / T_frame.getSize().x, grid.getH() / T_frame.getSize().y);

    Button* btn_start = new Button(std::wstring(L"Start"), sf::Vector2f(100.f, 32.f), sf::Color::White, sf::Color::Black);
    btn_start->setFont(font_cyrilic_old);
    btn_start->setPosition(sf::Vector2f((float)getSize().x - 200.f, 200.f));

    Button* btn_stop = new Button(std::wstring(L"Stop"), sf::Vector2f(100.f, 32.f), sf::Color::White, sf::Color::Black);
    btn_stop->setFont(font_cyrilic_old);
    btn_stop->setPosition(sf::Vector2f((float)getSize().x - 200.f, (float)getSize().y - 200.f));
    btn_stop->setActive(false);

    StateMashine* machina = new StateMashine(grid, btn_start, btn_stop);

    btn_start->setCallback([&]() { machina->start(); });
    btn_stop->setCallback([&]() { machina->stop(); });
    buttons.push_back(btn_start);
    buttons.push_back(btn_stop);

    setActive();
    setFramerateLimit(getScreenFrameRate());
    music_player.play();
    while (isOpen())
    {
        handleEvents(*this, events, *machina);

        machina->update();

        grid.renderFrame();
        
        clear(sf::Color(0u, 0u, 0u, 50u));

        draw(bg_sprite);

        for (auto& it : buttons)
        {
            it->drawTo(this);
        }
        grid.draw();

        draw(frame_sprite);

        display();
    }
    for (auto it = buttons.begin(); it != buttons.end();)
    {
        Button* button = *it;
        it = buttons.erase(it);
        delete button;
    }
}

const sf::SoundBuffer* Game::thePop()
{
    return &pop;
}

const sf::SoundBuffer* Game::theWhu()
{
    return &whu;
}

const sf::SoundBuffer* Game::theIllum()
{
    return &illum;
}

void Game::handleEvents(sf::RenderWindow& _window, sf::Event& events, StateMashine& _machina)
{
    while (_window.pollEvent(events))
    {
        switch (events.type)
        {
        case sf::Event::Closed:
            _window.close();
            break;
        case sf::Event::KeyPressed:
            if (events.key.code == sf::Keyboard::Num1)
            {
            }
            if (events.key.code == sf::Keyboard::Num2)
            {
            }
            break;
        case sf::Event::KeyReleased:
            if (events.key.code == sf::Keyboard::Num1)
            {
            }
            if (events.key.code == sf::Keyboard::Num2)
            {
            }
            break;
        case sf::Event::MouseMoved:
            for (auto& it : buttons)
            {
                if (it->isActive())
                {
                    if (it->isMouseOver(*this))
                    {
                        it->setBackColor(sf::Color::Magenta);
                    }
                    else
                    {
                        it->setBackColor(sf::Color::Cyan);
                    }
                }
                else
                {
                    it->setBackColor(sf::Color::White);
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (events.mouseButton.button == sf::Mouse::Button::Left)
            {
                for (auto& it : buttons)
                {
                    if (it->isHovered())
                    {
                        it->leftClick();
                    }
                }
            }
            break;
        case sf::Event::MouseButtonReleased:
            break;
        default:    // we don't process other types of events
            break;
        }
    }
}

void Game::loadResources()
{
    if (!font_cyrilic_old.loadFromFile("res/fonts/CyrilicOld.TTF"))
    {
        std::cerr << "Failed to load font CyrilicOld.TTF!" << std::endl;
    }
    if (!T_background.loadFromFile("res/textures/meme_wallpaper.jpg"))
    {
        std::cerr << "Failed to load texture meme_wallpaper.jpg" << std::endl;
    }
    if (!T_frame.loadFromFile("res/textures/rainbow_frame.png"))
    {
        std::cerr << "Failed to load texture rainbow_frame.png" << std::endl;
    }
    if (!T_illuminati.loadFromFile("res/textures/illum1.png"))
    {
        std::cerr << "Failed to load texture illum1.png!" << std::endl;
    }
    if (!T_reptiloid.loadFromFile("res/textures/illum2.png"))
    {
        std::cerr << "Failed to load texture illum2.png!" << std::endl;
    }
    if (!T_muskFace.loadFromFile("res/textures/musk1.png"))
    {
        std::cerr << "Failed to load texture musk1.png!" << std::endl;
    }
    if (!T_muskSmoke.loadFromFile("res/textures/musk2.png"))
    {
        std::cerr << "Failed to load texture musk2.png!" << std::endl;
    }
    if (!T_oatmealShut.loadFromFile("res/textures/cat1.png"))
    {
        std::cerr << "Failed to load texture cat1.png!" << std::endl;
    }
    if (!T_oatmealPop.loadFromFile("res/textures/cat2.png"))
    {
        std::cerr << "Failed to load texture cat2.png!" << std::endl;
    }
    pop.loadFromFile("res/sfx/pop.ogg");
    whu.loadFromFile("res/sfx/whu.ogg");
    illum.loadFromFile("res/sfx/illum.ogg");
}
