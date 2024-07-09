const express = require('express');
const { exec } = require('child_process');
const path = require('path');
const app = express();
const port = 3000;

app.use(express.static(path.join(__dirname)));
app.use(express.json());

app.post('/check_password', (req, res) => {
    const password = req.body.password;
    exec(`./backend/password_checker "${password}"`, (error, stdout, stderr) => {
        if (error) {
            console.error(`Execution error: ${error.message}`);
            return res.status(500).send(`Error executing password checker: ${error.message}`);
        }
        if (stderr) {
            console.error(`Standard error: ${stderr}`);
            return res.status(500).send(`Error: ${stderr}`);
        }
        console.log(`Output: ${stdout}`);
        res.send(stdout);
    });
});

app.listen(port, () => {
    console.log(`Server is running at http://localhost:${port}`);
});
