$NetBSD: patch-drivers_snmp-ups.c,v 1.1 2020/07/13 18:50:05 wiz Exp $

Get an explicit error message if we fail obtaining a response.

--- drivers/snmp-ups.c.orig	2016-03-09 11:39:45.000000000 +0000
+++ drivers/snmp-ups.c
@@ -577,6 +577,8 @@ struct snmp_pdu **nut_snmp_walk(const ch
 		status = snmp_synch_response(g_snmp_sess_p, pdu, &response);
 
 		if (!response) {
+			nut_snmp_perror(g_snmp_sess_p, status, response,
+				"%s: %s", __func__, OID);
 			break;
 		}
 
