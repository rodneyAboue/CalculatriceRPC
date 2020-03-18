/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculatrice.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
calc_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		calc ajouter_1_arg;
		calc soustraire_1_arg;
		calc multiplier_1_arg;
		int memoriser_1_arg;
		int extraire_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case ALLUMER:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) allumer_1_svc;
		break;

	case AJOUTER:
		_xdr_argument = (xdrproc_t) xdr_calc;
		_xdr_result = (xdrproc_t) xdr_long;
		local = (char *(*)(char *, struct svc_req *)) ajouter_1_svc;
		break;

	case SOUSTRAIRE:
		_xdr_argument = (xdrproc_t) xdr_calc;
		_xdr_result = (xdrproc_t) xdr_long;
		local = (char *(*)(char *, struct svc_req *)) soustraire_1_svc;
		break;

	case MULTIPLIER:
		_xdr_argument = (xdrproc_t) xdr_calc;
		_xdr_result = (xdrproc_t) xdr_long;
		local = (char *(*)(char *, struct svc_req *)) multiplier_1_svc;
		break;

	case MEMORISER:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) memoriser_1_svc;
		break;

	case EXTRAIRE:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_long;
		local = (char *(*)(char *, struct svc_req *)) extraire_1_svc;
		break;

	case ETEINDRE:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) eteindre_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (CALC_PROG, CALC_VERSION_1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, CALC_PROG, CALC_VERSION_1, calc_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALC_PROG, CALC_VERSION_1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, CALC_PROG, CALC_VERSION_1, calc_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALC_PROG, CALC_VERSION_1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
