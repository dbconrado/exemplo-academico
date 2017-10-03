<?php

session_start();

if (!isset($_SESSION['usuario']))
{
   header('Location: login.php');
}

$usuario = $_SESSION['usuario'];

if (isset($_GET['username']))
{

   $username = $_GET['username'];

   /* pegar os dados do usuario */
   $conexao = mysqli_connect("localhost", "root", "root", "dbpomba");
   mysqli_set_charset($conexao, "utf8");

   $sql = "SELECT nome, foto FROM pomber WHERE username='$username'";
   $resultado = mysqli_query($conexao, $sql);

   $dados = mysqli_fetch_assoc($resultado);

   $nome_usuario = $dados['nome'];
   $foto_perfil = $dados['foto'];

   /* pegar quantas pessoas ela segue */
   $sql = "SELECT COUNT(*) AS qtde FROM seguidor WHERE seguidor='$username'";
   $resultado = mysqli_query($conexao, $sql);
   $dados = mysqli_fetch_assoc($resultado);
   
   $seguindo = $dados['qtde'];

   /* pegar quantas pessoas a seguem */
   $sql = "SELECT COUNT(*) AS qtde FROM seguidor WHERE seguido='$username'";
   $resultado = mysqli_query($conexao, $sql);
   $dados = mysqli_fetch_assoc($resultado);

   $seguidores = $dados['qtde'];

   /* saber se o usuario logado ja segue esse perfil */
   $sql = "
      SELECT * FROM seguidor WHERE seguidor='$usuario' AND seguido='$username'";
   $resultado = mysqli_query($conexao, $sql);

   $ja_segue = mysqli_num_rows($resultado) > 0;
   
   /* pegar o feed do perfil */
   $sql = "SELECT texto, data_hora FROM pomba WHERE username='$username'";
   $resultado = mysqli_query($conexao, $sql);

   $prus = Array();

   while ($linha = mysqli_fetch_assoc($resultado))
   {
      $prus[] = $linha;
   }

   define("TITULO_PAGINA", "$username : Perfil");

   mysqli_close($conexao);
}

?>


<?php include('cabecalho.php'); ?>

<header id="perfil">
   <div class="foto-perfil">
      <img src="imagens/perfis/<?= $foto_perfil ?>"
         alt="Foto do perfil de <?= $nome_usuario ?>"
         width="200" height="200">
   </div>

   <div class="infousuario">
      <h1><?= $nome_usuario ?> (@<?= $username ?>)</h1>

      <p>Seguidores: <?= $seguidores ?></p>
      <p>Seguindo: <?= $seguindo ?></p>
   </div>

   <div class="opcoes">
      <form action="" method="post">
         <?php if ($ja_segue) { ?>
            <button type="submit">Deixar de Seguir</button>
         <?php } else { ?>
            <button type="submit">Seguir</button>
         <?php } ?>
      </form>
   </div>
</header>

<main>
   <section id="feed">

      <?php foreach ($prus as $pru) { ?>

      <article class="pomba">

         <section class="pomba-texto">
         <p>
            <?= $nome_usuario ?> pombou às 

            <?= date('H:i:s', strtotime($pru['data_hora'])) ?>:

         </p>
         <p><?= $pru['texto'] ?></p>
         </section>
      </article>

      <?php } ?>

   </section>
</main>

<?php include('rodape.php'); ?>
