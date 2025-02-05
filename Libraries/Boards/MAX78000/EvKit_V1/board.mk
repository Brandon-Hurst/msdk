###############################################################################
 #
 # Copyright (C) 2022-2023 Maxim Integrated Products, Inc. (now owned by
 # Analog Devices, Inc.),
 # Copyright (C) 2023-2024 Analog Devices, Inc.
 #
 # Licensed under the Apache License, Version 2.0 (the "License");
 # you may not use this file except in compliance with the License.
 # You may obtain a copy of the License at
 #
 #     http://www.apache.org/licenses/LICENSE-2.0
 #
 # Unless required by applicable law or agreed to in writing, software
 # distributed under the License is distributed on an "AS IS" BASIS,
 # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 # See the License for the specific language governing permissions and
 # limitations under the License.
 #
 ##############################################################################

ifeq "$(BOARD_DIR)" ""
# This Makefile will self-locate if BOARD_DIR is not specified.
BOARD_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
endif

# Source files for this test (add path to VPATH below)
SRCS += board.c
SRCS += stdio.c
SRCS += led.c
SRCS += pb.c
SRCS += tft_ssd2119.c
SRCS += tsc2046.c
SRCS += camera.c

ifeq "$(CAMERA)" "HM0360"
$(warning Using mono HM0360 by default.)
$(warning Use CAMERA=HM0360_COLOR for color drivers, or CAMERA=HM0360_MONO to clear this warning.)
CAMERA=HM0360_MONO
endif

ifeq "$(CAMERA)" "HM01B0"
SRCS += hm01b0.c
PROJ_CFLAGS+=-DCAMERA_HM01B0
PROJ_CFLAGS+=-DCAMERA_MONO
else ifeq "$(CAMERA)" "HM0360_MONO"
SRCS += hm0360_mono.c
PROJ_CFLAGS+=-DCAMERA_HM0360_MONO
PROJ_CFLAGS+=-DCAMERA_MONO
else ifeq "$(CAMERA)" "HM0360_COLOR"
SRCS += hm0360_color.c
SRCS += debayering.c
PROJ_CFLAGS+=-DCAMERA_BAYER
PROJ_CFLAGS+=-DCAMERA_HM0360_COLOR
else ifeq "$(CAMERA)" "OV5642"
SRCS += ov5642.c
PROJ_CFLAGS+=-DCAMERA_OV5642
else ifeq "$(CAMERA)" "OV5640"
SRCS += ov5640.c
PROJ_CFLAGS+=-DCAMERA_OV5640
PROJ_CFLAGS+=-DOV5640_DVP
else ifeq "$(CAMERA)" "OV7692"
SRCS += ov7692.c
PROJ_CFLAGS+=-DCAMERA_OV7692
else ifeq "$(CAMERA)" "PAG7920"
SRCS += pag7920.c
PROJ_CFLAGS+=-DCAMERA_PAG7920
PROJ_CFLAGS+=-DCAMERA_MONO
else ifeq "$(CAMERA)" ""
SRCS += ov7692.c
PROJ_CFLAGS+=-DCAMERA_OV7692
endif
SRCS += sccb.c

MISC_DRIVERS_DIR ?= $(MAXIM_PATH)/Libraries/MiscDrivers

# Where to find BSP source files
VPATH += $(BOARD_DIR)/Source
VPATH += $(MISC_DRIVERS_DIR)
VPATH += $(MISC_DRIVERS_DIR)/Camera
VPATH += $(MISC_DRIVERS_DIR)/Display
VPATH += $(MISC_DRIVERS_DIR)/LED
VPATH += $(MISC_DRIVERS_DIR)/PushButton
VPATH += $(MISC_DRIVERS_DIR)/Touchscreen


# Where to find BSP header files
IPATH += $(BOARD_DIR)/Include
IPATH += $(MISC_DRIVERS_DIR)
IPATH += $(MISC_DRIVERS_DIR)/Camera
IPATH += $(MISC_DRIVERS_DIR)/Display
IPATH += $(MISC_DRIVERS_DIR)/LED
IPATH += $(MISC_DRIVERS_DIR)/PushButton
IPATH += $(MISC_DRIVERS_DIR)/Touchscreen

include $(MISC_DRIVERS_DIR)/Display/fonts/fonts.mk
