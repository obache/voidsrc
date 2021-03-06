# $NetBSD: options.mk,v 1.3 2017/01/14 09:28:41 ryoon Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.corebird
PKG_SUPPORTED_OPTIONS=	gstreamer spellcheck
PKG_SUGGESTED_OPTIONS=	gstreamer spellcheck

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
DEPENDS+=	gst-plugins1-bad-[0-9]*:../../multimedia/gst-plugins1-bad
DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=	gst-plugins1-libav-[0-9]*:../../multimedia/gst-plugins1-libav
.else
CONFIGURE_ARGS+=	--disable-video
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
BUILDLINK_API_DEPENDS.gspell+=	gspell>=1.2.2
.include "../../textproc/gspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-spellcheck
.endif
