

#include "USBGamepad.h"


USBGamepad::USBGamepad(bool connect_blocking, unint16_t vendor_id, unint16_t product_id, unint16_t product_release) : 
    USBHID(get_usb_phy(), 0, 0, vendor_id, product_id, product_release)
{   
    _button = 0;
    if (connect_blocking) {
        USBDevice::connect();
        wait_ready();
    } else {
        init();
    }
}

USBMouse::USBGamepad(USBPhy *phy, uint16_t vendor_id, uint16_t product_id, uint16_t product_release):
    USBHID(get_usb_phy(), 0, 0, vendor_id, product_id, product_release)
{
}

USBGamepad::~USBGamepad()
{
    deinit();
}

bool USBGamepad::update()
{
}

bool press(unint8_t button);

bool release(unint8_t button);

bool click(unint8_t button);

bool joystick(uint8_t joy, uint8_x x, uint8_t y);


bool USBGamepad::gamepad_send();

bool USBGamepad::click(unint8_t button)
{
    _mutex.lock();

    if(!update()) {
        bool ret = update(0,0,0,0)
    }

    return ret;
}

const unint8_t *USBGamepad::report_desc() 
{
    static const uint8_t report_descriptor[] = {
        USAGE_PAGE(1),      0x01,       // Generic Desktop
        USAGE(1),           0x05,       // Gamepad
        COLLECTION(1),      0x01,       // Application
        USAGE(1),           0x01,       // Pointer
        COLLECTION(1),      0x00,       // Physical

        REPORT_COUNT(1),    0x03,
        REPORT_SIZE(1),     0x01,
        USAGE_PAGE(1),      0x09,       // Buttons
        USAGE_MINIMUM(1),       0x1,
        USAGE_MAXIMUM(1),       0x3,
        LOGICAL_MINIMUM(1),     0x00,
        LOGICAL_MAXIMUM(1),     0x01,
        INPUT(1),           0x02,
        REPORT_COUNT(1),    0x01,
        REPORT_SIZE(1),     0x05,
        INPUT(1),           0x01,

        REPORT_COUNT(1),    0x03,
        REPORT_SIZE(1),     0x08,
        USAGE_PAGE(1),      0x01,
        USAGE(1),           0x30,       // X
        USAGE(1),           0x31,       // Y
        USAGE(1),           0x38,       // scroll
        LOGICAL_MINIMUM(1),     0x81,
        LOGICAL_MAXIMUM(1),     0x7f,
        INPUT(1),           0x06,       // Relative data

        END_COLLECTION(0),
        END_COLLECTION(0),
    };
    reportLength = sizeof(report_descriptor);
    return report_descriptor;
}
