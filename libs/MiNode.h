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
#include "MiNodeRGB.h"
#include "MiNodeDHT11.h"
#include "MiNodeSwitch.h"
#include "MiNodeRotary.h"
#include "MiNodePIR.h"
#include "MiNodeMIC.h"
#include "MiNodeLightSensor.h"
#include "MiNodeFan.h"

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
  MiNodeModulePool<MiNodeRGB>      rgb;
  MiNodeModulePool<MiNodeDHT>      dht11;
  MiNodeModulePool<MiNodeSwitch>   switches;
  MiNodeModulePool<MiNodeRotary>   rotary;
  MiNodeModulePool<MiNodePIR>      pir;
  MiNodeModulePool<MiNodeMIC>      mic;
  MiNodeModulePool<MiNodeLight>    light;
  MiNodeModulePool<MiNodeFan>      fan;

};

#endif