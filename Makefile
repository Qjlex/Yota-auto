include $(TOPDIR)/rules.mk

PKG_NAME:=yota-auto
PKG_RELEASE:=1
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/yota-auto
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=Автоматически продление интернета
endef

define Package/yota-auto/description
	Данная программа автоматически продлевает бесплатный 64 кбитный интернет от Yota.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/yota-auto/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/yota-auto $(1)/bin/
endef

$(eval $(call BuildPackage,yota-auto))