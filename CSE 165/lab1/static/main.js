$(document).ready(function(){
    $("#plus").click(function(){
        var left = $("#left").val();
        var right = $("#right").val();


        $.get("/add", {"x": left, "y": right}, function(response){
            var data = JSON.parse(response);

            var ans = data["ans"];

            $("#ans_area").html(ans);
        });
    });

    $("#minus").click(function(){
        var left = $("#left").val();
        var right = $("#right").val();

        $.get("/subtract", {"x":left, "y":right}, function(response){
            var data = JSON.parse(response);
            var ans = data["ans"];
            $("#ans_area").html(ans);
        })
    });

    $("#multiply").click(function(){
        var left = $("#left").val();
        var right = $("#right").val();

        $.get("/multiply", {"x":left, "y":right}, function(response){
            var data = JSON.parse(response);
            var ans = data["ans"];
            $("#ans_area").html(ans);
        })
    })

    $("#divide").click(function()
    {
        var left = $("#left").val();
        var right = $("#right").val();

        $.get("/divide", {"x":left, "y":right}, function(response){
            var data = JSON.parse(response);
            var dividend = data["dividend"];
            var remainder = data["remainder"];

            $("#ans_area").html(dividend + ", remainder: " + remainder);
        });
    });
});