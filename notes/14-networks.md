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
* Wireless & Wired connections:
    * Wired: computers connected through Ethernet cables which connect Ethernet port to router or similar
    * Wireless:
        * Computers have wireless NIC
        * Connect via router to physical network
            * Must be within range of router
            * Router uses radio signals to send data
        * Computer's wireless adapter/network card converts data to radio signal and wireless receiver decodes it for computer to understand it
        * Wireless transmissions can be intercepted by anyone within range of router
        * MAC address
        * WiFi Protected Access
        * Advantages:
            * Cheap to set up
            * Not tied down in one chair or area
            * Can connect multiple devices without extra hardware needed
            * Less disruption to building; no wires needed
        * Disadvantages:
            * Interference possible
            * The connection is not as stable as wired networks and can 'drop off'
            * It will lose quality through walls or obstructions
            * More open to hacking
            * Slower than wired networks
* Networking hardware
    * Routers: form LAN by connecting devices within a building. Makes it possible to connect different networks together—connects to the internet usually. Incorporates modem.
    * Modem: enables computer to connect to internet over telephone line. Converts digital signals from computer to analog signals that are then sent over telephone lines. Modem on the other side goes the other way around.
    * Hub: broadcast data to all devices. Uses lots of bandwidth because unnecessary data is sent.
    * Switch: basically a hub, but only sends things to the computer that wants it.
    * Bridge: connects two LAN networks. Can be a computer with the OS. Not on IB exam.
    * Wireless Access Point (WAP): required for wireless connection. Usually built into router.
    * MAC address: hardcoded (can be changed during runtime). Unique. 48 bits -> 12 hexadecimal digits.
    * NIC (Network Interface Card): enable laptops and desktops to connect to network. Small circuit boards that connect to the motherboard. Smartphones also use a GSM chip to connect to telephone network.
* Networking models:
    * Client-Server model
        * "Client side" means the front end
    * P2P/Peer-to-Peer
        * No single provider is responsible for being the server. Each computer stores files and acts as a server, sending sections of a file, etc. Ideal for sharing files, but wouldn't work well for things like booking tickets, where one server needs to keep a record of how many tickets have been sold.
* Types of servers
    * Web servers: host websites and handle requests for *STATIC* information like HTML pages or images. Manage the website on a server, typically include FTP software to host and share large files. Apache is a popular web server for this.
    * Application servers: contain programming and scripts that are more complex than a static HTML page. May use MySQL or NoSQL databases to store data. Server is used to organize nd run the web application. Client sends requests to the web server, which sends requests to application server.
    * Network Attached Storage (NAS): server dedicated to storing and sharing files. Useful for storing large files, like music/video, but not for storing websites.
    * Print servers: make it easy for various devices to connect to a printer. Removes the need for devices to install printer driver software or connect to printer using cables.
    * Mail server: store email messages, clients request messages from it.

* Internet: a network of networks
* Internet of Things: devices are connected to the internet like fridges and thermostats
* MUST KNOW TYPES OF CORDS - in other notes
