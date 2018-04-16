<?php

/*
 * Este script cadastra uma nova avaliação no banco de dados.
 * Recebe os parâmetros via POST.
 * Depois, ele redireciona para a página que mostra as avaliações
 */

$conexao = mysqli_connect("localhost", "root", "root", "escola2");
if (!$conexao)
   die("Não consegui conectar: " . mysqli_connect_error());

if (!isset($_POST['descricao']) || !isset($_POST['valor']))
   die("Parâmetros incorretos");

$descricao = $_POST['descricao'];
$valor = $_POST['valor'];

$sql = "INSERT INTO avaliacao (descricao, valor) VALUES
         ('${descricao}',${valor})";

$sucesso = mysqli_query($conexao, $sql);
if (!$sucesso)
   die("Não consegui cadastrar: " . mysqli_error($conexao));

header("Location: avaliacoes.php");
?>
