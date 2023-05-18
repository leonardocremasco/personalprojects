// SCRIPT: calculando idade com base na data de nascimento

function calcularIdade() {
    var dataNascimento = document.getElementById("dataNascimento").value;
    var dataAtual = new Date();
    var anoNascimento = new Date(dataNascimento).getFullYear();
    var anoAtual = dataAtual.getFullYear();
    var idade = anoAtual - anoNascimento;

    document.getElementById("resultado").innerHTML = "A idade é: " + idade + " anos.";
}