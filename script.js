document.getElementById('passwordForm').addEventListener('submit', function(event) {
    event.preventDefault();
    let password = document.getElementById('password').value;

    let xhr = new XMLHttpRequest();
    xhr.open('POST', '/check_password', true);
    xhr.setRequestHeader('Content-Type', 'application/json;charset=UTF-8');

    xhr.onload = function() {
        if (xhr.status === 200) {
            let response = JSON.parse(xhr.responseText);
            displayStrengthResult(response);
        } else {
            alert('Error checking password strength');
        }
    };

    xhr.send(JSON.stringify({ password: password }));
});

function displayStrengthResult(result) {
    let resultDiv = document.getElementById('strengthResult');
    resultDiv.innerHTML = `<h2>Password Strength: ${result.strength}</h2>
                           <p>Feedback: ${result.feedback}</p>`;
}
