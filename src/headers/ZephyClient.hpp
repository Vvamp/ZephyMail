#pragma once
#include "EmailAccount.hpp"
#include <vector>

///@file

/**
 * @brief The Zephymail Email Client Base Class
 * 
 */
class ZephyClient{
public:
    /// @brief Constructor
    ZephyClient(){ 
        // load emails cached if any
    };


private:
    /// @brief All emailed accounts currently signed in to
    std::vector<EmailAccount> emailAccounts;

};