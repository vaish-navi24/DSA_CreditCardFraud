/* Steps : 
* For multiple users : 
* A hashmap that contains the data of the user. : DOne
* User Login : Done
* putting the 	data from csv file to the users's map.
* Initializing the linked list and the bst.  
* Functions : 
*/
#include <SDL2/SDL.h>  // Ensure SDL2 is included here for SDL_Renderer
#include <SDL2/SDL_ttf.h>
#define MAPSIZE 11
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define WIDTH 800
#define HEIGHT 600
#define epsilon 1e-6

typedef struct countLoc{
	int fin;
	int fout;
	int in;
	int out;
	int total_f;
	int total;
}countLoc;

typedef struct countTime{
	int df;
	int d;
	int nf;
	int n;
	int odf;
	int od;
	int total_f;
	int total;
}countTime;

typedef struct countAmt {
	int z1f;
	int z2f;
	int z3f;
	int z1;
	int z2;
	int z3;
	int total_f;
	int total;
}countAmt;

typedef struct countStatus{
	int sf;
	int s;
	int ff;
	int f;
	int total_f;
	int total;
}countStatus;

typedef struct date {

	int day;
	int month;
	int year;
	
}date;

typedef struct location {

	char city[32];
	char state[32];
	char country[32];
	
}location;

typedef struct node {

	char transaction_id[40];
	date date_of_payment;
	struct tm time_of_payment;
	location payment_place;
	int zipCode;
	float amount;
	char status; 
	int fraud;
	struct node *prev;
	struct node *next;
	
}node;

typedef struct dll {
	
	node *head;
	node *end;
	
}dll;

typedef struct transaction {
	
	date date_of_payment;
	struct tm time_of_payment;
	location payment_place;
	float amount;
	char status; 
	struct transaction *left;
	struct transaction *right;
	
}transaction;

typedef struct user {

	char name[20];
	long int cardNo;
	int cvv;
	date expiryDate;
	char password[20];
	location address;
}user;

typedef struct item {

	user client;
	float stdDev;
	float mean;
	dll list;
	transaction *root;
	struct item *next;
	
}item;

typedef struct Map {

	item **array;
	int size;
	int count;
	
}Map;

char *getLine(FILE **fp); 

Map *initHashMap();

int hashfunction(long int card_no); 

void enter_users(Map *h, user a);

void readUsersData(Map *map, FILE **fp); 

item *find(Map *map, long int no);

char* checkPass(char *input); 

int checkUser(Map *map, long int no, char *pass);

void init_dll(dll *list);

node* createNode(char *id, date payment_date, struct tm payment_time, location payment_place, int zip_code, float amount, char status);

void insertEnd(dll* list, node* newNode);

void readCsv(dll *list, FILE **fp); 

node *copyList(dll list); 

node* findMiddle(node *head); 

transaction *sortedToBST(node *head); 

float calculateMean(dll *list); 

float calculateStandardDeviation(dll *list); 

void printMenu(); 

int getInput(int num, dll list, item *endUser);

void drawLineGraph(SDL_Renderer *renderer, dll list);

//void drawAxis(SDL_Renderer *renderer);
void drawAxis(SDL_Renderer *renderer,  TTF_Font *font);

void display_graph(item *endUser);

void printRecent(dll list);

void RecentToLast(dll list); 

void oldTonew(dll list); 

int compareDate(date d1, date d2);

int is_odd_hour(struct tm time); 

int multiple_failed_transactions(node *temp); 

void renderText(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y);

void find_transactions_by_date(transaction *root, date target_date, int *count);

void find_transactions_byLocation(dll list, location place);

int is_small_time_frame(struct tm last_time, struct tm current_time); 

int frequent_trans(node *temp); 

int is_location_anomaly(location current, location last, location home);

void fraudAlert(dll list, item *endUser); 

int *flag(item *endUser);

void findFreq(item *endUser, countAmt *amt_cat, countLoc *loc_cat, countTime *time_cat, countStatus *st_cat);

void TrainModel(item *endUser, char *country, struct tm t, float at, char status, countTime time_cat, countAmt amt_cat, countLoc loc_cat, countStatus st_cat, int *counts);

void detectFraud(item *endUser);
