//
// main.cpp for main.cpp in /home/bequig_s//workspace/rush
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Mar  8 20:43:58 2013 sebastien bequignon
// Last update Sun Mar 10 18:14:33 2013 sebastien bequignon
//
#include<iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;
#define HELO "HELO smtp.gmail.com\r\n"
#define DATA "DATA\r\n"
#define QUIT "QUIT\r\n"

//#define h_addr h_addr_list[0]
//FILE *fin;
int sock;
struct sockaddr_in server;
struct hostent *hp, *gethostbyname();
char buf[BUFSIZ+1];
int len;
// char *host_id="smtp.yopmail.com";
// char *from_id="sebeq33@hotmail.fr";
// char *to_id="ababababa@yopmail.com";
char *host_id="smtp.gmx.com";
char *from_id="poney42@caramail.com";
char *to_id="poney42@netcourrier.com";
char *sub="testmail\r\n";
char wkstr[100]="hello how r u\r\n";

/*=====Send a string to the socket=====*/

void send_socket(char *s)
{
  if (write(sock,s,strlen(s)) < 0)
    printf("FAIL WRITE\n");
  write(1,s,strlen(s));
  //printf("Client:%s\n",s);
}

//=====Read a string from the socket=====*/

void read_socket()
{
  len = read(sock,buf,BUFSIZ);
  write(1,buf,len);
  //printf("Server:%s\n",buf);
}

/*=====MAIN=====*/
int main(int argc, char* argv[])
{

  /*=====Create Socket=====*/
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock==-1)
    {
      perror("opening stream socket");
      exit(1);
    }
  else
    cout << "socket created\n";
  /*=====Verify host=====*/
  server.sin_family = AF_INET;
  hp = gethostbyname(host_id);
  if (hp == (struct hostent *) 0)
    {
      fprintf(stderr, "%s: unknown host\n", host_id);
      exit(2);
    }

  /*=====Connect to port 25 on remote host=====*/
  memcpy((char *) &server.sin_addr, (char *) hp->h_addr, hp->h_length);
  server.sin_port=htons(25); /* SMTP PORT */
  if (connect(sock, (struct sockaddr *) &server, sizeof server)==-1)
    {
      perror("connecting stream socket");
      exit(1);
    }
  else
    cout << "Connected\n";

  /*=====Write some data then read some =====*/
  read_socket(); /* SMTP Server logon string */
  send_socket(HELO); /* introduce ourselves */
  read_socket(); /*Read reply */

  send_socket("AUTH LOGIN\r\n");
  read_socket(); // Sender OK */

  send_socket();
  read_socket(); // Sender OK */

  send_socket("MAIL FROM: <");
  send_socket(from_id);
  send_socket(">\r\n");
  read_socket(); /* Sender OK */

  // send_socket("RCPT ");
  // send_socket(from_id);
  // send_socket("\r\n");
  // read_socket(); // Sender OK */

  send_socket("RCPT TO: <"); /*Mail to*/
  send_socket(to_id);
  send_socket(">\r\n");
  read_socket(); // Recipient OK*/
  send_socket(DATA);// body to follow*/
  send_socket("Subject: ");
  send_socket(sub);
  read_socket(); // Recipient OK*/
  send_socket(wkstr);
  send_socket(".\r\n");
  read_socket();
  send_socket(QUIT); /* quit */
  read_socket(); // log off */

  //=====Close socket and finish=====*/
  close(sock);
  exit(0);
}
