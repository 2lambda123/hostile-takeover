#ifndef __IPHONEHTTPREQUEST_H__
#define __IPHONEHTTPREQUEST_H__

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#include "game/httpservice.h"
#include "game/httprequest.h"
#include "base/thread.h"
#include "base/bytebuffer.h"

namespace wi {

class IPhoneHttpRequest : public HttpRequest, base::MessageHandler {
public:
    IPhoneHttpRequest(HttpResponseHandler *phandler);
    ~IPhoneHttpRequest();

    void Dispose();
    NSURLRequest *CreateNSURLRequest();
    void OnReceivedResponse(NSHTTPURLResponse *resp);
    void OnReceivedData(NSData *data);
    void OnFinishedLoading();
    void OnError(NSError *error);

private:
    virtual void OnMessage(base::Message *pmsg);

    HttpResponseHandler *handler_;
};

struct ReceivedResponseParams : base::MessageData {
    int code;
    Map headers;
};

struct ReceivedDataParams : base::MessageData {
    base::ByteBuffer bb;
};

struct ErrorParams : base::MessageData {
    char szError[80];
};

} // namespace wi

#endif // __IPHONEHTTPREQUEST_H__
