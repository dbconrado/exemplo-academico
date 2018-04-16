CREATE DATABASE escola2;
USE escola2;

CREATE TABLE aluno (
   id int auto_increment primary key,
   nome varchar(80),
   datanascimento DATE,
   cpf varchar(11),
   email varchar(250)
);

