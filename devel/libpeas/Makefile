# $NetBSD: Makefile,v 1.49 2021/04/12 13:31:13 nia Exp $

DISTNAME=	libpeas-1.26.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libpeas/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Libpeas
COMMENT=	GObject-based plugins engine
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt pkg-config

# XXX: revisit at later date if something needs this
MESON_ARGS+=	-Dpython2=false
MESON_ARGS+=	-Dpython3=false
MESON_ARGS+=	-Dlua51=false

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	output/meson-private/libpeas-gtk-1.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/libpeas-1.0.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.39.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
