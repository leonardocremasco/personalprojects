// Fazendo tudo funcionar por JS

function validateForm(event) {
    event.preventDefault(); // Prevent form submission

    // Definindo constantes de usuário e senha
    const USERNAME = "github.com/leonardocremasco";
    const PASSWORD = "clerivaldotop";

    // Obtendo os valores digitados pelo usuário
    const enteredUsername = document.getElementById("username").value;
    const enteredPassword = document.getElementById("password").value;

    // Verificando se o nome de usuário e senha estão corretos
    if (enteredUsername === USERNAME && enteredPassword === PASSWORD) {
      document.getElementById("loginMessage").textContent = "Acesso permitido!";
    } else {
      document.getElementById("loginMessage").textContent = "Acesso negado!";
    }
}