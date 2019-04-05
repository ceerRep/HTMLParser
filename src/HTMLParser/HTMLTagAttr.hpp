#ifndef _COWR_HTMLPARSER_HTMLTAGATTR

#define _COWR_HTMLPARSER_HTMLTAGATTR

#include <sstream>
#include <string>
#include <vector>

#include "../Utils/util.hpp"

namespace cowr {

class HTMLTagAttr {
public:
    using Attr = std::pair<std::string, std::string>;

private:
    std::vector<Attr> attr_list;

public:
    auto begin()
    {
        return attr_list.begin();
    }

    auto begin() const
    {
        return attr_list.begin();
    }

    auto end()
    {
        return attr_list.end();
    }

    auto end() const
    {
        return attr_list.end();
    }

    auto& addAttr(std::string name, std::string value)
    {
        auto pos = begin();

        for (auto end_pos = end(); pos != end_pos; pos++) {
            if (name == pos->first)
                break;
        }

        attr_list.emplace(pos, std::make_pair(name, value));

        return *this;
    }

    std::string toString() const
    {
        std::stringstream buffer;

        for (auto&& attr : attr_list) {
            buffer << " ";
            buffer << attr.first;
            buffer << "=\"";
            buffer << escape_string(attr.second);
            buffer << '"';
        }

        buffer.get(); //Delete the first space (if any)

        return buffer.str();
    }
};

}

#endif
