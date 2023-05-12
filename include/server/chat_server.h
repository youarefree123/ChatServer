#pragma once
#include "net/tcp_server.h"


class ChatServer
{

    
public:
    ChatServer(EventLoop* loop,
               const InetAddress& listen_addr,
               const std::string &name_arg);
    ~ChatServer();
    void Start();

private:
    // 新连接接入或者旧链接断开触发的回调
    void OnConnection( const TcpConnectionPtr& );
    
    // 读事件到来时触发的回调 
    void OnMessage( const TcpConnectionPtr&, Buffer*,Timestamp );

    TcpServer server_;
    EventLoop loop_;

};


