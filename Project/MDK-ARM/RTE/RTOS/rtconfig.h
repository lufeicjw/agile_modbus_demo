/* RT-Thread config file */

#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

#if defined(__CC_ARM) || defined(__CLANG_ARM)
#include "RTE_Components.h"

#if defined(RTE_USING_FINSH)
#define RT_USING_FINSH
#endif //RTE_USING_FINSH

#endif //(__CC_ARM) || (__CLANG_ARM)

// <<< Use Configuration Wizard in Context Menu >>>
// <h>Basic Configuration
// <o>Maximal level of thread priority <8-256>
//  <i>Default: 32
#define RT_THREAD_PRIORITY_MAX  8
// <o>OS tick per second
//  <i>Default: 1000   (1ms)
#define RT_TICK_PER_SECOND  1000
// <o>Alignment size for CPU architecture data access
//  <i>Default: 4
#define RT_ALIGN_SIZE   4
// <o>the max length of object name<2-16>
//  <i>Default: 8
#define RT_NAME_MAX    8
// <c1>Using RT-Thread components initialization
//  <i>Using RT-Thread components initialization
#define RT_USING_COMPONENTS_INIT
// </c>

#define RT_USING_USER_MAIN

// <o>the stack size of main thread<1-4086>
//  <i>Default: 512
#define RT_MAIN_THREAD_STACK_SIZE     512

// </h>

// <h>Debug Configuration
// <c1>enable kernel debug configuration
//  <i>Default: enable kernel debug configuration
#define RT_DEBUG
// </c>
// <c1>enable kernel debug color
//  <i>Default: enable kernel debug color
#define RT_DEBUG_COLOR
// </c>
// <o>enable components initialization debug configuration<0-1>
//  <i>Default: 0
#define RT_DEBUG_INIT 0
// <c1>thread stack over flow detect
//  <i> Diable Thread stack over flow detect
//#define RT_USING_OVERFLOW_CHECK
// </c>
// </h>

// <h>Hook Configuration
// <c1>using hook
//  <i>using hook
//#define RT_USING_HOOK
// </c>
// <c1>using idle hook
//  <i>using idle hook
#define RT_USING_IDLE_HOOK
// </c>
// </h>

// <e>Software timers Configuration
// <i> Enables user timers
#define RT_USING_TIMER_SOFT         0
#if RT_USING_TIMER_SOFT == 0
    #undef RT_USING_TIMER_SOFT
#endif
// <o>The priority level of timer thread <0-31>
//  <i>Default: 4
#define RT_TIMER_THREAD_PRIO        4
// <o>The stack size of timer thread <0-8192>
//  <i>Default: 512
#define RT_TIMER_THREAD_STACK_SIZE  512
// </e>

// <h>IPC(Inter-process communication) Configuration
// <c1>Using Semaphore
//  <i>Using Semaphore
#define RT_USING_SEMAPHORE
// </c>
// <c1>Using Mutex
//  <i>Using Mutex
#define RT_USING_MUTEX
// </c>
// <c1>Using Event
//  <i>Using Event
#define RT_USING_EVENT
// </c>
// <c1>Using MailBox
//  <i>Using MailBox
#define RT_USING_MAILBOX
// </c>
// <c1>Using Message Queue
//  <i>Using Message Queue
//#define RT_USING_MESSAGEQUEUE
// </c>
// </h>

// <h>Memory Management Configuration
// <c1>Dynamic Heap Management
//  <i>Dynamic Heap Management
//#define RT_USING_HEAP
// </c>
// <c1>using small memory
//  <i>using small memory
//#define RT_USING_SMALL_MEM
// </c>
// <c1>using tiny size of memory
//  <i>using tiny size of memory
//#define RT_USING_TINY_SIZE
// </c>
// </h>

// <h>Console Configuration
// <c1>Using console
//  <i>Using console
#define RT_USING_CONSOLE
// </c>
// <o>the buffer size of console <1-1024>
//  <i>the buffer size of console
//  <i>Default: 128  (128Byte)
#define RT_CONSOLEBUF_SIZE          512
// <s>the device name for console
//  <i>the device name for console
#define RT_CONSOLE_DEVICE_NAME      "usart1"
// </h>

#if defined(RT_USING_FINSH)
    #define FINSH_USING_MSH
    #define FINSH_USING_MSH_ONLY
    // <h>Finsh Configuration
    // <o>the priority of finsh thread <1-7>
    //  <i>the priority of finsh thread
    //  <i>Default: 6
    #define __FINSH_THREAD_PRIORITY     4
    #define FINSH_THREAD_PRIORITY       (RT_THREAD_PRIORITY_MAX / 8 * __FINSH_THREAD_PRIORITY + 1)
    // <o>the stack of finsh thread <1-4096>
    //  <i>the stack of finsh thread
    //  <i>Default: 4096  (4096Byte)
    #define FINSH_THREAD_STACK_SIZE     1024
    // <o>the history lines of finsh thread <1-32>
    //  <i>the history lines of finsh thread
    //  <i>Default: 5
    #define FINSH_HISTORY_LINES         5

    #define FINSH_USING_SYMTAB
    #define FINSH_USING_HISTORY
    // </h>
#endif

// <e>AT commands Configuration
// <i> Enables AT commands
#define RT_USING_AT         1
#if RT_USING_AT == 0
    #undef RT_USING_AT
#endif
#ifdef RT_USING_AT
// <c1>enable debug log output
//  <i>enable debug log output
#define AT_DEBUG
// </c>
// <c1>enable AT commands client
//  <i>enable AT commands client
#define AT_USING_CLIENT
// </c>
#ifdef AT_USING_CLIENT
// <o>the maximum number of supported clients
//  <i>Default: 1
#define AT_CLIENT_NUM_MAX   1
// <c1>enable CLI(Command-Line Interface) for AT commands
//  <i>enable CLI(Command-Line Interface) for AT commands
#define AT_USING_CLI
// </c>
// <c1>enable print RAW format AT command communication data
//  <i>enable print RAW format AT command communication data
//#define AT_PRINT_RAW_CMD
// </c>
// <o>the maximum length of AT Commands buffer
//  <i>Default: 128
#define AT_CMD_MAX_LEN      128
#endif
#endif
// </e>

// <h>WIFI Configuration
// <s>the client device name for wifi
//  <i>the client device name for wifi
#define WIFI_CLIENT_DEVICE_NAME     "usart3"
// <o>the power pin of wifi
//  <i>the power pin of wifi
#define WIFI_POWER_PIN              5
// <o>the reset pin of wifi
//  <i>the reset pin of wifi
#define WIFI_RESET_PIN              6
// <o>the recv buf len of wifi
//  <i>the recv buf len of wifi
#define WIFI_RECV_BUFF_LEN          1024
// <o>the listen port of wifi
//  <i>the listen port of wifi
#define WIFI_LISTEN_PORT            502
// <o>the client timeout(/s) of wifi
//  <i>the client timeout(/s) of wifi
#define WIFI_CLIENT_TIMEOUT         10
// </h>

// <<< end of configuration section >>>

#endif
