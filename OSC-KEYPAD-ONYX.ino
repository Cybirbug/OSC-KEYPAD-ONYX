#include "EspUsbHostKeybord.h"
#include "EspUsbHost.h"
#include <SPI.h>
#include <OSCMessage.h>
#include <EthernetUdp.h>
#include "defines.h"
//s3 pins
//MOSI: 11
//MISO : 13
//SCK : 12
//SS : 10

const IPAddress broadcastip = { 255,255,255,255 };
const IPAddress subnet = { 255,0,0,0 };

IPAddress ip(10, 0, 0, 253);

unsigned int consolePort = 8000;      // local port to listen on

EthernetUDP Udp;


//const uint16_t map[24] {
//    0x3a, 0x3b, 0x3c, 0x3d, 
//    0x04, 0x05, 0x06, 0x07, 
//    0x0c, 0x0d, 0x0e, 0x0f,
//    0x10, 0x11, 0x12, 0x13,
//    0x3e, 0x3f, 0x40, 0x41,
//    0x08, 0x09, 0x0a, 0x0b
//};

class MyEspUsbHostKeybord : public EspUsbHostKeybord {
public:
    byte oldData[16];

    void onKey(usb_transfer_t* transfer) {
        uint8_t* const p = transfer->data_buffer;

        for (int i = 0; i < 16; i++) {
            if (oldData[i] != p[i]) {
                int pitch = p[i] | oldData[i];//figure out what key was pressed or lifted
                uint velocity = 0;
                if (p[i] > 0) velocity = 1;
                uint press = 1;
                OSCMessage msg("");
                switch (pitch)
                {
                case 0x3a: {//1
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/0/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x3b: {//2
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/1/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x3c: {//3
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/2/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x3d: {//4
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/3/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }

                    break;
                }
                case 0x04: {//5
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/10/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x05: {//6
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/11/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x06: {//7
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/12/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x07: {//8
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/13/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x0c: {//9
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/20/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x0d: {//10
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/21/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x0e: {//11
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/22/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x0f: {//12
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/23/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x10: {//13
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/30/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/30/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x11: {//14
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/31/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/31/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x12: {//15
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/32/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/32/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x13: {//16
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/33/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/33/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x3e: {//17
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/40/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/40/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x3f: {//18
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/41/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/41/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x40: {//19
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/42/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/42/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x41: {//20
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/43/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/43/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x08: {//21
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/50/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/50/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x09: {//22
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/51/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/51/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x0a: {//23
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/52/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/52/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                case 0x0b: {//24
                    if (velocity == 1) {
                        OSCMessage msg("/Mx/playback/page2/53/go");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    else {
                        OSCMessage msg("/Mx/playback/page2/53/release");
                        msg.add(press);
                        Udp.beginPacket(broadcastip, consolePort);
                        msg.send(Udp); // send the bytes to the SLIP stream
                        Udp.endPacket(); // mark the end of the OSC Packet
                        msg.empty(); // free space occupied by message
                    }
                    break;
                }
                default:
                    break;
                }
                oldData[i] = p[i];
            }
        }
    };
};

//this has to go here and not near the top for some compiler reason
MyEspUsbHostKeybord usbHost;
void setup() {
    Serial.begin(115200);
    usbHost.begin();
    Ethernet.init(10);  // Most Arduino shields
    Ethernet.begin(mac[0], ip, dns, dns, subnet);
    delay(500);
    Udp.begin(consolePort);
    Serial.println("setup end");
}

void loop() {
    usbHost.task();
}
