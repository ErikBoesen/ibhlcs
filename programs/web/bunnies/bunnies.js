let canvas = document.getElementById('canv');
const RES = 32;
const SIZE = 20;
const MAX_GRASS_GROWTH = 10;
const GRASS_GROWTH_SPEED = 50;
const STARTING_BUNNY_COUNT = 20;
const BUNNY_PADDING = 3;
const REPRODUCTION_COOLDOWN = 10;
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
        time_since_reproduction: REPRODUCTION_COOLDOWN,
        x: random(),
        y: random(),
    });
}
let wolves = [];

function tick() {
    for (square = 0; square < GRASS_GROWTH_SPEED; square++) {
        restore_x = random();
        restore_y = random();
        if (grass[restore_y][restore_x] < MAX_GRASS_GROWTH) grass[restore_y][restore_x] += 1
    }
    var starting_bunny_count = bunnies.length;
    console.log(starting_bunny_count);
    if (starting_bunny_count < RES * RES) {
        for (bunny = 0; bunny < starting_bunny_count; bunny++) {
            for (partner = 0; partner < starting_bunny_count; partner++) {
                // If two bunnies are in the same place, reproduce.
                if (bunny != partner
                        && bunnies[bunny].x == bunnies[partner].x
                        && bunnies[bunny].y == bunnies[partner].y
                        && bunnies[bunny].time_since_reproduction >= REPRODUCTION_COOLDOWN
                        && bunnies[partner].time_since_reproduction >= REPRODUCTION_COOLDOWN) {
                    // Duplicate bunny and add to array
                    console.log('Duplicating bunny');
                    bunnies[bunny].time_since_reproduction = 0;
                    bunnies[partner].time_since_reproduction = 0;
                    bunnies.push({
                        time_since_reproduction: 0,
                        x: bunnies[bunny].x,
                        y: bunnies[bunny].y,
                    });
                }
            }
        }
    }
    for (bunny of bunnies) {
        bunny.time_since_reproduction += 1;
        if (grass[bunny.y][bunny.x] > 0) grass[bunny.y][bunny.x] -= 1;
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
let main_loop = setInterval(loop, 100);
