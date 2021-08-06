#include "HTTPClientFactory.h"
#include "../../HTTP/HTTPClient/CURLHTTP.h"

std::shared_ptr<PAL::IHTTPClient> PAL::HTTPClientFactory::makeHTTPClient() {
	return std::make_shared<PAL::CURLHTTP>();
}

using namespace PAL;
using namespace std;
function<shared_ptr<IHTTPClient>()> HTTPClientFactory::createHTTPClient = HTTPClientFactory::makeHTTPClient;
