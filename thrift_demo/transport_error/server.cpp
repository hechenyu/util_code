// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "EchoTest.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <iostream>
#include <string>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::demo;

bool g_pause_flag = false;

void my_pause()
{
  std::cerr << "pause, entry \\n to continue\n";
  std::string str;
  std::getline(std::cin, str);
}

class EchoTestHandler : virtual public EchoTestIf {
 public:
  EchoTestHandler() {
    // Your initialization goes here
  }

  void echo(std::string& _return, const std::string& str) {
    // Your implementation goes here
    std::cerr << "echo " << str << "\n";
    if (g_pause_flag)
      my_pause();
    _return = str;
  }

};

int main(int argc, char **argv) {

  int port = 9090;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] == 'x') {
      g_pause_flag = true;
    } else {
      int tmp = atoi(argv[1]);
      if (tmp != 0) port = tmp;
    }
  }

  shared_ptr<EchoTestHandler> handler(new EchoTestHandler());
  shared_ptr<TProcessor> processor(new EchoTestProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
