#ifndef _MINODE_H
#define _MINODE_H



#include "mbed.h"

#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "MiNodeConn.h"
#include "MiNodeComponent.h"
#include "MiNodeIO.h"
#include "MiNodeModulePool.h"
#include "MiNodeSwitch.h"
#include "MiNodeFan.h"
#include "MiNodeDHT11.h"
#include "MiNodePIR.h"
#include "MiNodeRotary.h"
#include "MiNodeLightSensor.h"
#include "MiNodeMIC.h"
#include "MiNodeRGB.h"


class MiNode
{

public:
  MiNode() :
  io(MINODE_ID_A0, MINODE_ID_A1, MINODE_ID_A2,
     MINODE_ID_D12, MINODE_ID_D13, MINODE_ID_D14, MINODE_ID_D15)
  {

  }

  ~MiNode() {

  }

  MiNodeIO io;
  MiNodeModulePool<MiNodeSwitch>   switches;
  MiNodeModulePool<MiNodeFan>      fan;
  MiNodeModulePool<MiNodeDHT>      dht11;
  MiNodeModulePool<MiNodePIR>      pir;
  MiNodeModulePool<MiNodeRotary>   rotary;
  MiNodeModulePool<MiNodeLight>    light;
  MiNodeModulePool<MiNodeMIC>      mic;
  MiNodeModulePool<MiNodeRGB>      rgb;

};

#endif