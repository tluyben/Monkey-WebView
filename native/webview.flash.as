import flash.external.ExternalInterface

function OpenWebView(url:String,x:Number,y:Number,w:Number,h:Number):void {
	ExternalInterface.call("OpenWebView('"+url+"',"+x+","+y+","+w+","+h+")");
}

function CloseWebView():void {
	ExternalInterface.call("CloseWebView()");	
}

function WebViewLoaded():Boolean {
	var s:Boolean = ExternalInterface.call("WebViewLoaded()");
	return s;
}
