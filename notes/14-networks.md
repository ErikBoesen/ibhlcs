* Network: a system where multiple devies are connected together. Purpose is to share data between devices.
* Network environments: internet (world), offices/universities, home
* Networks started so universities could share research
* Data is communicated with packets - small chunks of data which include to & from addresses, index number, data, time stamp, parity bit
* Advantages of networking:
    * Communication
    * Sharing information
    * Sharing resources
    * Sharing software
* Disadvantages:
    * Threats of black-hat hacking
    * Dependence
    * Expensive hardware
* Types of networks:
    * LAN: Local Area Network, network of computers within same building, like a school, home, or business. Not necessarily connected to the internet. Contains clients and servers.
    * WAN: Wide Area Network. Created by connected LANs, requiring media like broadband cables. Connects organizations in different geographical places. The internet is a WAN.
    * VPN: Virtual Private Network. Hosted securely on another network to provide connectivity. Often used to work on secure information held by an institution. "Tunneling"
    * WPAN: Wireless Personal Area Network. Allows individual to connect devices like a smartphone to desktop machine, or form bluetooth connection with devices in a car. Wired personal network is a PAN.
    * PAN: Personal Area Network. Wired personal network.
* Topologies: different ways to set up a LAN, with different tradeoffs regarding speed and cost.
    * Bus topology: two terminators, with stops in between. All connected to one cable.
        * Advantages: cheap and easy to install because there's only one cable.
        * Disadvantages: slower with more workstations, because of data collision. If main cable fails or is damaged, the whole network will fail. Every workstation sees other workstations' traffic, a security risk.
    * Ring topology: circle. Connection passes through each client/server to get to the next one. Each data packet on the network travels in one direction, like on the beltway.
        * Advantages: quick transfer since data flows only one way; no data collisions.
        * Disadvantages: If one cable fails, the whole network will fail.
    * Star topology: all devices connected to one central hub or switch via its own cable. Most popular LAN setup. Speed is a priority for these.
        * Advantages: very reliable; if one cable fails the others will still work. High performing as no data collisions occur.
        * Disadvantages: expensive since it requires lots of cable. Extra hardware (hubs/switches) are required, adding to the cost. If hub/switch fails, all devices lose connection.
