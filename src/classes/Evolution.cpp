#include "Evolution.hpp"


Evolution::Evolution()
{
    map = Map();
    window.create(sf::VideoMode(map.GetWidth(), map.GetHeight()), "Evolution");
    buttonDecrease= Button(0, 5, 0);
    buttonIncrease = Button(40, 70, 180);
}

Evolution::Evolution(const Evolution& ev)
    :        map(ev.map),
             keyboard(ev.keyboard)
{
    window.create(sf::VideoMode(ev.map.GetWidth(), ev.map.GetHeight()), "Evolution");
}

Evolution::Evolution(Evolution&& ev)
    :    threads(std::move(ev.threads)),
         map(std::move(ev.map)),
         keyboard(std::move(ev.keyboard))
{
     window.create(sf::VideoMode(ev.map.GetWidth(), ev.map.GetHeight()), "Evolution");
}
void Evolution::Statistics()
{
    double statisticsOfLifeIt = 0;
    for (size_t inner = 0; inner < map.GetStaticOrganisms().size(); ++inner)
    {
        statisticsOfLifeIt += map.GetStaticOrganisms()[inner]->GetNumberOfLifeIterations();
    }
    statisticsOfLifeIt /= map.GetStaticOrganisms().size();
    boost::filesystem::path path = boost::filesystem::current_path().parent_path();
    path += "/recordsNew";
    if(!boost::filesystem::exists(path))
        boost::filesystem::create_directory(path);
    std::string path_to_file = path.string() + "/Statistics";
    std::fstream fl(path_to_file, std::ios::app);
    fl << map.GetEvolutionNumber() << " " << statisticsOfLifeIt << std::endl;
    fl.close();
}

/*void Evolution::CatchingEvents()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || keyboard.isPressed(sf::Keyboard::Escape))
                window.close();
            else if (event.type == sf::Event::KeyPressed)
                keyboard.press(event.key.code);
            else if (event.type == sf::Event::KeyReleased)
                keyboard.release(event.key.code);
            else if (keyboard.isPressed(sf::Keyboard::S))
            {
                map.SaveToFile();
                //  window.close();
            }
            else if (keyboard.isPressed(sf::Keyboard::U))
            {
                map.UploadFromFile();
            }
            window.clear();
        }
    }
}*/


void Evolution::run()
{
    map.MultiplyPixels(10);
    while (window.isOpen())
    {
        if (map.GetEvolutionNumber() == 1 || map.GetEvolutionNumber() % 10 == 0)
            map.SaveToFile();
        while (map.GetNumberOfAliveOrganisms() > 0 && window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || keyboard.isPressed(sf::Keyboard::Escape))
                    window.close();
                else if (event.type == sf::Event::KeyPressed)
                    keyboard.press(event.key.code);
                else if (event.type == sf::Event::KeyReleased)
                    keyboard.release(event.key.code);
                else if (keyboard.isPressed(sf::Keyboard::S))
                {
                    map.SaveToFile();
                    //  window.close();
                }
                else if (keyboard.isPressed(sf::Keyboard::U))
                {
                    map.UploadFromFile();
                }
                else if (keyboard.isPressed(sf::Keyboard::W))
                {
                    map.IncreaseTimesToSleep(10);
                    buttonIncrease.SetColor(sf::Color::Green);
                    buttonIncrease.Print(&window);
                }
                else if (keyboard.isPressed(sf::Keyboard::E))
                {
                    if (map.GetTimeToSleep() >= 10)
                    {
                        map.DecreaseTimesToSleep(10);
                    }
                    buttonDecrease.SetColor(sf::Color::Green);
                    buttonDecrease.Print(&window);
                }
                if (!(keyboard.isPressed(sf::Keyboard::W)))
                {
                    buttonIncrease.SetColor(sf::Color(169, 169, 169));
                    buttonIncrease.Print(&window);
                }
                if (!(keyboard.isPressed(sf::Keyboard::E)))
                {
                    if (map.GetTimeToSleep() > 0)
                        buttonDecrease.SetColor(sf::Color(169, 169, 169));
                    buttonDecrease.Print(&window);
                }
                window.clear();
            }
            //  PrintOrNot = (map.GetTimeToSleep() > 10);
            //  if (PrintOrNot)
            //      map.Print(&window);
            map.Update();
            buttonIncrease.Print(&window);
            buttonDecrease.Print(&window);

            window.display();
        }
        Statistics();
        map.IncreaseEvolutionNumber();
        map.RecreateMap(map.GetStaticOrganisms());
        return;
    }
}