#ifndef USBGAMEPAD_H
#define USBGAMEPAD_H

#include "USBHID.h"
#include "PlatformMutex.h"



class USBGamepad: public USBHID {
public:
    USBGamepad(bool connect_blocking = true, unint16_t vendor_id = 0x1234, unint16_t = 0x0001, unint16_t product_release = 0x0001); )

    virtual ~USBGamepad();


    virtual const unint8_t *report_desc();
    
protected:

    virtual const unint8_t *configuration_desc(unint8_t index);

private:
}

#endif
