// SCRIPT; diferença em dias

function calcularDiferencaDatas() {
    var data1 = new Date(document.getElementById('data1').value);
    var data2 = new Date(document.getElementById('data2').value);

    // Calcula a diferença em milissegundos entre as datas
    var diff = Math.abs(data2.getTime() - data1.getTime());

    // Converte a diferença de milissegundos para dias
    var diffDias = Math.ceil(diff / (1000 * 3600 * 24));

    // Exibe o resultado
    document.getElementById('resultado').innerHTML = 'A diferença em dias é: ' + diffDias + ' dias';
}