<!DOCTYPE html>
<html>
   <head>
      <meta charset="UTF-8">
      <title>Bem-vindo!</title>
      <style type="text/css">
         h1, img {
            display: block;
            margin: 0 auto;
         }

         h1 { padding-top: 25px; }
      </style>
   </head>
   <body>
      <h1>Hey! 
      
      <?php
         $nome = $_GET['nome'];
         print $nome;
      ?>
      
      
      !</h1>
      <img 
         src="https://i.pinimg.com/originals/57/22/1d/57221d1e3f6e3b0c7a1e2ead4bb364a0.jpg">
   </body>
</html>
