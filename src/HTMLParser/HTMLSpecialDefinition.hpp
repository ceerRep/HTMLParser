#ifndef _COWR_HTMLPARSER_HTMLSPECIALDEFINITION

#define _COWR_HTMLPARSER_HTMLSPECIALDEFINITION

#include <algorithm>
#include <string>
#include <vector>

class HTMLSpecialDefinition {
    inline static std::vector<std::string> raw_text_tags = {
        "title",
        "textarea",
        "script",
        "style"
    };

public:
    static bool isRawTextTag(std::string str)
    {
        return std::find(raw_text_tags.begin(), raw_text_tags.end(), str) != raw_text_tags.end();
    }
};

#endif
