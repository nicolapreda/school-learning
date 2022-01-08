$(document).ready(function () {
  //Array  with possible colors
  var possibleColors = ["blue", "green", "red", "yellow", "orange", "pink", "white", "black", "brown", "lightgreen"];
  var currentColor = "white";

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

    //Insert boards into the interface
    var boardId = 0
    for (var i = 1; i <= 10; i++) {
      for (var s = 0; s < parseInt(nSequence.value); s++) {
        //
        document.getElementById('slot' + i).insertAdjacentHTML('beforeend', '<div class="square square-lg m-2"><button class="w-h-100 socket" id="board' + boardId +  '"></div>');
      boardId++
    }

      document.getElementById('slot' + i).insertAdjacentHTML('afterbegin', '<div class="roundresult">');
      for (var s = 0; s < parseInt(nSequence.value); s++) {
        if (s % 2 == 0) {
          //Insert boards results
          document.getElementById('slot' + i).insertAdjacentHTML('beforeend', '<div class="d-flex"><div class="square square-lg mr-1"><button class="w-h-100 socketresult" disabled></div>');

        } 
        else {
          document.getElementById('slot' + i).insertAdjacentHTML('beforeend', '<div class="square square-lg mr-1"><button class="w-h-100 socketresult" disabled></div></div>');

        }

      }

    }


    var currentBoardCells = [];
    var currentPegCells = [];
    var currentRow = 10;
    var cellColor = [];


    //Set sequence code
    let code = [];
    for (let i = 0; i < parseInt(nSequence.value); i++) {
      code[i] = possibleColors[Math.floor(Math.random() * parseInt(nSequence.value))];
      currentBoardCells[i] = 'board' + i;
      currentPegCells[i] = 'peg' + i;

    }
    console.log(currentBoardCells)
    console.log(currentPegCells)
    console.log(code);


    //change the current color when the user clicks on the color board
    $(".color").click(function () {
      let color = $(this).attr("id");
      currentColor = color;
      $(".currentColor").css("background-color", color);
    });

    //change the color of a board cell on click
    $(".socket").click(function () {
      var id = $(this).attr("id");
      if(isValid(id)){
        $(this).css("background-color", currentColor);
      }
      

    });

    //do actions when the submit button is clicked
    $(".submit").click(function () {
      updatePegs();
      checkWin();
      changeCurrentRow();
    });

    function isValid(id){
      if(currentBoardCells.includes(id) && hasWon === false){
        return true;
      }
      return false;
    }


    //check if the player has won
    function checkWin(){
      hasWon = true;
      for(var c = 0; c<parseInt(nSequence.value); c++){
        if(code[c] != cellColor[c]){
          hasWon = false;
        }
      }
      if(hasWon == true){
        alert("Congratulations, you have won!\nThe code will now be displayed.");
      }
          
    }
      return hasWon; 
  

    function changeCurrentRow() {
      currentRow -= 1;

      for (let i = 0; i < parseInt(nSequence.value); i++) {

        currentBoardCells[i] = 'board' + i + (10 - currentRow);
        currentPegCells[i] = 'peg' + i + (10 - currentRow);

      }
      
    }

    function updatePegs(){
      var cells = []
      for(var c = 0; c < parseInt(nSequence.value); c++){
        cells[c] = $("#"+currentBoardCells[c]);
        cellColor[c] = colors[cellColor[c].css("background-color")];
      }


      cell1Color = colors[cell1.css("background-color")];
      cell2Color = colors[cell2.css("background-color")];
      cell3Color = colors[cell3.css("background-color")];
      cell4Color = colors[cell4.css("background-color")];

      let peg1 = $("#"+currentPegCells[0]);
      let peg2 = $("#"+currentPegCells[1]);
      let peg3 = $("#"+currentPegCells[2]);
      let peg4 = $("#"+currentPegCells[3]);
    }

  });
});
