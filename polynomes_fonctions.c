/***																		***/
/***														***/
/***	Description : Projet polynomes										***/
/***																		***/
/******************************************************************************/

/******************************************************************************/
/***	***	***	***		Fichiers includes									***/
/******************************************************************************/

#include	"polynomes_fonctions.h"
#include<math.h>

/******************************************************************************/
/***	***	***	***		Saisie d'un polynome								***/
/***	***	***	***															***/
/***	***	***	***		Renvoi : poly -> adresse du polynome				***/
/******************************************************************************/

Maillon	*SaisirPolynome()
{
	int		exposant;
	int	facteur;
	char	reponse, *chaine;
	Maillon	*poly, *temp;
	Booleen	ok, repOK;

	poly = InitFilePrior();
	ok = FAUX;

	while(!ok)
	{
		repOK = FAUX;

		printf("Veuillez saisir un monome :\n");
		printf("\t- Facteur .... : ");
		fflush(stdin);
		scanf("%d", &facteur);
		exposant = -1;
		while(exposant < 0)
		{
			printf("\t- Exposant ... : ");
			fflush(stdin);
			scanf("%d", &exposant);
		}

		temp = poly;
		poly = AddPolynomes(poly, NouveauMaillon(exposant, facteur));
		SupprimeFile(temp);

		do
		{
			printf("\nEncore un monome ? (o/n) : ");
			fflush(stdin);
			scanf("%c", &reponse);
			printf("\n");
			if(reponse == 'n' || reponse == 'N')
			{
				repOK = VRAI;
				ok = VRAI;
			}
			else
			{
				repOK = VRAI;
			}
		}
		while(!repOK);
	}

	return poly;
}

/******************************************************************************/
/***	*** ***	***		Addition de deux polynomes							***/
/***	***	***	***															***/
/***	***	***	***		Renvoi : polyRes = polyA + polyB					***/
/******************************************************************************/

Maillon		*AddPolynomes(Maillon *polyA, Maillon *polyB)
{
	Maillon	*pA = polyA, *pB = polyB, *pC, *polyRes;
	int	facteur;

	if(polyA == NULL)
	{
		polyRes = CopieFile(polyB);
	}
	else if(polyB == NULL)
	{
		polyRes = CopieFile(polyA);
	}
	else
	{
		polyRes = CopieFile(polyA);

		while(pB != NULL)
		{
			if(pB->facteur != 0)
			{
				pC = polyRes;
				while(pC->suivant != NULL && pC->exposant != pB->exposant)
				{
					pC = pC->suivant;
				}

				if(pC->exposant == pB->exposant)
				{
					facteur = pC->facteur + pB->facteur;
					if(facteur != 0)
					{
						pC->facteur = facteur;
					}
					else
					{
						polyRes = Defiler(polyRes, pC->exposant);
					}
				}
				else
				{
					polyRes = EnfilerParPrior(polyRes, NouveauMaillon(pB->exposant, pB->facteur));
				}
			}
			pB = pB->suivant;
		}
	}

	return polyRes;
}

/******************************************************************************/
/***	*** ***	***		Differences de deux polynomes						***/
/***	***	***	***															***/
/***	***	***	***		Renvoi : polyRes = polyA - polyB					***/
/******************************************************************************/

Maillon		*DifPolynomes(Maillon *polyA, Maillon *polyB)
{
	Maillon	*polyRes;

	polyRes = AddPolynomes(polyA, ProdPolynomes(NouveauMaillon(0, -1), polyB));

	return polyRes;
}

/******************************************************************************/
/***	***	***	***		Produit de deux polynomes							***/
/***	***	***	***															***/
/***	***	***	***		Renvoi : polyRes = polyA * polyB					***/
/******************************************************************************/

Maillon		*ProdPolynomes(Maillon *polyA, Maillon *polyB)
{
	Maillon	*polyRes, *polyProv, *polyTemp, *pA = polyA, *pB;

	polyRes = InitFilePrior();

	if(polyA == NULL || polyB == NULL)
	{
		return NULL;
	}
	else
	{
		polyProv = NouveauMaillon(0, 0);
		while(pA != NULL)
		{
			pB = polyB;
			while(pB != NULL)
			{
				polyProv->exposant = pA->exposant + pB->exposant;
				polyProv->facteur = pA->facteur * pB->facteur;
				polyTemp = polyRes;
				polyRes = AddPolynomes(polyRes, polyProv);
				SupprimeFile(polyTemp);
				pB = pB->suivant;
			}
			pA = pA->suivant;
		}
		free(polyProv);
	}

	return polyRes;
}

/******************************************************************************/
/***	***	***	***		Derivee d'un polynome								***/
/***	***	***	***															***/
/***	***	***	***		Renvoi : polyRes = (poly)'							***/
/******************************************************************************/

Maillon		*DervPolynome(Maillon *poly)
{
	Maillon	*p, *polyRes;

	if(poly == NULL)
	{
		return NULL;
	}
	else
	{
		polyRes = CopieFile(poly);
		polyRes = Defiler(polyRes, 0);
		p = polyRes;

		while(p != NULL)
		{
			p->facteur *= p->exposant;
			p->exposant --;
			p = p->suivant;
		}
	}

	return polyRes;
}

/******************************************************************************/
/***	***	***	***		Primitive d'un polynome								***/
/***	***	***	***															***/
/***	***	***	***		Renvoi : polyRes = Primitive(poly)					***/
/******************************************************************************/

Maillon		*PrimPolynome(Maillon *poly)
{
	Maillon	*p, *polyRes;

	if(poly == NULL)
	{
		return NULL;
	}
	else
	{
		polyRes = CopieFile(poly);
		p = polyRes;

		while(p != NULL)
		{
			p->exposant ++;
			p->facteur /= p->exposant;
			p = p->suivant;
		}
	}

	return polyRes;
}

/******************************************************************************/
/***	***	***	***		Affichage d'un polynome								***/
/******************************************************************************/

void		AfficherPolynome(Maillon* poly)
{
	Maillon	*p = poly;

	if(poly == NULL)
	{
		printf("\nLe polynome est vide !!!\n\n");
	}
	else
	{
		while(p != NULL)
		{
			printf("%s", (p == poly) ? (p->facteur < 0) ? " -" : " " : (p->facteur < 0) ? "- " : "+ ");
			if(monAbs(p->facteur) != 1 || p->exposant == 0)
			{
				printf("%g", monAbs(p->facteur));
			}
			if(p->exposant != 0)
			{
				printf("x");
				if(p->exposant != 1)
				{
					printf("^%d", p->exposant);
				}
			}
			printf(" ");
			p = p->suivant;
		}
	}
}

/******************************************************************************/
/***	***	***	***		Calcul de la valeur absolue							***/
/******************************************************************************/

float		monAbs(float val)
{
	return ((val >= 0) ? val : -val);
}
/***evaluation de polynome en un entier x   ***/
int evaluepolynome(Maillon*poly,int x)
{
float total=0;
if(poly!=NULL)
{
total=(poly->facteur)*((float) pow(x,poly->exposant)) +evaluepolynome(poly->suivant,x);
}
return(total);
}
Booleen zerodupolynome(Maillon*poly,int x)
{
    int T=evaluepolynome(poly, x);
    if(T=='0')
      {

        return(VRAI);
      }
        else
            return(FAUX);

}

