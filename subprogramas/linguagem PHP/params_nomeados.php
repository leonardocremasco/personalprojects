
<?php

// Definindo a função SOMADOR
function SOMADOR($params) {
    $params['soma'] = 0; // Inicializa a soma

    // Itera sobre a lista somando os elementos
    for ($i = 0; $i < $params['comprimento']; $i++) {
        $params['soma'] += $params['lista'][$i];
    }
    
    // Retorna a soma calculada
    return $params['soma'];
}

$meu_comprimento = 5;
$meu_array = [1, 2, 3, 4, 5];
$minha_soma = 0;

// Inicializando o array associativo com os parâmetros
$params = [
    'comprimento' => $meu_comprimento,
    'lista' => $meu_array,
    'soma' => &$minha_soma
];

// Chama a função SOMADOR
$minha_soma = SOMADOR($params);

// Imprime o resultado
echo "A soma dos elementos é: $minha_soma\n";
?>
