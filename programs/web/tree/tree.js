var canvas = document.getElementById('canv');
canvas.height = window.innerHeight;
canvas.width  = window.innerWidth;
var ctx = canvas.getContext('2d');

function drawBranch(length, startX, startY) {
    /*
     * @param angle: angle from top left in radians
     */
    ctx.moveTo(startX, startY);
    ctx.lineTo(startX + length, startY);
}

drawBranch(100, 0, 200);
