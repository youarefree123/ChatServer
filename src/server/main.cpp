#include "server/chat_server.h"
#include "log.h"
int main()
{
    ONLY_TO_CONSOLE; LOGINIT(); LOG_LEVEL_TRACE;
    EventLoop loop;
    InetAddress addr(8000);
    
    ChatServer server(&loop, addr, "EchoServer-01"); // Acceptor non-blocking listenfd  create bind 

   

    server.Start(); // listen  loopthread  listenfd => acceptChannel => mainLoop =>
    loop.Loop(); // 启动mainLoop的底层Poller

    return 0;
}