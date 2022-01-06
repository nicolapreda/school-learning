$(document).ready(function () {
  //Array  with possible colors
  var possibleColors = ["blue", "green", "red", "yellow", "orange", "pink", "white", "black", "brown", "lightgreen"];
  let typeMode = document.getElementById("modeType");
  let checkBoxSequence = document.getElementById("nSequence");
  checkBoxSequence.addEventListener("change", function () {
    let nSequence = parseInt(this.value);
    console.log(nSequence);

  });

  let checkBoxNColors = document.getElementById("nColors");
  checkBoxNColors.addEventListener("change", function () {
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



  //Define start button
  let startBtn = document.getElementById("start");
  //When start button is clicked
  $(startBtn).click(function () {
    let hasWon = false;


    //Disable options
    checkBoxSequence.setAttribute("disabled", "");
    checkBoxNColors.setAttribute("disabled", "");
    isRepeatedColors.setAttribute("disabled", "");
    startBtn.setAttribute("disabled", "");
    typeMode.setAttribute("disabled", "");
    possibleColors.slice(0, -nColors)
    console.log(possibleColors)




    //let gameContent = document.getElementById('gameContainer');
    //gameContent.style.display = 'initial';

    //Set the colors

    let colors = ["rgb(0, 0, 255)", // Blue
      "rgb(0, 128, 0)",//Green
      "rgb(255, 0, 0)",//Red
      "rgb(255, 255, 0)", //Yellow
      "rgb(255, 165, 0)", //Orange
      "rgb(255, 192, 203)", //Pink
      "rgb(255, 255, 255)", // White
      "rgb(0,0,0)", // Black
      "rgb(79, 44, 27)", // Brown
      "rgb(78, 191, 50)"] //Light Green

    //Create color backgrounds
    for (var c = 0; c < parseInt(nColors.value); c++) {
      if (c < 5) {
        document.getElementById('colorsContent1').insertAdjacentHTML('beforeend', '<div class="square square-lg m-2"><button class="w-h-100 color" style="background-color:' + colors[c] + '" id="' + colors[c] + '"></div>');
      }
      else {
        document.getElementById('colorsContent2').insertAdjacentHTML('beforeend', '<div class="square square-lg m-2"><button class="w-h-100 color" style="background-color:' + colors[c] + '" id="' + colors[c] + '"></div>');
      }
    };

    //Set sequence code
    let code = [];
    for (let i = 0; i < parseInt(nSequence.value); i++) {
      code[i] = possibleColors[Math.floor(Math.random() * 6)];
    }
    console.log(code);

    //Insert sockets into the interface
    for (var i = 1; i <= 10; i++) {
      for (var s = 1; s <= parseInt(nSequence.value); s++) {

        document.getElementById('slot' + i).insertAdjacentHTML('afterbegin', '<div class="square square-lg m-2"><button class="w-h-100 socket" id="socket' + s + '"></div>');
      }
      //Insert Socket results
      document.getElementById('slot' + i).insertAdjacentHTML('beforeend', '<div class="roundresult"><div class="d-flex"><div class="square square-lg mr-1"><button class="w-h-100 socketresult" disabled></div><div class="square square-lg"><button class="w-h-100 socketresult" disabled></div></div><div class="d-flex"><div class="square square-lg mr-1"><button class="w-h-100 socketresult" disabled></div><div class="square square-lg"><button class="w-h-100 socketresult" disabled></div></div></div>');
    }
    
    //change the current color when the user clicks on the color board
    $(".color").click(function () {
      let color = $(this).attr("id");
      currentColor = color;
      $(".currentColor").css("background-color", color);
    });

    //change the color of a board cell on click
    $(".socket").click(function () {
      var id = $(this).attr("id");

        $(this).css("background-color", currentColor);
      
    });

  });
});
