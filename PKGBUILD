# $Id: PKGBUILD 113973 2014-07-01 10:51:04Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwmalt
pkgver=6.0
pkgrel=2
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama')
install=dwmalt.install
source=(dwmalt-$pkgver.tar.gz
	config.h
	dwmalt.desktop)

build() {
  cd $srcdir/$pkgname-$pkgver
  cp $srcdir/config.h config.h
  sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
  sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
  sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
  sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
  sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
  install -m644 -D $srcdir/dwmalt.desktop $pkgdir/usr/share/xsessions/dwmalt.desktop
  rm config.h
}
md5sums=('482c9b01f1c2f8fe728610b40f88d7c9'
         '55239b76ea3783021c422aff8c4a96c2'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('482c9b01f1c2f8fe728610b40f88d7c9'
         '3e178e2a534b15f493fbc919cd0a9c50'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('482c9b01f1c2f8fe728610b40f88d7c9'
         'f3cd7df806500f2704461c6a4451ef97'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('482c9b01f1c2f8fe728610b40f88d7c9'
         '3b14a83cf9601c263f10360c1634b553'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('482c9b01f1c2f8fe728610b40f88d7c9'
         '7e5ec11f7a4b6e96d43164377c00d06f'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('482c9b01f1c2f8fe728610b40f88d7c9'
         'f86984b1d5260896bf521f4ccc3032da'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('482c9b01f1c2f8fe728610b40f88d7c9'
         '68592dc8cbe5c6ad358d29cb76c1afdb'
         '939f403a71b6e85261d09fc3412269ee')
