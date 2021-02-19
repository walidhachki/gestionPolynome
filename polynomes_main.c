
/******************************************************************************/
/***																		***/
/***	Fichier	: /polynomes/polynomes_main.c								***/
/***																		***/
/***	Description : Projet polynomes										***/
/***																		***/
/******************************************************************************/

/******************************************************************************/
/***	***	***	***		Fichiers includes									***/
/******************************************************************************/

#include	"polynomes_main.h"

/******************************************************************************/
/***	***	***	***		Programme principal									***/
/******************************************************************************/

int		main()
{
	Maillon	*resultat, *polyA, *polyB, *polynome;
	int Z,R ;
	float Y;
	Booleen reponse;
    resultat = InitFilePrior();
	/***     saisie de polynome     ***/
	system(CLEAR);
	printf("saisie de polynome :\n\n");
	polynome=SaisirPolynome();
	printf("polynome =");
	AfficherPolynome(polynome);
	printf("\n");
	fflush(stdin);
	getchar();


/***	Saisie des deux polynomes		***/
	system(CLEAR);
	printf("Saisie de polyA :\n\n");
	polyA = SaisirPolynome();
	system(CLEAR);
	printf("polyA = ");
	AfficherPolynome(polyA);
	printf("\n");
	fflush(stdin);
	getchar();

	system(CLEAR);
	printf("Saisie de polyB :\n\n");
	polyB = SaisirPolynome();
	system(CLEAR);
	printf("polyB = ");
	AfficherPolynome(polyB);
	printf("\n");
	fflush(stdin);
	getchar();

/***	Addition des deux polynomes		***/
	system(CLEAR);
	printf("Addition de deux polynomes : polyA + polyB\n");
	printf("------------------------------------------\n\n");

	printf("On a polyA + polyB =\n\n");
	printf("("); AfficherPolynome(polyA); printf(") + ");
	printf("("); AfficherPolynome(polyB); printf(") = ");
	resultat = AddPolynomes(polyA, polyB);
	AfficherPolynome(resultat);
	resultat = SupprimeFile(resultat);
	printf("\n");
	fflush(stdin);
	getchar();

/***	Difference des deux polynomes		***/
	system(CLEAR);
	printf("Difference de deux polynomes : polyA - polyB\n");
	printf("------------------------------------------\n\n");

	printf("On a polyA + polyB =\n\n");
	printf("("); AfficherPolynome(polyA); printf(") - ");
	printf("("); AfficherPolynome(polyB); printf(") = ");
	resultat = DifPolynomes(polyA, polyB);
	AfficherPolynome(resultat);
	resultat = SupprimeFile(resultat);
	printf("\n");
	fflush(stdin);
	getchar();

/***	Multiplication des deux polynomes	***/
	system(CLEAR);
	printf("Multiplication de deux polynomes : polyA * polyB\n");
	printf("------------------------------------------------\n\n");

	printf("On a polyA * polyB =\n\n");
	printf("("); AfficherPolynome(polyA); printf(") * ");
	printf("("); AfficherPolynome(polyB); printf(") = ");
	resultat = ProdPolynomes(polyA, polyB);
	AfficherPolynome(resultat);
	resultat = SupprimeFile(resultat);
	printf("\n");
	fflush(stdin);
	getchar();

/***	Derive du polynome saisie			***/
	system(CLEAR);
	printf("Derivee d'un polynome : (polynome)'\n");
	printf("--------------------------------\n\n");

	printf("On a (polynome)' =\n\n");
	printf("("); AfficherPolynome(polynome); printf(")' = ");
	resultat = DervPolynome(polynome);
	AfficherPolynome(resultat);
	resultat = SupprimeFile(resultat);
	printf("\n");
	fflush(stdin);
	getchar();

/***	Primitive du polynome polyB			***/
	system(CLEAR);
	printf("Primitive d'un polynomes : P(polyB)\n");
	printf("-----------------------------------\n\n");

	printf("On a P(polyB) =\n\n");
	printf("P("); AfficherPolynome(polyB); printf(") = ");
	resultat = PrimPolynome(polyB);
	AfficherPolynome(resultat);
	resultat = SupprimeFile(resultat);
	printf("\n");
	fflush(stdin);
	getchar();
/*** evaluer le polynome en un entier x ***/
    system(CLEAR);
    printf("Saisir la valeur de Z :");
					 scanf("%d",&Z);
					 Y = evaluepolynome(polynome,Z);
					 printf("Pour Z = %d\n",Z);
					 AfficherPolynome(polynome);
					 printf("= %f",Y);
					 fflush(stdin);
					 getchar();
/*** teste si un entier est un zero du polynome   ***/

	printf(" saisir la valeur de R :");
    scanf("%d",&R);
    reponse = zerodupolynome(polynome,R);
    printf("=%b",reponse);
    fflush(stdin);
    getchar();
	return 0;
}
