#include "json.h"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>


using namespace std;

int main(int argc, char const *argv[])
{
    json js;
    js["msg_type"] = 2;
    js["name"] = "zhangsan";
    js["msg"] = "hello world";
    js["id"] = {1,2,3,4,5};
    js["arr"]["张三"] = "zhangsan";
    js["arr"]["李四"] = "lisi";
    std::string sendBuf = js.dump();
    printf("%s\n",sendBuf.c_str());

    json js2 = json::parse( sendBuf );
    cout<<js2["name"]<<endl;


    return 0;
}
