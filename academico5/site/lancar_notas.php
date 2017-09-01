<?php
/*
 * Este script grava as notas no banco de dados.
 * É importante que, caso a nota já exista,
 * nós devemos atualizá-la ao invés de criar outra, ok?
 */

# agora, eu monto a SQL.

$sql = "REPLACE INTO nota (id_aluno, id_avaliacao, nota) VALUES ";

$primeiro = true;

foreach ($_POST as $ids => $valor)
{
   $vetor = explode('_', $ids);
   $id_aluno = $vetor[1];
   $id_avaliacao = $vetor[2];

   if (!$primeiro)
      $sql .= ", ";
   else
      $primeiro = false;

   $sql .= "($id_aluno, $id_avaliacao, $valor)";
}

echo $sql;

$conexao = mysqli_connect("localhost", "root", "root", "escola2");
if (!$conexao)
   die("Não consegui conectar: " . mysqli_connect_error());

$sucesso = mysqli_query($conexao, $sql);
/*
 *Quando se usa REPLACE, mysqi_query tem um comportamento fora do esperado.
 Ele retorna falso caso já haja notas lançadas ao aluno, mesmo que ele
 faça atualizações. Fazer o quê, né?
 */
if (!$sucesso)
   die("Não consegui cadastrar: " . mysqli_error($conexao));
 */
mysqli_close($conexao);

header("Location: lancar_notas.php");
?>
