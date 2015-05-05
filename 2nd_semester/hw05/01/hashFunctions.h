#pragma once

#include <QString>

///Class for handling different hash functions.
class HashFunctions
{
public:
    ///Generates hash from string depending on current hash function.
    virtual int hash(const QString &string) = 0;
};

