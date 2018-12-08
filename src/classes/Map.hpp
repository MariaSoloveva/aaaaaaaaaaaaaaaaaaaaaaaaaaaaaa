#ifndef EVOLUTION_MAP_H
#define EVOLUTION_MAP_H

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include <boost/filesystem.hpp>
#include <SFML/Graphics.hpp>

#include "Hexagon.hpp"
#include "Food.hpp"

class Pixel;

class Row
{
    std::vector<Hexagon*> row;
public:
    Row() = default;
    ~Row() = default;
    Hexagon*& operator[](size_t index)
    {
        return row[index];
    }

    const Hexagon* operator[](size_t index) const
    {
        return row[index];
    }

    void push_back(Hexagon* hex)
    {
        row.push_back(hex);
    }

    void erase(size_t index)
    {
        row.erase(row.begin() + index);
    }

    void insert(Hexagon* hex, size_t index)
    {
        row.insert(row.begin() + index, hex);
    }

    std::vector<Hexagon*>::iterator begin()
    {
        return row.begin();
    }

    Hexagon* back()
    {
        return row.back();
    }
};


class Map
{
public:
    Map();
    Map(const std::string&);
    Map(const Map&);
    Map(Map&&);
    ~Map() = default;
    Map& operator=(const Map&);
    Map& operator=(Map&&);
    Row& operator[](size_t);
    const Row& operator[](size_t) const;

    void Update();
    void MultiplyPixels(int);
    void CreateFood(int);
    void SetPoison(int);
    void RecreateMap(const std::vector<Pixel*>&);
    void ClonePixels(Map&, const std::vector<Pixel*>&);

    unsigned int GetWidth() const;
    unsigned int GetHeight() const;

    size_t GetWidthInCells() const;
    size_t GetHeightInCells() const;

    std::vector<Pixel*> GetOrganisms() const;
    std::vector<Pixel*> GetStaticOrganisms() const;
    size_t GetNumberOfAliveOrganisms() const;

    unsigned int GetEvolutionNumber() const;
    void IncreaseEvolutionNumber();

    int GetTimeToSleep() const;

    void IncreaseTimesToSleep(int);
    void DecreaseTimesToSleep(int);
    
    Wall* GetWall() const;

    void SetOrganism(Pixel*);
    void Swap(Hexagon*, Hexagon*);
    void SaveToFile() const;
    void UploadFromFile();
    void Print(sf::RenderWindow*) const;

private:
    static const unsigned int width = 2000;
    static const unsigned int height = 1000;
    static const size_t widthInCells = 94;
    static const size_t heightInCells = 60;
    std::vector<Row> map;
    std::vector<Pixel*> organisms;
    std::vector<Pixel*> staticOrganisms;
    Wall* wall;
    int evolutionNumber = 1;
    int timeToSleep = 100;
};

#endif
