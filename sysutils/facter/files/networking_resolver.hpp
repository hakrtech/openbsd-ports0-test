/**
 * @file
 * Declares the OpenBSD networking fact resolver.
 */
#pragma once

#include "../bsd/networking_resolver.hpp"
#include <map>
#include <ifaddrs.h>

namespace facter { namespace facts { namespace openbsd {

    /**
     * Responsible for resolving networking facts.
     */
    struct networking_resolver : bsd::networking_resolver
    {
     protected:
        /**
         * Gets the MTU of the link layer data.
         * @param interface The name of the link layer interface.
         * @param data The data pointer from the link layer interface.
         * @return Returns The MTU of the interface.
         */
        virtual boost::optional<uint64_t> get_link_mtu(std::string const& interface, void* data) const override;

        /**
         * Determines if the given sock address is a link layer address.
         * @param addr The socket address to check.
         * @returns Returns true if the socket address is a link layer address or false if it is not.
         */
        virtual bool is_link_address(sockaddr const* addr) const override;

        /**
         * Gets the bytes of the link address.
         * @param addr The socket address representing the link address.
         * @return Returns a pointer to the address bytes or nullptr if not a link address.
         */
        virtual uint8_t const* get_link_address_bytes(sockaddr const* addr) const override;

        /**
         * Finds known DHCP servers for all interfaces.
         * @return Returns a map between interface name and DHCP server.
         */
        virtual std::map<std::string, std::string> find_dhcp_servers() const override;

        /**
         * Finds the DHCP server for the given interface.
         * @param interface The interface to find the DHCP server for.
         * @returns Returns the DHCP server for the interface or empty string if one isn't found.
         */
        virtual std::string find_dhcp_server(std::string const& interface) const override;
    };

}}}  // namespace facter::facts::openbsd
