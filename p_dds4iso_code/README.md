# DDS-HSI Proof of Concept

Testing and prototyping for the DDS-Implementation of High-Speed-ISOBUS.


## Quickstart

1. Use CMAKE with the options `-G "Visual Studio 15 2017" -DBUILD_GUI_LIB=TRUE -DCONNEXTDDS_ARCH=x64Win64VS2017 -A x64`. CMakeLists.txt is in src 
1. You must manually copy your RTI licence file to the output directory next to the .exes
1. You should begin by looking at simple_sprayer (src\applications\Implement\simple_sprayer\simple_sprayer_main.cpp). This is a single-file implementation of a simplified sprayer. The hierarchy (which would be the DDOP in ISOBUS) is: root > tank + boom > 3x sections.

4. There is a GUI built in C# in the TC_GUI folder. It can be built from the .sln file. *You must copy the InformationModel directory and your RTI licence to the output directory next to the exe*.

5. The c++ code in src builds a dll file which handles all DDS functions, and the GUI is purely for visualisation. It has no logic.

## Applications in this CMake project

### Simple_Sprayer
This is a simple (the readers are polled, single-file — plus generated datatypes) implementation of a sprayer. 

### TC_GUI & HSI_SPRAYER_LIB
A C# GUI is given in the TC_GUI directory. The C#'s only purpose is to call the TC_logic_run function which is built into a DLL (HSI_SPRAYER_LIB). The C# passes function pointers to TC_logic_run so that the TC can call functions which update the graphical elements. 

HSI_SPRAYER_LIB and TC_logic_run function implement a simple (the readers are polled, single-file — plus generated datatypes) implementation of a TC. There is no real logic based on position etc implemented.

### gui_simple_TC_as_cli
This is a command line version of the C# GUI. The C# GUI is recommended over this.

### Sprayer
This is an implementation of a sprayer. It is not yet feature complete. The topics are read via callback functions. Classes are used to simulate sprayer functions.

### TaskController_dp
This is an implementation of a TC. It is in progress.


## Information Model in general
The information model is created with RTI System Designer. And given in XML format.

The keys to communications with DDS are *topics*. Topics are a way of organising related data (e.g. a GNSS location topic) and each topic has a data type. This is normally a struct of various different fields, rather than only a single value. in this PoC the topics generally each have a different data type, but this is not a constraint of DDS. Topics do not belong to any specific domain participant.

The "end users" of DDS are *domain participants* (DPs). Each DP is generally a physically-separated device, however it is also possible to have multiple DPs on a single device. DPs are uniquely identified by a GUID and each have one or more IP addresses.

A DP holds *publishers* and *subscribers*. Publishers create and manage *data writers*. Subscribers create and manage *data readers*. Conceptually publishers are the counterpart to subscribers and data writers are the counterpart to data readers. Data writers/readers relate to only one topic and only one publisher/subscriber

Publishers can hold multiple data writers. The writers could be for different topics or for the same topic multiple times (same for subscribers and data readers).

What is the trade-off between having one Subscriber with multiple DataReaders, versus multiple Subscribers that each have one DataReader? See: https://community.rti.com/kb/should-i-combine-my-datareaders-under-one-subscriber-or-use-separate-subscribers

As of the current version of this PoC, each publisher/subscriber organises the readers/writers for a single topic. Another way of working may be to have a single publisher/subscriber per application and all data readers/writers are held by the same publisher or subscriber. Further investigation will reveal if this should be standardised or not. Currently the topics and QoS are the only standardised parts of the PoC and the arrangement of readers and writers is proprietary. It may be that by standardising the readers/writers themselves that the DDS middleware can handle more features (e.g. service discovery maybe could use the presence of readers/writers to determine what devices are offering which services).

There are certain scenarios where a reader and writer can be incompatible. Writers can set a minimum level of QoS which they require and a reader may be unable to meet this. Obviously this situation should be avoided for plug-and-play.

There are not direct 1-to-1 analogies between DDS and CAN/ISOBUS. Below some rough comparisons are listed as a starting point but the reader should bear in mind that this simplification hides some of the subtle benefits of DDS middleware.
- Roughly a topic performs the role of an ISOBUS PGN. It is something that has a standardised meaning mapped to some physical purpose at compile time. However the distinction between broadcast and addressable PGNs does not exist for topics.
- from the point of view of the application layer, the middleware makes the topics appear as a bus network. messages are sent to/received from everyone in the topic.
- Just as a CAN transceiver can filter CAN IDs, data readers/writers can filter which information is transmitted to each other for each topic. As part of the participant discovery, readers and writers inform each other of their existence and their filters. Filtering can happen on either the writer-side or the reader-side. If a writer knows that there are no readers for a topic, it will not send data on the wire. If writers and readers have shared their filtering information (e.g. reader is only interested when temperature > 30 or reader max data rate is 10 updates/sec) then they negotiate if this is done on the writer side (writer sends only to interested receivers) or reader side (reader receives the message on the wire but the middleware discards it). 
- The data bytes in ISOBUS map to specific SPNs. This is similar to the datatype of each topic. Many different points of information can be grouped together and shared at the same time under a single umbrella (of topic/PGN).

## Information Model Specifics
It is not yet implemented but it is planned that the TC and the implement each have 2 data -writers- and 1 data -reader-. One data writer would be using an unreliable QoS for rapidly-updating process data (e.g if the application rate updates every 100ms). The other data writer would be reliable and not *durable* for infrequently updating data (e.g. X-offset of a section, or machine workstate).

As the PoC develops, more topics will be added. Currently, each topic has a different data type. It is possible that in the future there is more reuse of data types.

### Further considerations for the information model
To allow unbounded lengths or not (e.g. strings/sequences with no maximum length). This seems to already cause 
To allow sequences variable-length or not. A sequence is  

## Building & Developing

### Prerequisites

A licence file (rti_license.dat) is required for RTI Connext. It should be placed in the same directory as the compiled exes.

### Building
RTI provides CMakelists dependent on the resources installed with RTI-Conntext.

The project is developed under Windows 10/11 with Visual Studio 2022 and 2017.
The following instructions are currently only tested for this setup.

* Change $CMAKE_MODULE_PATH in src/CMakeLists.txt to cmake-resources of RTI-Conntext installation folder (e.g. "C:\\Program Files\\rti_connext_dds-7.2.0\\resource\\cmake")
* cd src
* mkdir build && cd build
* cmake -G "Visual Studio 15 2017" -DBUILD_GUI_LIB=TRUE -DCONNEXTDDS_ARCH=x64Win64VS2017 -A x64 ..
* Open the generated .sln file with Visual Studio
* In the VS-solution explorer: Right-Click "ALL_BUILD" and select "Build"
* The generated executables are now located within src/build/Debug (When Debug-configuration is enabled by default) 

## Running Applications
The project currently builds two executables, one for a sprayer implement and one for a Task Controller (Server). When both are run they communicate over shared topics with dummy information.
To run the applications:
* Open a terminal and execute "C:\\Program Files\\rti_connext_dds-7.2.0\\resource\\scripts\\rtisetenv_x64Win64VS2017.bat" to set the RTI license information.
* Run the executeable from within the "p_dds4iso_code" parent directory (e.g., \<your repo-path\>\\p_dds4iso_code>src\out\build\x64-Debug\Sprayer.exe)

In the future we hope to build separate executables to prove the concept where an implement may be made up of multiple independent controllers.

## Future work
### Add a GNSS reciever to the PoC
This requires a new topic and GNSS data type.

### Service discovery
Add a topic (called "t_service_discovery" for example). The data type of this topic should be an extensible struct. Key field is the NAME, then a number of optional (NULL-able) uint8 fields (or better bool??) follows such as: TC_client_version, TC_server_version, VT_client_version, VT_server_version ...
0 or NULL == not implemented in the device, greater than 0 == standard version (like in current ISOBUS).

As new functionalities are developed, the struct is extended. DDS extensible datatypes handle the mismatch between a new device (with a long struct of services) and an old device (with a short list of services).

### Investigate if/how DDS can implement read/write-only fields
Can DDs set access controls such that only the TC can write setpoints and only the implement can write actuals.
Similar for a situation with multi-implement; can DDS control that implements only update their own setpoints?
Presumably, this would involve authentication of the messages and some check of the signature vs the key fields.

* Maybe through Wireshark (Something like Firewall)? Еach sended packet goes through a filter. If it doesnt match the filter e.g. TC sends actual, but it shouldn't be able, then drop the packet. 

### Add two QoS levels to the TC topics
See [Information-model-specifics](https://gitlab.aef-online.org/hsi-middleware-group/hsi-middleware#information-model-specifics).

### Add authentication and encryption of the communication between the nodes
Keywords: RTI Secure, OpenSSL

### Is distance-based logging possible through the QoS and if not maybe through the code?
* Through the change of the SQL expression (Reader side)?
* Through WaitSet class (Reader side)?
* Through Partition QoS? (Writer side)

## Contributors
Built by TU Munich. Contributors (firstname.lastname@tum.de): Timo Oksanen, Samuel Brodie, Henri Hornburg, Daniel Ostermeier, and Maksim Pavlov
