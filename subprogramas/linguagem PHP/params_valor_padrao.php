
<?php

// Função original com todos os parâmetros
function printValues($a, $b = 10) {
    echo "a = $a, b = $b\n";
}

// Chamadas da função
printValues(5); // $b usará o valor padrão de 10
printValues(5, 20); // $b usará o valor passado de 20

?>
