const express = require('express');
const router = express.Router();


let count = 0;

router.get('/', (req, res) => {
    console.log('Solicitud get');
    count++;
    res.json({
        ok: count
    })
})

router.post('/', (req, res) => {
    const { temperatura, humedad } = req.body;

    let date = new Date()
    let min = date.getMinutes();
    let hour = date.getHours();
    let dateNow = `${hour}:${min}`


    console.log("Solicitud post. temperatura:", temperatura, humedad, dateNow)
    res.json({
        ok: 'post',
        date: dateNow
    })
})

module.exports = router;