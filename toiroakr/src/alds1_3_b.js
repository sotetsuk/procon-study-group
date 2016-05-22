function main() {
    var nq = input[0].split(' ').map(Number),
        queue = [], process,
        total;
    input.slice(1, nq[0] + 1).forEach(function (process) {
        process = process.split(' ');
        process[1] = Number(process[1]);
        queue.push(process);
    });

    total = 0;
    while (queue.length !== 0) {
        process = queue.shift();
        if (process[1] > nq[1]) {
            process[1] -= nq[1];
            total += nq[1];
            queue.push(process);
        } else {
            total += process[1];
            console.log(process[0] + ' ' + total);
        }
    }
}

var input = '';

process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function (chunk) {
    input += chunk;
});
process.stdin.on('end', function () {
    input = input.split('\n');
    main();
});
