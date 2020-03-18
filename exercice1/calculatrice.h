/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALCULATRICE_H_RPCGEN
#define _CALCULATRICE_H_RPCGEN

#include <rpc/rpc.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


struct calc {
	long val1;
	long val2;
};
typedef struct calc calc;
static long registre[6];
static long globale;
#define CALC_PROG 0x20000002
#define CALC_VERSION_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define ALLUMER 1
extern  void * allumer_1(void *, CLIENT *);
extern  void * allumer_1_svc(void *, struct svc_req *);
#define AJOUTER 2
extern  long * ajouter_1(calc *, CLIENT *);
extern  long * ajouter_1_svc(calc *, struct svc_req *);
#define SOUSTRAIRE 3
extern  long * soustraire_1(calc *, CLIENT *);
extern  long * soustraire_1_svc(calc *, struct svc_req *);
#define MULTIPLIER 4
extern  long * multiplier_1(calc *, CLIENT *);
extern  long * multiplier_1_svc(calc *, struct svc_req *);
#define MEMORISER 5
extern  void * memoriser_1(int *, CLIENT *);
extern  void * memoriser_1_svc(int *, struct svc_req *);
#define EXTRAIRE 6
extern  long * extraire_1(int *, CLIENT *);
extern  long * extraire_1_svc(int *, struct svc_req *);
#define ETEINDRE 7
extern  void * eteindre_1(void *, CLIENT *);
extern  void * eteindre_1_svc(void *, struct svc_req *);
extern int calc_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ALLUMER 1
extern  void * allumer_1();
extern  void * allumer_1_svc();
#define AJOUTER 2
extern  long * ajouter_1();
extern  long * ajouter_1_svc();
#define SOUSTRAIRE 3
extern  long * soustraire_1();
extern  long * soustraire_1_svc();
#define MULTIPLIER 4
extern  long * multiplier_1();
extern  long * multiplier_1_svc();
#define MEMORISER 5
extern  void * memoriser_1();
extern  void * memoriser_1_svc();
#define EXTRAIRE 6
extern  long * extraire_1();
extern  long * extraire_1_svc();
#define ETEINDRE 7
extern  void * eteindre_1();
extern  void * eteindre_1_svc();
extern int calc_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_calc (XDR *, calc*);

#else /* K&R C */
extern bool_t xdr_calc ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALCULATRICE_H_RPCGEN */
