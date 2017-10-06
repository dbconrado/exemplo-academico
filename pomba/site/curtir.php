<?php

session_start();

if (!isset($_SESSION['usuario']))
{
   header('Location: login.php');
}

$usuario = $_SESSION['usuario'];

$conexao = mysqli_connect("localhost", "root", "root", "dbpomba");
if (!$conexao)
   die("Não consegui conectar: " . mysqli_connect_error());

mysqli_set_charset($conexao, 'utf8');

$id = $_POST['idpomba'];

$sql = "INSERT INTO curtida (username, id_pomba) VALUES
   ('$usuario', $id)";

mysqli_query($conexao, $sql);
mysqli_close($conexao);

header('Location: index.php');
