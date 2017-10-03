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

$sql = "
SELECT se.seguido, po.texto, po.data_hora, pr.foto
FROM pomba po
INNER JOIN seguidor se ON (po.username = se.seguido)
INNER JOIN pomber pr ON (po.username = pr.username)
WHERE se.seguidor = '${usuario}';
";

$resultados = mysqli_query($conexao, $sql);
if (!$resultados)
   die("Não consegui selecionar: " . mysqli_error());

$prus = Array();

while ($linha = mysqli_fetch_assoc($resultados))
{
   $prus[] = $linha;
}

$sql = "
SELECT nome, foto FROM pomber WHERE username='${usuario}'
";

$resultados = mysqli_query($conexao, $sql);
$linha = mysqli_fetch_assoc($resultados);

$foto_perfil = $linha['foto'];
$nome_usuario = $linha['nome'];

define("TITULO_PAGINA", "$usuario : Página Inicial");

?>



<?php include('cabecalho.php'); ?>

      <main>
         <header id="perfil">
            <div class="foto-perfil">
               <img src="imagens/perfis/<?= $foto_perfil ?>"
                  alt="Foto do perfil de <?= $usuario ?>"
                  width="200" height="200">
            </div>

            <h1><?= $nome_usuario ?></h1>

            <form id="nova-pomba" action="postar.php" method="post">
               <textarea autofocus maxlength="141" name="pomba"
                 placeholder="O que está acontecendo?"
                 rows="3" cols="50" required></textarea>
               
               <div id="botao-pombar">
                  <button type="submit">Pombar</button>
               </div>
            </form>
         </header>
         
         <section id="feed">

            <?php foreach ($prus as $pru) { ?>

            <article class="pomba">
               <div class="foto-seguindo">
               <a href="perfil.php?username=<?= $pru['seguido'] ?>">
                  <img src="imagens/perfis/<?= $pru['foto']?>"
                     alt="Foto de <?= $pru['seguido']?>" width="48" height="48">
               </a>
               </div>

               <section class="pomba-texto">
               <p>
                  <a href="perfil.php?username=<?= $pru['seguido'] ?>">
                     <?= $pru['seguido'] ?></a>

                  pombou às 

                  <?= date('H:i:s', strtotime($pru['data_hora'])) ?>:

               </p>
               <p><?= $pru['texto'] ?></p>
               </section>
            </article>

            <?php } ?>
         
         </section>

      </main>

<?php include('rodape.php'); ?>

