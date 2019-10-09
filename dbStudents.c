#include <stdio.h>
#include <mysql.h>
//KAI ALLA HEADER FILES...

void sfalma(){
	printf("error");
	mysql_close(conn);
	exit(1);
}

int yparxei(MYSQL *conn,char *name){

	
}

void upgradeGrade(MYSQL *conn,char *name,float grade){
	char *sqlQuery;
	char tempGrade[3];
	sqlQuery="UPDATE
	            mathites
	          SET
                grade=";
	gcvt(grade,3,tempGrade); 	
	strcat(sqlQuery,tempGrade);			
	strcat(sqlQuery,"WHERE name='");			
    strcat(sqlQuery,name);
	strcat(sqlQuery,"';");
	if (mysql_query(conn,sqlQuery)){sfalma();}
}

void insertAnewRecord(MYSQL *conn,char *name,float grade){
	char *sqlQuery;
	char tempGrade[3];
	sqlQuery="INSERT INTO
	            mathites
			  SET	
                name='"; //???sth php ok edw???
	//concat to create the sql query
	//remember that sql query is a string for c
    strcat(sqlQuery,name);
    strcat(sqlQuery,"',grade=");
    gcvt(grade,3,tempGrade); 	
	strcat(sqlQuery,tempGrade);
	strcat(sqlQuery,";");
	if (mysql_query(conn,sqlQuery)){sfalma();}
}

void displayDB(MYSQL *conn){
	char *sqlQuery,*field0,*field1;
	sqlQuery="SELECT 
	              *
			  FROM 
                 mathites			  
	          ORDER BY grade DESC 
	                  ";
	if (mysql_query(conn,sqlQuery)){sfalma();}
    MYSQL_RES *result=mysql_store_result(conn);
    if (result==NULL){
		sfalma();
	}	
	MYSQL_ROW row;				  
	while (row=mysql_fetch_row(result)){
		field0=row[0];
		field1=row[1];
		puts(field0);
		puts(field1);
		puts(" ");
	}
	mysql_free_result(result);
}

int main(int argc,char **argv){
	MYSQL *conn;
	int choice;
	char name[15];
	float grade;
	//connect to DB
	conn=mysql_init(NULL);			
	if (conn==NULL){
		sfalma();
	}
	if (mysql_real_connect(conn,"localhost","admin","admin","students",0,NULL,0)==NULL){
		sfalma();
	}
	//print choices and read user's input
	printf("1.Upgrade database \n");
	printf("2.Display database \n");
	printf("choose:");
	scanf("%d",&choice);
	
	if (choice==1){
		//read the student's name
		gets(name);
		//read student's grade
		scanf("%f",&grade);
		//chech an yparxei hdh tetoios mathitis
		if (yparxei(conn,name)){
			updateGrade(conn,name,grade);
		}else{
			insertAnewRecord(conn,name,grade);
		}
	}else{
		displayDB(conn);
	}
	
	mysql_close(conn);
	return 0;
}