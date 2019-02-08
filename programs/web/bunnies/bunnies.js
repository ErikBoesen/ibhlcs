let canvas = document.getElementById('canv');
const RES = 32;
const SIZE = 20;
const MAX_GRASS_GROWTH = 10;
canvas.height = RES * SIZE;
canvas.width  = RES * SIZE;
let ctx = canvas.getContext('2d');

console.log('Started run.');

let grass = [];
for (row = 0; row < RES; row++) {
    grass.push([]);
    for (col = 0; col < RES; col++) {
        grass[row].push(MAX_GRASS_GROWTH);
    }
}
console.log(grass);
let bunnies = [];
let wolves = [];

function tick() {

}
function draw() {
    for (row = 0; row < RES; row++) {
        for (col = 0; col < RES; col++) {
            ctx.fillStyle = 'rgb(0,' + (255/10 * grass[row][col]) + ',0)';
            ctx.fillRect(col * SIZE, row * SIZE, SIZE, SIZE);
        }
    }
}
function loop() {
    tick();
    draw();
}

let main_loop = setInterval(loop, 100);
