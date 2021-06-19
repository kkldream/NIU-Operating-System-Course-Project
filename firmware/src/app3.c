/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app3.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app3.h"
int a;
void APP3_Initialize(void) {
//    memset(&app3Data, 0, sizeof (app3Data));
//    app3Data.state = APP3_STATE_INIT;
//    app3Data.usartTaskState = APP3_USART_STATE_DRIVER_OPEN;
//    app3Data.WriteBufHandler = DRV_USART_BUFFER_HANDLE_INVALID;
}


void APP3_Tasks(void) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    LED3_Toggle();
    
//    uint64_t sysCount = 0;
//    uint8_t count = 0;
//    uint8_t counter = 0;
//    bool foundInLast = false;
//
//    app3Data.currentOffset = 0;
//
//    /* Check the application's current state. */
//    switch (app3Data.state) {
//            /* Application's initial state. */
//        case APP3_STATE_INIT:
//            USB_HOST_EventHandlerSet(APP_USBHostEventHandler, 0);
//            USB_HOST_HID_KEYBOARD_EventHandlerSet(APP_USBHostHIDKeyboardEventHandler);
//
//            USB_HOST_BusEnable(USB_HOST_BUS_ALL);
//            app3Data.state = APP3_STATE_WAIT_FOR_HOST_ENABLE;
//            break;
//
//        case APP3_STATE_WAIT_FOR_HOST_ENABLE:
//            /* Check if the host operation has been enabled */
//            if (USB_HOST_BusIsEnabled(USB_HOST_BUS_ALL)) {
//                /* This means host operation is enabled. We can
//                 * move on to the next state */
//                app3Data.state = APP3_STATE_HOST_ENABLE_DONE;
//            }
//            break;
//        case APP3_STATE_HOST_ENABLE_DONE:
//            app3Data.stringSize = 64;
//            if (app3Data.usartTaskState == APP3_USART_STATE_CHECK_FOR_STRING_TO_SEND) {
//                memcpy(&app3Data.string[0], "\r\n***Connect Keyboard***\r\n",
//                        sizeof ("\r\n***Connect Keyboard***\r\n"));
//                app3Data.stringReady = true;
//                /* The test was successful. Lets idle. */
//                app3Data.state = APP3_STATE_WAIT_FOR_DEVICE_ATTACH;
//            }
//            break;
//
//        case APP3_STATE_WAIT_FOR_DEVICE_ATTACH:
//
//            /* Wait for device attach. The state machine will move
//             * to the next state when the attach event
//             * is received.  */
//
//            break;
//
//        case APP3_STATE_DEVICE_ATTACHED:
//
//            /* Wait for device report */
//            if (app3Data.usartTaskState == APP3_USART_STATE_CHECK_FOR_STRING_TO_SEND) {
//                memcpy(&app3Data.string[0], "---Keyboard Connected---\r\n",
//                        sizeof ("---Keyboard Connected---\r\n"));
//                app3Data.stringReady = true;
//                app3Data.stringSize = 64;
//                app3Data.state = APP3_STATE_READ_HID;
//            }
//            break;
//
//        case APP3_STATE_READ_HID:
//
//            if (app3Data.usartTaskState == APP3_USART_STATE_CHECK_FOR_STRING_TO_SEND) {
//                /* We need to display only the non modifier keys */
//                for (count = 0; count < 6; count++) {
//                    if (app3Data.data.nonModifierKeysData[count].event == USB_HID_KEY_PRESSED) {
//                        app3Data.stringReady = false;
//                        /* We can send Data to USART but need to check*/
//                        app3Data.stringSize = 64;
//                        memset(&app3Data.string, 0, sizeof (app3Data.string));
//                        for (counter = 0; counter < 6; counter++) {
//                            if ((app3Data.lastData.data.nonModifierKeysData[counter].event == USB_HID_KEY_PRESSED)
//                                    &&((app3Data.lastData.data.nonModifierKeysData[counter].keyCode ==
//                                    app3Data.data.nonModifierKeysData[count].keyCode))) {
//                                sysCount = SYS_TIME_CounterGet();
//                                if (200 <= 1000 *
//                                        (sysCount - app3Data.lastData.data.nonModifierKeysData[counter].sysCount)
//                                        / SYS_TIME_FrequencyGet()) {
//                                    foundInLast = false;
//                                } else {
//                                    foundInLast = true;
//                                }
//                                break;
//                            }
//                        }
//                        if (foundInLast == false) {
//                            app3Data.stringReady = true;
//                            APP_MapKeyToUsage(app3Data.data.nonModifierKeysData[count].keyCode);
//                        } else {
//                            /* Reset it it false for next iteration */
//                            foundInLast = false;
//                        }
//                    }
//                }
//                /* Store the present to future */
//                memcpy(&app3Data.lastData.data, &app3Data.data, sizeof (app3Data.data));
//            }
//            break;
//
//        case APP3_STATE_DEVICE_DETACHED:
//            app3Data.state = APP3_STATE_HOST_ENABLE_DONE;
//            break;
//
//        case APP3_STATE_ERROR:
//
//            /* The application comes here when the demo
//             * has failed. Provide LED indication .*/
//
//
//            break;
//
//        default:
//            break;
//    }
//    /* Call the USART task routine */
//    APP3_USART_Tasks();
}


/*******************************************************************************
 End of File
 */
