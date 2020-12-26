#define FRAME_RATE_LIMIT 60

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900

#define BOARD_SIZE 800

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Board.h"
#include "Cursor.h"
#include "Game.h"

#define WINDOW_ICON_PATH "Graphics/Icon/Icon16x16.png"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chess" , sf::Style::Close);
    window.setFramerateLimit(FRAME_RATE_LIMIT);
    sf::Event event;


    // Icon Setup
    sf::Image icon;
    if (!(icon.loadFromFile(WINDOW_ICON_PATH))) // rethink
    {
        std::cout<<"[WARNING]: Image not found: "<<WINDOW_ICON_PATH<<'\n';
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    // Object Initialization
    Board board;
    board.initialize(BOARD_SIZE, sf::Vector2i({(SCREEN_WIDTH-BOARD_SIZE)/2,(SCREEN_HEIGHT - BOARD_SIZE) / 2}));


    Cursor cursor;
    cursor.initialize();
    
    // Figures Arranging
    Game game;
    game.arrangeFigures(board);

    while (true)
    {
        window.clear(sf::Color::Black);
        window.pollEvent(event);

        if (event.type == sf::Event::Closed)
        {

            window.close();
            std::cout<<"[INFO]: Window closed.\n";
            break;

        }
        else
        {

            board.draw(window);

            for (int z = 0; z < 3; z++)
            {
                for (int i = 0; i < game.pieces.size(); i++)
                {
                    if (game.pieces[i]->getZ() == z)
                    {
                        game.pieces[i]->raise(cursor, game.arrangement, board);
                        game.pieces[i]->updatePiece(window);
                    }
                }
            }

            cursor.update(window);

        }

        window.display();
    }

    return EXIT_SUCCESS;
}