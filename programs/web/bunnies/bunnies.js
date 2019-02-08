let canvas = document.getElementById('canv');
const RES = 32;
const SIZE = 20;
const MAX_GRASS_GROWTH = 10;
const STARTING_BUNNY_COUNT = 4;
const BUNNY_PADDING = 3;
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
function jump() {
    return Math.floor(Math.random() * 3 - 1);
}
function random() {
    return Math.floor(Math.random() * RES);
}
let bunnies = [];
for (count = 0; count < STARTING_BUNNY_COUNT; count++) {
    bunnies.push({
        'x': random(),
        'y': random(),
    });
}
let wolves = [];

function tick() {
    for (bunny of bunnies) {
        grass[bunny.y][bunny.x] -= 1;
        bunny.x += jump();
        bunny.y += jump();
        if (bunny.x < 0) bunny.x = 0;
        else if (bunny.x >= RES) bunny.x = RES - 1;
        if (bunny.y < 0) bunny.y = 0;
        else if (bunny.y >= RES) bunny.y = RES - 1;
    }
}
function draw() {
    for (row = 0; row < RES; row++) {
        for (col = 0; col < RES; col++) {
            ctx.fillStyle = 'rgb(0,' + (255/10 * grass[row][col]) + ',0)';
            ctx.fillRect(col * SIZE, row * SIZE, SIZE, SIZE);
        }
    }
    ctx.fillStyle = '#333';
    for (bunny of bunnies) {
        ctx.fillRect(bunny.x * SIZE + BUNNY_PADDING, bunny.y * SIZE + BUNNY_PADDING, SIZE - 2*BUNNY_PADDING, SIZE - 2*BUNNY_PADDING);
    }
}
function loop() {
    tick();
    draw();
}

loop();
let main_loop = setInterval(loop, 1000);
