$NetBSD$

* OpenCC-1.0 API support
  https://github.com/pyzy/pyzy/pull/1

--- src/SimpTradConverter.cc.orig	2012-07-13 02:46:34.000000000 +0000
+++ src/SimpTradConverter.cc
@@ -4,6 +4,7 @@
  *
  * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
  * Copyright (c) 2010 BYVoid <byvoid1@gmail.com>
+ * Copyright (c) 2015 Hillwood Yang <hillwood@opensuse.org>
  *
  * This library is free software; you can redistribute it and/or modify
  * it under the terms of the GNU Lesser General Public License as
@@ -40,7 +41,6 @@ namespace PyZy {
 #ifdef HAVE_OPENCC
 
 class opencc {
-    static const int BUFFER_SIZE = 64;
 public:
     opencc (void)
     {
@@ -55,29 +55,13 @@ public:
 
     void convert (const char *in, String &out)
     {
-        long n_char;
-        unichar *in_ucs4 = g_utf8_to_ucs4_fast (in, -1, &n_char);
-
-        ucs4_t *pinbuf = (ucs4_t *)in_ucs4;
-        size_t inbuf_left = n_char;
-        while (inbuf_left != 0) {
-            ucs4_t *poutbuf = (ucs4_t *)m_buffer;
-            size_t outbuf_left = BUFFER_SIZE;
-            size_t retval = opencc_convert(m_od, &pinbuf, &inbuf_left, &poutbuf, &outbuf_left);
-            if (retval == (size_t) -1) {
-                /* append left chars in pinbuf */
-                g_warning ("opencc_convert return failed");
-                out << (unichar *) pinbuf;
-                break;
-            }
-            *poutbuf = L'\0';
-            out << m_buffer;
-        }
-        g_free (in_ucs4);
+        char * converted = opencc_convert_utf8 (m_od, in, -1);
+        g_assert (converted != NULL);
+        out = converted;
+        opencc_convert_utf8_free (converted);
     }
 private:
     opencc_t m_od;
-    unichar m_buffer[BUFFER_SIZE + 1];
 };
 
 void
