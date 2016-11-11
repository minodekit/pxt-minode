#ifndef MINODE_COMPONENT_h
#define MINODE_COMPONENT_h

#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "MiNodeConn.h"


#define MINODE_ID_START                 100
#define MINODE_ID_NC                    (uint16_t)0xFFFFFFFF

#define MINODE_ID_A0                    MINODE_ID_START
#define MINODE_ID_A1                    MINODE_ID_A0 + 2
#define MINODE_ID_A2                    MINODE_ID_A0 + 4

#define MINODE_ID_D_START               MINODE_ID_START + 10
#define MINODE_ID_D0                    MINODE_ID_NC
#define MINODE_ID_D1                    MINODE_ID_NC
#define MINODE_ID_D2                    MINODE_ID_NC
#define MINODE_ID_D3                    MINODE_ID_NC
#define MINODE_ID_D4                    MINODE_ID_NC
#define MINODE_ID_D5                    MINODE_ID_NC
#define MINODE_ID_D6                    MINODE_ID_NC
#define MINODE_ID_D7                    MINODE_ID_NC
#define MINODE_ID_D8                    MINODE_ID_NC
#define MINODE_ID_D9                    MINODE_ID_NC
#define MINODE_ID_D10                   MINODE_ID_NC
#define MINODE_ID_D11                   MINODE_ID_NC
#define MINODE_ID_D12                   MINODE_ID_D_START + 24
#define MINODE_ID_D13                   MINODE_ID_D_START + 26
#define MINODE_ID_D14                   MINODE_ID_D_START + 28
#define MINODE_ID_D15                   MINODE_ID_D_START + 30




#define MINODE_ID_MODULE_START          150
#define MINODE_ID_MODULE_SWITCH         MINODE_ID_MODULE_START
#define MINODE_ID_MODULE_LIGHT          MINODE_ID_MODULE_START+20
#define MINODE_ID_MODULE_DHT11          MINODE_ID_MODULE_START+40
#define MINODE_ID_MODULE_RGB            MINODE_ID_MODULE_START+60
#define MINODE_ID_MODULE_PIR            MINODE_ID_MODULE_START+80
#define MINODE_ID_MODULE_MIC            MINODE_ID_MODULE_START+100
#define MINODE_ID_MODULE_ROTARY         MINODE_ID_MODULE_START+120
#define MINODE_ID_MODULE_RELAY          MINODE_ID_MODULE_START+140
#define MINODE_ID_MODULE_FAN            MINODE_ID_MODULE_START+160
#define MINODE_ID_MODULE_SPEAKER        MINODE_ID_MODULE_START+180


class MiNodeComponent : public MicroBitComponent
{
public:
  MiNodeComponent();
  ~MiNodeComponent();

  ConnName getConnector();
  AnalogConnName AgetConnector();
  int getId();

protected:

  void initConnector(ConnName connName);
  void initAConnector(AnalogConnName connName);

  ConnName cn;
  AnalogConnName cna;
  int baseId;
};


#endif