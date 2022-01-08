$(document).ready(function () {

    //Set the colors
    var currentColor = "white";
    var colors = ["blue", "green", "red", "yellow", "orange", "pink", "white", "black", "brown", "lightgreen"]

    var currentBoardNumber = 3;

    var typeMode = document.getElementById("modeType");
    var checkBoxSequence = document.getElementById("nSequence");
  checkBoxSequence.addEventListener("change", function () {
    var nSequence = parseInt(this.value);
    console.log(nSequence);

  });

  var checkBoxNColors = document.getElementById("nColors");
  checkBoxNColors.addEventListener("change", function () {
    var nColors = parseInt(this.value);
    console.log(nColors);
  });

  // Get the checkbox
  var isRepeatedColors = document.getElementById("RepeatedColors");

  if (isRepeatedColors.checked == true) {
    repeatedColors = true;
  } else {
    repeatedColors = false;
  }



  //Define start button
  var startBtn = document.getElementById("start");
  //When start button is clicked
  $(startBtn).click(function () {
    var hasWon = false;


    //Disable options
    checkBoxSequence.setAttribute("disabled", "");
    checkBoxNColors.setAttribute("disabled", "");
    isRepeatedColors.setAttribute("disabled", "");
    startBtn.setAttribute("disabled", "");
    typeMode.setAttribute("disabled", "");
    colors.slice(0, -nColors)
    console.log(colors)




    //Create color backgrounds
    for (var c = 0; c < parseInt(nColors.value); c++) {
      if (c < 5) {
        document.getElementById('colorsContent1').insertAdjacentHTML('beforeend', '<div class="square square-lg m-2"><button class="w-h-100 color" style="background-color:' + colors[c] + '" id="' + colors[c] + '"></div>');
      }
      else {
        document.getElementById('colorsContent2').insertAdjacentHTML('beforeend', '<div class="square square-lg m-2"><button class="w-h-100 color" style="background-color:' + colors[c] + '" id="' + colors[c] + '"></div>');
      }
    };


    var currentBoardCells = [];
    var currentRow = 10;
    var cellColor = [];


    //Insert boards into the interface
    var boardId = 0
    for (var i = 1; i <= 10; i++) {
      for (var s = 0; s < parseInt(nSequence.value); s++) {
        //
        document.getElementById('slot' + i).insertAdjacentHTML('beforeend', '<div class="square square-lg m-2"><button class="w-h-100 socket" id="board' + boardId +  '"></div>');
      boardId++
    }

      //document.getElementById('slot' + i).insertAdjacentHTML('afterbegin', '<div class="roundresult">');
      
      /*for (var s = 0; s < parseInt(nSequence.value); s++) {
        if (s % 2 == 0) {
          //Insert boards results
          document.getElementById('slot' + i).insertAdjacentHTML('beforeend', '<div class="d-flex"><div class="square square-lg mr-1"><button class="w-h-100 socketresult" disabled></div>');

        } 
        else {
          document.getElementById('slot' + i).insertAdjacentHTML('beforeend', '<div class="square square-lg mr-1"><button class="w-h-100 socketresult" disabled></div></div>');

        }

      }*/

    }



    //Set sequence code
    var code = [];
    for (let i = 0; i < parseInt(nSequence.value); i++) {
      code[i] = colors[Math.floor(Math.random() * parseInt(nSequence.value))];
      currentBoardCells[i] = 'board' + i;

    }
    console.log(code);


    //change the current color when the user clicks on the color board
    $(".color").click(function () {
      let color = $(this).attr("id");
      currentColor = color;
      $(".currentColor").css("background-color", color);
    });

    // change the color of a board cell on click
    $(".socket").click(function () {
      var id = $(this).attr("id");
      if(isValid(id)){
        $(this).css("background-color", currentColor);
      }
    });

    // do actions when the submit button is clicked
    $(".submit").click(function () {
      
      for(var i = 0; i < parseInt(nSequence.value); i++){
        
        cellColor[i] = document.getElementById(currentBoardCells[i]).style.backgroundColor;
      }
      console.log(cellColor);

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
      return hasWon; 
    }
      
  

    function changeCurrentRow() {
      currentRow -= 1;
      
      for (let i = 0; i < parseInt(nSequence.value); i++) {
        currentBoardCells[i] = 'board' + currentBoardNumber;
        currentBoardNumber++;
      }
      
    }

    function updatePegs(){
      var cells = []
      for(var c = 0; c <= parseInt(nSequence.value); c++){
        cells[c] = $("#"+currentBoardCells[c]);
        cellColor[c] = colors[cellColor[c].css("background-color")];
      }

    }

  });
});
