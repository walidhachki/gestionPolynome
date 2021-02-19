/***																		***/
/***	Fichier	: /polynomes/polynomes_listes.c
/***																							***/
/***	Description : Projet polynomes
/***																		***/
/******************************************************************************/

/******************************************************************************/
/***	***	***	***		Fichiers includes									***/
/******************************************************************************/

#include	"polynomes_listes.h"

/******************************************************************************/
/***	***	***	***		Initialise la file									***/
/******************************************************************************/

Maillon	*InitFilePrior()
{
	return NULL;
}

/******************************************************************************/
/***	***	***	***		Supprime la file									***/
/******************************************************************************/

Maillon	*SupprimeFile(Maillon *file)
{
	if(file != NULL)
	{
		SupprimeFile(file->suivant);
		free(file);
	}

	return NULL;
}

/******************************************************************************/
/***	***	***	***		Copie une file dans l'autre							***/
/******************************************************************************/

Maillon	*CopieFile(Maillon *source)
{
	Maillon	*temp = source, *destination;

	destination = InitFilePrior();

	while(FilePriorVide(temp) == FAUX)
	{
		if(temp->facteur != 0)
		{
			destination = EnfilerParPrior(destination, NouveauMaillon(temp->exposant, temp->facteur));
		}
		temp = temp->suivant;
	}

	return destination;
}

/******************************************************************************/
/***	***	***	***		Creer un nouveau maillon							***/
/******************************************************************************/

Maillon	*NouveauMaillon(int exposant, int facteur)
{
	Maillon	*p;

	p = (Maillon *) malloc(sizeof(Maillon));
	if(p == NULL)
	{
		printf("Erreur lors de l'allocation dans 'Maillon *NouveauMaillon(int, float)'\n\n");
		printf("Appuyer sur entree pour quitter ...\n\n");
		fflush(stdin);
		getchar();
		exit(-1);
	}

	p->exposant = exposant;
	p->facteur = facteur;
	p->suivant = NULL;

	return p;
}

/******************************************************************************/
/***	***	***	***		Enfile un element selon sa priorite					***/
/******************************************************************************/

Maillon	*EnfilerParPrior(Maillon *tete, Maillon *maillon)
{
	Maillon		*p, *pp;

	if(FilePriorVide(tete) == FAUX)
	{
		if(tete->exposant < maillon->exposant)
		{
			maillon->suivant = tete;
			tete = maillon;
//	printf("Maillon en tête\n");
		}
		else
		{
			p = tete;
			pp = tete;

			while(p->suivant != NULL && maillon->exposant < p->exposant)
			{
				pp = p;
				p = p->suivant;
			}

			if(p->suivant == NULL && maillon->exposant < p->exposant)
			{
				maillon->suivant = NULL;
				p->suivant = maillon;
//	printf("Maillon en queue\n");
			}
			if(maillon->exposant >= p->exposant)
			{
				maillon->suivant = p;
				pp->suivant = maillon;
//	printf("Maillon  au milieu\n");
			}
		}
	}
	else
	{
		tete = maillon;
		maillon->suivant = NULL;
//	printf("Premier Maillon\n");
	}

	return tete;
}

/******************************************************************************/
/***	***	***	***		Defile l'element de plus grande priorite			***/
/******************************************************************************/

Maillon	*DefilerParPrior(Maillon *tete)
{
	Maillon	*p = tete;

	if(FilePriorVide(tete) == FAUX)
	{
		tete = tete->suivant;
		free(p);
	}

	return tete;
}


/******************************************************************************/
/***	***	***	***		Defile le maillon de priorite prior					***/
/******************************************************************************/

Maillon	*Defiler(Maillon *tete, int prior)
{
	Maillon	*p = NULL, *pp;

	if(FilePriorVide(tete) == FAUX)
	{
		if(tete->exposant == prior)
		{
			tete = tete->suivant;
			free(p);
		}
		else
		{
			p = tete;
			pp = tete;

			while(p->suivant != NULL && p->exposant != prior)
			{
				pp = p;
				p = p->suivant;
			}

			if(p->exposant == prior)
			{
				pp->suivant = p->suivant;
				free(p);
			}
		}
	}

	return tete;
}

/******************************************************************************/
/***	***	***	***		Test si la file est vide							***/
/******************************************************************************/

Booleen	FilePriorVide(Maillon *tete)
{
	return (tete == NULL);
}
