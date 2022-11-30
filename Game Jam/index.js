var playing = true;

//set array with life and power
var card1_stat = [3, 10];
var card2_stat = [3, 10];
var card3_stat = [3, 10];
var card4_stat = [3, 10];
var card5_stat = [3, 10];

function startGame() {
    document.getElementById("main-menu").remove();
    //show the game
    document.getElementById("game").style.display = "block";
    //remove background blur
    document.getElementById("game").style.filter = "blur(0px)";
    var rand = Math.floor(Math.random() * 10) + 1;
    setTimeout(movePowerup, rand * 1000);
}


function movePowerup() {
    //select a random powerup in ./assets/img/powerup folder
    var powerup_names = ["boost.png", "gun.png", "helmet.png", "kill.png", "medikit.png", "pump.png"];
    var powerup_img = Math.floor(Math.random() * 5) + 1;
    //create canva element
    var canvas = document.createElement("canvas");
    canvas.id = ""
    //set canvas size
    canvas.width = 100;
    canvas.height = 100;
    //set canvas position to the bottom left corner
    const ctx = canvas.getContext("2d");
    //set ctx position to the bottom left corner
    ctx.translate(0, canvas.height);
    //set canvas position to the bottom left corner
    canvas.style.position = "absolute";
    canvas.style.bottom = "0";
    canvas.style.marginBottom = "0";
    canvas.style.zIndex = "1";
    canvas.style.left = "240px";
    //add canvas to game div
    //set background color
    canvas.style.backgroundImage = "url(./assets/img/powerup/" + powerup_names[powerup_img] + ")";
    canvas.style.backgroundRepeat = "no-repeat";
    canvas.style.backgroundSize = "cover";
    document.getElementById("game-section").appendChild(canvas);
    //move canvas up with an animation
    var pos = 0;
    var id = setInterval(frame, 10);
    function frame() {
        if (pos == 365) {
            clearInterval(id);
            var pos1 = 240;
            var id1 = setInterval(frame1, 10);
            function frame1() {
                if (pos1 == 880) {
                    clearInterval(id1);
                    var pos2 = 365;
                    var id2 = setInterval(frame2, 10);
                    function frame2() {
                        if (pos2 == 900) {
                            clearInterval(id2);
                            canvas.remove();

                            var rand = Math.floor(Math.random() * 10) + 1;
                            setTimeout(movePowerup, rand * 1000);

                        } else {
                            pos2++;
                            canvas.style.bottom = pos2 + 'px';
                        }
                    }
                } else {
                    pos1++;
                    canvas.style.left = pos1 + 'px';
                }
            }
        } else {
            pos++;
            canvas.style.bottom = pos + 'px';
        }
    }


    canvas.addEventListener('click', function () {
        console.log("clicked");
        let card1 = document.getElementById("card1");
        let card2 = document.getElementById("card2");
        let card3 = document.getElementById("card3");
        let card4 = document.getElementById("card4");
        let card5 = document.getElementById("card5");

        //add a yellow border to all cards
        card1.style.border = "3px solid yellow";
        card2.style.border = "3px solid yellow";
        card3.style.border = "3px solid yellow";
        card4.style.border = "3px solid yellow";
        card5.style.border = "3px solid yellow";

        function borderNone() {
            card1.style.border = "none";
            card2.style.border = "none";
            card3.style.border = "none";
            card4.style.border = "none";
            card5.style.border = "none";
        }
        //check if cards are clicked
        card1.addEventListener('click', function () {
            console.log("card1 clicked");
            borderNone();

            switch (powerup_names[powerup_img]) {
                case "boost.png":
                    console.log("boost");
                    card1_stat[1] = 10;
                    break;
                case "kill.png":
                    card1_stat[0] = 0;
                    //move card to the graveyard
                    card1.left = "1000px";
                    card1.top = "1000px";
                    card1.id = "card1-graveyard";
                    break;
                case "medikit.png":
                    card1_stat[0] = 3;
                    break;

            }

            canvas.remove();
            return;
        }
        );

        card2.addEventListener('click', function () {
            console.log("card2 clicked");
            borderNone();
            switch (powerup_names[powerup_img]) {
                case "boost.png":
                    console.log("boost");
                    
                    break;
                case "kill.png":
                    card1_stat[0] = 0;
                    //move card to the graveyard
                    card1.left = "1000px";
                    card1.top = "1000px";
                    card1.id = "card1-graveyard";
                    break;
                case "medikit.png":
                    card1_stat[0] = 3;
                    break;
            }

            canvas.remove();
            return;
        }
        );
        card3.addEventListener('click', function () {
            console.log("card3 clicked");
            borderNone();
            switch (powerup_names[powerup_img]) {
                case "boost.png":
                    console.log("boost");
                    break;
                case "kill.png":
                    card1_stat[0] = 0;
                    //move card to the graveyard
                    card1.left = "1000px";
                    card1.top = "1000px";
                    card1.id = "card3-graveyard";
                    break;
                case "medikit.png":
                    card1_stat[0] = 3;
                    break;

            }

            canvas.remove();
            canvas.remove();
            return;
        }
        );

        card4.addEventListener('click', function () {
            console.log("card4 clicked");
            borderNone();
            switch (powerup_names[powerup_img]) {
                case "boost.png":
                    console.log("boost");
                    break;
                case "kill.png":
                    card1_stat[0] = 0;
                    //move card to the graveyard
                    card1.left = "1000px";
                    card1.top = "1000px";
                    card1.id = "card4-graveyard";
                    break;
                case "medikit.png":
                    card1_stat[0] = 3;
                    break;

            }
            canvas.remove();
            return;
        }
        );

        card5.addEventListener('click', function () {
            console.log("card5 clicked");
            borderNone();
            switch (powerup_names[powerup_img]) {
                case "boost.png":
                    console.log("boost");
                    break;
                case "kill.png":
                    card1_stat[0] = 0;
                    //move card to the graveyard
                    card1.left = "1000px";
                    card1.top = "1000px";
                    card1.id = "card5-graveyard";
                    break;
                case "medikit.png":
                    card1_stat[0] = 3;
                    break;
            }
            canvas.remove();
            return;
        }
        );

    }, false);

}


