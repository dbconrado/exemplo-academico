<!DOCTYPE html>
<html>
   <head>
      <meta charset="utf-8">
      <title>Acadêmico: Avaliações</title>
   </head>
   <body>

<?php
$conexao = mysqli_connect("localhost", "root", "root", "escola2");
if (!$conexao)
   die("Não consegui conectar: " . mysqli_connect_error());

$sql = "SELECT * FROM avaliacao";
$res = mysqli_query($conexao, $sql);
if (!$res)
   die("Não consegui fazer Select: " . mysqli_error($conexao));

?>


      <h1>Avaliações</h1>
      
      <form action="formulario_avaliacao.html" method="get">
         <button>Cadastrar Avaliação</button>
      </form>

      <table border="1">
         <thead>
            <tr>
               <th>ID</th>
               <th>Descrição</th>
               <th>Valor</th>
            </tr>
         </thead>
         <tbody>
            
<?php    while ($linha = mysqli_fetch_assoc($res)) { ?>
            
            <tr>
               <td><?= $linha['id'] ?></td>
               <td><?= $linha['descricao'] ?></td>
               <td><?= $linha['valor'] ?></td>
            </tr>
<?php    } 
         
         mysqli_close($conexao);
?>
         </tbody>
      </table>

   </body>
</html>
