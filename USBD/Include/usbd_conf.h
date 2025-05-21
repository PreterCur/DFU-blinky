/*!
    \file    usbd_conf.h
    \brief   usb device driver basic configuration

    \version 2024-01-05, V2.3.0, firmware for GD32F10x
*/

/*
    Copyright (c) 2024, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#ifndef __USBD_CONF_H
#define __USBD_CONF_H

#include "gd32f10x.h"

/* define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
#define USBD_LOWPWR_MODE_ENABLE

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

/* link power mode support */
/* #define LPM_ENABLED */


//USB STANDARD HID CONFIG
#ifdef USB_HID_STANDARD_KEYBOARD

#define USBD_CFG_MAX_NUM                   1
#define USBD_ITF_MAX_NUM                   1

#define USBD_HID_INTERFACE                 0

/* endpoint count used by the HID device */
#define EP_COUNT                           (2)

#define USB_STRING_COUNT                   4

/* endpoint0, Rx/Tx buffers address offset */
#define EP0_TX_ADDR                        0x20
#define EP0_RX_ADDR                        0x40

#define HID_INT_TX_ADDR                    0x50
#define HID_INT_RX_ADDR                    0x60

#define HID_IN_EP                          EP_IN(1)

#define HID_IN_PACKET                      8

/* base address of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000)

#endif


//USB CUSTOM HID CONFIG
#if defined(USB_HID_CUSTOM)

#define USBD_CFG_MAX_NUM                   1U
#define USBD_ITF_MAX_NUM                   1U

#define CUSTOM_HID_INTERFACE               0U

/* define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
//#define USB_DEVICE_LOW_PWR_MODE_SUPPORT

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */


/* endpoint polling interval in ms */

#define CUSTOM_HID_EP_IN_poll_interval          0x20U
#define CUSTOM_HID_EP_OUT_poll_interval         0x20U


/* endpoint count used by the CDC ACM device */
#define CUSTOMHID_IN_EP                    EP_IN(1U)
#define CUSTOMHID_OUT_EP                   EP_OUT(1U)

#define CUSTOMHID_IN_PACKET                2U
#define CUSTOMHID_OUT_PACKET               2U

/* endpoint0, Rx/Tx buffers address offset */
#define EP0_RX_ADDR                        (0x40U)
#define EP0_TX_ADDR                        (0xA0U)

/* CDC data Tx buffer address offset */
#define HID_TX_ADDR                        (0x140U)

/* CDC data Rx buffer address offset */
#define HID_RX_ADDR                        (0x100U)

/* endpoint count used by the CDC ACM device */
#define EP_COUNT                           (4U)

#define USB_STRING_COUNT                   4U

/* base address of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000)
#endif


#ifdef USB_COMPOSITE_HID_KEYBOARD_CUSTOM

#define USBD_CFG_MAX_NUM                   1U
#define USBD_ITF_MAX_NUM                   2U

/* define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
//#define USB_DEVICE_LOW_PWR_MODE_SUPPORT

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

#define USBD_HID_INTERFACE                 0x01
#define CUSTOM_HID_INTERFACE               0x00

/* endpoint0, Rx/Tx buffers address offset */
#define EP0_RX_ADDR                        (0x40U)
#define EP0_TX_ADDR                        (0x80U)


//HID Keyboard Rx/Tx buffers and EP
#define HID_IN_EP                          EP_IN(2)

#define HID_IN_PACKET                      8

#define HID_INT_RX_ADDR                        0xC0U
#define HID_INT_TX_ADDR                        (HID_INT_RX_ADDR + HID_IN_PACKET)


/* class layer parameter used by the Custom HID device */
#define CUSTOMHID_IN_EP                    EP_IN(1)
#define CUSTOMHID_OUT_EP                   EP_OUT(1)

#define CUSTOMHID_IN_PACKET                2
#define CUSTOMHID_OUT_PACKET               2

/* HID data Tx/Rx buffer address offset */
#define HID_RX_ADDR                        0xE0U
#define HID_TX_ADDR                        0xF0U



/* endpoint count used by the composite device */
#define EP_COUNT                           3U

/* base address offset of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000U)

/* base address of the allocation buffer, used for buffer descriptor table and packet memory */
#define BUFFER_ADDRESS                     (0x0000U)


/* endpoint polling interval in ms */
#define CUSTOM_HID_EP_IN_poll_interval          0x20U
#define CUSTOM_HID_EP_OUT_poll_interval         0x20U
#define STANDARD_HID_EP_IN_poll_interval          0x20U
#define STANDARD_HID_EP_OUT_poll_interval         0x20U
#endif


#ifdef USB_COMPOSITE_KEYBOARD_CDC

#define USBD_CFG_MAX_NUM                   1U
#define USBD_ITF_MAX_NUM                   3U

/* define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
//#define USB_DEVICE_LOW_PWR_MODE_SUPPORT

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

#define USBD_HID_INTERFACE                 0x00
#define CDC_COM_INTERFACE                  0x01



//#define USBD_COMPOSITE_EP0_MAX_SIZE         128U
#define USBD_COMPOSITE_EP0_MAX_SIZE         USBD_EP0_MAX_SIZE


//HID Keyboard Rx/Tx buffers and EP
#define HID_IN_EP                          EP_IN(4U)

#define CDC_CMD_EP                         EP_IN(2U)
#define CDC_IN_EP                          EP_IN(1U)
#define CDC_OUT_EP                         EP_OUT(3U)

#define HID_IN_PACKET                       8

#define CDC_ACM_CMD_PACKET_SIZE            8U
#define CDC_ACM_DATA_PACKET_SIZE           64U

#if (USBD_COMPOSITE_EP0_MAX_SIZE == USBD_EP0_MAX_SIZE)
/* endpoint0, Rx/Tx buffers address offset */
#define EP0_RX_ADDR                        (0x40U)
#define EP0_TX_ADDR                        (0x80U)

/* endpoint count used by the HID device */
#define HID_INT_RX_ADDR                    (0x180U)
#define HID_INT_TX_ADDR                    (0x190U)

/* endpoint count used by the CDC ACM device */
/* CDC data Tx buffer address offset */
#define BULK_TX_ADDR                       (0x140U)

/* CDC data Rx buffer address offset */
#define BULK_RX_ADDR                       (0x100U)

/* CDC command Tx buffer address offset */
#define CDC_INT_TX_ADDR                    (0xC0U)


#else
/* endpoint0, Rx/Tx buffers address offset */
#define EP0_RX_ADDR                             (0x80U)
#define EP0_TX_ADDR                             (0x100U)

#define HID_INT_RX_ADDR                         (0x180U)
#define HID_INT_TX_ADDR                         (0x190U)

/* CDC data Tx buffer address offset */
#define BULK_TX_ADDR                            (0x220U) 

/* CDC data Rx buffer address offset */
#define BULK_RX_ADDR                            (0x1E0U)

/* CDC command Tx buffer address offset */
#define CDC_INT_TX_ADDR                         (0x1A0U)
#endif

/* endpoint count used by the composite device */
#define EP_COUNT                           5U

#define USB_STRING_COUNT                   4U

/* base address offset of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000U)


/* endpoint polling interval in ms */
#define STANDARD_HID_EP_IN_poll_interval          0x20U
#define STANDARD_HID_EP_OUT_poll_interval         0x20U
#endif


#ifdef USB_DUAL_CDC_ACM

#define USBD_HID_INTERFACE                 0x04U


#define USBD_CFG_MAX_NUM                   1U
#define USBD_ITF_MAX_NUM                   5U

/* define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
//#define USB_DEVICE_LOW_PWR_MODE_SUPPORT

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

/* endpoint count used by the CDC ACM device 0 */
#define CDC_ACM0_CMD_EP                    EP_IN(3U)
#define CDC_ACM0_DATA_IN_EP                EP_IN(1U)
#define CDC_ACM0_DATA_OUT_EP               EP_OUT(1U)

/* endpoint count used by the CDC ACM device 1 */
#define CDC_ACM1_CMD_EP                    EP_IN(4U)
#define CDC_ACM1_DATA_IN_EP                EP_IN(2U)
#define CDC_ACM1_DATA_OUT_EP               EP_OUT(2U)

/* endpoint0, Rx/Tx buffers address offset */
#define EP0_RX_ADDR                        (0x40U)
#define EP0_TX_ADDR                        (0x80U)

/* CDC0 data Tx buffer address offset */
#define BULK0_TX_ADDR                      (0x110U)

/* CDC0 data Rx buffer address offset */
#define BULK0_RX_ADDR                      (0xD0U)

/* CDC0 command Tx buffer address offset */
#define INT0_TX_ADDR                       (0xC0U)

/* CDC1 data Tx buffer address offset */
#define BULK1_TX_ADDR                      (0x1A0U)

/* CDC1 data Rx buffer address offset */
#define BULK1_RX_ADDR                      (0x160U)

/* CDC1 command Tx buffer address offset */
#define INT1_TX_ADDR                       (0x150U)


//HID Interface defines
#define HID_IN_PACKET                       8

#define HID_IN_EP                          EP_IN(5U)

/* endpoint count used by the HID device */
#define HID_INT_RX_ADDR                        (0x200U)
#define HID_INT_TX_ADDR                        (0x210U)

#define CDC_ACM_CMD_PACKET_SIZE            8U
#define CDC_ACM_DATA_PACKET_SIZE           64U

/* endpoint count used by the CDC ACM device */
#define EP_COUNT                           (6U)
#define USB_STRING_COUNT                   4U

/* base address offset of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000U)


#endif

//CDC ACM CONFIG
#if defined(USB_CDC_ACM)

#define USBD_CFG_MAX_NUM                   1U
#define USBD_ITF_MAX_NUM                   1U

#define CDC_COM_INTERFACE                  0U

/* define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
//#define USB_DEVICE_LOW_PWR_MODE_SUPPORT

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

/* endpoint count used by the CDC ACM device */
#define CDC_CMD_EP                         EP_IN(2U)
#define CDC_IN_EP                          EP_IN(1U)
#define CDC_OUT_EP                         EP_OUT(3U)

/* endpoint0, Rx/Tx buffers address offset */
#define EP0_RX_ADDR                        (0x40U)
#define EP0_TX_ADDR                        (0x80U)

/* CDC data Tx buffer address offset */
#define BULK_TX_ADDR                       (0x140U)

/* CDC data Rx buffer address offset */
#define BULK_RX_ADDR                       (0x100U)

/* CDC command Tx buffer address offset */
#define INT_TX_ADDR                        (0xC0U)

#define CDC_ACM_CMD_PACKET_SIZE            8U
#define CDC_ACM_DATA_PACKET_SIZE           64U

/* endpoint count used by the CDC ACM device */
#define EP_COUNT                           (4U)

#define USB_STRING_COUNT                   4U

/* base address offset of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000U)
#endif



//USB IAP CONFIG
#if defined(USB_IAP)

#define USBD_CFG_MAX_NUM                   1U
#define USBD_ITF_MAX_NUM                   1U

#define USBD_IAP_INTERFACE                 0U

/* define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
/* #define USBD_LOWPWR_MODE_ENABLE */

/* endpoint count used by the custom HID device */
#define EP_COUNT                           (2U)

/* base address offset of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000U)

#define USB_STRING_COUNT                   4U

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

/* endpoint0, Rx/Tx buffers address offset */
#define EP0_RX_ADDR                        (0x40U)
#define EP0_TX_ADDR                        (0x80U)

#define IAP_IN_EP                          EP_IN(1U)
#define IAP_OUT_EP                         EP_OUT(1U)

#define IAP_IN_PACKET                      17U
#define IAP_OUT_PACKET                     64U

/* Tx buffer address offset */
#define INT_TX_ADDR                        (0x100U)

/* Rx buffer address offset */
#define INT_RX_ADDR                        (0x140U)

#define TRANSFER_SIZE                      62U    /* IAP maximum data packet size */

#define PAGE_SIZE                          2048U  /* MCU page size */

/* memory address from where user application will be loaded, which represents 
   the DFU code protected against write and erase operations.*/
#define APP_LOADED_ADDR                    0x08008000U

/* maximum number of supported memory media (Flash, RAM or EEPROM and so on) */
#define MAX_USED_MEMORY_MEDIA              1

/* make sure the corresponding memory where the DFU code should not be loaded
   cannot be erased or overwritten by DFU application. */
#define IS_PROTECTED_AREA(addr)            (uint8_t)((((addr) >= 0x08000000U) && ((addr) < (APP_LOADED_ADDR)))? 1U : 0U)
#endif


//USB DFU CONFIG
#if defined(USB_DFU)

//#include "dfu_mem.h"
//#include "exmc_nandflash.h"
//#include "nor_flash_if.h"
//#include "nand_flash_if.h"
//#include "inter_flash_if.h"

#define USBD_CFG_MAX_NUM                  1U
#define USBD_ITF_MAX_NUM                  1U
#define USB_STR_DESC_MAX_SIZE         64U

#define DFU_MAX_ALT_ITF_NUM           3
#define STR_IDX_ALT_ITF0              5
#define STR_IDX_ALT_ITF1              6
#define STR_IDX_ALT_ITF2              7

#define USBD_DFU_INTERFACE                0U

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

/* USB user string supported */
#define USB_SUPPORT_USER_STRING_DESC

#define MAX_USED_MEMORY_MEDIA             1U    //only using internal flash
//#define MAX_USED_MEMORY_MEDIA             3U

/* DFU maximum data packet size */
#define TRANSFER_SIZE                     2048U

/* memory address from where user application will be loaded, which represents 
   the dfu code protected against write and erase operations.*/
#define APP_LOADED_ADDR                   0x08008000U

/* Make sure the corresponding memory where the DFU code should not be loaded
   cannot be erased or overwritten by DFU application. */
#define IS_PROTECTED_AREA(addr)  (uint8_t)((((addr) >= 0x08000000) && ((addr) < (APP_LOADED_ADDR)))? 1 : 0)

/* DFU endpoint define */
#define DFU_IN_EP                          EP_IN(0)
#define DFU_OUT_EP                         EP_OUT(0)

#define EP0_TX_ADDR                        0x10U
#define EP0_RX_ADDR                        0x50U

/* endpoint count used by the DFU device */
#define EP_COUNT                           (1U)

/* base address of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000U)

#define USB_STRING_COUNT                   8
#endif


#ifdef USB_COMPOSITE_DFU_CUST_HID_KEYBOARD

#define USBD_CFG_MAX_NUM                   1U
#define USBD_ITF_MAX_NUM                   3U

/* define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
//#define USB_DEVICE_LOW_PWR_MODE_SUPPORT

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

#define USBD_HID_INTERFACE                  0x01U
#define CUSTOM_HID_INTERFACE                0x00U
#define USBD_DFU_INTERFACE                  0x02U


#define USB_STR_DESC_MAX_SIZE         64U

#define DFU_MAX_ALT_ITF_NUM           3
#define STR_IDX_ALT_ITF0              5
#define STR_IDX_ALT_ITF1              6
#define STR_IDX_ALT_ITF2              7


/* endpoint0, Rx/Tx buffers address offset */
#define EP0_RX_ADDR                        (0x40U)
#define EP0_TX_ADDR                        (0x80U)

//HID Keyboard Rx/Tx buffers and EP
#define HID_IN_EP                          EP_IN(2)

#define HID_IN_PACKET                      8

#define INT_RX_ADDR                        0xC0U
#define INT_TX_ADDR                        (INT_RX_ADDR + HID_IN_PACKET)


/* class layer parameter used by the Custom HID device */
#define CUSTOMHID_IN_EP                    EP_IN(1)
#define CUSTOMHID_OUT_EP                   EP_OUT(1)

#define CUSTOMHID_IN_PACKET                2
#define CUSTOMHID_OUT_PACKET               2

/* HID data Tx/Rx buffer address offset */
#define HID_RX_ADDR                        0xE0U
#define HID_TX_ADDR                        0xF0U


//DFU CONFIG
/* USB user string supported */
#define USB_SUPPORT_USER_STRING_DESC

#define MAX_USED_MEMORY_MEDIA             3U

/* DFU maximum data packet size */
#define TRANSFER_SIZE                     2048U

/* memory address from where user application will be loaded, which represents 
   the dfu code protected against write and erase operations.*/
#define APP_LOADED_ADDR                   0x08008000U

/* Make sure the corresponding memory where the DFU code should not be loaded
   cannot be erased or overwritten by DFU application. */
#define IS_PROTECTED_AREA(addr)  (uint8_t)((((addr) >= 0x08000000) && ((addr) < (APP_LOADED_ADDR)))? 1 : 0)

/* DFU endpoint define */
/* DFU endpoint define */
#define DFU_IN_EP                          EP_IN(3)
#define DFU_OUT_EP                         EP_OUT(3)

#define EP3_TX_ADDR                        0x100U
#define EP3_RX_ADDR                        0x140U





/* endpoint count used by the composite device */
#define EP_COUNT                           4U

/* base address offset of the allocation buffer, used for buffer descriptor table and packet memory */
#define BTABLE_OFFSET                      (0x0000U)

/* base address of the allocation buffer, used for buffer descriptor table and packet memory */
#define BUFFER_ADDRESS                     (0x0000U)


/* endpoint polling interval in ms */
#define CUSTOM_HID_EP_IN_poll_interval          0x20U
#define CUSTOM_HID_EP_OUT_poll_interval         0x20U
#define STANDARD_HID_EP_IN_poll_interval          0x20U
#define STANDARD_HID_EP_OUT_poll_interval         0x20U
#endif





#define USB_PULLUP                         GPIOC
#define USB_PULLUP_PIN                     GPIO_PIN_11
#define RCU_AHBPeriph_GPIO_PULLUP          RCU_GPIOC

#endif /* __USBD_CONF_H */
