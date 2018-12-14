
#ifndef PARSER_H
#define PARSER_H

#include <deque>
#include <expat.h>
#include <map>
#include <string>

class Parser
{
    public :
        Parser(const std::string&);
        virtual ~Parser();

        const std::map<std::string, std::string> get_xml_data() const;
        static void start(void*, const char*, const char**);
        static void end(void*, const char*);
        static void chars(void*, const char*, int);

    private :
        const std::string file_name;
        XML_Parser parser;
        char buff[512];
        std::deque<std::string> tag_names;
        std::map<std::string, std::string> xml_data;

        std::string make_tag() const;
        std::string make_tag(const std::string&) const;
        static void strip_white_space(std::string&);
        void start_helper(const char*, const char**);
        void end_helper(const char*);
        void chars_helper(const char*, int);

        Parser(const Parser&);
        Parser& operator=(const Parser&);
};

#endif

