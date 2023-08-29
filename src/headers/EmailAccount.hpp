#pragma once

#include "EmailConfigurationProvider.hpp"
#include "EmailCredential.hpp"

///@file
/**
 * @brief A local email account
 */
class EmailAccount{
public:
    EmailAccount();

    /// @brief Remote email server configuration
    EmailConfigurationProvider remote;

    /// @brief Current email account details
    EmailCredential details;

    /**
     * @brief Connect to the email account
     * @details Make a connection through the emailconfigurationprovider.
     */
    void Connect();

    /**
     * @brief Disconnect from the email account
     */
    void Disconnect();

    /**
     * @brief Send an email through the current email server
     */
    void SendEmail(); //TODO: add emailmessage param

    /**
     * @brief Whether a connection to the current email server exists
     * 
     * @return true if a connection is already active
     * @return false if no connection is currently active
     */
    bool IsConnected();
private:


};