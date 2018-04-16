<!DOCTYPE html>
<html>
   <head>
      <meta charset="UTF-8">
      <title>Acadêmico</title>
   </head>
   <body>
   <h1>Acadêmico</h1>
   <p>Mostrando todos os alunos:</p>
   <ol>
   <?php
   $conexao = mysqli_connect("localhost", "root", "root", "escola");
   $res = mysqli_query($conexao, 'SELECT * FROM aluno ORDER BY nome');
   while ($linha = mysqli_fetch_assoc($res)) {
      print "<li>" . $linha['nome'] . "</li>";
   }
   ?>
   </ol>
   </body>
</html>
