#pragma once

#include "EmailCredential.hpp"

///@file 
/**
 * @brief Interface for a credential storage manager
 * @details Interfaces the managing of an email account's credentials, be it OAUTH2 or locally-encrypted
 */
class ICredentialManager{
public:
    /// @brief Retrieve email credentials 
    /// @return The retrieved email credentials
    EmailCredential GetEmailCredentials();

    /// @brief Save the email credentials 
    /// @param credentials The credentials to cache
    void SaveEmailCredentials(const EmailCredential & credentials);
private:
};