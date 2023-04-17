var canvas;
var ctx;

var sourceImage = new Image();
sourceImage.src = './assets/cards.png';

sourceImage.onload = function () {


    var w = 0;
    var h = 0;

    for (var q = 0; q < 3; q++, w += 312, h += 560) {
        canvas = document.getElementById('nemico' + q);
        ctx = canvas.getContext('2d');

        canvas.width = 94;
        canvas.height = 167;
        ctx.scale(0.3, 0.3)


        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }

    var w = 0;
    var h = 0;

    for (var i = 3; i < 7; i++, w += 312, h += 560) {
        var mazzo = document.getElementById('mazzo');
        //in base al numero di carte nel mazzo, aggiungo un canvas e modifica la classe 
        var canvas = document.createElement('canvas');
        canvas.id = 'canvas' + i;
        canvas.className = 'carta';
        mazzo.appendChild(canvas);


        canvas = document.getElementById('canvas' + i);
        ctx = canvas.getContext('2d');
        canvas.width = 94;
        canvas.height = 167;

        ctx.scale(0.3, 0.3);

        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }

    var w = 0;
    var h = 0;

    for (var p = 7; p < 10; p++, w += 312, h += 560) {
        canvas = document.getElementById('canvas' + p);
        ctx = canvas.getContext('2d');
        canvas.width = 94;
        canvas.height = 167;

        ctx.scale(0.3, 0.3);

        ctx.drawImage(sourceImage, 0, 0, 312, 560, 0, 0, 312, 560);

    }
    

}




