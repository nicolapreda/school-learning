//create the random color code

let possibleColors = ["blue", "green", "red", "yellow", "orange", "pink"];


let colors = {
    "rgb(0, 128, 0)": "green",
    "rgb(255, 255, 0)": "yellow",
    "rgb(255, 0, 0)": "red",
    "rgb(0, 0, 255)": "blue",
    "rgb(255, 192, 203)": "pink",
    "rgb(255, 165, 0)": "orange"
}

let hasWon = false;

let code = [
  possibleColors[Math.floor(Math.random() * 6)],
  possibleColors[Math.floor(Math.random() * 6)],
  possibleColors[Math.floor(Math.random() * 6)],
  possibleColors[Math.floor(Math.random() * 6)],
];

console.log(code);