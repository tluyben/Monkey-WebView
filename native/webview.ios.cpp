@interface MonkeyWebViewUIDelegate : NSObject <UIWebViewDelegate>{
    UIView *view;
    UIWebView *webView;
@public    
    bool finished;
}

@end
@implementation MonkeyWebViewUIDelegate
- (void)webViewDidFinishLoad:(UIWebView *)webView{
    
    self->finished = true;
}
- (void)webViewDidStartLoad:(UIWebView *)webView{
    
}
- (void)show:(bool)show{
 
    if (show) {
        [self->webView setHidden:NO];
        
    } else {
        [self->webView setHidden:YES];
    }
    
}
- (void)initGUI:(UIView *)myView :(String)url :(float)x :(float)y :(float)w :(float)h{
    self->finished = false;
    self->view = myView;
    if (self->webView == NULL) {
        self->webView = [[[UIWebView alloc]initWithFrame:CGRectMake(x, y, w, h)] autorelease];
        webView.autoresizesSubviews = YES;
        webView.autoresizingMask=(UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth);
        [self->view addSubview:webView];
        [webView setDelegate:self];
    } else {
        self->webView.frame = CGRectMake(x, y, w, h);
        [self->webView setHidden:NO];
    }
    NSURL *_url = [NSURL URLWithString:url.ToNSString()];
    NSURLRequest *requestObj = [NSURLRequest requestWithURL:_url];
    [webView loadRequest:requestObj];
}
@end
MonkeyWebViewUIDelegate *activeView=NULL;

void HideWebView() {
    if (activeView != NULL) {
        [activeView show:false];
    }
}
void ShowWebView() {
    if (activeView != NULL) {
        [activeView show:true];
    }
}
void CloseWebView() {
    HideWebView();
}
bool WebViewLoaded() {
    return activeView != NULL && activeView->finished;
}
void OpenWebView(String url, Float x, Float y, Float w, Float h) {
    if (activeView == NULL) {
        activeView = [[MonkeyWebViewUIDelegate alloc] init];
    }
    MonkeyAppDelegate *appDelegate=(MonkeyAppDelegate*)[[UIApplication sharedApplication] delegate];
    [activeView initGUI:appDelegate->view :url :x :y :w :h];
}