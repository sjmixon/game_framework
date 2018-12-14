
#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <map>
#include <sstream>
#include <string>

#include "Vector.h"
#include "Parser.h"

class Game_Data
{
    public :
        ~Game_Data();

        static Game_Data& get_instance();
        bool get_xml_bool(const std::string&) const;
        const std::string& get_xml_string(const std::string&) const;
        float get_xml_float(const std::string&) const;
        int get_xml_int(const std::string&) const;

    private :
        Parser parser;
        const std::map<std::string, std::string> game_data;

        Game_Data(const std::string& fn = "xml/game.xml");
        Game_Data(const Game_Data&);
        Game_Data& operator=(const Game_Data&);
};

#endif

