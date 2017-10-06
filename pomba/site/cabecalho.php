<!DOCTYPE html>
<html>
   <head>
      <meta charset="utf-8">
      <title><?= TITULO_PAGINA ?> : Pomba</title>
      <link href="estilos/estilo.css" rel="stylesheet" type="text/css">
   </head>
   <body>
      <header id="topbar">
         <h1>Pomba</h1>
         <form action="pesquisar.php" method="get">
            <label for="ibusca">Procurar</label>
            <input id="ibusca" type="search" name="busca"
               required>
            <button type="submit">Procurar</button>
         </form>
         <div id="logout-panel">
           <a href="logout.php">Logout</a>
         </div> 
      </header>
