
## Types of networks
* Local Area Network (LAN) - Network inside a house or small business; small geographical location
* Virtual Local Area Network (VLAN) - Simulates a LAN among computers which aren't geographically near each other
* Wide Area Network (WAN) - Network for a large geographical area
* Storage Area Network (SAN) - "The Cloud"
* Wireless Local Area Network (WLAN) - WiFi
* Internet - A network of networks, covering the whole world.
* Extranet
* Virtual Private Network (VPN)
* Personal Area Network (PAN)
* Peer-to-Peer (P2P)

## Outline the importance of standards in the construction of networks
* Stanards play an important role in networking
* Without standardization it would be difficult to get different systems to interact
* Many groups handle standardization:
    * IEEE - Institute of Electrical and Electronic Engineers
    * ISO - International Organization for Standardization

## OSI Model - Open System 
* Data - Application - The layer the user interacts with
* Data - Presentation - Data representation and encryption
* Data - Session - Interhost Communication
* Segments - Transport - End-to-end Connections and Reliability
* Packets - Network - Path Determination and Logical Addressing (IP)
* Frames - Data link - Physical Addressing (Mac & LLC)
* Bits - Physical - Media, Signal, and Binary Transmission

### Application layer
The layer with which the user interacts.

### Presentation layer
Translate application format to network format.
This is where encryption occurs.

### Session Layer
Involves setup, coordination, and termination of session. Two devices communicate here.

### Transport layer
How much data to send, at what rate, where to, and where the TCP takes place

### Network layer
Router functionality

### Data Link layer
Provides node-to-node transfer, switches work on this level.

### Physical layer
Electrical and physical representation.


### Why is the OSI 7 layer model important?

> "The purpose of the OSI reference model is to guide vendors and developers so the digital communication products and software programs they create will interoperate, and to facilitate clear comparisons among communications tools."

Mneumonic: "All People Seem To Need Data Processing"

# What is a VPN?
Tunnel to the internet through filters or firewalls.

## Types of data transferring
* Fiber Optics
    * Glass fibers carrying light pulses, each pulse considered a bit
    * High speed operation: 100 MB/s Ethernet, high-speed point-to-point transmission (5GB/s)
    * Low error rate: repeaters spaced far apart, immune to electromagnetic noise
* Twisted Pair Copper Wire
    * Unshielded Twisted Pair (UTP) is commonly used for compter networks within a buildings (LANs)
    * Data rates for LANs using UTP is 10-100MB/s
* Twisted Pair Copper Wire CAT5
    * More twists per cm, faster.
    * Typically preinstalled in office buildings
* Coaxial cable
    * This consists of solid copper core surrounded by insulation surrounded by copper shielding covered by plastic sheath
    * Early computer networks used coax cable with bandwidth of 10MB/s but nowadays not efficient enough for modern nerworks
* Wi-Fi
    * Allows wireless data exchange using radio waves
    * Current standard - 802.11 - supports 300MB/s but need all hardware to support this thus usually runs at around <=130MB/s
    * Uses unlicensed radio spectrum
    * LANs can be set up without cabling
    * WiFi allows roaming between access points

## Compression
Makes transferring data over a network easier.
You can also encrypt it.

Types on IB:
* Lossless - Everything is preserved. Types: PNG, ZIP, GIF
* Lossy - Some data is lost. Types: JPG

__Textbase Compression__ - Huffman Coding, 1950s

ASCII - Binary Formatting of American English text

a-z|A-Z|0-9
:---:|:---:|:---:
97-122|65-90|65-91

Representing this in binary, however, is inefficient; you have to stick 0s onto the starting. This is where compression comes in.

ZEEFE -> 40 bits
110 0 0 1110 0 -> using how frequently they appear
