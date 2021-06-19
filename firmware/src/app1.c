#include <string.h>
#include <stdio.h>

#include "app1.h"
#include "portmacro.h"
#include "definitions.h"

APP1_DATA app1Data;
QueueHandle_t eventQueue;
bool TC4_active = false;

void TC4_callBack(TC_COMPARE_STATUS status, uintptr_t context) {
    TC4_active = true;
    TC4_CompareStop();
}

void APP1_Initialize ( void ) {
    app1Data.isInitDone = false;
    app1Data.state = APP1_STATE_INIT;
    eventQueue = xQueueCreate( 10, sizeof(app1Data.queueBuffer) );
    TC4_CompareCallbackRegister(TC4_callBack, (uintptr_t) NULL);
}

bool BT2_Press = false;
int times = 0;
void APP1_Tasks ( void )
{
    if (app1Data.isInitDone == false) {
        app1Data.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, 0);
        if (app1Data.usartHandle != DRV_HANDLE_INVALID ) {
            app1Data.isInitDone = true;
            char *strBuffer = "----- APP1 is Init Done -----\n";
            DRV_USART_WriteBuffer(app1Data.usartHandle, strBuffer, strlen((char*) strBuffer));
        }
    }
    
    if (BT2_Get()) BT2_Press = false;
    else if (BT2_Press == false) {
        TC4_CompareStart();
        LED1_Clear();
        BT2_Press = true;
        sprintf((char*) app1Data.queueBuffer, "Times: %d\n", times++);
//        DRV_USART_WriteBuffer(app1Data.usartHandle, app1Data.queueBuffer, strlen((char*) app1Data.queueBuffer));
        xQueueSend( eventQueue, app1Data.queueBuffer, portMAX_DELAY );
    }
    
    if (TC4_active) {
        TC4_active = false;
        LED1_Set();
    }
}