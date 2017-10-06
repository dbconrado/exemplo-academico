<?php

session_start();

if (!isset($_SESSION['usuario']))
{
   header('Location: login.php');
}

$usuario = $_SESSION['usuario'];

$pomba = $_POST['pomba'];
$sql = "INSERT INTO pomba (texto, username) VALUES
   ('$pomba', '$usuario')";

$conexao = mysqli_connect("localhost", "root", "root", "dbpomba");
if (!$conexao)
   die("Não consegui conectar: " . mysqli_connect_error());

mysqli_set_charset($conexao, 'utf8');

$resultados = mysqli_query($conexao, $sql);
$mysqli_close($conexao);

header('Location: index.php');

