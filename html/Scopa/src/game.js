
var canvas;
var ctx;

var sourceImage = new Image();
sourceImage.src = './assets/cards.png';

//filtra il link e prendi l'id della lobby
var url = window.location.href;
var id = url.substring(url.lastIndexOf('=') + 1);


//decidi casualmente il giocatore che inizierà
var turn = Math.floor(Math.random() * 2) + 1;

//crea il mazzo di carte al giocatore 1



sourceImage.onload = function () {


    var w = 0;
    var h = 0;
    for (var q = 0; q < 3; q++, w+=312, h+=560) {
        canvas = document.getElementById('canvas' + q);
        ctx = canvas.getContext('2d');

        canvas.width = 94;
        canvas.height = 167;
        ctx.scale(0.3, 0.3)


        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }
    var w = 0;
    var h = 0;

    for (var i = 3; i < 7; i++, w+=312, h+=560) {
        canvas = document.getElementById('canvas' + i);
        ctx = canvas.getContext('2d');
        canvas.width = 94;
        canvas.height = 167;

        ctx.scale(0.3, 0.3);

        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }

    var w = 0;
    var h = 0;

    for (var p = 7; p < 10; p++, w+=312, h+=560) {
        canvas = document.getElementById('canvas' + p);
        ctx = canvas.getContext('2d');
        canvas.width = 94;
        canvas.height = 167;

        ctx.scale(0.3, 0.3);

        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }
    

}

