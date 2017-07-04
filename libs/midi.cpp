#include "pxt.h"
#include "MiNode.h"

MiNode node;

using namespace pxt;
namespace minode {
    //%
    void rgbChooseColor(ConnName connName , MiNodeColor color) {
      MiNodeRGB* pRGB;

      pRGB = node.rgb.attach(connName);

      pRGB->chooseColor(color);
    }

}
