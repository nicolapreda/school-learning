$(document).ready(function() {
    let checkBoxSequence = document.getElementById("nSequence");
    checkBoxSequence.addEventListener("change", function() {
        let nSequence = parseInt(this.value);
        console.log(nSequence);
    });

    let checkBoxNColors = document.getElementById("nColors");
    checkBoxNColors.addEventListener("change", function() {
        let nColors = parseInt(this.value);
        console.log(nColors);
    });
    let repeatedColors;

    // Get the checkbox
    let isRepeatedColors = document.getElementById("RepeatedColors");

    if (isRepeatedColors.checked == true) {
        repeatedColors = true;
    } else {
        repeatedColors = false;
    }

    //Array  with possible colors
    let possibleColors = ["blue", "green", "red", "yellow", "orange", "pink"];

    let colors = {
        "rgb(0, 128, 0)": "green",
        "rgb(255, 255, 0)": "yellow",
        "rgb(255, 0, 0)": "red",
        "rgb(0, 0, 255)": "blue",
        "rgb(255, 192, 203)": "pink",
        "rgb(255, 165, 0)": "orange",
    };

    let hasWon = false;

    //Define start button
    let startBtn = document.getElementById("start");
    //When start button is clicked
    $(startBtn).click(function() {
        //Disable options
        checkBoxSequence.setAttribute("disabled", "");
        checkBoxNColors.setAttribute("disabled", "");
        isRepeatedColors.setAttribute("disabled", "");

        //Set sequence code
        let code = [];
        for (let i = 0; i < nSequence; i++) {
            code[i] = possibleColors[Math.floor(Math.random() * 6)];
        }
        console.log(code);

        //change the current color when the user clicks on the color board
        $(".color").click(function() {
            let color = $(this).attr("id");
            currentColor = color;
            $(".currentColor").css("background-color", color);
        });

        //change the color of a board cell on click
        $(".boardCell").click(function() {
            var id = $(this).attr("id");

            if (isValid(id)) {
                $(this).css("background-color", currentColor);
            }
        });
    });
});