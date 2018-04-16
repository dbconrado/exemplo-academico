<!DOCTYPE html>
<html>
   <head>
      <meta charset="utf-8">
      <title>Acadêmico : Lançar Notas</title>
   </head>
   <body>

<?php
$conexao = mysqli_connect("localhost", "root", "root", "escola2");
if (!$conexao)
   die("Não consegui conectar: " . mysqli_connect_error());

/* Pego todos os alunos e coloco em um vetor */

$sql = "SELECT id, nome FROM aluno";
$res = mysqli_query($conexao, $sql);
if (!$res)
   die("Não consegui fazer consulta: " . mysqli_error($conexao));

$alunos = array();
while ($a = mysqli_fetch_assoc($res))
{
   $id_aluno = $a['id'];
   $alunos["$id_aluno"] = $a;
}

/* agora, pego todas as avaliações e as coloco em outro vetor */

$sql = "SELECT id,descricao,valor FROM avaliacao";
$res = mysqli_query($conexao, $sql);
if (!$res)
   die("Não consegui fazer consulta: " . mysqli_error($conexao));

$avaliacoes = array();
while ($a = mysqli_fetch_assoc($res))
{
   $id_avaliacao = $a['id'];
   $avaliacoes["$id_avaliacao"] = $a;
}

/* monto uma matriz para guardar as notas das avaliações
 * obtidas pelos alunos. Inicialmente as notas serão zero.
 * Depois, vou fazer outra consulta no banco de dados
 * para ver as verdadeiras notas dos alunos, se houver.
 */

$matriz = array();
foreach ($alunos as $al)
{
   $id_aluno = $al['id'];
   $matriz["$id_aluno"] = array();
   
   foreach ($avaliacoes as $av)
   {
      $id_avaliacao = $av['id'];
      $matriz["$id_aluno"]["$id_avaliacao"] = 0;
   }
}

/* agora sim, consulto o banco de dados para ver as notas verdadeiras */

$sql = "SELECT id_aluno, id_avaliacao, nota FROM nota";
$res = mysqli_query($conexao, $sql);
if (!$res)
   die("Não consegui fazer consulta: " . mysqli_error($conexao));

while ($linha = mysqli_fetch_assoc($res))
{
   $id_aluno = $linha['id_aluno'];
   $id_avaliacao = $linha['id_avaliacao'];
   $matriz["$id_aluno"]["$id_avaliacao"] = $linha['nota'];
}

/* Com a matriz pronta, basta montar a tabela */
?>

      <h1>Lançar Notas</h1>

      <form action="lancar_notas.php" method="post">

         <table border="1">

            <thead>
               <tr>
                  <th>Nome do Aluno</th>

<?php             foreach ($avaliacoes as $av)
                  {  ?>
                     <th><?= $av['descricao'] ?></th>
<?php             }  ?>

               </tr>
            </thead>
            <tbody>

<?php       foreach ($matriz as $id_aluno => $ids_avaliacoes)
            { ?>

               <tr>
                  <td><?= $alunos["$id_aluno"]['nome'] ?></td>

<?php             foreach ($ids_avaliacoes as $id_avaliacao => $nota)
                  { ?>
                     
                     <td>
                        <input type="number" step="0.1" min="0"
                        max="<?= $avaliacoes["$id_avaliacao"]['valor'] ?>"
                        value="<?= $nota ?>"
                        name="nota_<?=$id_aluno?>_<?=$id_avaliacao?>">
                     </td>

<?php             } // fim do foreach de avaliações ?> 
                  
               </tr>

<?php      } // fim do foreach de alunos ?>


            </tbody>
         </table>

         <div>
            <button type="submit">Salvar Notas</button>

      </form>

<?php
mysqli_close($conexao);
?>

   </body>
</html>
