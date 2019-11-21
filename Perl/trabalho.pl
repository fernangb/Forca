#O arquivo "palavras.txt" possui as strings na seguinte ordem:
#   - Palavra a ser descoberta
#   - Dica da palavra
#   - Numero de caracteres
#   - Numero de caracteres diferentes
#   - Nivel de dificuldade (Facil, Medio, Dificil)


#Funcionalidade 1: Adicionar palavra
sub adicionarPalavra {
    ($palavra, $dica) = @;

  # my $palavra = $_[0];
   # my $dica = $_[1];

    my $arquivo = 'palavras.txt';

    open(FILE, '<:encoding(UTF-8)', $arquivo) or die "Nao foi possivel abrir o arquivo '$filename' $!";
    
    #my @data = <FILE>;

    print $arquivo "$palavra $dica\n";



    close(FILE);




}

adicionarPalavra("Gabriel","Nome");


#Funcionalidade 2:Escolher nivel de dificuldade da palavra

#Funcionalidade 3:Escolher palavra

#Funcionalidade 4:Salvar pontuacao

#Funcionalidade 5:Ranking de jogadas
