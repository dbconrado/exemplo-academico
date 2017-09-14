<?php

session_start();

if (!isset($_SESSION['usuario']))
{
	header('Location: login.php');
}

?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Pomba</title>
	</head>
	<body>
		<h1>Pomba</h1>
		<p>Bem-vindo, <?= $_SESSION['usuario']?>
		vezes!</p>
		<p>
			<a href="logout.php">Sair</a>
		</p>
	</body>
</html>