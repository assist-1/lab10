#include <iostream>
#include "node.h"
#include "deck.h"



int main()
{
    Deck<int> deck;
    deck.push_front(3);
    deck.push_back(2);
    deck.push_front(4);
    deck.push_back(1);
    //1234

    std::cout << deck << '\n' << std::endl;


    std::cout << "size = " << deck.get_size() << std::endl;

    for(int i = 0; i < 4; i++)
    {
        std::cout << deck.get_front() << std::endl;
        deck.pop_front();
    }
}

