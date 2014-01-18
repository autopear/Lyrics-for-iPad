export TARGET=iphone:6.1:5.0
export ARCHS = armv7

include theos/makefiles/common.mk

TWEAK_NAME = LyricsforiPad
LyricsforiPad_FRAMEWORKS = UIKit MediaPlayer AVFoundation QuartzCore
LyricsforiPad_FILES = Tweak.xm

include $(THEOS_MAKE_PATH)/tweak.mk

SUBPROJECTS += lyricsforipadpreferences
include $(THEOS_MAKE_PATH)/aggregate.mk

before-package::
	plutil -convert binary1 _/Library/MobileSubstrate/DynamicLibraries/LyricsforiPad.plist \
	_/Library/PreferenceLoader/Preferences/LyricsforiPadPreferences.plist \
	_/Library/PreferenceBundles/LyricsforiPadPreferences.bundle/*.plist
	find _ -exec touch -r _/Library/MobileSubstrate/DynamicLibraries/LyricsforiPad.dylib {} \;

after-package::
	rm -fr .theos/packages/*
	
