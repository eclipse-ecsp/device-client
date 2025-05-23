[<img src="./images/logo.png" width="300" height="150"/>](logo.png)

[![Build](../../actions/workflows/c-cpp.yml/badge.svg)](../../actions/workflows/c-cpp.yml)
[![License Compliance](../../actions/workflows/license-compliance.yml/badge.svg)](../../actions/workflows/license-compliance.yml)
[![Coverage](../../actions/workflows/UnitTest.yml/badge.svg)](../../actions/workflows/UnitTest.yml)

# Device Client
deviceclient is the device's edge component in the overall Ignite eco system. It aggregates various data from the deployed device, validates them, performs various edge algorithms, persists the data, schedule and upload the data to cloud over secured connections.

This application internally contains many sub-components.

```
deviceclient - Executable component which incorporates all the other components listed below.
libClientBL - contains business logics
libCore - contains core platform logics
libAuto - contains automotive specific usecases
libNetwork - contains cloud communication components
libDevice - contains device specific processing/communication logics
libUtils - contains various utility components
libEvent - Library to create and send events .Using Event library any application in the system can create events and send them to deviceclient.
libmosquitto - mqtt client library
```
Apart from libEvent library, all other components are statically linked with the deviceclient application binary.

Along with the above SW components, deviceclient also comes with a configuration file(using which many functionalities of the Client can be controlled) and cert file(s).

# Table of Contents
* [Getting Started](#getting-started)
* [Usage](#usage)
* [How to contribute](#how-to-contribute)
* [Code of Conduct](#code-of-conduct)
* [Authors](#authors)
* [Security Contact Information](#security-contact-information)
* [Support](#support)
* [Troubleshooting](#troubleshooting)
* [License](#license)
* [Announcements](#announcements)


## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 


### Prerequisites
In order to build this library, in general, you need to have the C++ build environment in your Linux machine. Below installations will help to setup so (Versions of repos may vary based on the OS version).

```
* [cmake] sudo apt install cmake
* [zlib] sudo apt install zlib1g-dev
* [sqlite] sudo apt-get install libsqlite3-dev
* [curl] sudo apt-get install libcurl4-openssl-dev
* [ssl] sudo apt-get install libssl-dev
* [crypto] sudo apt-get install libcrypto++-dev
* [zmq] sudo apt-get install libzmq3-dev
```

#### 3rd-party libraries
Below are the 3rd-party library used internally by deviceclient and built along with deviceclient build process.

```
  -libmosquitto
```

### Build process
Post installing above components, copy the device-client repo code to local machine . 
After that deviceclient can be built as below.
```
<working-directory>\device-client\client> ls -l
\deviceclient
\libClientBL
\libCore
\libAuto
\libNetwork
\libDevice
\libUtils
\libEvent
\libmosquitto
\CMakeLists.txt

<working-directory>\device-client\client> mkdir build
<working-directory>\device-client\client> cd build
<working-directory>\device-client\client\build> cmake ..
<working-directory>\device-client\client\build> make
```

### Installation
Post completion of the build process, deviceclient binary can be found in the ```.\bin\``` folder and the libEvent.so file can be found in the ```.\lib\``` folder.

a. Load the binary file `deviceclient` into the target device (ex: /usr/bin). 
b. Load the shared library file `libEvent.so` also into the target device (ex: /usr/lib). 
c. Also, load the configuration and cert files (that are available in the device-client/assets/ folder) into the target device (ex: assets/config or /usr/config etc.).


### Coding style check configuration
Coding guidelines are separately documented in the CodingGuidelines.pdf document.

## Usage
The deviceclient application can be used by invoking it like below.

```
deviceclient -c <configuration file path> [optional switches]

[optional switches]
-re <restart reason> <restart count> - to set the client restart reason and restart count
-d <debug log level {1..7}> - to set debug log level
-i - to print client details and then exit
```

### How to build?
Below is the folder structure of all deviceclient components.

```
	\deviceclient
		\CMakeLists.txt
		<other files>
	\libClientBL
		\CMakeLists.txt
		<other files>
	\libCore
		\CMakeLists.txt
		<other files>
	\libAuto
		\CMakeLists.txt
		<other files>
	\libNetwork
		\CMakeLists.txt
		<other files>
	\libDevice
		\CMakeLists.txt
		<other files>
	\libUtils
		\CMakeLists.txt
		<other files>
	\libEvent
		\CMakeLists.txt
		<other files>
	\libmosquitto
		\CMakeLists.txt
		<other files>
	\CMakeLists.txt
```

Now the build can be triggered post setting up the toolchain (if any).

### Running the tests

Google test framework is used for unit tests. In order to run the unit tests, the deviceclient application has to be built by enabling the UT flag 'IC_UNIT_TEST' in the top cmake file. Post building the client with unit test flag enabled, client shall be started to run it along with the unit tests.

### Sample Simulator
Sample device simulator is provided for validating the messages received from cloud, this simulator mimics the behavior of receiving the message(Over ZMQ) from deviceclient and then sending the message back to deviceclient.
Usage instruction of this simulator is present at [HowToUse.txt](./simulators/zmq_device_simulator/HowToUse.txt)

## How to contribute
Please read [CONTRIBUTING.md](./CONTRIBUTING.md) for details on our contribution guidelines, and the process for submitting pull requests to us.

## Code of Conduct
Please read [CODE_OF_CONDUCT.md](./CODE_OF_CONDUCT.md) for details on our code of conduct, and the process for submitting pull requests to us.


## Authors
* [**Nayan Deshpande**](https://github.com/nayandeshpandeharman) - *Initial work*
* **Viji Daniel John Thankachan** - *Initial work* 

See also the list of [contributors](https://github.com/eclipse-ecsp/device-client/graphs/contributors) who participated in this project.


## Security Contact Information
Please read [SECURITY.md](./SECURITY.md) to raise any security related issues.

## Support
Please write to us at [csp@harman.com](mailto:csp@harman.com)

## Troubleshooting
Please read [CONTRIBUTING.md](./CONTRIBUTING.md) for details on how to raise an issue and submit a pull request to us.

## License
This project is licensed under the Apache-2.0 License - see the [LICENSE](./LICENSE) file for details.


## Announcements
All updates to this component are present in our [releases page](https://github.com/eclipse-ecsp/device-client/releases).
For the versions available, see the [tags on this repository](https://github.com/eclipse-ecsp/device-client/tags)..

