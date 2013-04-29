
Import mojo
Import webview

Class TestApp Extends App
	Field open:Bool = True 
	
	Method OnCreate()

		SetUpdateRate 60
		
		OpenWebView("http://va5.com", 50, 50, 640, 400)
	End
	Method OnUpdate()
		If MouseHit(MOUSE_LEFT) And MouseX() >= 0 And MouseY() > 410
			If open 
				open = False
				CloseWebView
			Else
				open = True
				OpenWebView("http://va5.com", 100, 50, 640, 400)
				
			End
		End
	End
	Method OnRender() 
		DrawText("Click  to close", 10, 430)
		If WebViewLoaded 
			DrawText("Page has been loaded", 10, 450)
		End
	End
End

Function Main() 
	New TestApp
End