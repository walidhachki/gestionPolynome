/***	Description : Projet polynomes										***/
/***																		***/
/******************************************************************************/

#ifndef	_POLYNOMES_FONCTIONS_H

/******************************************************************************/
/***	***	***	***		Fichiers includes									***/
/******************************************************************************/

#include	<stdio.h>
#include	"polynomes_listes.h"

/******************************************************************************/
/***	***	***	***		Definitions											***/
/******************************************************************************/

#define	_POLYNOMES_FONCTIONS_H

/******************************************************************************/
/***	***	***	***		Declaration des fonctions							***/
/******************************************************************************/

/***	Calculs sur des polynomes			***/
Maillon		*SaisirPolynome();
Maillon		*AddPolynomes(Maillon*, Maillon*);
Maillon		*DifPolynomes(Maillon*, Maillon*);
Maillon		*ProdPolynomes(Maillon*, Maillon*);
Maillon		*DervPolynome(Maillon*);
Maillon		*PrimPolynome(Maillon*);
void		AfficherPolynome(Maillon*);
int evaluepolynome(Maillon*,int x);
Booleen zerodupolynome(Maillon*,int x);

/***	Fonction utilitaire					***/
float		monAbs(float);

/******************************************************************************/

#endif
