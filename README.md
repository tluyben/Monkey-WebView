Monkey-WebView
==============

WebView module for Monkey

Allowing loading of web pages in games at specific coordinates. 

- OpenWebView(url:String, x:Float, y:Float, w:Float, h:Float) 

Opens a webview with the specific url at the specified coordinates with a specific width and height. 

In HTML5 and Flash this is implemented with an iframe, on mobile (TODO) using UIWebView on iOS and 
android.webkit.WebView on Android.

- CloseWebView()

Closes the opened view. 

- WebViewLoaded?

Returns True if the web page has been loaded. Does not work in Flash. 


Installation:

Add the module to your project or to the Monkey modules directory. 

For Flash, add 

	<script language="javascript" src="webview.html5.js"></script>

to MonkeyGame.html
