# $NetBSD: Makefile,v 1.19 2020/08/31 18:13:16 wiz Exp $

PKGNAME=			${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=			4

.include "../../www/clearsilver/Makefile.common"

CONFIGURE_ARGS+=		--enable-ruby
CONFIGURE_ARGS+=		--with-ruby=${RUBY:Q}
INSTALLATION_DIRS=		${RUBY_VENDORARCHLIB} ${RUBY_VENDORLIB}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ruby/ext/hdf/hdf.${RUBY_DLEXT} \
		${DESTDIR}${PREFIX}/${RUBY_VENDORARCHLIB}
	${INSTALL_DATA} ${WRKSRC}/ruby/lib/neo.rb \
		${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}/neo.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
