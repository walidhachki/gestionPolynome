
/***																		***/
/***	Fichier	: /polynomes/polynomes_listes.h								***/
/***																		***/
/***	Auteur	: DELETRAIN	- RAVON											***/
/***																		***/
/***	Date de création ....... : 30/01/2003	14h00						***/
/***	Dernière mise à jour ... : 30/01/2003	14h00						***/
/***	Révision ............... : v0.90									***/
/***																		***/
/***	Description : Projet polynomes										***/
/***																		***/
/******************************************************************************/

#ifndef	_POLYNOMES_LISTES_H

/******************************************************************************/
/***	***	***	***		Fichiers includes									***/
/******************************************************************************/

#include	<stdio.h>

/******************************************************************************/
/***	***	***	***		Definitions											***/
/******************************************************************************/

#define	_POLYNOMES_LISTES_H

#ifdef	__WIN32
	#define		CLEAR	"cls"			/***	Compilation sous Windows	***/
#else
	#define		CLEAR	"clear"			/***	Compilation sous Unix		***/
#endif

typedef enum {FAUX, VRAI} Booleen;

typedef	struct Maillon
{
	int		exposant;
	float	facteur;
	struct	Maillon	*suivant;
}
Maillon;

/******************************************************************************/
/***	***	***	***		Declaration des fonctions							***/
/******************************************************************************/

/***	Manipulation d'une file	ordonnee	***/
Maillon*	InitFilePrior();
Maillon*	SupprimeFile(Maillon*);
Maillon*	CopieFile(Maillon*);
Maillon*	NouveauMaillon(int, int);
Maillon*	EnfilerParPrior(Maillon*, Maillon*);
Maillon*	DefilerParPrior(Maillon*);
Booleen		FilePriorVide(Maillon*);
Maillon*	Defiler(Maillon*, int);

/******************************************************************************/

#endif
