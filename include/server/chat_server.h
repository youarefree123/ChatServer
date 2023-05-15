#pragma once
#include "net/tcp_server.h"

class ChatServer
{

    
public:
    // using ConnctionMap = std::unordered_map< std::string, TcpConnectionPtr >;
    ChatServer(EventLoop* loop,
               const InetAddress& listen_addr,
               const std::string &name_arg);
    ~ChatServer() = default;
    void Start();
    const ConnctionMap& conns() const { return server_.conns(); } 
private:
    // 新连接接入或者旧链接断开触发的回调
    void OnConnection( const TcpConnectionPtr& );
    
    // 读事件到来时触发的回调 
    void OnMessage( const TcpConnectionPtr&, Buffer*,Timestamp );

    TcpServer server_;
    EventLoop* loop_;

};


