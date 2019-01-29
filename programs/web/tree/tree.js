var canvas = document.getElementById('canv');
canvas.height = window.innerHeight;
canvas.width  = window.innerWidth;
var ctx = canvas.getContext('2d');

var options = {
    sideLengthMultiplier: .75,
    middleLengthMultiplier: .5,
};

ctx.strokeStyle = 'white';
function random() {
    return 0.2;
    return Math.random() / 8;
}
var height = window.innerHeight;
function drawBranch(iterations, length, startX, startY, angle) {
    if (iterations == 0) return;
    ctx.moveTo(startX, height - startY);
    var endX = startX + Math.cos(angle) * length;
    var endY = startY + Math.sin(angle) * length;
    ctx.lineTo(endX, height - endY);
    drawBranch(iterations - 1, length * options.sideLengthMultiplier, endX, endY, angle - Math.PI / 4 + random());
    drawBranch(iterations - 1, length * options.middleLengthMultiplier, endX, endY, angle + 0 + random());
    drawBranch(iterations - 1, length * options.sideLengthMultiplier, endX, endY, angle + Math.PI / 4 + random());
}

function startTree() {
    ctx.beginPath();
    drawBranch(8, 100, 500, 0, Math.PI / 2);
    ctx.stroke();
}

startTree();
document.setInterval(100, startTree());

