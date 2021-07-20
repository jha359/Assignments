$(document).ready(function(){
	// The entire database should be displayed when your app starts
	// The Search button should be programmed to hit the /search endpoint along with the query string from the text box

	$("#searchbtn").click(function(){
		var inquiry = $("#requested").val();

		$.get("/search", {"q":inquiry}, function(response){
			var data = JSON.parse(response);
			var tried = data["attempt"];
			var list = data["result"];
			var htmlCodeSearch= "";
			var empty = "";
			var count = 0;
			
			if(tried == "Reset")
			{
				count = 1;
				for(var i in list)
				{
					htmlCodeReset = "";
					for( var j in list[i]) 
					{
						htmlCodeReset += "<div class='col-sm-3'> <img style='width:100%' src='images/" + list[i][j] + "'></div>"
					}
					$("#area" + count).html(htmlCodeReset);
					count++;
				}
			}
			else
			{
				if(tried == "Failed")
				{
					htmlCodeSearch += "Could not find any matching results."
				}
				else
				{
					for(var i in list)
					{
						htmlCodeSearch += "<div class='col-sm-3'> <img style='width:100%' src='images/" + list[i] + "'></div>"
					}
				}
				$("#area1").html(htmlCodeSearch);

				count = 2;
				while(count < 6)
				{
					$("#area" + count).html(empty);
					count++
				}
			}
		});
	});

	$.get("/search", {}, function(response){
		var data = JSON.parse(response);
		var list = data["result"];

		var count = 1;
		for(var i in list)
		{
			htmlCode = "";
			for( var j in list[i]) 
			{
				htmlCode += "<div class='col-sm-3'> <img style='width:100%' src='images/" + list[i][j] + "'></div>"
			}
			$("#area" + count).html(htmlCode);
			count++;
		}


	});
});	
	
