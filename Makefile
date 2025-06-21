#export THEOS=/var/mobile/theos
ARCHS = arm64
DEBUG = 0
FINALPACKAGE = 1
FOR_RELEASE = 1
THEOS_PACKAGE_SCHEME = roothide
TARGET = iphone:latest:14.0

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = HexIpa

$(TWEAK_NAME)_FRAMEWORKS =  UIKit Foundation Security QuartzCore CoreGraphics CoreText  AVFoundation Accelerate GLKit SystemConfiguration GameController 

#$(TWEAK_NAME)_CCFLAGS = -std=c++17 -fno-rtti -fno-exceptions -DNDEBUG
#$(TWEAK_NAME)_CFLAGS = -fobjc-arc -Wno-deprecated-declarations -Wno-unused-variable -Wno-unused-value -v -O2 -s fvisibility=hidden

$(TWEAK_NAME)_CCFLAGS = -std=c++17 -fno-rtti -fno-exceptions -DNDEBUG -fvisibility=hidden -Wc++11-narrowing -Wno-narrowing -Wundefined-bool-conversion -Wreturn-stack-address -Wno-error=format-security -fvisibility=hidden -fpermissive -fexceptions -w -s -Wno-error=format-security -fvisibility=hidden -Werror -fpermissive -Wall -fexceptions
$(TWEAK_NAME)_CFLAGS = -fobjc-arc -Wno-deprecated-declarations -Wno-unused-variable -Wno-unused-value -fvisibility=hidden -Wc++11-narrowing -Wno-narrowing -Wundefined-bool-conversion -Wreturn-stack-address -Wno-error=format-security -fvisibility=hidden -fpermissive -fexceptions -w -s -Wno-error=format-security -fvisibility=hidden -Werror -fpermissive -Wall -fexceptions

#Add dobby hook
$(TWEAK_NAME)_OBJ_FILES = utils/libdobby_fixed.a

$(TWEAK_NAME)_FILES = ImGuiDrawView.mm $(wildcard utils/alert/*.mm) $(wildcard Esp/*.mm) $(wildcard Esp/*.m) $(wildcard IMGUI/*.cpp) $(wildcard IMGUI/*.mm) $(wildcard SCLAlertView/*.m) $(wildcard functions/inline-hook/*.mm)

$(TWEAK_NAME)_LDFLAGS += JRMemory.framework/JRMemory 

include $(THEOS_MAKE_PATH)/tweak.mk


