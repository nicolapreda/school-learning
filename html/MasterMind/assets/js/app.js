$(document).ready(function () {
  
  let checkBoxSequence = document.getElementById("nSequence")
  checkBoxSequence.addEventListener("change", function () {
    let nSequence = parseInt(this.value)
    console.log(nSequence)
  });

  let checkBoxNColors = document.getElementById('nColors')
  checkBoxNColors.addEventListener("change", function () {
    let nColors = parseInt(this.value)
    console.log(nColors)
  });
  
  function CheckRepeatedColors() {
    // Get the checkbox
    var isRepeatedColors = document.getElementById("RepeatedColors");

    if (isRepeatedColors.checked == true) {
    } else {
    }
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

  let code = [
    possibleColors[Math.floor(Math.random() * 6)],
    possibleColors[Math.floor(Math.random() * 6)],
    possibleColors[Math.floor(Math.random() * 6)],
    possibleColors[Math.floor(Math.random() * 6)],
  ];

  let startBtn = document.getElementById("start");

  
});
