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

$busca = $_GET['busca'];
$sql = "SELECT username, nome, foto FROM pomber
   WHERE nome LIKE '%$busca%' OR username LIKE '%$busca%'";

$resultados = mysqli_query($conexao, $sql);

$qtde = mysqli_num_rows($resultados);

$usuarios = Array();

while ($linha = mysqli_fetch_assoc($resultados))
{
   $usuarios[] = $linha;
}

mysqli_close($conexao);
?>

<?php include('cabecalho.php'); ?>

<main>
   <h2>Resultado da pesquisa</h2>

   <p>O termo '<?= $busca ?>' retornou <?= $qtde ?> resultados.</p>

   <?php foreach ($usuarios as $usu) { ?>

   <div>
      <a href="perfil.php?username=<?= $usu['username'] ?>">
         <img src="imagens/perfis/<?= $usu['foto'] ?>">
         <p>
            <?= $usu['nome'] ?> (@<?= $usu['username'] ?>)
         </p>
      </a>
   </div>

   <?php } ?>
</main>

<?php include('rodape.php'); ?>
