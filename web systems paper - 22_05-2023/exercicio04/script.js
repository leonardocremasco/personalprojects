// script: ano bissexto

function verificarAnoBissexto() {
  var ano = document.getElementById("ano").value;

  if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
    document.getElementById("resultado").innerHTML = ano+ " <strong>é</strong> um ano bissexto.";
  } else {
    document.getElementById("resultado").innerHTML = ano + " <strong>NÃO</strong> é um ano bissexto.";
  }
}