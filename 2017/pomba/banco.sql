CREATE DATABASE dbpomba CHARACTER SET utf8;
USE dbpomba;

CREATE TABLE pomber (
username varchar(30) not null primary key,
senha varchar(200) not null,
nome varchar(200) not null,
foto varchar(500) not null);

INSERT INTO pomber VALUES (
'amanda', '123', 'Amanda', 'amanda.jpg'),
('andre', '123', 'André', 'andre.jpg'),
('karine', '123', 'Karine', 'karine.jpg');

CREATE TABLE pomba (
id int not null auto_increment primary key,
texto VARCHAR(141) not null,
data_hora timestamp not null default current_timestamp,
username varchar(30) not null,
foreign key (username) references pomber (username));

INSERT INTO pomba VALUES
(DEFAULT, 'Mudei de xampu', DEFAULT, 'andre'),
(DEFAULT, 'Bleach é ruim', DEFAULT, 'karine');

CREATE TABLE seguidor (
id int not null auto_increment primary key,
seguidor varchar(30) not null,
seguido varchar(30) not null,
foreign key (seguidor) references pomber (username),
foreign key (seguido) references pomber (username));

INSERT INTO seguidor VALUES
(DEFAULT, 'amanda', 'andre'),
(DEFAULT, 'amanda', 'karine');

CREATE TABLE curtida (
   username varchar(30) not null,
   id_pomba int not null,
   data_hora timestap not null default current_timestamp,
   primary key(username, id_pomba),
   foreign key (username) references pomber (username),
   foreign key (id_pomba) references pomba (id)
);

