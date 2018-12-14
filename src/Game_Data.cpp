
#include "Game_Data.h"

Game_Data& Game_Data::get_instance()
{
    static Game_Data gd;
    return (gd);
}

Game_Data::~Game_Data()
{
}

Game_Data::Game_Data(const std::string& fn) :
    parser(fn),
    game_data(parser.get_xml_data()) 
{
}

bool Game_Data::get_xml_bool(const std::string& tag) const
{
    std::map<std::string, std::string>::const_iterator ptr =
            game_data.find(tag);
    if (ptr == game_data.end())
    {
        throw (std::string("Game didn't find boolean tag ") + tag +
                std::string(" in XML."));
    }
    else
    {
        if (ptr->second == "true")
        {
            return (true);
        }
        else
        {
            return (false);
        }
    }
}

int Game_Data::get_xml_int(const std::string& tag) const
{
    std::map<std::string, std::string>::const_iterator ptr =
            game_data.find(tag);
    if (ptr == game_data.end())
    {
        throw (std::string("Game didn't find integer tag ") + tag +
                std::string(" in XML."));
    }
    else
    {
        std::stringstream stream;
        stream << ptr->second;
        int data;
        stream >> data;
        return (data);
    }
}

float Game_Data::get_xml_float(const std::string& tag) const
{
    std::map<std::string, std::string>::const_iterator ptr =
            game_data.find(tag);
    if (ptr == game_data.end())
    {
        throw (std::string("Game didn't find float tag ") + tag +
                std::string(" in XML."));
    }
    else
    {
        std::stringstream stream;
        stream << ptr->second;
        float data;
        stream >> data;
        return (data);
    }
}

const std::string& Game_Data::get_xml_string(const std::string& tag) const
{
    std::map<std::string, std::string>::const_iterator ptr =
            game_data.find(tag);
    if (ptr == game_data.end())
    {
        throw (std::string("Game didn't find string tag ") + tag +
                std::string(" in XML."));
    }
    else
    {
        return (ptr->second);
    }
}

