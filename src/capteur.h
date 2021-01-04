
typedef struct {
char identifiant [100];
char type [100];
char marque [100];
int reference ;
char etat[20];
}capteur;

int ajouter (capteur C);
void modifier (capteur c);
int supprimer (char identifiant[]);
//int alarment(float min1, float max1);
int alarment(float min1,float max1,float min2 ,float max2);
//int temper(float min1,float max1);
int temper(float min1,float max1, float min2,float max2);
/*int nb_capteur (float maxH,float minH,float maxT,float minT,char temperature[],char humide[]);*/
