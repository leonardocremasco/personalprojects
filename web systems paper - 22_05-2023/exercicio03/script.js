// SCRIPT: adicionar minutos a uma data

function adicionarMinutos() {
    var dataInput = document.getElementById("data").value;
    var minutosInput = parseInt(document.getElementById("minutos").value);

    var data = new Date(dataInput);
    data.setMinutes(data.getMinutes() + minutosInput);

    document.getElementById("resultado").innerHTML = "<strong>Nova data</strong>: " + data;
  }