/* toralize.h */

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PROXY         "127.0.0.1"
#define PROXYPORT     9050
#define USERNAME      "toraliz"
#define reqsize sizeof(struct proxy_request)
#define ressize sizeof(struct proxy_response)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

/*
* Network Packet
* SOCKS Connect
*		          +----+----+----+----+----+----+----+----+----+----+....+----+
*		          | VN | CD | DSTPORT |      DSTIP        | USERID       |NULL|
*          		+----+----+----+----+----+----+----+----+----+----+....+----+
*            	   1    1      2              4           variable       1
*/

struct proxy_request {
  int8 vn; // * version number
  int8 cd;  // * connect code
  int16 dstport; // * destination port
  int32 destip; // * destination IP
  unsigned char username[8];
};

typedef struct proxy_request Req;

/*
* SOCKS Response
*       		+----+----+----+----+----+----+----+----+
*		        | VN | CD | DSTPORT |      DSTIP        |
*		        +----+----+----+----+----+----+----+----+
*             1    1      2              4
*/

struct proxy_response {
  int8 vn; // * version number
  int8 cd; // * connect code
  int16 _;
  int32 __;
};

typedef struct proxy_response Res;

Req *request(const char *, const int);
int main(int, char**);