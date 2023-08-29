#include <iostream>
#include <string>
#include <vmime/vmime.hpp>
#include "vmime/platforms/posix/posixHandler.hpp"

#include <vmime/vmime.hpp>

int main()
{
    vmime::platform::setHandler<vmime::platforms::posix::posixHandler>();

    vmime::shared_ptr<vmime::net::session> session = vmime::net::session::create();
    vmime::shared_ptr<vmime::net::transport> transport = session->getTransport("smtp");

    // Set the server and port
    transport->setProperty("server.address", "smtp.gmail.com");
    transport->setProperty("server.port", "587");
   // transport->setProperty("options.need-authentication", "true");
    transport->setProperty("options.tls", "starttls");
    transport->setProperty("options.log", "true");
    transport->setProperty("auth.username", "vvampus@gmail.com");
    //transport->setProperty("auth.password", "password");

    // Connect to the server
    try
    {
        transport->connect();
        std::cout << "Connected!" << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << "Failed to connect: " << ex.what() << std::endl;
        return 1;
    }

    if (transport->isConnected())
    {
        std::cout << "Connected to the SMTP server." << std::endl;
    }
    else
    {
        std::cerr << "Failed to connect to the SMTP server." << std::endl;
        return 1;
    }

    // Create and send the message
    vmime::messageBuilder mb;

    // Fill in the basic fields
    auto from = vmime::mailbox("vvampus@gmail.com");
    mb.setExpeditor(from);

    vmime::addressList to;
    to.appendAddress(vmime::make_shared<vmime::mailbox>("vvampus@gmail.com"));

    mb.setRecipients(to);

    // vmime::addressList bcc;
    // bcc.appendAddress(vmime::make_shared <vmime::mailbox>("you-bcc@nowhere.com"));

    // mb.setBlindCopyRecipients(bcc);

    mb.setSubject(vmime::text("My first message generated with vmime::messageBuilder"));

    // Message body
    mb.getTextPart()->setText(
        vmime::make_shared<vmime::stringContentHandler>(
            "I'm writing this short text to test message construction "
            "using the vmime::messageBuilder component."));

    // Construction
    vmime::shared_ptr<vmime::message> msg = mb.construct();

    // Configure the message here
    try
    {
        transport->send(msg);
        std::cout << "Message sent successfully!" << std::endl;
    }
    catch (const vmime::exception &ex)
    {
        std::cerr << "Error sending message: " << ex.what() << std::endl;
    }
    // Disconnect
    transport->disconnect();

    return 0;
}
