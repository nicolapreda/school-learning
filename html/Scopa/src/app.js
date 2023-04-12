

var canvas;
var ctx;

var sourceImage = new Image();
sourceImage.src = './cards/cards.jpg';

sourceImage.onload = function () {
    var w = 0;
    var h = 0;
    for (var x = 0; i < 3; x++, w+=312, h+=560) {
        canvas = document.getElementById('canvas' + x);
        ctx = canvas.getContext('2d');
        canvas.width = 312;
        canvas.height = 560;

        //diminuisce la dimensione dell'immagine
        ctx.scale(0.3, 0.3);

        // Disegna l'immagine sul canvas
        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }
    var w = 0;
    var h = 0;

    for (var i = 3; i < 7; i++, w+=312, h+=560) {
        canvas = document.getElementById('canvas' + i);
        ctx = canvas.getContext('2d');
        canvas.width = 312;
        canvas.height = 560;

        //diminuisce la dimensione dell'immagine
        ctx.scale(0.3, 0.3);

        // Disegna l'immagine sul canvas
        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }

    var w = 0;
    var h = 0;

    for (var z = 7; i < 10; z++, w+=312, h+=560) {
        canvas = document.getElementById('canvas' + z);
        ctx = canvas.getContext('2d');
        canvas.width = 312;
        canvas.height = 560;

        //diminuisce la dimensione dell'immagine
        ctx.scale(0.3, 0.3);

        // Disegna l'immagine sul canvas
        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }

}

    


