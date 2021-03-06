 /*
-------------------------------------------------------------------------
 MESSAGE DEFINITION SECTION

 Following the header section is the body of the Message Compiler
 source file. The body consists of zero or more message definitions.
 Each message definition begins with one or more of the following
 statements:

 MessageId = [number|+number]
 Severity = severity_name
 Facility = facility_name
 SymbolicName = name

 The MessageId statement marks the beginning of the message
 definition. A MessageID statement is required for each message,
 although the value is optional. If no value is specified, the value
 used is the previous value for the facility plus one. If the value
 is specified as +number then the value used is the previous value
 for the facility, plus the number after the plus sign. Otherwise, if
 a numeric value is given, that value is used. Any MessageId value
 that does not fit in 16 bits is an error.

 The Severity and Facility statements are optional. These statements
 specify additional bits to OR into the final 32-bit message code. If
 not specified they default to the value last specified for a message
 definition. The initial values prior to processing the first message
 definition are:

 Severity=Success
 Facility=Application

 The value associated with Severity and Facility must match one of
 the names given in the FacilityNames and SeverityNames statements in
 the header section. The SymbolicName statement allows you to
 associate a C/C++ symbolic constant with the final 32-bit message
 code.
 */
 // For the sake of keeping common message-IDs with the pywin32 service
 // modules etc, we keep these generic messages
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: PYS_E_GENERIC_ERROR
//
// MessageText:
//
// %1
//
#define PYS_E_GENERIC_ERROR              ((DWORD)0xC00000FFL)

//
// MessageId: PYS_E_GENERIC_WARNING
//
// MessageText:
//
// %1
//
#define PYS_E_GENERIC_WARNING            ((DWORD)0x800000FFL)

//
// MessageId: E_PYISAPI_FILTER_FAILED
//
// MessageText:
//
// The pyISAPI filter encountered an error.
// %n%1
// %nThe last windows error was: %2
//
#define E_PYISAPI_FILTER_FAILED          ((DWORD)0xC0001000L)

//
// MessageId: E_PYISAPI_EXTENSION_FAILED
//
// MessageText:
//
// The pyISAPI extension encountered an error.
// %n%1
// %nThe last windows error was: %2
//
#define E_PYISAPI_EXTENSION_FAILED       ((DWORD)0xC0001001L)

 // A nod to py2exe or similar tools
//
// MessageId: E_PYISAPI_STARTUP_FAILED
//
// MessageText:
//
// The pyISAPI extension failed to initialize.
// %n%1
// %nThe last windows error was: %2
//
#define E_PYISAPI_STARTUP_FAILED         ((DWORD)0xC0001100L)

