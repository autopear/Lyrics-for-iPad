export TARGET=iphone:6.1:5.0
export ARCHS = armv7

include theos/makefiles/common.mk

BUNDLE_NAME = LyricsforiPadPreferences
LyricsforiPadPreferences_FILES = LyricsforiPadPreferences.mm
LyricsforiPadPreferences_INSTALL_PATH = /Library/PreferenceBundles
LyricsforiPadPreferences_FRAMEWORKS = UIKit
LyricsforiPadPreferences_PRIVATE_FRAMEWORKS = Preferences

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/LyricsforiPadPreferences.plist$(ECHO_END)
