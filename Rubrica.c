#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

static struct Connection *conn;

void dbClose(){
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

void die(const char *message){
    if(errno)	perror(message);
    else    	printf("ERROR: %s\n", message);
	dbClose();
    exit(1);
}

void addrPrint(struct Address *addr){
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void dbLoad(){
    int rc = fread(conn->db, sizeof(*(conn->db)), 1, conn->file);
    if(rc != 1) die("Failed to load database.");
}

void dbOpen(const char *filename, char mode){
    conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error");

    if(mode == 'c')
        conn->file = fopen(filename, "w");
    else {
    	conn->file = fopen(filename, "r+");
        if(conn->file)
            dbLoad(conn);
    }

    if(!conn->file) die("Failed to open the file");
}

void dbWrite(){
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(*(conn->db)), 1, conn->file);
    if(rc != 1) die("Failed to write database.");

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");
}

void dbCreate(){
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address addr = {.id = i, .set = 0};
        conn->db->rows[i] = addr;
    }
}

void dbSet(int id, const char *name, const char *email){
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die("Already set, delete it first");

    addr->set = 1;

    char *res = strncpy(addr->name, name, MAX_DATA);

    if(!res) die("Name copy failed");

    res = strncpy(addr->email, email, MAX_DATA);
    if(!res) die("Email copy failed");
}

void dbGet(int id){
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        addrPrint(addr);
    } else {
        die("ID is not set");
    }
}

void dbDelete(int id){
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void dbList(){
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];
        if(cur->set)
            addrPrint(cur);
    }
}

void dbFindName(char *query){
	int i = 0;
	for (; i < MAX_ROWS; ++i){
		if (*(conn->db->rows[i].name) == *query)
		addrPrint(&conn->db->rows[i]);
	}		
}

void dbFindEmail(char *query){
	int i = 0;
	for (; i < MAX_ROWS; ++i){
		if (*(conn->db->rows[i].email) == *query)
		addrPrint(&conn->db->rows[i]);
	}	
}

int main(int argc, char *argv[]){
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    dbOpen(filename, action);
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);
    if(id >= MAX_ROWS) die("There's not that many records.");

    switch(action) {
        case 'c':
            dbCreate();
            dbWrite();
            break;

        case 'g':
            if(argc != 4) die("Need an id to get");

            dbGet(id);
            break;

        case 's':
            if(argc != 6) die("Need id, name, email to set");

            dbSet(id, argv[4], argv[5]);
            dbWrite();
            break;

        case 'd':
            if(argc != 4) die("Need id to delete");

            dbDelete(id);
            dbWrite();
            break;

        case 'l':
            dbList();
            break;
            
        case 'f':
        	if(argc != 5) puts("FIND USAGE: <db file> f <n == name/e == email> <query>");
        	if (argv[3][0] == 'n')
        		dbFindName(argv[4]);
        	else if (argv[3][0] == 'e')
        		dbFindEmail(argv[4]);
        	break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");            
    }

    dbClose();

    return 0;
}
