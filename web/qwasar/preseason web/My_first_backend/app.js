const express = require('express') ;
const app = express() ; 
const port = 8080 ;
const song = ["TOO ROMANTIC", "SAY IT", "IS THIS THE BEGINNING OF THE END", "APRIL PLAYED THE FIDDLE", "I HAVEN'T TIME TO BE A MILLIOAIRE", "I COULD MAKE YOU CARE", "OUR LOVE AFFAIR", "I'D KNOW YOU ANYWHERE", "NOT SO LONG AGO", "YOU LUCKY PEOPLE YOU", "IT'S ALWAYS YOU", "POOR YOU", "I'LL TAKE TALLULAH", "THE LAST CALL FOR LOVE", "BE CAREFUL IT'S MY HEART", "DOLORES", "I'LL NEVER LET A DAY PASS BY", "HOW ABOUT YOU", "MY WAY", "SOMETHIN' STUPID", "THE WORLD WE KNEW"] ; 
var random = Math.floor(Math.random() * song.length) ;
const wives = ["Nancy Sinatra", "Ava Gardner", "Mia Farrow", "Barbara Sinatra"] ;

const credentials = {
    secretName: 'admin',
    secretPassword: 'admin'
};

function son(){
    var random = Math.floor(Math.random() * song.length) ;
    return song[random] ;
}
app.get('/', (req, res) => {
    res.send(son());
}) ;

app.get('/birth_date', (req, res) => {
    res.send("December 12, 1915");
});

app.get('/birth_city', (req, res) => {
    res.send('Hoboken, New Jersey');
});

app.get('/wives', (req, res) => {
    res.send("Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx");
});

app.get('/picture', (req, res) => {
    res.redirect('https://en.wikipedia.org/wiki/Frank_Sinatra#/media/File:Frank_Sinatra2,_Pal_Joey.jpg');
});

app.get('/public', (req, res) => {
    res.send("Everybody can see this page");
});

app.get('/protected', (req, res) => {
    const authHeader = req.headers['authorization'];
    if (!authHeader) {
        res.set('WWW-Authenticate', 'Basic realm="Access to Index"');
        return res.status(401).send("Not authorized");
    }

    const base64Credentials = authHeader.split(' ')[1];
    const [name, password] = Buffer.from(base64Credentials, 'base64').toString('ascii').split(':');

    if (name === credentials.secretName && password === credentials.secretPassword) {
        return res.status(200).send("Welcome, authenticated client");
    }

    res.set('WWW-Authenticate', 'Basic realm="Access to Index"');
    res.status(401).send("Not authorized");
});

app.listen(port)
