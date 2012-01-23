/*
	WakeOnLan by Ryan Esteves
	
	Send WOL magic packets
	
	To Use:
	(Arduino 1.0+)
		1. Initialize WakeOnLan with your EthernetUDP object.
		2. Send magic packet using the method 'send(byte* mac, byte port);'
		3. Repeat step 3 for as many packets as you would like to send.
	(Arduino 0023-)
		1. Initiate Udp
		2. Send magic packet using the static method 'send(byte* mac, byte port);'
		3. Repeat step 3 for as many packets as you would like to send.
*/
#ifndef wakeonloan_h
#define wakeonloan_h

#if defined(ARDUINO) && ARDUINO >= 100 // Arduino 1.0+ compatibility

# include "EthernetUdp.h"
# include "Arduino.h"
class WakeOnLan {
	public:
		WakeOnLan(EthernetUDP Upd);
		// Send a magic packet to the provided mac address on the specified port
		void send(byte* mac, byte port);
		
	private:
		EthernetUDP _udp;
		byte _ip[];
};

#else

# include "Udp.h"
# include "WProgram.h"
class WakeOnLan {
	public:
		WakeOnLan();	
		// Send a magic packet to the provided mac address on the specified port
		static void send(byte* mac, byte port);
		
	private:
		byte _ip[];	
};

#endif

#endif