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
            std::bind(&ChatServer::OnConnection, this, std::placeholders::_1)
        );

        server_.set_msg_callback(
            std::bind(&ChatServer::OnMessage, this,
                std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)
        );
        
        // 设置合适的loop线程数量 loopthread
        server_.set_thread_num(2);
    }

void ChatServer::Start()
{
    server_.Start();
}


// 新连接接入或者旧链接断开触发的回调
void ChatServer::OnConnection( const TcpConnectionPtr& conn ) {
    if( conn->Connected() ) {
        INFO(" The Conn is Connected ");
    }
    else {
        INFO(" The Conn is Shutdown ");
    }

}

// 读事件到来时触发的回调 

// 可读写事件回调
void ChatServer::OnMessage(const TcpConnectionPtr &conn,
            UnlimitedBuffer *buf,
            Timestamp time)
{
    std::string msg = buf->RetrieveAll();
    INFO( "current loop = {},  The msg = {}", reinterpret_cast<size_t>( conn->loop() ) , msg );
    ConnctionMap connsMap = this->conns();
    for( auto [key,value] : connsMap ) {
        value->Send(conn->name()+": "+msg);
    }
    // conn->Send(msg);
    // conn->Shutdown(); // 写端   EPOLLHUP =》 closeCallback_
    
}


