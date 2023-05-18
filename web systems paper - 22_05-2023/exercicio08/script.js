// SCRIPT: relogio digital

function updateClock() {
    var now = new Date();
    var hours = now.getHours();
    var minutes = now.getMinutes();
    var seconds = now.getSeconds();
  
    document.getElementById('hours').textContent = addZeroPadding(hours);
    document.getElementById('minutes').textContent = addZeroPadding(minutes);
    document.getElementById('seconds').textContent = addZeroPadding(seconds);
}
  
function addZeroPadding(number) {
    if (number < 10) {
      return '0' + number;
    }
    return number;
}
  
setInterval(updateClock, 1000);
  