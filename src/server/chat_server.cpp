#include "server/chat_server.h"
#include "log.h"

ChatServer::ChatServer(EventLoop *loop,
            const InetAddress &addr, 
            const std::string &name)
        : server_(loop, addr, name)
        , loop_(loop)
    {
        // 注册回调函数
        server_.set_conn_callback(
            std::bind(&ChatServer::onConnection, this, std::placeholders::_1)
        );

        server_.set_msg_callback(
            std::bind(&ChatServer::onMessage, this,
                std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)
        );
    }

void ChatServer::Start()
{
    server_.Start();
}


// 新连接接入或者旧链接断开触发的回调
void OnConnection( const TcpConnectionPtr& conn ) {
    if( conn->Connected() ) {
        INFO(" The Conn is Connected ");
        conn->Shutdown();
    }
    else {
        INFO(" The Conn is Shutdown ");
    }

}

// 读事件到来时触发的回调 
void OnMessage( const TcpConnectionPtr&, Buffer*,Timestamp ) {}




