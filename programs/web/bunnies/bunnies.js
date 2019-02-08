var canvas = document.getElementById('canv');
const RES = 32;
const SIZE = 20;
const MAX_GRASS_GROWTH = 10;
canvas.height = RES * SIZE;
canvas.width  = RES * SIZE;
var ctx = canvas.getContext('2d');

var grass = [];
for (row = 0; row < RES; row++) {
    grass.push([]);
    for (col = 0; col < RES; col++) {
        grass[row].push(MAX_GRASS_GROWTH);
    }
}

function loop() {
    tick();
    draw();
}
