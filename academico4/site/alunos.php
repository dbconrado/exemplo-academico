<!DOCTYPE html>
<html>
   <head>
      <meta charset="UTF-8">
      <title>Acadêmico</title>
   </head>
   <body>
   <h1>Acadêmico</h1>
   <p>Mostrando todos os alunos:</p>

   <?php
   $conexao = mysqli_connect("localhost", "root", "root", "escola2");
   $res = mysqli_query($conexao, 'SELECT * FROM aluno ORDER BY nome');
   ?>

   <table border="1">
      <thead>
         <tr>
            <th>ID</th>
            <th>Nome</th>
            <th>Data Nascimento</th>
            <th>E-mail</th>
            <th>CPF</th>
         </tr>
      </thead>
      <tbody>

      <?php
      while ($linha = mysqli_fetch_assoc($res)) {
      ?>
         <tr>
            <td><?= $linha['id'] ?></td>
            <td><?= $linha['nome'] ?></td>
            <td><?= $linha['datanascimento'] ?></td>
            <td><?= $linha['email'] ?></td>
            <td><?= $linha['cpf'] ?></td>
         </tr>
      <?php
      }
      ?>

      </tbody>
   </table>
   </body>
</html>
