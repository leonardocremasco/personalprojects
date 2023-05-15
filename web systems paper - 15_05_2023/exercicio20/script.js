// putting life into code

function estacao() {
    let entrada = prompt('Digite o mês em extenso ou o número do mês');
  
    let mes;
    if (isNaN(entrada)) {
      mes = entrada.toUpperCase();
    } else {
      const meses = [
        'JANEIRO', 'FEVEREIRO', 'MARÇO', 'ABRIL', 'MAIO', 'JUNHO',
        'JULHO', 'AGOSTO', 'SETEMBRO', 'OUTUBRO', 'NOVEMBRO', 'DEZEMBRO'
      ];
  
      const numeroMes = parseInt(entrada, 10);
      if (numeroMes >= 1 && numeroMes <= 12) {
        mes = meses[numeroMes - 1];
      } else {
        mes = 'INVALIDO';
      }
    }
  
    let saida = document.querySelector('section#saida');
    let estacao;
  
    switch (mes) {
      case 'JANEIRO':
      case 'FEVEREIRO':
      case 'MARÇO':
        estacao = 'INVERNO';
        break;

      case 'ABRIL':
      case 'MAIO':
      case 'JUNHO':
        estacao = 'PRIMAVERA';
        break;

      case 'JULHO':
      case 'AGOSTO':
      case 'SETEMBRO':
        estacao = 'VERÃO';
        break;

      case 'OUTUBRO':
      case 'NOVEMBRO':
      case 'DEZEMBRO':
        estacao = 'OUTONO';
        break;
        
      default:
        estacao = 'INDEFINIDA';
        break;
    }
  
    if (estacao !== 'INVALIDO') {
      saida.innerHTML = `<p>No mês de <mark>${mes}</mark>, estamos na estação <mark><strong>${estacao}</strong></mark>.</p>`;
    } else {
      saida.innerHTML = `<p>Entrada inválida. Por favor, digite o mês em extenso ou o número do mês corretamente.</p>`;
    }
}
  
   