//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "SlaveApplication.h"


Define_Module(SlaveApplication);

void SlaveApplication::initialize()
{
    // TODO - Generated method body
    counter=0;
}

void SlaveApplication::handleMessage(cMessage *msg)
{
    counter++;
    EV << "I'm EtherCatApplicationSlave and receive payload from SlaveMAC"<< msg << "\n";
    cPacket *byte = (cPacket*)msg;
    //EtherCatFrame *payload = (EtherCatFrame*)msg;
    send(byte,"out");
    EV << "I'm MasterApplication and RE-send payload"<< byte << "\n";
    cMsgPar *global=&msg->par("global");
    bool globalValue=global->boolValue();


}

void SlaveApplication::finish(){
        ev << "Payload Received: " << counter <<  "\n";
}
