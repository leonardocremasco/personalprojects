
// Função para atualizar o relógio
function updateClock() {
    var now = new Date();
    var hours = now.getHours();
    var minutes = now.getMinutes();
    var seconds = now.getSeconds();

    var hourHand = document.querySelector('.hour-hand');
    var minuteHand = document.querySelector('.minute-hand');
    var secondHand = document.querySelector('.second-hand');

    // Cálculo dos ângulos para cada ponteiro
    var hourAngle = (hours % 12) * 30 + (minutes / 2);
    var minuteAngle = minutes * 6 + (seconds / 10);
    var secondAngle = seconds * 6;

    // Aplicando os ângulos aos ponteiros
    hourHand.style.transform = `rotate(${hourAngle}deg)`;
    minuteHand.style.transform = `rotate(${minuteAngle}deg)`;
    secondHand.style.transform = `rotate(${secondAngle}deg)`;
}

  // Chama a função updateClock a cada segundo (1000 milissegundos)
    setInterval(updateClock, 1000);