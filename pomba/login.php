<?php

session_start();

$erro = null;

if (isset($_SESSION['usuario']))
{
	header('Location: index.php');
}
else
{
	if (isset($_POST['usuario']))
	{
		$usuario = $_POST['usuario'];
		$senha = $_POST['senha'];

		if ((($usuario == 'amanda') ||
			($usuario == 'karine') ||
			($usuario == 'andre'))
			&&
			($senha == '123'))
		{
			$_SESSION['usuario'] = $usuario;

			header('Location: index.php');
		}
		else
		{
			$erro = "Usuario não cadastrado";
		}
	}
}

?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Pomba: Login</title>
	</head>
	<body>
		<h1>Pomba</h1>
		<p><?= $erro ?></p>
		<form action="login.php" method="post">
			<p>
			<label for="iusuario">Usuário</label>
			<input id="iusuario" name="usuario"
				type="text">
			</p>
			<p>
			<label for="isenha">Senha</label>
			<input id="isenha" name="senha"
				type="password">
			</p>
			<p>
			<button type="submit">Entrar</button>
		</form>
	</body>
</html>