#pragma once
#include <string>

///@file 
/**
 * @brief Wrapper for an email username and password
 */
struct EmailCredential{
    std::string email;
    std::string password;    
};