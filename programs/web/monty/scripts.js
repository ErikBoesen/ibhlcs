const NUM_DOORS = 3,
      OPEN = true,
      CLOSED = false;


function doorRow(status, count) {
    var arr = [];
    for (var i = 0; i < count; i++) arr.push(status);
    return arr;
}


function Hall() {
    this.random_door = function() {
        return Math.random() * NUM_DOORS;
    };
    this.choose_random = function() {
        this.guess = this.random_door();
    }
    this.open_zonk = function() {
        for (door = 0; door < NUM_DOORS; door++) {
            if (door != this.guess && door != this.car_position) {
                this.statuses[door] = OPEN;
                break;
            }
        }
    }
    this.is_swap_correct = function() {
        return this.car_position != this.guess;
    }
    this.car_position = this.random_door()
    this.statuses = Array(NUM_DOORS).fill(CLOSED);
}


let successes = 0, tries = 0;

while (true) {
    let hall = new Hall();
    hall.choose_random();
    hall.open_zonk();
    if (hall.is_swap_correct()) {
        successes += 1;
    }
    tries += 1;
    console.log(successes, tries, 100 * successes / tries);
}
