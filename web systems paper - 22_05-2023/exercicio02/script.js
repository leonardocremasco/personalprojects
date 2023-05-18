// SCRIPT: ora atual

function exibirHoraAtual() {
    var dataAtual = new Date();
    var hora = dataAtual.getHours();
    var minutos = dataAtual.getMinutes();
    var segundos = dataAtual.getSeconds();

    // Formatação da hora para sempre ter 2 dígitos
    hora = hora < 10 ? "0" + hora : hora;
    minutos = minutos < 10 ? "0" + minutos : minutos;
    segundos = segundos < 10 ? "0" + segundos : segundos;

    var horaFormatada = hora + ":" + minutos + ":" + segundos;

    // Atualiza o conteúdo do parágrafo com a hora atual
    document.getElementById("hora-atual").textContent = horaFormatada;
}

  // Chama a função exibirHoraAtual a cada segundo
    setInterval(exibirHoraAtual, 1000);