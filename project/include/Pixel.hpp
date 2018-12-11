#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <algorithm>
#include "Hexagon.hpp"
#include "Food.hpp"
#include "Map.hpp"
#include </home/mariasolovyova/CLionProjects/Evolution/tools/json/single_include/nlohmann/json.hpp>

using Json = nlohmann::json;

class Pixel
        : public Hexagon
{
    Brain brain;
    unsigned int numberOfLifeIterations;
public:
    explicit Pixel();
    ~Pixel() = default;
    Pixel(const double, const double, const size_t, const size_t);
    Pixel(const double, const double, const size_t, const size_t, Brain);
    Pixel(const float xNew, const float yNew, const size_t CellStrNew,
          const size_t CellColNew, const double lifesNew, Brain brainNew);
    Pixel(const float xNew, const float yNew, const size_t CellStrNew,
          const size_t CellColNew, const double lifesNew, Brain brainNew, double medicineNew);
    Pixel(const Pixel&);

    std::vector<Hexagon*> LookAround(Map&) const;
    void Update(Map&);
    void EatingFood(Hexagon*, Map&);
    void Move(Map&, Hexagon*);
    void Reproduction(Map&);
    Hexagon* ViewNearbyCells(Map&, const Type&);
    unsigned int GetNumberOfLifeIterations() const;
    const Brain& GetBrain() const;
    void SetBrain(const Brain&);
    void ResetNumberOfLifeIterations();
    void Print(sf::RenderWindow*) const override;
    const Json getJson() const;
};

#endif
