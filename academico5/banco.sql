USE escola2;

CREATE TABLE nota (
   id_avaliacao INT NOT NULL,
   id_aluno INT NOT NULL,
   nota DECIMAL(5,2) NULL,
   PRIMARY KEY (id_avaliacao, id_aluno),
   FOREIGN KEY (id_avaliacao) REFERENCES avaliacao (id),
   FOREIGN KEY (id_aluno) REFERENCES aluno (id));
