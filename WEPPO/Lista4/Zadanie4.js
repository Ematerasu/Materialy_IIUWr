process.stdout.write("Podaj swoje imie: ");

process.stdin.on('data', function(data) {
    process.stdout.write("Witaj " + data);
    process.exit();
});