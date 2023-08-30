#pragma once
#include <string>
#include <cstdint>
#include "ICredentialManager.hpp"

///@file 
/**
 * @brief Email server connection configuration 
 */
class EmailConfigurationProvider{
public:

    /// @brief Hostname for the IMAP server
    std::string imapHostname;

    /// @brief Port for the IMAP connection
    uint16_t imapPort;

    /// @brief Hostname for the SMTP server
    std::string smtpHostname;

    /// @brief Port for the SMTP server
    uint16_t smtpPort;

    /**
     * @brief Manage cached email credentials
     * @details This object handles reading and writing the cached email credentials
     */
    ICredentialManager credentialManager;
    
private:
};