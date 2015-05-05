#pragma once
#include <string>

///Class for counting prefix expressinons using parse tree.
class Counter
{
public:
    ///Counts an expression from file with certain file name.
    static int countExpression(const std::string &fileName);
};
