<?php

/*
 * Este script cadastra um aluno no banco de dados.
 * Ele espera receber via POST um parâmetro chamado "nome"
 * contendo o nome do aluno a ser cadastrado.
 */
if (!$_POST['nome'])
   die("Parâmetro não informado");

# conectando ao banco de dados
$conexao = mysqli_connect("localhost", "root", "root", "escola");

if (!$conexao)
   die("Não consegui conectar: " . mysqli_connect_error());

# montando a sql
$nome = $_POST['nome'];
$sql = "INSERT INTO aluno (nome) VALUES ('${nome}')";

# executando a sql
$sucesso = mysqli_query($conexao, $sql);

if (!$sucesso)
   die("Nao consegui inserir no banco de dados: " . mysqli_error());

# redireciono para a página alunos.php
header("Location: alunos.php");

# fim
?>
