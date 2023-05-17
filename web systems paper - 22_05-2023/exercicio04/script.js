// putting life into the code

function verificarAnoBissexto() {
  var ano = document.getElementById("ano").value;

  if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
    document.getElementById("resultado").innerHTML = ano + " é um ano bissexto.";
  } else {
    document.getElementById("resultado").innerHTML = ano + " não é um ano bissexto.";
  }
}