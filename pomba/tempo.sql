USE dbpomba;

CREATE TABLE curtida (
   username varchar(30) not null,
   id_pomba int not null,
   data_hora timestamp not null default current_timestamp,
   primary key(username, id_pomba),
   foreign key (username) references pomber (username),
   foreign key (id_pomba) references pomba (id)
);

