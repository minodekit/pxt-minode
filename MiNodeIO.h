#ifndef MINODE_IO_H
#define MINODE_IO_H

#include "mbed.h"
#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MiNodeComponent.h"
#include "MiNodeConn.h"


class MiNodeIO
{

public:
  MiNodeConn a[0];
  MiNodeConn A0;
  MiNodeConn A1;
  MiNodeConn A2;

  MiNodeConn d[0];
  MiNodeConn D0;
  MiNodeConn D1;
  MiNodeConn D2;
  MiNodeConn D3;
  MiNodeConn D4;
  MiNodeConn D5;
  MiNodeConn D6;
  MiNodeConn D7;
  MiNodeConn D8;
  MiNodeConn D9;
  MiNodeConn D10;
  MiNodeConn D11;
  MiNodeConn D12;
  MiNodeConn D13;
  MiNodeConn D14;
  MiNodeConn D15;

  MiNodeIO( int ID_A0, int ID_A1, int ID_A2,
            int ID_D12,int ID_D13,int ID_D14,int ID_D15);

};

#endif