/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app3.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP3_Initialize" and "APP3_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP3_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP3_H
#define _APP3_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "configuration.h"
#include "definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP3_STATE_INIT=0,
    APP3_STATE_SERVICE_TASKS,
    APP3_STATE_OPEN_HOST_LAYER,
    APP3_STATE_WAIT_FOR_HOST_ENABLE,
    APP3_STATE_HOST_ENABLE_DONE,
    APP3_STATE_WAIT_FOR_DEVICE_ATTACH,
    APP3_STATE_DEVICE_ATTACHED,
    APP3_STATE_READ_HID,
    APP3_STATE_DEVICE_DETACHED,
    APP3_STATE_CHANGE_DEVICE_PARAMETERS,
    APP3_USART_STATE_DRIVER_OPEN,
    APP3_USART_STATE_CHECK_FOR_STRING_TO_SEND,
    APP3_USART_STATE_DRIVER_WRITE,
    APP3_STATE_ERROR
    /* TODO: Define states used by the application state machine. */

} APP3_STATES;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP3_STATES state;

} APP3_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP3_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP3_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP3_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP3_Initialize ( void );


/*******************************************************************************
  Function:
    void APP3_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP3_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP3_Tasks( void );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP3_H */

/*******************************************************************************
 End of File */

