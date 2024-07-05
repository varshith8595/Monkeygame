let currMonPos,currBombPos;
window.onload = function(){
    setBoard();
}
let score = 0;
let gameOver = false;
function setBoard(){
for(let i=0;i<9;i++){
    let tile = document.createElement("div");
    tile.id = i.toString();
    tile.addEventListener("click",checkTile);
    document.getElementById("board").appendChild(tile);
}
setInterval(setMonkey,1000);
setInterval(setBomb,1000);
}
function setMonkey(){
    if(gameOver){
        return;
    }
    if(currMonPos){
        currMonPos.innerHTML="";
    }
    let mon = document.createElement("img");
    mon.src="monkey.png";
    let num = Math.floor(Math.random()*9);
    let n = num.toString();
    if(currBombPos && currBombPos.id == n){
        return;
    }
    currMonPos = document.getElementById(n);
    currMonPos.appendChild(mon);
}
function setBomb(){
    if(gameOver){
        return;
    }
    if(currBombPos){
        currBombPos.innerHTML="";
    }
    let bomb = document.createElement("img");
    bomb.src="bomb.png";
    let num = Math.floor(Math.random()*9);
    let n = num.toString();
    if(currMonPos && currMonPos.id == n){
        return;
    }
    currBombPos = document.getElementById(n);
    currBombPos.appendChild(bomb);
}
function checkTile(){
    if(gameOver){
        return;
    }
    if(this==currMonPos){
        score += 10;
        document.getElementById("score").innerText = score.toString();
    }
    else if(this==currBombPos){
        document.getElementById("score").innerText = "Game over  "+score.toString();
        gameOver = true;
        return;
    }
}