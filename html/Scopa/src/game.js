
var canvas;
var ctx;

var sourceImage = new Image();
sourceImage.src = './assets/cards.png';

var retroImage = new Image();
retroImage.src = './assets/retro.png';

//filtra il link e prendi l'id della lobby
var url = window.location.href;
var id = url.substring(url.lastIndexOf('=') + 1);

//se il tuo nickname inizia con scopa1 o scopa0 decidi chi gioca per primo
/*if (localStorage.getItem('nickname').startsWith("scopa1") || localStorage.getItem('nickname').startsWith("scopa0")) {
    var turn = Math.floor(Math.random() * 2) + 1;
}*/
    

//mossa:
//0 => bastoni
//1 => spade
//2 => coppe
//3 => ori

//mosse 2:
//x_0 => prima carta
//x_1 => seconda carta
//x_2 => terza carta
//x_3 => quarta carta
//x_4 => quinta carta
//x_5 => sesta carta
//x_6 => settima carta
//x_7 => ottava carta
//x_8 => nona carta
//x_9 => decima carta


//crea un array contenente il mazzo alleato
var allyDeck = [];


sourceImage.onload = function () {


    var w = 0;
    var h = 0;
    for (var q = 0; q < 3; q++, w+=312, h+=560) {
        canvas = document.getElementById('canvas' + q);
        ctx = canvas.getContext('2d');

        canvas.width = 94;
        canvas.height = 167;

        //disegna la carta senza tagliare pezzi della foto
        ctx.drawImage(retroImage, 0, 0, 643, 1023, 0, 0, 643, 1023);

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

