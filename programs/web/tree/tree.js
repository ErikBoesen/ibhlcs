var canvas = document.getElementById('canv');
canvas.height = window.innerHeight;
canvas.width  = window.innerWidth;
var ctx = canvas.getContext('2d');

var options = {
    sideLengthMultiplier: {
        default: .75,
        min: 0,
        max: 1,
    },
    middleLengthMultiplier: {
        default: .5,
        min: 0,
        max: 0,
    },
};

const CONTROLS = document.getElementById('controls');

for (option in options) {
    slider = document.createElement('input');
    options[option].readout = document.createElement('label');
    slider.type = 'range';
    slider.min = options[option].min;
    slider.max = options[option].max;
    slider.value = options[option].default;
    slider.id = option;
    slider.step = 0.05;
    options[option].slider = slider;
    CONTROLS.appendChild(slider);
}

ctx.strokeStyle = 'white';
function random() {
    return Math.random() / 8;
}
var height = window.innerHeight;
function drawBranch(iterations, length, startX, startY, angle) {
    ctx.moveTo(startX, height - startY);
    var endX = startX + Math.cos(angle) * length;
    var endY = startY + Math.sin(angle) * length;
    ctx.lineTo(endX, height - endY);
    if (iterations > 0) {
        drawBranch(iterations - 1, length * options.sideLengthMultiplier.value, endX, endY, angle - Math.PI / 4 + random());
        drawBranch(iterations - 1, length * options.middleLengthMultiplier.value, endX, endY, angle + 0 + random());
        drawBranch(iterations - 1, length * options.sideLengthMultiplier.value, endX, endY, angle + Math.PI / 4 + random());
    }
}

function startTree() {
    ctx.beginPath();
    drawBranch(8, 100, window.innerWidth / 2, 0, Math.PI / 2);
    ctx.stroke();
}

setInterval(100, startTree());

oninput = function(e) {
    console.log(e.target);
    options[e.target.id].value = e.target.value;
}
