import flash.net.navigateToURL;
import flash.net.URLRequest;

function getURL(url:String, window:String = "_self"):void
{
    navigateToURL(new URLRequest(url), window);
}
function OpenWebView(url:String,x:Number,y:Number,w:Number,h:Number):void {
	getURL("javascript:OpenWebView('"+url+"',"+x+","+y+","+w+","+h+");");
}

function CloseWebView():void {
	getURL("javascript:CloseWebView();");	
}

function WebViewLoaded():Boolean {
	return false; 
}
