const express = require("express");
const bodyParser = require('body-parser');
const app = express();
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());


let contador = 0;

let respuesta = {
    estado: "ok",
    //numero: contador
};

app.get('/', function(req, res) {
    contador += 1;
    res.send(respuesta);
});
app.listen(3000, () => {
    console.log("El servidor está inicializado en el puerto 3000");
});