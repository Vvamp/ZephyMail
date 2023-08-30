#pragma once
#include <string>

///@file
/**
 * @brief Wrapper for a simple external email account
 * 
 */
class EmailUser{
public:
    EmailUser(std::string name, std::string emailAddress) : emailAddress(emailAddress), name(name) {};
    
    /// @brief User's email address
    std::string emailAddress;

    /// @brief User's full name
    std::string name;
private:
};