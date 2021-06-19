#include <string.h>
#include <stdio.h>

#include "app2.h"
#include "peripheral/port/plib_port.h"
#include "portmacro.h"
#include "definitions.h"

APP2_DATA app2Data;
bool TC5_active = false;

void TC5_callBack(TC_COMPARE_STATUS status, uintptr_t context) {
    TC5_active = true;
    TC5_CompareStop();
}

void APP2_Initialize ( void ) {
    app2Data.state = APP2_STATE_INIT;
    TC5_CompareCallbackRegister(TC5_callBack, (uintptr_t) NULL);
}

bool BT3_Press = false;
void APP2_Tasks ( void )
{
    if (app2Data.isInitDone == false) {
        app2Data.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, 0);
        if (app2Data.usartHandle != DRV_HANDLE_INVALID ) {
            app2Data.isInitDone = true;
            char *strBuffer = "----- APP2 is Init Done -----\n";
            DRV_USART_WriteBuffer(app2Data.usartHandle, strBuffer, strlen((char*) strBuffer));
        }
    }

    if (BT3_Get()) BT3_Press = false;
    else if (BT3_Press == false) {
        TC5_CompareStart();
        LED2_Clear();
        BT3_Press = true;
        UBaseType_t num = uxQueueMessagesWaiting(eventQueue);
        while ((int) num > 0) {
            xQueueReceive( eventQueue, app2Data.queueBuffer, portMAX_DELAY );
            DRV_USART_WriteBuffer(app2Data.usartHandle, app2Data.queueBuffer, strlen((char*) app2Data.queueBuffer));
            num = uxQueueMessagesWaiting(eventQueue);
        }
    }
    
    if (TC5_active) {S
        TC5_active = false;
        LED2_Set();
    }
}