//Board.cpp
#include "Board.h"

Board::Board()
{
    sys = Console("Board");
    initBoard();
    // printBoard();
}

void Board::initBoard()
{
    sys.print("Building Board");
    board.clear();

    // --- BOTTOM ROW (0 to 10) ---
    board.push_back(std::make_unique<Square>(0, "GO", SquareType::Go));
    board.push_back(std::make_unique<PropertySquare>(1, "Mediterranean Avenue", 60, std::array<int, 6>{2, 10, 30, 90, 160, 250}));
    board.push_back(std::make_unique<Square>(2, "Community Chest", SquareType::CommunityChest));
    board.push_back(std::make_unique<PropertySquare>(3, "Baltic Avenue", 60, std::array<int, 6>{4, 20, 60, 180, 320, 450}));
    board.push_back(std::make_unique<TaxSquare>(4, "Income Tax", 200));
    board.push_back(std::make_unique<RailroadSquare>(5, "Reading Railroad", 200));
    board.push_back(std::make_unique<PropertySquare>(6, "Oriental Avenue", 100, std::array<int, 6>{6, 30, 90, 270, 400, 550}));
    board.push_back(std::make_unique<Square>(7, "Chance", SquareType::Chance));
    board.push_back(std::make_unique<PropertySquare>(8, "Vermont Avenue", 100, std::array<int, 6>{6, 30, 90, 270, 400, 550}));
    board.push_back(std::make_unique<PropertySquare>(9, "Connecticut Avenue", 120, std::array<int, 6>{8, 40, 100, 300, 450, 600}));
    board.push_back(std::make_unique<Square>(10, "In Jail / Just Visiting", SquareType::Jail));

    // --- LEFT ROW (11 to 20) ---
    board.push_back(std::make_unique<PropertySquare>(11, "St. Charles Place", 140, std::array<int, 6>{10, 50, 150, 450, 625, 750}));
    board.push_back(std::make_unique<UtilitySquare>(12, "Electric Company", 150));
    board.push_back(std::make_unique<PropertySquare>(13, "States Avenue", 140, std::array<int, 6>{10, 50, 150, 450, 625, 750}));
    board.push_back(std::make_unique<PropertySquare>(14, "Virginia Avenue", 160, std::array<int, 6>{12, 60, 180, 500, 700, 900}));
    board.push_back(std::make_unique<RailroadSquare>(15, "Pennsylvania Railroad", 200));
    board.push_back(std::make_unique<PropertySquare>(16, "St. James Place", 180, std::array<int, 6>{14, 70, 200, 550, 750, 950}));
    board.push_back(std::make_unique<Square>(17, "Community Chest", SquareType::CommunityChest));
    board.push_back(std::make_unique<PropertySquare>(18, "Tennessee Avenue", 180, std::array<int, 6>{14, 70, 200, 550, 750, 950}));
    board.push_back(std::make_unique<PropertySquare>(19, "New York Avenue", 200, std::array<int, 6>{16, 80, 220, 600, 800, 1000}));
    board.push_back(std::make_unique<Square>(20, "Free Parking", SquareType::FreeParking));

    // --- TOP ROW (21 to 30) ---
    board.push_back(std::make_unique<PropertySquare>(21, "Kentucky Avenue", 220, std::array<int, 6>{18, 90, 250, 700, 875, 1050}));
    board.push_back(std::make_unique<Square>(22, "Chance", SquareType::Chance));
    board.push_back(std::make_unique<PropertySquare>(23, "Indiana Avenue", 220, std::array<int, 6>{18, 90, 250, 700, 875, 1050}));
    board.push_back(std::make_unique<PropertySquare>(24, "Illinois Avenue", 240, std::array<int, 6>{20, 100, 300, 750, 925, 1100}));
    board.push_back(std::make_unique<RailroadSquare>(25, "B. & O. Railroad", 200));
    board.push_back(std::make_unique<PropertySquare>(26, "Atlantic Avenue", 260, std::array<int, 6>{22, 110, 330, 800, 975, 1150}));
    board.push_back(std::make_unique<PropertySquare>(27, "Ventnor Avenue", 260, std::array<int, 6>{22, 110, 330, 800, 975, 1150}));
    board.push_back(std::make_unique<UtilitySquare>(28, "Water Works", 150));
    board.push_back(std::make_unique<PropertySquare>(29, "Marvin Gardens", 280, std::array<int, 6>{24, 120, 360, 850, 1025, 1200}));
    board.push_back(std::make_unique<Square>(30, "Go To Jail", SquareType::GoToJail));

    // --- RIGHT ROW (31 to 39) ---
    board.push_back(std::make_unique<PropertySquare>(31, "Pacific Avenue", 300, std::array<int, 6>{26, 130, 390, 900, 1100, 1275}));
    board.push_back(std::make_unique<PropertySquare>(32, "North Carolina Avenue", 300, std::array<int, 6>{26, 130, 390, 900, 1100, 1275}));
    board.push_back(std::make_unique<Square>(33, "Community Chest", SquareType::CommunityChest));
    board.push_back(std::make_unique<PropertySquare>(34, "Pennsylvania Avenue", 320, std::array<int, 6>{28, 150, 450, 1000, 1200, 1400}));
    board.push_back(std::make_unique<RailroadSquare>(35, "Short Line Railroad", 200));
    board.push_back(std::make_unique<Square>(36, "Chance", SquareType::Chance));
    board.push_back(std::make_unique<PropertySquare>(37, "Park Place", 350, std::array<int, 6>{35, 175, 500, 1100, 1300, 1500}));
    board.push_back(std::make_unique<TaxSquare>(38, "Luxury Tax", 75));
    board.push_back(std::make_unique<PropertySquare>(39, "Boardwalk", 400, std::array<int, 6>{50, 200, 600, 1400, 1700, 2000}));
}

void Board::printBoard()
{
    std::stringstream boardStream;
    for (int i = 0; i < board.size(); i++){boardStream << "\n" << board[i]->name << ": " << board[i]->position;}
    sys.print(boardStream);
}

Board::~Board(){}