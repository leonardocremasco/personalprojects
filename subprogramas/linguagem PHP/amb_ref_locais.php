
<?php

function somador($array) {
    static $soma = 0; // --> aqui é onde a variável se torna ESTÁTICA
    $var_a = 0; // --> variável definida por padrão como dinâmica (em PHP todas as variáveis são dinâmicas por padrão)
    
    foreach ($array as $value) {
        $soma += $value;
    }
    
    return $soma;
}

// Exemplo de uso
$array = [1, 2, 3, 4, 5];
$soma_total = somador($array);
echo "A soma dos elementos é: $soma_total\n";
?>
