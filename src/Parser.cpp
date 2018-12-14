
#include "Parser.h"

Parser::Parser(const std::string& fn) :
    file_name(fn),
    parser(XML_ParserCreate(NULL)),
    tag_names(),
    xml_data()
{
    if (!parser)
    {
        throw (std::string("Game couldn't allocate memory for Parser."));
    }
    XML_SetUserData(parser, this);
    XML_SetElementHandler(parser, start, end);
    XML_SetCharacterDataHandler(parser, chars);
    std::fstream in;
    in.open(file_name.c_str(), std::ios::in);
    if (!in)
    {
        throw (std::string("Game cannot open XML file ") + file_name +
                std::string("."));
    }
    int length = 0;
    in.getline(buff, 512);
    bool done = false;
    while (!done)
    {
        if (!XML_Parse(parser, buff, std::strlen(buff), length))
        {
            throw (std::string("Game couldn't parse file ") + file_name +
                    std::string("."));
        }
        if (in.eof())
        {
            done = true;
        }
        else
        {
            in.getline(buff, 512);
        }
    }
}

Parser::~Parser()
{
    XML_ParserFree(parser);
}

const std::map<std::string, std::string> Parser::get_xml_data() const
{
    return (xml_data);
}

std::string Parser::make_tag(const std::string& name) const
{
    std::string tag_name;
    for (unsigned int i = 1; i < tag_names.size() - 1; i++)
    {
        tag_name += tag_names[i] + '/';
    }
    tag_name += tag_names[tag_names.size() - 1];
    tag_name += std::string("/") + name;
    return (tag_name);
}

std::string Parser::make_tag() const
{
    std::string tag_name;
    for (unsigned int i = 1; i < tag_names.size() - 1; i++)
    {
        tag_name += tag_names[i] + '/';
    }
    tag_name += tag_names[tag_names.size() - 1];
    return (tag_name);
}

void Parser::strip_white_space(std::string& str)
{
    int length = str.size();
    int i = length - 1;
    while (i >= 0)
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {
            i = -1;
        }
        else if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            str.erase(i, 1);
        }
        i--;
    }
}

void Parser::start(void* data, const char* el, const char** attr)
{
    Parser* parser = static_cast<Parser*>(data);
    parser->start_helper(el, attr);
}

void Parser::start_helper(const char* el, const char** attr)
{
    tag_names.push_back(el);
    for (int i = 0; attr[i]; i += 2)
    {
        xml_data.insert(std::make_pair(make_tag(attr[i]), attr[i + 1]));
    }
}

void Parser::end(void* data, const char* el)
{
    Parser* parser = static_cast<Parser*>(data);
    parser->end_helper(el);
}

void Parser::end_helper(const char* tag_end)
{
    if (tag_end != tag_names.back())
    {
        throw (std::string("XML tags ") + tag_end + " and " +
                tag_names.back() + std::string(" don't match."));
    }
    tag_names.pop_back();
}

void Parser::chars(void* data, const char* text, int len)
{
    Parser* parser = static_cast<Parser*>(data);
    parser->chars_helper(text, len);
}

void Parser::chars_helper(const char* text, int len)
{
    std::string str(text, len);
    Parser::strip_white_space(str);
    if (str.size())
    {
        xml_data.insert(std::pair<std::string, std::string>(make_tag(), str));
    }
}

